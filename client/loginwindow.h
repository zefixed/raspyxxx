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
    /// Default constructor
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    /// Slot triggered by pressing a button
    void on_log_in_button_clicked();

    /// Slot triggered by pressing the show button
    void on_show_pass_button_pressed();

    /// Slot triggered when show button released
    void on_show_pass_button_released();

    /// Slot triggered by auth signal
    void slot_on_auth(QStringList);

private:
    Ui::LoginWindow* ui;

    QWidget* MW;

    //StudentWindow* SW;
    //TeacherWindow* TW;
    //MethodistWindow* MW;
};

#endif // LOGINWINDOW_H
