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
    qDebug() << serverAns;
    if (serverAns[0] == "reg")
        emit reg(serverAns[1]);
    else if (serverAns[0] == "auth")
        emit auth(serverAns[1]);
    else if (serverAns[0] == "view")
        emit view(serverAns[1]);
    else if (serverAns[0] == "err")
        emit err(serverAns[1]);
    else if (serverAns[0] == "exc")
        emit exc(serverAns[1]);

    qDebug() << "readFromServer";
}

Client* Client::p_instance;
ClientDestroyer Client::destroyer;
