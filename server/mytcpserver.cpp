#include "mytcpserver.h"
#include "Parser.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    for (auto Socket : mTcpSocket) {
        Socket->close();
    }
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject* parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket* socket = mTcpServer->nextPendingConnection();
        int client_desc = socket->socketDescriptor();
        mTcpSocket[client_desc] = socket;
        socket->write("Hola user!\r\n");
        qDebug() << client_desc;

        connect(socket, &QTcpSocket::readyRead,
                this, &MyTcpServer::slotServerRead);
        connect(socket, &QTcpSocket::disconnected,
                this, &MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* socket = (QTcpSocket*)sender();
    int desc = socket->socketDescriptor();
    QByteArray array;
    QString tmp;

    while(mTcpSocket[desc]->bytesAvailable() > 0)
    {
        array=(socket->readLine());
        tmp.append(array);
    }
    array.clear();
    array.append(tmp.toUtf8());
    Parser test(array);
    test.parse();
    // array.append(parsing(tmp).toUtf8()); when will be func parsing
    socket->write(array);
}

void MyTcpServer::slotClientDisconnected(){
    // closing connection with socket
    QTcpSocket* socket = (QTcpSocket*)sender();
    socket->close();

    // deleting socket from qmap
    QMap<int, QTcpSocket*>::iterator i = mTcpSocket.begin();
    while(i.value() != socket)
    {
        if(i.value() == socket)
            mTcpSocket.erase(i);
        i++;
    }
}
