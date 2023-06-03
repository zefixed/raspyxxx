#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMap>

#include <iostream>

#include "Parser.h"

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    /// An explicit сonstructor takes a pointer to a parent QWidget
    explicit MyTcpServer(QObject* parent = nullptr);

    /// Default destructor
    ~MyTcpServer();
public slots:

    // Slot slotNewConnection
    void slotNewConnection();

    // Slot slotClientDisconnected
    void slotClientDisconnected();

    // Slot slotServerRead
    void slotServerRead();

    //void slotReadClient();
private:
    // The server
    QTcpServer* mTcpServer;

    // Qmap with sockets
    QMap<int, QTcpSocket*> mTcpSocket;

    // Status of the server
    int server_status;

    // ip address of pc
    QString ip_addr;

    /// Function that gets ip address from file and returns it
    void getIPaddress();
};
#endif // MYTCPSERVER_H







