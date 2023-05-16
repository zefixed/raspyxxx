#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "Client.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_log_in_button_clicked();

    void on_show_pass_button_pressed();

    void on_show_pass_button_released();

    void slot_on_auth(QString);

private:
    Ui::LoginWindow* ui;

    QWidget* MW;

    //StudentWindow* SW;
    //TeacherWindow* TW;
    //MethodistWindow* MW;
};

#endif // LOGINWINDOW_H
