#ifndef MYPOSTGRESDB_H
#define MYPOSTGRESDB_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class MyPostgresDB;

class MyPostgresDBDestroyer
{
    private:
        MyPostgresDB* p_instance;
    public:
        ~MyPostgresDBDestroyer();
        void initialize(MyPostgresDB* p);
};

class MyPostgresDB
{
    private:
        static MyPostgresDB* p_instance;
        static MyPostgresDBDestroyer destroyer;
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    protected:
        MyPostgresDB();
        MyPostgresDB(const MyPostgresDB&);
        MyPostgresDB& operator = (MyPostgresDB &);
        ~MyPostgresDB();
        friend class MyPostgresDBDestroyer;
    public:
        static MyPostgresDB* getInstance();
        bool add_user(QStringList);
        bool sendQuery(QString qsl);

};

#endif // MYPOSTGRESDB_H
