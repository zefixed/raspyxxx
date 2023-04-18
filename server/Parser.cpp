#include "Parser.h"
#include "MyPostgresDB.h"

Parser::Parser()
{

}

Parser::Parser(QString str)
{
    // this->qsl = str.left(str.capacity() - 2).split("&"); // from "str&str&str\r\n" to ("str", "str", "str")
    this->qsl = str.left(str.capacity()).split("&"); // from "str&str&str\r\n" to ("str", "str", "str")
}

bool Parser::parse()
{
    if(this->qsl.empty())
        return false;
    if(this->qsl[0] == "reg") reg(qsl);
    else if(this->qsl[0] == "auth") auth(qsl);
    else if(this->qsl[0] == "viev") check_schedule(qsl);
    else if(this->qsl[0] == "resch") reschedule(qsl);
    else if(this->qsl[0] == "excp") select_exception(qsl);
    else return false;
    return true;
}

void Parser::reg(QStringList reg_data)
{
    MyPostgresDB::getInstance()->add_user(reg_data);
}

void Parser::auth(QStringList auth_data)
{
    MyPostgresDB::getInstance()->auth_user(auth_data);
}

void Parser::check_schedule(QStringList view_data)
{
    MyPostgresDB::getInstance()->view_schedule(view_data);
    qDebug() << view_data;
}

void Parser::reschedule(QStringList qsl)
{
    qDebug() << qsl;
}

void Parser::select_exception(QStringList qsl)
{
    qDebug() << qsl;
}
