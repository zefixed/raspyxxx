
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


void MainWindow::on_login_as_student_clicked()
{
    hide();
    SW = new StudentWindow(this);
    SW->show();
}


void MainWindow::on_login_as_teacher_clicked()
{
    LTW = new LoginTeacherWindow(this);
    LTW->setModal(true);
    LTW->exec();
}



void MainWindow::on_login_as_methodist_clicked()
{
    LMW = new LoginMethodistWindow(this);
    LMW->setModal(true);
    LMW->exec();
}

