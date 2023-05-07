
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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

