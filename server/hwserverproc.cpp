#include "hwserverproc.h"
#include <QNetworkInterface>
#include <iostream>


HwServerProc::HwServerProc(QObject *parent) : QTcpServer(parent)
{

}

void HwServerProc::StartServer()
{
    std::cout << "----------------------------------\n"
              << "| Homework TCP Server ver. 1.0.1 |\n"
              << "----------------------------------\n";
    int port;
    std::cout << "\nEnter port (0 = auto): ";
    std::cin >> port;
    if(listen(QHostAddress::Any,port))
    {
        QString ipAddress;
        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
        for (int i = 0; i < ipAddressesList.size(); ++i)
        {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address())
            {
                ipAddress = ipAddressesList.at(i).toString();
                break;
            }
        }
        if (ipAddress.isEmpty())
            ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
        qDebug() << "\nServer started on:" << ipAddress << ":" << serverPort() << "\n\n";
    }
    else
    {
        qDebug() << "\nServer not started!";
    }
}

void HwServerProc::incomingConnection(int handle)
{
    HwClientProc *client = new HwClientProc(this);
    client->SetSocket(handle);
}
