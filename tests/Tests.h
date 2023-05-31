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
    void test_Gerasenkov();
    void test_Petrochenko();
};
#endif // TESTS_H
