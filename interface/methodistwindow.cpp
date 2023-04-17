#include "methodistwindow.h"
#include "ui_methodistwindow.h"

MethodistWindow::MethodistWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MethodistWindow)
{
    ui->setupUi(this);
    mainWindow = parent->nativeParentWidget();
}

MethodistWindow::~MethodistWindow()
{
    delete ui;
}

void MethodistWindow::on_back_from_methodist_window_button_clicked()
{
    close();
    mainWindow->show();
}


void MethodistWindow::on_change_schedule_button_clicked()
{

}

