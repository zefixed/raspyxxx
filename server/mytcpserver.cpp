#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::MyTcpServer(QObject* parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    getIPaddress();

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        QString sis = QString("server is started at " + this->ip_addr);
        QDebug debug = qDebug();
        debug.noquote();
        debug << sis;
    }
}

MyTcpServer::~MyTcpServer()
{
    for (auto Socket : mTcpSocket) {
        Socket->close();
    }
    mTcpServer->close();
    server_status=0;
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
    qDebug() << "MyTcpServer::slotServerRead()\t" << array;
    Parser test((QString)array);

    //test.parse(); // (rewrite!!!!!!) return true or false and this answer need to be sent to client
    // array.append(parsing(tmp).toUtf8()); when will be func parsing
    socket->write(test.parse().toUtf8());
}

void MyTcpServer::getIPaddress()
{
    QFile file("../server/ip/ip_addr");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString errorString = file.errorString();
        qDebug() << "Error opening file: " << errorString;
        qDebug() << "Failed to open file at path: " << QFileInfo(file).absoluteFilePath();
        this->ip_addr = "0.0.0.0";
    }

    QTextStream in(&file);
    QString ip = in.readAll();

    file.close();

    this->ip_addr = ip;
}

