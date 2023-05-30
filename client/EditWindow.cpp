#include "EditWindow.h"
#include "ui_EditWindow.h"

EditWindow::EditWindow(QWidget *parent, QStringList data) : QDialog(parent), ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    ui->teacher_comboBox->hide();
    ui->teacher_label->hide();
    ui->teacher_line_label->hide();
    ui->teacher_lineEdit->hide();
    ui->group_comboBox->hide();
    ui->group_label->hide();
    ui->group_line_label->hide();
    ui->group_lineEdit->hide();
    ui->discipline_comboBox->hide();
    ui->discipline_label->hide();
    ui->discipline_line_label->hide();
    ui->discipline_lineEdit->hide();

    QString type = data[0];
    data.removeFirst();

    if(type == "teachers")
    {
        ui->teacher_comboBox->show();
        ui->teacher_label->show();
        ui->teacher_line_label->show();
        ui->teacher_lineEdit->show();
        for (QString teacher : data) {
            ui->teacher_comboBox->addItem(teacher);
        }
    }
    else if(type == "groups")
    {
        ui->group_comboBox->show();
        ui->group_label->show();
        ui->group_line_label->show();
        ui->group_lineEdit->show();
        for (QString group : data) {
            ui->group_comboBox->addItem(group);
        }
    }
    else if(type == "disciplines")
    {
        ui->discipline_comboBox->show();
        ui->discipline_label->show();
        ui->discipline_line_label->show();
        ui->discipline_lineEdit->show();
        for (QString discipline : data) {
            ui->discipline_comboBox->addItem(discipline);
        }
    }
    MW = parent;
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_add_button_clicked()
{
    if(ui->teacher_lineEdit->isVisible())
    {
        Client::getInstance()->sendToServer("add&teachers&" + ui->teacher_lineEdit->text());
        close();
    }
    else if(ui->group_lineEdit->isVisible())
    {
        Client::getInstance()->sendToServer("add&groups&" + ui->group_lineEdit->text());
        close();
    }
    else if(ui->discipline_lineEdit->isVisible())
    {
        Client::getInstance()->sendToServer("add&disciplines&" + ui->discipline_lineEdit->text());
        close();
    }
}

void EditWindow::on_update_button_clicked()
{
    if(ui->teacher_lineEdit->isVisible())
    {
        Client::getInstance()->sendToServer("update&teachers&" + ui->teacher_comboBox->currentText() + "&" + ui->teacher_lineEdit->text());
        close();
    }
    else if(ui->group_lineEdit->isVisible())
    {
        Client::getInstance()->sendToServer("update&groups&" + ui->group_comboBox->currentText() + "&" + ui->group_lineEdit->text());
        close();
    }
    else if(ui->discipline_lineEdit->isVisible())
    {
        Client::getInstance()->sendToServer("update&disciplines&" + ui->discipline_comboBox->currentText() + "&" + ui->discipline_lineEdit->text());
        close();
    }
}


void EditWindow::on_delete_button_clicked()
{
    if(ui->teacher_lineEdit->isVisible())
    {
        Client::getInstance()->sendToServer("delete&teachers&" + ui->teacher_comboBox->currentText());
        close();
    }
    else if(ui->group_lineEdit->isVisible())
    {
        Client::getInstance()->sendToServer("delete&groups&" + ui->group_comboBox->currentText());
        close();
    }
    else if(ui->discipline_lineEdit->isVisible())
    {
        Client::getInstance()->sendToServer("delete&disciplines&" + ui->discipline_comboBox->currentText());
        close();
    }
}

