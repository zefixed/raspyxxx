
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "Client.h"
#include "loginwindow.h"
#include "exceptionswindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    /// Default constructor
    MainWindow(QWidget *parent = nullptr);

    /// Destructor
    ~MainWindow();

private slots:
    /// Slot triggered by pressing an exception button
    void on_exceptions_button_clicked();

    /// Slot triggered by pressing a change schedule button
    void on_change_schedule_button_clicked();

    /// Slot triggered by pressing a change schedule button
    void err_slot(QString);

    /// Slot triggered by pressing return in lineedit
    void on_input_group_lineedit_returnPressed();

    void slot_on_idk(QList<QString> ansFromServ);

    void exc_slot(QString dataFromServ);

private:
    Ui::MainWindow* ui;

    LoginWindow* LW;
    ExceptionsWindow* EW;


};

#endif // MAINWINDOW_H
