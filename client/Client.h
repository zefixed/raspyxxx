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

    /// Instance initialization function
    void initialize(Client* p) { p_instance = p; }
};


class Client : public QObject {
	Q_OBJECT
private:
    static Client* p_instance;
    static ClientDestroyer destroyer;
	QTcpSocket* socket;
    qint64 account_id;
    // qwe
protected:
    /// Default constructor
    explicit Client();
    Client(const Client&) = delete;

    /// Operator overload equals
    Client& operator = (Client&) = delete;

    /// Destructor
    ~Client();
    friend class ClientDestroyer;
public:
    /// Get instance function
    static Client* getInstance();

    /// Data sending dunction
	bool sendToServer(QString);
protected slots:
    /// Slot triggered when receiving data from the server
	void slot_readFromServer();
signals:
    /// Signal auth
    void auth(QString);

    /// Signal reg
    void reg(QString);

    /// Signal view
    void view(QString);

    /// Signal err
    void err(QString);
};

#endif // Client_H
