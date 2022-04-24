#ifndef HWSERVERPROC_H
#define HWSERVERPROC_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include "hwclientproc.h"

class HwServerProc : public QTcpServer
{
public:
    explicit HwServerProc(QObject *parent = 0);
    void StartServer();

protected:
    void incomingConnection(int handle);

signals:

public slots:
};

#endif // HWSERVERPROC_H
