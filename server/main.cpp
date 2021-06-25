#include <QCoreApplication>
#include "hwserverproc.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    HwServerProc Server;
    Server.StartServer();
    return a.exec();
}

