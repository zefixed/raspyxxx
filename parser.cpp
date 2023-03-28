#include "Parser.h"

Parser::Parser()
{

}

Parser::Parser(QString str)
{
    this->qsl = str.left(str.capacity() - 2).split("&"); // from "str&str&str\r\n" to ("str", "str", "str")
}
bool Parser::parse()
{
    if(this->qsl.empty())
        return false;
    if(this->qsl[0] == "reg") reg(qsl);
    else if(this->qsl[0] == "auth") auth(qsl);
    else if(this->qsl[0] == "check") check_schedule(qsl);
    else if(this->qsl[0] == "resch") reschedule(qsl);
    else if(this->qsl[0] == "excp") select_exception(qsl);
    else return false;
    return true;
}

/// The function that redirects to the registration function
void Parser::reg(QStringList qsl)
{
    qDebug() << qsl;
}

/// The function that redirects to the authentication function
void Parser::auth(QStringList qsl)
{
    qDebug() << qsl;
}

/// The function that redirects to the schedule view function
void Parser::check_schedule(QStringList qsl)
{
    qDebug() << qsl;
}

/// The function that redirects to the schedule change function
void Parser::reschedule(QStringList qsl)
{
    qDebug() << qsl;
}

/// The function that redirects to the exception selection function
void Parser::select_exception(QStringList qsl)
{
    qDebug() << qsl;
}
