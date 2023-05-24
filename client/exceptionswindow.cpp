#include "exceptionswindow.h"
#include "ui_exceptionswindow.h"

ExceptionsWindow::ExceptionsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExceptionsWindow)
{
    ui->setupUi(this);

    if(data == "err")
        data = "1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1|1 1 1 1 1 1 1";
    qDebug()<<"////////////////////////"<<data;
    pair_buttons = {ui->mon_1_lesson_button, ui->mon_2_lesson_button, ui->mon_3_lesson_button, ui->mon_4_lesson_button, ui->mon_5_lesson_button, ui->mon_6_lesson_button, ui->mon_7_lesson_button,
                    ui->tue_1_lesson_button, ui->tue_2_lesson_button, ui->tue_3_lesson_button, ui->tue_4_lesson_button, ui->tue_5_lesson_button, ui->tue_6_lesson_button, ui->tue_7_lesson_button,
                    ui->wed_1_lesson_button, ui->wed_2_lesson_button, ui->wed_3_lesson_button, ui->wed_4_lesson_button, ui->wed_5_lesson_button, ui->wed_6_lesson_button, ui->wed_7_lesson_button,
                    ui->thu_1_lesson_button, ui->thu_2_lesson_button, ui->thu_3_lesson_button, ui->thu_4_lesson_button, ui->thu_5_lesson_button, ui->thu_6_lesson_button, ui->thu_7_lesson_button,
                    ui->fri_1_lesson_button, ui->fri_2_lesson_button, ui->fri_3_lesson_button, ui->fri_4_lesson_button, ui->fri_5_lesson_button, ui->fri_6_lesson_button, ui->fri_7_lesson_button,
                    ui->sat_1_lesson_button, ui->sat_2_lesson_button, ui->sat_3_lesson_button, ui->sat_4_lesson_button, ui->sat_5_lesson_button, ui->sat_6_lesson_button, ui->sat_7_lesson_button};

    qint8 numberCounter = 0;

    for(int i = 0; i < data.size(); i++)
    {
        qDebug()<<data.size();
        QChar c = data[i];
        if(c != ' ' && c != '|')
        {
            if(c == '1')
            {
                pair_buttons.at(numberCounter)->setStyleSheet("background-color: rgb(132, 255, 105);"
                                    "color: rgb(0, 0, 0);"
                                    "font-family: Arial;"
                                    "font-size: 17px;"
                                    "border: 1px solid rgb(0, 0, 0);");
            }

            else
            {
                pair_buttons.at(numberCounter)->setStyleSheet("background-color: rgb(255, 98, 101);"
                                    "color: rgb(0, 0, 0);"
                                    "font-family: Arial;"
                                    "font-size: 17px;"
                                    "border: 1px solid rgb(0, 0, 0);");
            }
            numberCounter++;
        }

    }
}

ExceptionsWindow::~ExceptionsWindow()
{
    delete ui;
}

void ExceptionsWindow::set_data(QString dataFromServ)
{
    this->data = dataFromServ;
    qDebug()<<"qqqqqqqqqqqqqqqqqqqqqqqq"<<data;
}

void ExceptionsWindow::on_ok_button_clicked()
{
    /// Data sending
    Client::getInstance()->sendToServer("exc&add&" + QString::number(Client::getInstance()->get_account_id()) + "&" +  data);
    close();
}

void ExceptionsWindow::on_cancel_button_clicked()
{
    close();
}

void ExceptionsWindow::colorSwitch()
{
    /// Getting a pointer to the button that caused the signal
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    /// Getting the current button CSS
    QString currentStyle = button->styleSheet();

    /// Button color сhanging
    if (currentStyle.contains("background-color: rgb(255, 98, 101)"))
    {
        button->setStyleSheet("background-color: rgb(132, 255, 105);"
                              "color: rgb(0, 0, 0);"
                              "font-family: Arial;"
                              "font-size: 17px;"
                              "border: 1px solid rgb(0, 0, 0);");
    }
    else
    {
        button->setStyleSheet("background-color: rgb(255, 98, 101);"
                              "color: rgb(0, 0, 0);"
                              "font-family: Arial;"
                              "font-size: 17px;"
                              "border: 1px solid rgb(0, 0, 0);");
    }
}

void ExceptionsWindow::dataToGreen(qint8 id)
{
    /// Data change from 0 to 1
    qint8 numberCounter = 0;
    for(int i = 0; i < data.size(); i++)
    {
        QChar c = data[i];
        if(c != ' ' && c != '|')
            numberCounter++;
        if(c != ' ' && c != '|' && id == numberCounter)
            data[i] = '1';
    }
}

void ExceptionsWindow::dataToRed(qint8 id)
{
    /// Data change from 1 to 0
    qint8 numberCounter = 0;
    for(int i = 0; i < data.size(); i++)
    {
        QChar c = data[i];
        if(c != ' ' && c != '|')
            numberCounter++;
        if(c != ' ' && c != '|' && id == numberCounter)
            data[i] = '0';
    }
}

void ExceptionsWindow::dataChange(qint8 id)
{
    if(pair_buttons.at(id)->styleSheet().contains("background-color: rgb(132, 255, 105)"))
        dataToGreen(id);
    else
        dataToRed(id);
}

void ExceptionsWindow::on_mon_1_lesson_button_clicked()
{
    qint8 day_id = 0;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_mon_2_lesson_button_clicked()
{
    qint8 day_id = 1;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_mon_3_lesson_button_clicked()
{
    qint8 day_id = 2;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_mon_4_lesson_button_clicked()
{
    qint8 day_id = 3;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_mon_5_lesson_button_clicked()
{
    qint8 day_id = 4;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_mon_6_lesson_button_clicked()
{
    qint8 day_id = 5;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_mon_7_lesson_button_clicked()
{
    qint8 day_id = 6;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_tue_1_lesson_button_clicked()
{
    qint8 day_id = 7;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_tue_2_lesson_button_clicked()
{
    qint8 day_id = 8;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_tue_3_lesson_button_clicked()
{
    qint8 day_id = 9;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_tue_4_lesson_button_clicked()
{
    qint8 day_id = 10;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_tue_5_lesson_button_clicked()
{
    qint8 day_id = 11;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_tue_6_lesson_button_clicked()
{
    qint8 day_id = 12;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_tue_7_lesson_button_clicked()
{
    qint8 day_id = 13;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_wed_1_lesson_button_clicked()
{
    qint8 day_id = 14;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_wed_2_lesson_button_clicked()
{
    qint8 day_id = 15;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_wed_3_lesson_button_clicked()
{
    qint8 day_id = 16;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_wed_4_lesson_button_clicked()
{
    qint8 day_id = 17;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_wed_5_lesson_button_clicked()
{
    qint8 day_id = 18;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_wed_6_lesson_button_clicked()
{
    qint8 day_id = 19;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_wed_7_lesson_button_clicked()
{
    qint8 day_id = 20;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_thu_1_lesson_button_clicked()
{
    qint8 day_id = 21;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_thu_2_lesson_button_clicked()
{
    qint8 day_id = 22;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_thu_3_lesson_button_clicked()
{
    qint8 day_id = 23;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_thu_4_lesson_button_clicked()
{
    qint8 day_id = 24;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_thu_5_lesson_button_clicked()
{
    qint8 day_id = 25;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_thu_6_lesson_button_clicked()
{
    qint8 day_id = 26;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_thu_7_lesson_button_clicked()
{
    qint8 day_id = 27;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_fri_1_lesson_button_clicked()
{
    qint8 day_id = 28;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_fri_2_lesson_button_clicked()
{
    qint8 day_id = 29;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_fri_3_lesson_button_clicked()
{
    qint8 day_id = 30;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_fri_4_lesson_button_clicked()
{
    qint8 day_id = 31;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_fri_5_lesson_button_clicked()
{
    qint8 day_id = 32;
    colorSwitch();
    dataChange(day_id);
}
void ExceptionsWindow::on_fri_6_lesson_button_clicked()
{
    qint8 day_id = 33;
    colorSwitch();
    dataChange(day_id);
}
void ExceptionsWindow::on_fri_7_lesson_button_clicked()
{
    qint8 day_id = 34;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_sat_1_lesson_button_clicked()
{
    qint8 day_id = 35;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_sat_2_lesson_button_clicked()
{
    qint8 day_id = 36;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_sat_3_lesson_button_clicked()
{
    qint8 day_id = 37;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_sat_4_lesson_button_clicked()
{
    qint8 day_id = 38;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_sat_5_lesson_button_clicked()
{
    qint8 day_id = 39;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_sat_6_lesson_button_clicked()
{
    qint8 day_id = 40;
    colorSwitch();
    dataChange(day_id);
}


void ExceptionsWindow::on_sat_7_lesson_button_clicked()
{
    qint8 day_id = 41;
    colorSwitch();
    dataChange(day_id);
}
