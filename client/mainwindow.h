
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studentwindow.h"
#include "teacherwindow.h"
#include "methodistwindow.h"
#include "Client.h"


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
    void on_log_in_button_2_clicked();

    void on_show_pass_button_pressed();

    void on_show_pass_button_released();

private:
    Ui::MainWindow *ui;
    StudentWindow* SW;
    TeacherWindow* TW;
    MethodistWindow* MW;
};

#endif // MAINWINDOW_H
