#include "teacherwindow.h"
#include "ui_teacherwindow.h"

TeacherWindow::TeacherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    mainWindow = parent->nativeParentWidget();
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::on_back_from_teacher_window_button_clicked()
{
    close();
    mainWindow->show();
}

