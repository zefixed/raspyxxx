#include "Parser.h"
#include "MyPostgresDB.h"

Parser::Parser()
{

}

Parser::Parser(QString str)
{
    // this->qsl = str.left(str.capacity() - 2).split("&"); // from "str&str&str\r\n" to ("str", "str", "str") // from console
    this->qsl = str.left(str.capacity()).split("&"); // from "str&str&str\r\n" to ("str", "str", "str") // from ui
}

bool Parser::parse()
{
    if(this->qsl.empty())
        return false;
    if(this->qsl[0] == "reg") return reg(qsl);
    else if(this->qsl[0] == "auth") return auth(qsl);
    else if(this->qsl[0] == "viev") return check_schedule(qsl);
    else if(this->qsl[0] == "resch") return reschedule(qsl);
    else if(this->qsl[0] == "excp") return select_exception(qsl);
    else return false;
    return true;
}

bool Parser::reg(QStringList reg_data)
{
    return MyPostgresDB::getInstance()->add_user(reg_data);
}

bool Parser::auth(QStringList auth_data)
{
    return MyPostgresDB::getInstance()->auth_user(auth_data);
}

bool Parser::check_schedule(QStringList view_data)
{
    return MyPostgresDB::getInstance()->view_schedule(view_data);
    qDebug() << view_data;
}

bool Parser::reschedule(QStringList qsl)
{
    qDebug() << qsl;
    return true;
}

bool Parser::select_exception(QStringList qsl)
{
    qDebug() << qsl;
    return true;
}
