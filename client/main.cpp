#include <QCoreApplication>
#include "Client.h"

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);
    Client::getInstance()->sendToServer("auth asdd asdf");
    return a.exec();
}
