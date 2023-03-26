#include "MyPostgresDB.h"

MyPostgresDBDestroyer::~MyPostgresDBDestroyer()
{
    delete p_instance;
}

void MyPostgresDBDestroyer::initialize(MyPostgresDB* p)
{
    p_instance = p;
}

MyPostgresDB::MyPostgresDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setConnectOptions();
    db.setHostName("localhost");
    db.setDatabaseName("raspyxxx");
    db.setUserName("postgres");
    db.setPassword("root");
    if(!db.open())
        qDebug()<<db.lastError().text();
}

MyPostgresDB::~MyPostgresDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setConnectOptions();
    db.setHostName("localhost");
    db.setDatabaseName("raspyxxx");
    db.setUserName("postgres");
    db.setPassword("root");
    db.close();
}

MyPostgresDB* MyPostgresDB::getInstance()
{
    if (!p_instance)
    {
        p_instance = new MyPostgresDB();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}


