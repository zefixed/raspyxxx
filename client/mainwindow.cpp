
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_log_in_button_2_clicked()
{
    QString login = ui->login_lineedit->text();
    QString password = ui->pass_lineedit->text();

    Client::getInstance()->sendToServer("auth&" + login + "&" + password);

    // The request sends to the server. Need to write a sending to the client

    if(login == "student" && password == "student")
    {
        hide();
        SW = new StudentWindow(this);
        SW->show();
    }
    else if(login == "teacher" && password == "teacher")
    {
        hide();
        TW = new TeacherWindow(this);
        TW->show();
    }
    else if(login == "methodist" && password == "methodist")
    {
        hide();
        MW = new MethodistWindow(this);
        MW->show();
    }
    else
    {
        ui->statusbar->showMessage("Неверный логин или пароль!");
    }
}

void MainWindow::on_show_pass_button_pressed()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Normal);
}


void MainWindow::on_show_pass_button_released()
{
    ui->pass_lineedit->setEchoMode(QLineEdit::Password);
}

