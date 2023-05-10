
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    connect(Client::getInstance(), &Client::view,
            this, &MainWindow::slot_on_view);

    ui->setupUi(this);

    ui->exceptions_button->hide();
    ui->change_schedule_button->hide();
    ui->input_group_label->hide();
    ui->input_group_lineedit->hide();

    LW = new LoginWindow(this);
    LW->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exceptions_button_clicked()
{
    Client::getInstance()->sendToServer("view&group_id&191-711"); // temporary
}


void MainWindow::on_change_schedule_button_clicked()
{

}

void MainWindow::slot_on_view(QString data)
{

}

