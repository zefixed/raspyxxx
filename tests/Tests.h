#ifndef TESTS_H
#define TESTS_H

#include <QDialog>
#include <QTest>
#include "../server/MyPostgresDB.h"

class Tests : public QObject
{
    Q_OBJECT

public:
    Tests(QWidget *parent = nullptr);
    ~Tests();

private slots:
    /// Unit test function written by Gerasenkov Ilya that tests the view_exception function of the MyPostgresDB class
    void test_Gerasenkov();

    /// Unit test function written by Petrochenko Kirill that tests the auth_user function of the MyPostgresDB class
    void test_Petrochenko();

    /// Unit test function written by Savinkin Ilya that tests the view_schedule function of the MyPostgresDB class
    void test_Savinkin();
};
#endif // TESTS_H
