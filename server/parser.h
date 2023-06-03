#ifndef PARSER_H
#define PARSER_H

#include <QDebug>
#include <QCoreApplication>

#include "MyPostgresDB.h"

class Parser
{
private:
    QStringList qsl;
public:
    /// Default constructor
    Parser();

    /// Initializing constructor that takes a QString with "&" delimiters, splits it, and assigns the resulting splitting QStringList to the qsl property
    Parser(QString);

    /// Parsing function that redirects the request to the desired function and returns a QString with "&" delimiters, which is the result of further functions
    QString parse();

    /// Not in use at the moment
    /// Function that takes a QStringList of the form ("reg", "login", "password", "role_id") redirecting to the registration function and returning the registration result true or false
    bool reg(QStringList);

    /// Function that takes a QStringList of the form ("auth", "login", "password") redirecting to the authorization function and returning QString "role_id&id&groups&teachers" if authorization is successful or ("err&arguments", "err&log", "err&pass") if it fails
    QString auth(QStringList);

    /// Function that takes a QStringList of the form ("view", "field", "field_id"), redirects to the schedule view function and returns a QString of the form "field&schedule" if successful and "false" if unsuccessful
    QString check_schedule(QStringList);

    /// Function that takes a QStringList of the form ("exc", "view", "teacher_id") or ("exc", "add", "teacher_id", "exceptions"), redirects to a function to view or change teacher exceptions and returns a QString of the form "view&exceptions" or "add&success"
    QString exceptions(QStringList);

    /// Function that redirects to the get teachers, groups and disciplines function and returns QString of the form "teachers&groups&disciplines"
    QString met_get();

    /// Function that takes QStringList forms ("add", "field", "data"), redirects to the function to add teachers, groups or disciplines and returns QString "successful" or "failed"
    QString met_add(QStringList);

    /// Function that takes QStringList forms ("update", "field", "data"), redirects to the function to update teachers, groups or disciplines and returns QString "successful" or "failed"
    QString met_updt(QStringList);

    /// Function that takes QStringList forms ("delete", "field", "data"), redirects to the function to delete teachers, groups or disciplines and returns QString "successful" or "failed"
    QString met_dlt(QStringList);
};

#endif // PARSER_H
