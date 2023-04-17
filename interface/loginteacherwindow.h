#ifndef LOGINTEACHERWINDOW_H
#define LOGINTEACHERWINDOW_H

#include <QDialog>
#include "teacherwindow.h"

namespace Ui {
class LoginTeacherWindow;
}

class LoginTeacherWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginTeacherWindow(QWidget *parent = nullptr);
    ~LoginTeacherWindow();

signals:

private slots:
    void on_log_in_button_2_clicked();

    void on_cancel_button_2_clicked();

    void on_show_pass_button_pressed();

    void on_show_pass_button_released();

private:
    Ui::LoginTeacherWindow *ui;
    TeacherWindow* TW;
    QWidget* mainWindow;
};

#endif // LOGINTEACHERWINDOW_H
