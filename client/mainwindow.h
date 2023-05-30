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
    /// Default constructor
    MainWindow(QWidget *parent = nullptr);

    /// Destructor
    ~MainWindow();

private slots:
    /// Slot triggered by pressing an exception button
    void on_exceptions_button_clicked();

    /// Slot triggered by pressing a change schedule button
    void on_change_schedule_button_clicked();

    /// Slot triggered by pressing a change schedule button
    void err_slot(QString);

    /// Slot triggered by pressing return in lineedit
    void on_input_group_lineedit_returnPressed();

    void on_input_teacher_lineedit_returnPressed();

    void slot_on_idk(QList<QString> ansFromServ);

    void exc_slot(QString dataFromServ);

    void set(QStringList);

    void on_edit_teachers_button_clicked();

    void on_edit_groups_button_clicked();

    void on_edit_disciplines_button_clicked();

private:
    Ui::MainWindow* ui;
    LoginWindow* LW;
    ExceptionsWindow* EW;
    EditWindow* EdW;
    QStringList teachers;
    QStringList groups;
    QStringList disciplines;
    QCompleter* group_completer = new QCompleter;
    QCompleter* teacher_completer = new QCompleter;
    QCompleter* discipline_completer = new QCompleter;

    QString txt_for_pair(QStringList);

    void set_textedit_style();

    void set_teacher_completer();

    void set_group_completer();

    void set_discipline_completer();
};

#endif // MAINWINDOW_H
