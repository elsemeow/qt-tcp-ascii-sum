#ifndef HWCLIENTPROC_H
#define HWCLIENTPROC_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>

class HwClientProc : public QObject
{
    Q_OBJECT
public:
    explicit HwClientProc(QObject *parent = 0);
    void SetSocket(int Descriptor);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // HWCLIENTPROC_H
