#include "Parser.h"

Parser::Parser()
{

}

void Parser::parse(QString str)
{
    QStringList qsl = str.left(str.capacity() - 2).split("&");
    if(qsl[0] == "reg") reg(qsl);
    else if(qsl[0] == "auth") auth(qsl);
    else if(qsl[0] == "check") check_schedule(qsl);
    else if(qsl[0] == "resch") reschedule(qsl);
    else if(qsl[0] == "excp") select_excption(qsl);
}

void Parser::reg(QStringList qsl)
{
    qDebug() << qsl;
}

void Parser::auth(QStringList qsl)
{
    qDebug() << qsl;
}

void Parser::check_schedule(QStringList qsl)
{
    qDebug() << qsl;
}

void Parser::reschedule(QStringList qsl)
{
    qDebug() << qsl;
}

void Parser::select_excption(QStringList qsl)
{
    qDebug() << qsl;
}
