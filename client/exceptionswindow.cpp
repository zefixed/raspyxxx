#include "exceptionswindow.h"
#include "ui_exceptionswindow.h"

ExceptionsWindow::ExceptionsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExceptionsWindow)
{
    ui->setupUi(this);
}

ExceptionsWindow::~ExceptionsWindow()
{
    delete ui;
}

void ExceptionsWindow::on_ok_button_clicked()
{

}


void ExceptionsWindow::on_cancel_button_clicked()
{
    close();
}

void ExceptionsWindow::colorSwitch()
{
    /// Getting a pointer to the button that caused the signal
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    /// Getting the current button CSS
    QString currentStyle = button->styleSheet();

    /// Button color сhanging
    if (currentStyle.contains("background-color: rgb(255, 98, 101)"))
    {
        button->setStyleSheet("background-color: rgb(132, 255, 105);color: rgb(0, 0, 0);font-family: Arial;font-size: 17px;border: 1px solid rgb(0, 0, 0);");
    }
    else
    {
        button->setStyleSheet("background-color: rgb(255, 98, 101);color: rgb(0, 0, 0);font-family: Arial;font-size: 17px;border: 1px solid rgb(0, 0, 0);");
    }
}

void ExceptionsWindow::dataChange()
{

}

void ExceptionsWindow::on_mon_1_lesson_button_clicked()
{
    colorSwitch();
    dataChange();
}
