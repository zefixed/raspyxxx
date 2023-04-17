#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QMainWindow>

namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherWindow(QWidget *parent = nullptr);
    ~TeacherWindow();

private slots:
    void on_back_from_teacher_window_button_clicked();

private:
    Ui::TeacherWindow *ui;
    QWidget* mainWindow;
};

#endif // TEACHERWINDOW_H
