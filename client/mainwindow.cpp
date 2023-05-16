#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    connect(Client::getInstance(), &Client::view,
            this, &MainWindow::on_input_group_lineedit_returnPressed);
    connect(Client::getInstance(), &Client::err,
            this, &MainWindow::err_slot);

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

}


void MainWindow::on_change_schedule_button_clicked()
{

}

void MainWindow::err_slot(QString err)
{
    qDebug() << err;
}


void MainWindow::on_input_group_lineedit_returnPressed()
{
    QString group = ui->input_group_lineedit->text();
    if (!group.isEmpty())
    {
        Client::getInstance()->sendToServer("view&group_id&" + group);
        ui->input_group_lineedit->clear();
    }
}

