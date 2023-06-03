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
    /// An explicit сonstructor takes a pointer to a parent QWidget
    explicit LoginWindow(QWidget *parent = nullptr);

    /// Default destructor
    ~LoginWindow();

private slots:
    // Slot on_log_in_button_clicked
    void on_log_in_button_clicked();

    // Slot on_show_pass_button_pressed
    void on_show_pass_button_pressed();

    // Slot on_show_pass_button_released
    void on_show_pass_button_released();

    // Slot slot_on_auth
    void slot_on_auth(QStringList);

private:
    Ui::LoginWindow* ui;
    QWidget* MW;

    //StudentWindow* SW;
    //TeacherWindow* TW;
    //MethodistWindow* MW;
};

#endif // LOGINWINDOW_H
