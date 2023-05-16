#include "Parser.h"


Parser::Parser()
{

}

Parser::Parser(QString str)
{
    // this->qsl = str.left(str.capacity() - 2).split("&"); // from "str&str&str\r\n" to ("str", "str", "str") // from console
    this->qsl = str.left(str.capacity()).split("&"); // from "str&str&str" to ("str", "str", "str") // from ui
}

QString Parser::parse()
{
    if(this->qsl.empty())
        return "err";
    if(this->qsl[0] == "reg") return "reg&" + QString::number(reg(qsl));
    else if(this->qsl[0] == "auth") return "auth&" + auth(qsl);
    else if(this->qsl[0] == "view") return "view&" +  check_schedule(qsl);
    /* else if(this->qsl[0] == "resch") return reschedule(qsl);
    else if(this->qsl[0] == "excp") return select_exception(qsl);
    else return false;
    return true;*/
}

bool Parser::reg(QStringList reg_data)
{
    qDebug() << reg_data;
    return MyPostgresDB::getInstance()->add_user(reg_data);
}

QString Parser::auth(QStringList auth_data)
{
    qDebug() << auth_data;
    return MyPostgresDB::getInstance()->auth_user(auth_data);
}

QString Parser::check_schedule(QStringList view_data)
{
    qDebug() << view_data;
    return MyPostgresDB::getInstance()->view_schedule(view_data);
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
