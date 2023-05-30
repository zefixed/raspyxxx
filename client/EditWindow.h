#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>

#include "Client.h"

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr, const QStringList = QStringList());


    ~EditWindow();

private slots:

    void on_add_button_clicked();

    void on_update_button_clicked();

    void on_delete_button_clicked();

private:
    Ui::EditWindow* ui;

    QWidget* MW;
};

#endif // EDITWINDOW_H
