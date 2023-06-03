#ifndef EXCEPTIONSWINDOW_H
#define EXCEPTIONSWINDOW_H

#include <QDialog>
#include "Client.h"

namespace Ui {
class ExceptionsWindow;
}

class ExceptionsWindow : public QDialog
{
    Q_OBJECT

public:
    /// An explicit сonstructor takes a pointer to a parent QWidget and a QString that stores the data from the server
    explicit ExceptionsWindow(QWidget *parent = nullptr, QString data = "");

    /// Default destructor
    ~ExceptionsWindow();

    /// Function for assigning a value to the data property
    void set_data(QString dataFromServ);

private slots:
    void on_ok_button_clicked();

    void on_cancel_button_clicked();

    void on_mon_1_lesson_button_clicked();
    void on_mon_2_lesson_button_clicked();
    void on_mon_3_lesson_button_clicked();
    void on_mon_4_lesson_button_clicked();
    void on_mon_5_lesson_button_clicked();
    void on_mon_6_lesson_button_clicked();
    void on_mon_7_lesson_button_clicked();

    void on_tue_1_lesson_button_clicked();
    void on_tue_2_lesson_button_clicked();
    void on_tue_3_lesson_button_clicked();
    void on_tue_4_lesson_button_clicked();
    void on_tue_5_lesson_button_clicked();
    void on_tue_6_lesson_button_clicked();
    void on_tue_7_lesson_button_clicked();

    void on_wed_1_lesson_button_clicked();
    void on_wed_2_lesson_button_clicked();
    void on_wed_3_lesson_button_clicked();
    void on_wed_4_lesson_button_clicked();
    void on_wed_5_lesson_button_clicked();
    void on_wed_6_lesson_button_clicked();
    void on_wed_7_lesson_button_clicked();

    void on_thu_1_lesson_button_clicked();
    void on_thu_2_lesson_button_clicked();
    void on_thu_3_lesson_button_clicked();
    void on_thu_4_lesson_button_clicked();
    void on_thu_5_lesson_button_clicked();
    void on_thu_6_lesson_button_clicked();
    void on_thu_7_lesson_button_clicked();

    void on_fri_1_lesson_button_clicked();
    void on_fri_2_lesson_button_clicked();
    void on_fri_3_lesson_button_clicked();
    void on_fri_4_lesson_button_clicked();
    void on_fri_5_lesson_button_clicked();
    void on_fri_6_lesson_button_clicked();
    void on_fri_7_lesson_button_clicked();

    void on_sat_1_lesson_button_clicked();
    void on_sat_2_lesson_button_clicked();
    void on_sat_3_lesson_button_clicked();
    void on_sat_4_lesson_button_clicked();
    void on_sat_5_lesson_button_clicked();
    void on_sat_6_lesson_button_clicked();
    void on_sat_7_lesson_button_clicked();

private:
    Ui::ExceptionsWindow *ui;

    /// The color change function of the time slot button when you press it
    void colorSwitch();

    /// Function redirecting to dataToGreen or dataToRed depending on the current state of the time slot button taking the id of the time slot button
    void dataChange(qint8 id);

    /// Function to change the data property when the state of the button changes from red to green, taking the id of the time slot button
    void dataToGreen(qint8 id);

    /// Function to change the data property when the state of the button changes from green to red, taking the id of the time slot button
    void dataToRed(qint8 id);

    QString data;
    QList<QPushButton*> pair_buttons;
};

#endif // EXCEPTIONSWINDOW_H
