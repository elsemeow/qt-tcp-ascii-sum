#include "hwclientproc.h"
#include <iostream>
#include <numeric>
#include <string>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QNetworkInterface>


HwClientProc::HwClientProc(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(16);
}

void HwClientProc::SetSocket(int Descriptor)
{
    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    socket->setSocketDescriptor(Descriptor);
}

void HwClientProc::connected(){}

void HwClientProc::disconnected(){}

void HwClientProc::readyRead()
{
    QString readsoc = socket->readAll();

    QString ipclient = socket->peerAddress().toString();

    QDate date = QDate::currentDate();
    QString datestr = date.toString("dd.MM.yyyy");

    QTime time = QTime::currentTime();
    QString timestr = time.toString("hh:mm:ss");

    qDebug() << '\t' << ipclient << "[" << datestr << "|" << timestr << "]:" << readsoc << '\n';

    std::string readsocstd = readsoc.toStdString();
    int sendsum = accumulate(readsocstd.begin(),readsocstd.end(),0);
    QString sendsumstr = QString::number(sendsum);

    QByteArray send2client;
    send2client.append(sendsumstr);
    socket->write(send2client);
    socket->waitForBytesWritten();
    socket->waitForReadyRead();

    QFile fileOut("HwServerLog.txt");
    if(fileOut.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream writeStream(&fileOut);
        writeStream << ipclient << " - [ " << datestr << " | " << timestr << " ]: " << readsoc
                    << '\n' << "Response by Server: " << sendsumstr << "\n\n";
        fileOut.close();
    }
}
