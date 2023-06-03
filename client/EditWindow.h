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
    /// An explicit сonstructor takes a pointer to a parent QWidget and a QStringList that stores the values to be substituted in the QComboBox
    explicit EditWindow(QWidget* parent = nullptr, const QStringList = QStringList());

    /// Default destructor
    ~EditWindow();

private slots:
    // Slot on_add_button_clicked
    void on_add_button_clicked();

    // Slot on_update_button_clicked
    void on_update_button_clicked();

    // Slot on_delete_button_clicked
    void on_delete_button_clicked();

private:
    Ui::EditWindow* ui;
    QWidget* MW;
};

#endif // EDITWINDOW_H
