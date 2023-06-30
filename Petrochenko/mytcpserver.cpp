#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>




// Поставьте троечку ;(




MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    qDeleteAll(mClientConnections);
    mClientConnections.clear();
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "Server is not started";
    } else {
        qDebug() << "Server is started";
    }

    loadProductData();
}

bool MyTcpServer::startServer(const QHostAddress &address, quint16 port)
{
    if (!mTcpServer->listen(address, port)) {
        qDebug() << "Server is not started";
        return false;
    }

    server_status = 1;
    return true;
}


void MyTcpServer::slotNewConnection()
{
    if (mClientConnections.size() >= 6) {
        qDebug() << "Connection limit reached. Rejecting new connection.";
        return;
    }

    QTcpSocket *clientSocket = mTcpServer->nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);

    mClientConnections.append(clientSocket);
    qDebug() << "New client connected. Total clients:" << mClientConnections.size();
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if (clientSocket) {
        mClientConnections.removeOne(clientSocket);
        clientSocket->deleteLater();
        qDebug() << "Client disconnected. Total clients:" << mClientConnections.size();
    }
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if (clientSocket) {
        QByteArray requestData = clientSocket->readAll();
        QString request = QString::fromUtf8(requestData).trimmed();
        qDebug() << "Received request:" << request;

        QStringList requestParts = request.split('&');
        if (requestParts.size() < 2) {
            QString errorMessage = "Invalid request format.";
            sendResponse(clientSocket, formatErrorMessage(errorMessage));
            return;
        }

        QString command = requestParts[0];
        QStringList arguments = requestParts.mid(1);

        processCommand(command, arguments, clientSocket);
    }
}

void MyTcpServer::processCommand(const QString &command, const QStringList &arguments, QTcpSocket *clientSocket)
{
    if (command == "max_price") {
        QList<int> maxPriceItems = findMaxPriceItems();
        QString response = formatProductData(maxPriceItems);
        sendResponse(clientSocket, response);
    } else if (command == "expensive_in_type") {
        if (arguments.size() < 1) {
            QString errorMessage = "Missing argument 'type'.";
            sendResponse(clientSocket, formatErrorMessage(errorMessage));
            return;
        }

        QString type = arguments[0];
        QList<int> expensiveItems = findExpensiveInType(type);
        QString response = formatProductData(expensiveItems);
        sendResponse(clientSocket, response);
    } else if (command == "max_price_in_type") {
        if (arguments.size() < 1) {
            QString errorMessage = "Missing argument 'type'.";
            sendResponse(clientSocket, formatErrorMessage(errorMessage));
            return;
        }

        QString type = arguments[0];
        QList<int> maxPriceItems = findMaxPriceInType(type);
        QString response = formatProductData(maxPriceItems);
        sendResponse(clientSocket, response);
    } else if (command == "expensive") {
        QList<int> expensiveItems = findExpensiveItems();
        QString response = formatProductData(expensiveItems);
        sendResponse(clientSocket, response);
    } else {
        QString errorMessage = "Invalid command.";
        sendResponse(clientSocket, formatErrorMessage(errorMessage));
    }
}

void MyTcpServer::sendResponse(QTcpSocket *clientSocket, const QString &response)
{
    QByteArray responseData = response.toUtf8();
    clientSocket->write(responseData);
    clientSocket->waitForBytesWritten();
    clientSocket->disconnectFromHost();
}

void MyTcpServer::loadProductData()
{
    //                  \
    //                  \
    //                  \
    //                  \
    //                  \       ИЗМЕНИТЬ ПУТЬ
    //               \  \  /
    //                \ \ /
    //                 \\/

    QFile file("D:/code/exam 2023/221_352_Kirill_Petrochenko/products.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open products.csv";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() == 4) {
            QString name = parts[0];
            QString type = parts[1];
            int price = parts[2].toInt();
            QString manufacturer = parts[3];

            mProductData[type][name].append(price);
        }
    }

    file.close();
}

QList<int> MyTcpServer::findMaxPriceItems()
{
    QList<int> maxPrices;
    for (const QMap<QString, QList<int>>& products : mProductData.values()) {
        for (const QList<int>& prices : products.values()) {
            int maxPrice = *std::max_element(prices.constBegin(), prices.constEnd());
            maxPrices.append(maxPrice);
        }
    }
    return maxPrices;
}

QList<int> MyTcpServer::findExpensiveInType(const QString &type)
{
    QList<int> expensiveItems;
    if (mProductData.contains(type)) {
        const QMap<QString, QList<int>>& productsOfType = mProductData[type];
        for (const QList<int>& prices : productsOfType.values()) {
            int averagePrice = std::accumulate(prices.constBegin(), prices.constEnd(), 0) / prices.size();
            for (int price : prices) {
                if (price > averagePrice) {
                    expensiveItems.append(price);
                }
            }
        }
    }
    return expensiveItems;
}

QList<int> MyTcpServer::findMaxPriceInType(const QString &type)
{
    QList<int> maxPriceItems;
    if (mProductData.contains(type)) {
        const QMap<QString, QList<int>>& productsOfType = mProductData[type];
        for (const QList<int>& prices : productsOfType.values()) {
            int maxPrice = *std::max_element(prices.constBegin(), prices.constEnd());
            maxPriceItems.append(maxPrice);
        }
    }
    return maxPriceItems;
}

QList<int> MyTcpServer::findExpensiveItems()
{
    QList<int> allPrices;
    for (const QMap<QString, QList<int>>& products : mProductData.values()) {
        for (const QList<int>& prices : products.values()) {
            allPrices.append(prices);
        }
    }

    int averagePrice = std::accumulate(allPrices.constBegin(), allPrices.constEnd(), 0) / allPrices.size();

    QList<int> expensiveItems;
    for (int price : allPrices) {
        if (price > averagePrice) {
            expensiveItems.append(price);
        }
    }
    return expensiveItems;
}

QString MyTcpServer::formatProductData(const QList<int> &itemIndices)
{
    QString formattedData;
    for (const QMap<QString, QList<int>>& products : mProductData.values()) {
        for (const QString& name : products.keys()) {
            const QList<int>& prices = products[name];
            int price = prices.first(); // For simplicity, assume only one price per item
            if (itemIndices.contains(price)) {
                QString line = QString("%1, %2\n").arg(name).arg(price);
                formattedData += line;
            }
        }
    }
    return formattedData;
}

QString MyTcpServer::formatErrorMessage(const QString &errorMessage)
{
    return QString("Error: %1\n").arg(errorMessage);
}
