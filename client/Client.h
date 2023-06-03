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

    /// Instance initialization function that takes a pointer to an instance
    void initialize(Client* p) { p_instance = p; }
};


class Client : public QObject {
	Q_OBJECT
private:
    static Client* p_instance;
    static ClientDestroyer destroyer;
	QTcpSocket* socket;
    qint64 account_id;
protected:
    /// Default constructor
    explicit Client();
    Client(const Client&) = delete;

    /// Prohibit the use of the assignment operator for this class
    Client& operator = (Client&) = delete;

    /// Destructor
    ~Client();
    friend class ClientDestroyer;
public:
    /// Get class instance function that returns a pointer to an instance of the class
    static Client* getInstance();

    /// A function to send content to the server that accepts a QString to send and returns the result of sending true or false
    bool sendToServer(QString);

    /// Function for assigning a value to the account_id property
    void set_account_id(QString id);

    /// Function for getting the value of account_id property
    qint64 get_account_id();

protected slots:
    // Slot triggered when receiving data from the server
	void slot_readFromServer();
signals:
    // Signal auth
    void auth(QStringList);

    // Signal reg
    void reg(QString);

    // Signal view
    void view(QList<QString>);

    // Signal err
    void err(QString);

    // Signal exc_add
    void exc_add(QString);

    // Signal exc_view
    void exc_view(QString);

    // Signal view_group
    void view_group(QStringList);

    // Signal view_teacher
    void view_teacher(QStringList);

    // Signal get
    void get(QStringList);
};

#endif // Client_H
