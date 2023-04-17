#ifndef LOGINMETHODISTWINDOW_H
#define LOGINMETHODISTWINDOW_H

#include <QDialog>
#include "methodistwindow.h"

namespace Ui {
class LoginMethodistWindow;
}

class LoginMethodistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginMethodistWindow(QWidget *parent = nullptr);
    ~LoginMethodistWindow();

private slots:
    void on_show_pass_button_pressed();

    void on_show_pass_button_released();

    void on_log_in_button_2_clicked();

    void on_cancel_button_2_clicked();

private:
    Ui::LoginMethodistWindow *ui;
    MethodistWindow* MW;
    QWidget* mainWindow;
};

#endif // LOGINMETHODISTWINDOW_H
