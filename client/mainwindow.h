
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Client.h"
#include "loginwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exceptions_button_clicked();

    void on_change_schedule_button_clicked();

private:
    Ui::MainWindow *ui;

    LoginWindow* LW;
};

#endif // MAINWINDOW_H
