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

void Client::slot_readFromServer() {
	qDebug() << "readFromServer";
}


Client* Client::p_instance;
ClientDestroyer Client::destroyer;
