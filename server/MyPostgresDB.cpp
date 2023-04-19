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

MyPostgresDB::MyPostgresDB(const MyPostgresDB&)
{

}

MyPostgresDB::~MyPostgresDB()
{
    this->db.close();
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

bool MyPostgresDB::add_user(QStringList reg_data)
{
    if(reg_data.size() != 4)
        return false;

    QSqlQuery query(db);
    query.prepare("SELECT login FROM users WHERE login = ?");
    query.addBindValue(reg_data[1]);
    query.exec();

    if(query.next())
        return false; // login exists

    query.prepare("INSERT INTO users (id, login, password, role_id) VALUES (DEFAULT, ?, ?, ?)");
    query.addBindValue(reg_data[1]);
    query.addBindValue(reg_data[2]);
    query.addBindValue(reg_data[3]);
    query.exec();
    return true;
}

QString MyPostgresDB::auth_user(QStringList auth_data)
{
    if(auth_data.size() != 3)
        return "err&arguments";

    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE login = ?");
    query.addBindValue(auth_data[1]);
    query.exec();

    if(!query.next())
        return "err&log"; // login doesn't exist

    if(query.value(query.record().indexOf("password")) != auth_data[2])
        return "err&pass"; // wrong password

    return query.value(query.record().indexOf("role_id")).toString(); // login and password is correct
}

bool MyPostgresDB::view_schedule(QStringList view_data)
{
    if(view_data.size() != 3)
        return false;

    QSqlQuery query(db);
    query.prepare("SELECT * FROM schedule WHERE " + view_data[1] + " = ?");
    //query.addBindValue(view_data[1]);
    query.addBindValue(view_data[2]);
    query.exec();

    while(query.next())
        qDebug() << query.value(query.record().indexOf("id"));

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

MyPostgresDB* MyPostgresDB::p_instance;
MyPostgresDBDestroyer MyPostgresDB::destroyer;
