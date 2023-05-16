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
        ///  Pointer to an instance of MyPostgresDB class
        MyPostgresDB* p_instance;
    public:
        /// The destructor of MyPostgresDBDestroyer class,
        /// which deletes a single instance of MyPostgresDB class
        ~MyPostgresDBDestroyer();

        /// Initializing MyPostgresDBDestroyer by assigning p_instance
        /// pointer to MyPostgresDB
        void initialize(MyPostgresDB* p);
};

class MyPostgresDB
{
    private:
        /// Static instance of MyPostgresDB class
        static MyPostgresDB* p_instance;

        /// Static instance of MyPostgresDBDestroyer class
        static MyPostgresDBDestroyer destroyer;

        /// Function to get the current ip address of the NIC
        QString getIPaddress();

        /// Postgres database object
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    protected:
        /// Default constructor
        MyPostgresDB();

        /// Сopy constructor
        MyPostgresDB(const MyPostgresDB&);

        /// Operator overload =
        MyPostgresDB& operator = (MyPostgresDB &);

        /// Destructor
        ~MyPostgresDB();

        /// Friend class
        friend class MyPostgresDBDestroyer;
    public:
        /// Function to get a database instance
        static MyPostgresDB* getInstance();

        /// Function to add a user to the database
        bool add_user(QStringList);

        /// Function for checking the correctness of user authentication data entry
        QString auth_user(QStringList);

        /// Function of viewing the schedule by various fields
        QString view_schedule(QStringList);

        /// Function to execute a database query
        bool sendQuery(QString qsl);
};

#endif // MYPOSTGRESDB_H
