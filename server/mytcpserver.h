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

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    /// Default constructor
    explicit MyTcpServer(QObject* parent = nullptr);

    /// Destructor
    ~MyTcpServer();
public slots:

    /// Slot triggered when a new client connects
    void slotNewConnection();

    /// Slot triggered when a client disconnects
    void slotClientDisconnected();

    /// The slot is triggered when the client sends something to the server
    void slotServerRead();

    //void slotReadClient();
private:
    /// The server
    QTcpServer* mTcpServer;

    /// Qmap with sockets
    QMap<int, QTcpSocket*> mTcpSocket;

    /// Status of the server
    int server_status;
};
#endif // MYTCPSERVER_H







