#include "Client.h"

Client::Client() {
	socket = new QTcpSocket;
	socket->connectToHost("127.0.0.1", 33333);
    connect(socket, &QTcpSocket::readyRead, this, &Client::slot_readFromServer);
}

Client* Client::getInstance() {
	if (!p_instance) {
        p_instance = new Client();
		destroyer.initialize(p_instance);
	}
	return p_instance;
}

Client::~Client() {
	socket->close();
}

bool Client::sendToServer(QString msg) {
    if (socket->write(msg.toUtf8()))
        return true;
	else
        return false;
}

void Client::set_account_id(QString id)
{
    this->account_id = id.toInt();
    qDebug()<<account_id;
}

qint64 Client::get_account_id()
{
    return this->account_id;
}

void Client::slot_readFromServer() {
    QByteArray array;
    QString tmp;

    while(socket->bytesAvailable() > 0)
    {
        array=(socket->readLine());
        tmp.append(array);
    }
    array.clear();
    QStringList serverAns = tmp.split("&");
    qDebug() << "Client::slot_readFromServer\t" << serverAns;
    if (serverAns[0] == "reg")
        emit reg(serverAns[1]);
    else if (serverAns[0] == "auth")
        emit auth(serverAns);
    else if (serverAns[0] == "view")
    {
        if(serverAns[1] == "group")
            emit view_group(serverAns);
        else if(serverAns[1] == "teacher")
            emit view_teacher(serverAns);
    }
    else if (serverAns[0] == "err")
        emit err(serverAns[1]);
    else if (serverAns[0] == "exc")
    {
        if(serverAns[1] == "add")
            emit exc_add(serverAns[2]);
        else if(serverAns[1] == "view")
            emit exc_view(serverAns[2]);
    }
    else if (serverAns[0] == "get")
    {
        serverAns.removeFirst();
        emit get(serverAns);
    }
}

Client* Client::p_instance;
ClientDestroyer Client::destroyer;
