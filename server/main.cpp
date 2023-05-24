#include <QCoreApplication>
#include "mytcpserver.h"
#include "MyPostgresDB.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer server;
    
    //MyPostgresDB::set_address(argv[1]);
    MyPostgresDB::getInstance();
    return a.exec();
}
