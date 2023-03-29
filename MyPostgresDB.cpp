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
    this->db.setConnectOptions();
    this->db.setHostName("localhost");
    this->db.setDatabaseName("raspyxxx");
    this->db.setUserName("postgres");
    this->db.setPassword("root");
    if(!db.open())
        qDebug()<<db.lastError().text();
}

MyPostgresDB::~MyPostgresDB()
{
    this->db.close();
}

bool MyPostgresDB::add_user(QStringList qsl)
{
    // Not work very well
    QSqlQuery query(db);
    query.prepare("INSERT INTO users (id, login, password, role_id) VALUES (DEFAULT, ?, ?, ?)");
    query.addBindValue(qsl[1]);
    query.addBindValue(qsl[2]);
    query.addBindValue(qsl[3]);
//    query.prepare("SELECT *  FROM users");
    query.exec();
    qDebug() << query.isActive();
    return true;
}

bool MyPostgresDB::sendQuery(QString qsl)
{
    // Not work very well
    QSqlQuery query(db);
    qDebug()<<qsl;
    query.exec(qsl);
    qDebug() << query.lastError();
    qDebug()<<query.value(0).toString();

    return true;
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

MyPostgresDB* MyPostgresDB::p_instance;
MyPostgresDBDestroyer MyPostgresDB::destroyer;
