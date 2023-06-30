#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QStringList>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();

    bool startServer(const QHostAddress &address, quint16 port);

public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();

private:
    QTcpServer *mTcpServer;
    QList<QTcpSocket *> mClientConnections;
    QMap<QString, QMap<QString, QList<int>>> mProductData;

    int server_status; // Добавленная переменная server_status

    void processCommand(const QString &command, const QStringList &arguments, QTcpSocket *clientSocket);
    void sendResponse(QTcpSocket *clientSocket, const QString &response);

    void loadProductData();
    QList<int> findMaxPriceItems();
    QList<int> findExpensiveInType(const QString &type);
    QList<int> findMaxPriceInType(const QString &type);
    QList<int> findExpensiveItems();

    QString formatProductData(const QList<int> &itemIndices);
    QString formatErrorMessage(const QString &errorMessage);
};

#endif // MYTCPSERVER_H
