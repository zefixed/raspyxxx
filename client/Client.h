#ifndef Client_H
#define Client_H

#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>
#include <QDebug>

class Client;

class ClientDestroyer {
private:
    Client* p_instance;
public:
    ~ClientDestroyer() { delete p_instance; }
    void initialize(Client* p) { p_instance = p; }
};


class Client : public QObject {
	Q_OBJECT
private:
    static Client* p_instance;
    static ClientDestroyer destroyer;
	QTcpSocket* socket;
protected:
    explicit Client();
    Client(const Client&) = delete;
    Client& operator = (Client&) = delete;
    ~Client();
    friend class ClientDestroyer;
public:
    static Client* getInstance();
	bool sendToServer(QString);
protected slots:
	void slot_readFromServer();
signals:
};

#endif // Client_H
