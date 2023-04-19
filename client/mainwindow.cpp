
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    StudentWindow* SW;
    TeacherWindow* TW;
    MethodistWindow* MW;
*/
    connect(Client::getInstance(), &Client::auth,
            this, &MainWindow::slot_on_auth);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_log_in_button_2_clicked()
{
    QString login = ui->login_lineedit->text();
    QString password = ui->pass_lineedit->text();

    qDebug()<<"auth&"+login+"&"+password;
    Client::getInstance()->sendToServer("auth&"+login+"&"+password); // temporary

    // The request sends to the server. Need to write a sending to the client


}

void MainWindow::on_show_pass_button_pressed()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Normal);
}


void MainWindow::on_show_pass_button_released()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Password);
}


void MainWindow::slot_on_auth(QString ansFromServ)
{
    QStringList auth_data = ansFromServ.split('&');

    if(auth_data[0] == "err")
    {
        ui->statusbar->showMessage("Неверный логин или пароль!");
        return;
    }

    hide();
    if(auth_data[0] == "1") // student
    {
        SW = new StudentWindow(this);
        SW->show();
    }
    else if(auth_data[0] == "2") // teacher
    {
        TW = new TeacherWindow(this);
        TW->show();
    }
    else if(auth_data[0] == "3") // methodist
    {
        MW = new MethodistWindow(this);
        MW->show();
    }
}
