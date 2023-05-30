#include "EditWindow.h"
#include "ui_EditWindow.h"

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    MW = parent;
}

EditWindow::~EditWindow()
{
    delete ui;
}
