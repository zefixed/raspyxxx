#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCompleter>
#include <QTextEdit>

#include "Client.h"
#include "loginwindow.h"
#include "exceptionswindow.h"
#include "EditWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    /// An explicit сonstructor takes a pointer to a parent QWidget
    MainWindow(QWidget *parent = nullptr);

    /// Default destructor
    ~MainWindow();

private slots:
    // Slot on_exceptions_button_clicked
    void on_exceptions_button_clicked();

    // Slot on_change_schedule_button_clicked
    void on_change_schedule_button_clicked();

    // Slot err_slot
    void err_slot(QString);

    // Slot on_input_group_lineedit_returnPressed
    void on_input_group_lineedit_returnPressed();

    // Slot on_input_teacher_lineedit_returnPressed
    void on_input_teacher_lineedit_returnPressed();

    // Slot slot_on_idk
    void slot_on_idk(QList<QString> ansFromServ);

    // Slot exc_slot
    void exc_slot(QString dataFromServ);

    // Slot set
    void set(QStringList);

    // Slot on_edit_teachers_button_clicked
    void on_edit_teachers_button_clicked();

    // Slot on_edit_groups_button_clicked
    void on_edit_groups_button_clicked();

    // Slot on_edit_disciplines_button_clicked
    void on_edit_disciplines_button_clicked();

private:
    Ui::MainWindow* ui;
    LoginWindow* LW;
    ExceptionsWindow* EW;
    EditWindow* EdW;
    QStringList teachers;
    QStringList groups;
    QStringList disciplines;
    QCompleter* teacher_completer = new QCompleter;
    QCompleter* group_completer = new QCompleter;
    QCompleter* discipline_completer = new QCompleter;

    /// Function for creating the schedule text of a single pair, taking a QStringList with pair data separated by "|" and returning the finished pair text to put it in a block with the schedule
    QString txt_for_pair(QStringList);

    /// Function to set the style of QTextEdit, in which the schedule is written, as if it were QLabel
    void set_textedit_style();

    /// Function for assigning values received from the server to the teacher_completer property
    void set_teacher_completer();

    /// Function for assigning values received from the server to the group_completer property
    void set_group_completer();

    ///Function for assigning values received from the server to the discipline_completer property
    void set_discipline_completer();
};

#endif // MAINWINDOW_H
