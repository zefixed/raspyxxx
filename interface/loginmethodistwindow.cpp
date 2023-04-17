#include <QMessageBox>

#include "loginmethodistwindow.h"
#include "ui_loginmethodistwindow.h"

LoginMethodistWindow::LoginMethodistWindow(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::LoginMethodistWindow)
{
    ui->setupUi(this);

    // получить указатель на главное окно
    mainWindow = parent;
}

LoginMethodistWindow::~LoginMethodistWindow()
{
    delete ui;
}

void LoginMethodistWindow::on_log_in_button_2_clicked()
{
    QString login = ui->login_lineedit->text();
    QString password = ui->pass_lineedit->text();

    if(login == "mazik" && password == "nefor"){
        mainWindow->hide();
        hide();
        MW = new MethodistWindow(this);
        MW->show();
    }
    else if(login == "mazik"){
        QMessageBox::warning(this, "Ошибка авторизации", "Введен неверный пароль.");
    }
    else if(password == "nefor"){
        QMessageBox::warning(this, "Ошибка авторизации", "Введен неверный логин.");
    }
    else if(login != "mazik" && password != "nefor"){
        QMessageBox::warning(this, "Ошибка авторизации", "Неверный логин и пароль.");
    }
    else{
        QMessageBox::information(this, "Ошибка авторизации", "Введите логин и пароль.");
    }
}

void LoginMethodistWindow::on_cancel_button_2_clicked()
{
    close();
}

void LoginMethodistWindow::on_show_pass_button_pressed()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Normal);
}


void LoginMethodistWindow::on_show_pass_button_released()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Password);
}

