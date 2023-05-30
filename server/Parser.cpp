#include "Parser.h"


Parser::Parser()
{

}

Parser::Parser(QString str)
{
    // this->qsl = str.left(str.capacity() - 2).split("&"); // from "str&str&str\r\n" to ("str", "str", "str") // from console
    this->qsl = str.split("&"); // from "str&str&str" to ("str", "str", "str") // from ui
}

QString Parser::parse()
{
    if(this->qsl.empty())
        return "err";
    if(this->qsl[0] == "reg") return "reg&" + QString::number(reg(qsl));
    else if(this->qsl[0] == "auth") return "auth&" + auth(qsl);
    else if(this->qsl[0] == "view") return "view&" +  check_schedule(qsl);
    else if(this->qsl[0] == "exc") return "exc&" + exceptions(qsl);
    else if(this->qsl[0] == "get") return "get&" + get();
    else if(this->qsl[0] == "add") return "add&" + add(qsl);
    else if(this->qsl[0] == "update") return "update&" + updt(qsl);
    else if(this->qsl[0] == "delete") return "delete&" + dlt(qsl);
    /* else if(this->qsl[0] == "resch") return reschedule(qsl);*/
    else return "err&parse";
}

bool Parser::reg(QStringList reg_data)
{
    return MyPostgresDB::getInstance()->add_user(reg_data);
}

QString Parser::auth(QStringList auth_data)
{
    return MyPostgresDB::getInstance()->auth_user(auth_data);
}

QString Parser::check_schedule(QStringList view_data)
{
    return MyPostgresDB::getInstance()->view_schedule(view_data);
}

bool Parser::reschedule(QStringList qsl)
{
    qDebug() << qsl;
    return true;
}

QString Parser::exceptions(QStringList exc_data)
{
    qDebug() << exc_data;
    if(exc_data[1] == "view")
        return MyPostgresDB::getInstance()->view_exception(exc_data);
    else if (exc_data[1] == "add")
        return MyPostgresDB::getInstance()->add_exception(exc_data);
    else
        return "err";
}

QString Parser::get()
{
    return MyPostgresDB::getInstance()->get();
}

QString Parser::add(QStringList add_data)
{
    return MyPostgresDB::getInstance()->add(add_data);
}

QString Parser::updt(QStringList update_data)
{
    return MyPostgresDB::getInstance()->updt(update_data);
}

QString Parser::dlt(QStringList delete_data)
{
    return MyPostgresDB::getInstance()->dlt(delete_data);
}
