#ifndef EXCEPTIONSWINDOW_H
#define EXCEPTIONSWINDOW_H

#include <QDialog>

namespace Ui {
class ExceptionsWindow;
}

class ExceptionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ExceptionsWindow(QWidget *parent = nullptr);
    ~ExceptionsWindow();

private slots:
    void on_ok_button_clicked();

    void on_cancel_button_clicked();

    void on_mon_1_lesson_button_clicked();

private:
    Ui::ExceptionsWindow *ui;

    void colorSwitch();
    void dataChange();

    QString data;
};

#endif // EXCEPTIONSWINDOW_H
