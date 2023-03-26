#ifndef PARSER_H
#define PARSER_H

#include <QDebug>
#include <QCoreApplication>

class Parser
{
public:
    /// Constructor
    Parser();

    void parse(QString);

    void reg(QStringList);

    void auth(QStringList);

    void check_schedule(QStringList);

    void reschedule(QStringList);

    void select_excption(QStringList);
};

#endif // PARSER_H
