
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studentwindow.h"
#include "loginteacherwindow.h"
#include "loginmethodistwindow.h"




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
    void on_login_as_student_clicked();

    void on_login_as_teacher_clicked();

    void on_login_as_methodist_clicked();

private:
    Ui::MainWindow *ui;
    StudentWindow* SW;
    LoginTeacherWindow* LTW;
    LoginMethodistWindow* LMW;
};

#endif // MAINWINDOW_H
