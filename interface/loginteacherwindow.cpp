#include "loginteacherwindow.h"
#include "ui_loginteacherwindow.h"
#include <QMessageBox>

LoginTeacherWindow::LoginTeacherWindow(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::LoginTeacherWindow)
{
    ui->setupUi(this);

    // получить указатель на главное окно
    mainWindow = parent;
}

LoginTeacherWindow::~LoginTeacherWindow()
{
    delete ui;
}

void LoginTeacherWindow::on_log_in_button_2_clicked()
{
    QString login = ui->login_lineedit->text();
    QString password = ui->pass_lineedit->text();

    if(login == "mazik" && password == "nefor"){
        mainWindow->hide();
        hide();
        TW = new TeacherWindow(this);
        TW->show();
    }
    else if(login == "mazik"){
        QMessageBox::warning(this, "Ошибка авторизации", "Введен неверный пароль.");
    }
    else if(password == "nefor"){
        QMessageBox::warning(this, "Ошибка авторизации", "Введен неверный логин.");
    }
    else{
        QMessageBox::warning(this, "Ошибка авторизации", "Неверный логин и пароль.");
    }
}


void LoginTeacherWindow::on_cancel_button_2_clicked()
{
    close();
}


void LoginTeacherWindow::on_show_pass_button_pressed()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Normal);
}


void LoginTeacherWindow::on_show_pass_button_released()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Password);
}

