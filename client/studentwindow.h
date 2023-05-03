#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = nullptr);
    ~StudentWindow();
    void closeEvent(QCloseEvent *event);

signals:
    void closeMainWindow();

private slots:
    void on_back_from_student_window_button_clicked();

private:
    Ui::StudentWindow *ui;
};

#endif // STUDENTWINDOW_H
