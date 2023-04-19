#ifndef PARSER_H
#define PARSER_H

#include <QDebug>
#include <QCoreApplication>

class Parser
{
private:
    QStringList qsl;
public:
    /// Default constructor
    Parser();

    /// Initializing constructor
    Parser(QString);

    /// The parsing function that redirects the request to the required function
    QString parse();

    /// The function that redirects to the registration function
    bool reg(QStringList);

    /// The function that redirects to the authentication function
    QString auth(QStringList);

    /// The function that redirects to the schedule view function
    bool check_schedule(QStringList);

    /// The function that redirects to the schedule change function
    bool reschedule(QStringList);

    /// The function that redirects to the exception selection function
    bool select_exception(QStringList);
};

#endif // PARSER_H
