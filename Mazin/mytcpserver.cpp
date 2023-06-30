#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QFile>
#include <QtAlgorithms>
#include <QList>


MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
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

    readDataFromFile();
}

void MyTcpServer::slotNewConnection()
{
    QTcpSocket* socket = mTcpServer->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);

    socket->write("Connected to the server\r\n");
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket)
        return;

    while (socket->canReadLine()) {
        QString request = QString::fromUtf8(socket->readLine()).trimmed();
        processRequest(request, socket);
    }
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket)
        return;

    socket->close();
    socket->deleteLater();
}

void MyTcpServer::readDataFromFile()
{
    QFile file("C:/Exam/products.csv"); //местоположение файла с товарами
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4) {
            QString name = fields[0];
            QString type = fields[1];
            int price = fields[2].toInt();
            QString manufacturer = fields[3];

            productTypes[name] = type;
            productPrices[name] = price;
            productManufacturers[name] = manufacturer;
        }
    }

    file.close();
}

void MyTcpServer::processRequest(const QString& request, QTcpSocket* socket)
{
    QString response;
    QStringList parts = request.split("&");
    if (parts.size() >= 2) {
        QString command = parts[0];
        QString argument = parts[1];

        if (command == "max_price") {
            // вывести самые дорогие товары
            QList<Product> sortedProducts = products; // Копируем список товаров для сортировки
            QSort(sortedProducts.begin(), sortedProducts.end(), [](const Product& p1, const Product& p2) {
                return p1.price > p2.price; // Сортируем по убыванию цены
            });
            response = "Max price products:n";
            for (const Product& product : sortedProducts) {
                response += product.toString() + "n"; // Добавляем информацию о каждом товаре в ответ
            }
        } else if (command == "expensive_in_type") {
            // Получение товаров по типу
            QString type = argument;
            QList<Product> filteredProducts;
            for (const Product& product : products) {
                if (product.type == type) {
                    filteredProducts.append(product); // Фильтруем товары по заданному типу
                }
            }
            QSort(filteredProducts.begin(), filteredProducts.end(), [](const Product& p1, const Product& p2) {
                return p1.price > p2.price; // Сортируем по убыванию цены
            });
            response = "Expensive products in type " + type + ":n";
            for (const Product& product : filteredProducts) {
                response += product.toString() + "n"; // Добавляем информацию о каждом товаре в ответ
            }
        } else if (command == "max_price_in_type") {
            // Получение самых дорогих товаров заданного типа
            QString type = argument;
            QList<Product> filteredProducts;
            for (const Product& product : products) {
                if (product.type == type) {
                    filteredProducts.append(product); // Фильтруем товары по заданному типу
                }
            }
            QSort(filteredProducts.begin(), filteredProducts.end(), [](const Product& p1, const Product& p2) {
                return p1.price > p2.price; // Сортируем по убыванию цены
            });
            response = "Max price products in type " + type + ":n";
            if (!filteredProducts.isEmpty()) {
                response += filteredProducts.first().toString() + "n"; // Добавляем информацию о самом дорогом товаре в ответ
            } else {
                response += "No products of type " + type + " found.n";
            }
        } else if (command == "expensive") {
            // Получение товаров, которые дороже, чем средняя цена
            double averagePrice = 0;
            for (const Product& product : products) {
                averagePrice += product.price; // Считаем сумму всех цен
            }
            averagePrice /= products.size(); // Вычисляем среднюю цену
            QList<Product> filteredProducts;
            for (const Product& product : products) {
                if (product.price > averagePrice) {
                    filteredProducts.append(product); // Фильтруем товары, цена которых превышает среднюю
                }
            }
            QSort(filteredProducts.begin(), filteredProducts.end(), [](const Product& p1, const Product& p2) {
                return p1.price > p2.price; // Сортируем по убыванию цены
            });
            response = "Expensive products:n";
            for (const Product& product : filteredProducts) {
                response += product.toString() + "n"; // Добавляем информацию о каждом товаре в ответ
            }
        }
    } else {
        response = "Invalid request";
    }
 //написать код для вывода данных о цене товара в  Product
    sendResponse(response, socket);
}

void MyTcpServer::sendResponse(const QString& response, QTcpSocket* socket)
{
    if (socket && socket->isOpen()) {
        socket->write(response.toUtf8());
        socket->write("\r\n");
    }
}
