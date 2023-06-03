#ifndef MYPOSTGRESDB_H
#define MYPOSTGRESDB_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

class MyPostgresDB;

class MyPostgresDBDestroyer
{
    private:
        //  Pointer to an instance of MyPostgresDB class
        MyPostgresDB* p_instance;
    public:
        /// The destructor of MyPostgresDBDestroyer class, which deletes a single instance of MyPostgresDB class
        ~MyPostgresDBDestroyer();

        /// Initializing MyPostgresDBDestroyer by assigning p_instance pointer to MyPostgresDB
        void initialize(MyPostgresDB* p);
};

class MyPostgresDB
{
    private:
        // Static instance of MyPostgresDB class
        static MyPostgresDB* p_instance;

        // Static instance of MyPostgresDBDestroyer class
        static MyPostgresDBDestroyer destroyer;

        /// Function that gets ip address from file and returns it
        QString getIPaddress();

        /// Postgres database object
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    protected:
        /// Default constructor
        MyPostgresDB();

        /// Copy constructor taking reference to MyPostgresDB
        MyPostgresDB(const MyPostgresDB&);

        /// Overloading the assignment operator for MyPostgresDB that takes a reference to the current instance of MyPostgresDB and returns a reference to a new instance of MyPostgresDB, allowing the operation "a = b = c"
        MyPostgresDB& operator = (MyPostgresDB &);

        /// Default destructor
        ~MyPostgresDB();

        // Friend class
        friend class MyPostgresDBDestroyer;
    public:
        /// Get database instance function that returns a pointer to MyPostgresDB
        static MyPostgresDB* getInstance();

        /// Function for adding a user to the database, taking a QStringList of the form ("add", "login", "password", "role_id") and returning the result of adding true or false
        bool add_user(QStringList);

        /// User authorization function taking QStringList of the form ("auth", "login", "password") and returning QString "role_id&id&groups&teachers" if authorization is successful or ("err&arguments", "err&log", "err&pass") if it fails
        QString auth_user(QStringList);

        /// Function to view the schedule for different fields that takes a QStringList of the form ("view", "field", "field_id") (field_id may contains "group_id" or "teacher_id") and returns a QString of the form "field&schedule" if successful and "false" if unsuccessful
        QString view_schedule(QStringList);

        /// Teacher exception view function that takes a QStringList of the form ("exc", "viev", "teacher_id") and returns a QString of the form "view&exceptions"
        QString view_exception(QStringList);

        /// Function for assigning exceptions to a teacher that takes a QStringList of the form ("exc", "add", "teacher_id", "exceptions") and returns a QString "add&successful"
        QString add_exception(QStringList);

        /// Get teachers, groups and disciplines function that returns a QString like "teachers&groups&disciplines"
        QString met_get();

        /// Function to add teachers, groups or disciplines that takes a QStringList of the form ("add", "field", "data") and that returns a QString "successful" or "failed"
        QString met_add(QStringList);

        /// Function to update teachers, groups or disciplines that takes a QStringList of the form ("update", "field", "data") and returns a QString "successful" or "failed".
        QString met_updt(QStringList);

        /// Function to delete teachers, groups or disciplines that takes a QStringList of the form ("delete", "field", "data") and returns a QString "successful" or "failed".
        QString met_dlt(QStringList);

        /// Obsolete function
        bool sendQuery(QString qsl);
};


#endif // MYPOSTGRESDB_H
