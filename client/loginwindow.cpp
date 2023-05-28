#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget* parent) : QDialog(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    connect(Client::getInstance(), &Client::auth,
            this, &LoginWindow::slot_on_auth);

    MW = parent;
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_log_in_button_clicked()
{
    QString login = ui->login_lineedit->text();
    QString password = ui->pass_lineedit->text();


    Client::getInstance()->sendToServer("auth&"+login+"&"+password); // temporary
    // The request sends to the server. Need to write a sending to the client
}

void LoginWindow::on_show_pass_button_pressed()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Normal);
}


void LoginWindow::on_show_pass_button_released()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Password);
}


void LoginWindow::slot_on_auth(QStringList ansFromServ)
{
    QStringList auth_data = ansFromServ;

    if(auth_data[1] == "err")
    {
        ui->groupBox->setTitle("Неверный логин или пароль!");
        return;
    }
    qDebug() << auth_data;
    Client::getInstance()->set_account_id(auth_data[2]);

    close();
    if(auth_data[1] == "1") // student
    {
        MW->show();
        MW->findChild<QWidget*>("input_group_label")->show();
        MW->findChild<QWidget*>("input_group_lineedit")->show();
    }
    else if(auth_data[1] == "2") // teacher
    {
        MW->show();
        MW->findChild<QWidget*>("exceptions_button")->show();
    }
    else if(auth_data[1] == "3") // methodist
    {
        MW->show();
        MW->findChild<QWidget*>("change_schedule_button")->show();
    }
}
