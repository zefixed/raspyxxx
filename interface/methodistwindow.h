#ifndef METHODISTWINDOW_H
#define METHODISTWINDOW_H

#include <QMainWindow>

namespace Ui {
class MethodistWindow;
}

class MethodistWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MethodistWindow(QWidget *parent = nullptr);
    ~MethodistWindow();

private slots:
    void on_back_from_methodist_window_button_clicked();

    void on_change_schedule_button_clicked();

private:
    Ui::MethodistWindow *ui;
    QWidget* mainWindow;
};

#endif // METHODISTWINDOW_H
