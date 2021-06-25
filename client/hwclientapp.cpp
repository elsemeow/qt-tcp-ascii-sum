#include "hwclientapp.h"

QTextStream cin(stdin);

HwClientApp::HwClientApp(QObject *parent) : QObject(parent){}

void HwClientApp::Connect()
{
    socket = new QTcpSocket(this);

    std::cout << "----------------------------------\n"
              << "| Homework TCP Client ver. 1.0.2 |\n"
              << "----------------------------------\n";

    std::string ip;
    std::cout << "\n-> Enter server IP: ";
    std::cin >> ip;
    QString ipq = QString::fromStdString(ip);

    int port;
    std::cout << "\n-> Enter server port: ";
    std::cin >> port;

    bool endloop = false;
    QString msgin;
    do
    {
        bool isnull = false;
        std::cout << "\n-> Enter your message: ";
        msgin = cin.readLine();
        std::string msgstd = msgin.toStdString();
        for(unsigned int i = 0; i < msgstd.size(); i++)
        {
            if((int)msgstd[i] < 0)
            {
                std::cout << "\n[!] Input Error: ASCII code of characters should be between 0 and 127!\n";
                isnull = true;
                break;
            }
        }
        if(msgstd.length() > 20 || msgstd.length() == 0)
        {
            if(isnull == false)
            {
              std::cout << "\n[!] Input Error: Length of message should be between 1 and 20 characters!\n";
            }
        }
        else
        {
            if(isnull != true){endloop = true;}
        }
    }while(endloop != true);

    endloop = false;
    std::string t;
    do
    {
        std::cout << "\n-> Enter send times: ";
        std::cin >> t;
        QString tqs = QString::fromStdString(t);
        int ti = tqs.toInt();
        bool isnull = false;
        for(unsigned int i = 0; i < t.size(); i++)
        {
            if((int)t[i] < 48 || (int)t[i] > 57)
            {
                std::cout << "\n[!] Input Error: Incorrect value!\n";
                isnull = true;
                break;
            }
        }
        if(ti > 100 || ti == 0)
        {
          if(isnull == false)
          {
              std::cout << "\n[!] Input Error: Value should be between 1 and 100!\n";
          }
        }
        else
        {
           if(isnull != true){endloop = true;}
        }
    }while(endloop != true);

    QString tqs = QString::fromStdString(t);
    int ti = tqs.toInt();

    qDebug() << '\n';
    for(int i = 0; i < ti; i++)
    {
        socket->connectToHost(ipq,port);
        if(socket->waitForConnected(3000))
        {
            int size = msgin.size();
            if(size > 20)
            {
               QStringRef msglim = msgin.leftRef(20);
               QByteArray msgbr;
               msgbr.append(msglim.toString());
               socket->write(msgbr);
            }
            else
            {
               QByteArray msgb;
               msgb.append(msgin);
               socket->write(msgb);
            }
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << "\t- Response by server: " << socket->readAll() << '\n';

            socket->close();
        }
    }
    socket->connectToHost(ipq,port);
    if(socket->waitForConnected(3000)){socket->close();}
    else{std::cout << "\n[!] Error: Can't connect to server!\n";}
    std::cout << "\n[x] End of session.";
}
