#include <QCoreApplication>
#include "mytcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer server;
    if (!server.startServer(QHostAddress::Any, 33333)) {
        qDebug() << "Failed to start server";
        return -1;
    }

    qDebug() << "Server is started";

    return a.exec();
}
