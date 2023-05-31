#include "Tests.h"

Tests::Tests(QWidget *parent)
    : QObject(parent)
{
}

Tests::~Tests()
{
}

void Tests::test_Gerasenkov()
{
    QVERIFY(MyPostgresDB::getInstance()->view_exception(QStringList() << "exc" << "view" << "999") == "view&1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1");
}

void Tests::test_Petrochenko()
{
    QVERIFY(MyPostgresDB::getInstance()->auth_user(QStringList() << "auth" << "2" << "1") == "err&pass");
}
