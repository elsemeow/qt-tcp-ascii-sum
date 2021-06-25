#include <QCoreApplication>
#include "hwclientapp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    HwClientApp HwCApp;
    HwCApp.Connect();
    return a.exec();
}

