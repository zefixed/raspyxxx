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
    else if(this->qsl[0] == "get") return "get&" + met_get();
    else if(this->qsl[0] == "add") return "add&" + met_add(qsl);
    else if(this->qsl[0] == "update") return "update&" + met_updt(qsl);
    else if(this->qsl[0] == "delete") return "delete&" + met_dlt(qsl);
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

QString Parser::met_get()
{
    return MyPostgresDB::getInstance()->met_get();
}

QString Parser::met_add(QStringList add_data)
{
    return MyPostgresDB::getInstance()->met_add(add_data);
}

QString Parser::met_updt(QStringList update_data)
{
    return MyPostgresDB::getInstance()->met_updt(update_data);
}

QString Parser::met_dlt(QStringList delete_data)
{
    return MyPostgresDB::getInstance()->met_dlt(delete_data);
}
