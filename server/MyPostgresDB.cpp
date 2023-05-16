#include "MyPostgresDB.h"
#include <QNetworkInterface>
MyPostgresDBDestroyer::~MyPostgresDBDestroyer()
{
    delete p_instance;
}

void MyPostgresDBDestroyer::initialize(MyPostgresDB* p)
{
    p_instance = p;
}

QString MyPostgresDB::getIPaddress()
{
    QString ipAddress;

    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    foreach (const QNetworkInterface& interface, interfaces) {
        // Пропускаем интерфейсы, которые не являются активными или не являются IPv4
        if (!interface.isValid() || !interface.flags().testFlag(QNetworkInterface::IsUp) ||
            interface.flags().testFlag(QNetworkInterface::IsLoopBack) ||
            !interface.flags().testFlag(QNetworkInterface::CanBroadcast))
        {
            continue;
        }

        QList<QNetworkAddressEntry> entries = interface.addressEntries();
        foreach (const QNetworkAddressEntry& entry, entries) {
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                ipAddress = entry.ip().toString();
                break;
            }
        }

        if (!ipAddress.isEmpty()) {
            break;
        }
    }
    return ipAddress;

}

MyPostgresDB::MyPostgresDB()
{
    this->db.setConnectOptions();
    this->db.setHostName(getIPaddress());
    this->db.setDatabaseName("raspyxxx");
    this->db.setUserName("postgres");
    this->db.setPassword("root");
    if(!db.open())
        qDebug()<<db.lastError().text();
}

MyPostgresDB::MyPostgresDB(const MyPostgresDB&)
{

}

MyPostgresDB::~MyPostgresDB()
{
    this->db.close();
}

MyPostgresDB* MyPostgresDB::getInstance()
{
    if (!p_instance)
    {
        p_instance = new MyPostgresDB();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

bool MyPostgresDB::add_user(QStringList reg_data)
{
    if(reg_data.size() != 4)
        return false;

    QSqlQuery query(db);
    query.prepare("SELECT login FROM users WHERE login = ?");
    query.addBindValue(reg_data[1]);
    query.exec();

    if(query.next())
        return false; // login exists

    query.prepare("INSERT INTO users (id, login, password, role_id) VALUES (DEFAULT, ?, ?, ?)");
    query.addBindValue(reg_data[1]);
    query.addBindValue(reg_data[2]);
    query.addBindValue(reg_data[3]);
    query.exec();
    return true;
}

QString MyPostgresDB::auth_user(QStringList auth_data)
{
    if(auth_data.size() != 3)
        return "err&arguments";

    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE login = ?");
    query.addBindValue(auth_data[1]);
    query.exec();

    if(!query.next())
        return "err&log"; // login doesn't exist

    if(query.value(query.record().indexOf("password")) != auth_data[2])
        return "err&pass"; // wrong password

    return query.value(query.record().indexOf("role_id")).toString(); // login and password is correct
}

QString MyPostgresDB::view_schedule(QStringList view_data)
{
    if(view_data.size() != 3)
        return "false";

    QSqlQuery query(db);
    //query.prepare("SELECT * FROM schedule WHERE " + view_data[1] + " = ?");
    query.prepare("SELECT groups.\"group\" AS \"group\", "
                  "CONCAT(teachers.last_name, ' ', teachers.first_name, ' ', teachers.patronymic) AS \"teacher\", "
                  "buildings.building_address AS \"address\", "
                  "rooms.room_num AS \"audience\", "
                  "CONCAT(times.start_time, ' - ', times.end_time) AS \"time\", "
                  "days.day AS \"weekday\", "
                  "discipline.name AS \"discipline\", "
                  "discipline_type.name AS \"discipline_type\" "
                  "FROM schedule "
                  "JOIN groups ON schedule.group_id = groups.id "
                  "JOIN teachers ON schedule.teacher_id = teachers.id "
                  "JOIN rooms ON schedule.room_id = rooms.id "
                  "JOIN buildings ON rooms.building_id = buildings.id "
                  "JOIN times ON schedule.pair_id = times.id "
                  "JOIN days ON schedule.day_id = days.id "
                  "JOIN discipline ON schedule.discipline_id = discipline.id "
                  "JOIN discipline_type ON schedule.discipline_type_id = discipline_type.id "
                  "WHERE groups.\"group\" = \'" + view_data[2] + "'");

    query.exec();

    QString ans;

    while(query.next()){
        ans += query.value(query.record().indexOf("group")).toString() + '|';
        ans += query.value(query.record().indexOf("teacher")).toString() + '|';
        ans += query.value(query.record().indexOf("address")).toString() + '|';
        ans += query.value(query.record().indexOf("audience")).toString() + '|';
        ans += query.value(query.record().indexOf("time")).toString() + '|';
        ans += query.value(query.record().indexOf("weekday")).toString() + '|';
        ans += query.value(query.record().indexOf("discipline")).toString() + '|';
        ans += query.value(query.record().indexOf("discipline_type")).toString();

        ans += "&";
    }

    return ans;

}

bool MyPostgresDB::sendQuery(QString qsl)
{
    // Not work very well
    QSqlQuery query(db);
    qDebug() << qsl;
    query.exec(qsl);
    qDebug() << query.lastError();
    qDebug()<<query.value(0).toString();

    return true;
}

MyPostgresDB* MyPostgresDB::p_instance;
MyPostgresDBDestroyer MyPostgresDB::destroyer;
