#include "studentwindow.h"
#include "ui_studentwindow.h"

StudentWindow::StudentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
    mainWindow = parent;
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::on_back_from_student_window_button_clicked()
{
    close();
    mainWindow->show();
}

