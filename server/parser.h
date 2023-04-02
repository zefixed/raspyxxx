#ifndef PARSER_H
#define PARSER_H

#include <QDebug>
#include <QCoreApplication>

class Parser
{
private:
    QStringList qsl;
public:
    /// Constructor
    Parser();
    Parser(QString);

    bool parse();

    void reg(QStringList);

    void auth(QStringList);

    void check_schedule(QStringList);

    void reschedule(QStringList);

    void select_exception(QStringList);
};

#endif // PARSER_H
