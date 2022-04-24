#ifndef HWCLIENTAPP_H
#define HWCLIENTAPP_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <iostream>
#include <string>

class HwClientApp : public QObject
{
    Q_OBJECT
public:
    explicit HwClientApp(QObject *parent = 0);
    void Connect();

signals:

public slots:

private:
    QTcpSocket *socket;
};

#endif // HWCLIENTAPP_H
