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
    bool parse();

    /// The function that redirects to the registration function
    void reg(QStringList);

    /// The function that redirects to the authentication function
    void auth(QStringList);

    /// The function that redirects to the schedule view function
    void check_schedule(QStringList);

    /// The function that redirects to the schedule change function
    void reschedule(QStringList);

    /// The function that redirects to the exception selection function
    void select_exception(QStringList);
};

#endif // PARSER_H
