#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    connect(Client::getInstance(), &Client::view,
            this, &MainWindow::on_input_group_lineedit_returnPressed);
    connect(Client::getInstance(), &Client::err,
            this, &MainWindow::err_slot);

    ui->setupUi(this);

    ui->exceptions_button->hide();
    ui->change_schedule_button->hide();
    ui->input_group_label->hide();
    ui->input_group_lineedit->hide();

    LW = new LoginWindow(this);
    LW->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exceptions_button_clicked()
{
    EW = new ExceptionsWindow(this);
    EW->show();
}


void MainWindow::on_change_schedule_button_clicked()
{

}

void MainWindow::err_slot(QString err)
{
    qDebug() << err;
}


void MainWindow::on_input_group_lineedit_returnPressed()
{
    QString group = ui->input_group_lineedit->text();
    if (!group.isEmpty())
    {
        Client::getInstance()->sendToServer("view&group_id&" + group);
        ui->input_group_lineedit->clear();
    }
}

void MainWindow::slot_on_idk(QList<QString> ansFromServ)
{
    /// Converting the server response into a normalized list of lists
    QList<QStringList> transformed_list;

    foreach(const QString& element, ansFromServ)
    {
        QStringList splittedElements = element.split('|');
        transformed_list.append(splittedElements);
    }

    // group|teacher|address|audience|time|weekday|discipline|discipline_type,

    // QList<QString> weekday_buttons = {"monday_schedule_label", "tuesday_schedule_label", "wednesday_schedule_label", "thursday_schedule_label", "friday_schedule_label", "saturday_schedule_label"};

    for (int i = 0; i < transformed_list.length(); i++)
    {
        QList lesson = transformed_list.at(i);

        /// Set monday schedule
        if(lesson.at(5) == "monday")
        {
            QString boofer = ui->monday_schedule_label->text();
            ui->monday_schedule_label->setText(
                boofer       +"\n\n" +
                lesson.at(4) + '\n'  +   // time
                lesson.at(3) + '\n'  +   // audience
                lesson.at(6) + " ("  +   // discipline
                lesson.at(7) + ")\n" +   // discipline_type
                lesson.at(1) + '\n');    // teacher
        }
        /// Set tuesday schedule
        else if(lesson.at(5) == "tuesday")
        {
            QString boofer = ui->tuesday_schedule_label->text();
            ui->tuesday_schedule_label->setText(
                boofer       +"\n\n" +
                lesson.at(4) + '\n'  +   // time
                lesson.at(3) + '\n'  +   // audience
                lesson.at(6) + " ("  +   // discipline
                lesson.at(7) + ")\n" +   // discipline_type
                lesson.at(1) + '\n');    // teacher
        }
        /// Set wednesday schedule
        else if(lesson.at(5) == "wednesday")
        {
            QString boofer = ui->wednesday_schedule_label->text();
            ui->wednesday_schedule_label->setText(
                boofer       +"\n\n" +
                lesson.at(4) + '\n'  +   // time
                lesson.at(3) + '\n'  +   // audience
                lesson.at(6) + " ("  +   // discipline
                lesson.at(7) + ")\n" +   // discipline_type
                lesson.at(1) + '\n');    // teacher
        }
        /// Set thursday schedule
        else if(lesson.at(5) == "thursday")
        {
            QString boofer = ui->thursday_schedule_label->text();
            ui->thursday_schedule_label->setText(
                boofer       +"\n\n" +
                lesson.at(4) + '\n'  +   // time
                lesson.at(3) + '\n'  +   // audience
                lesson.at(6) + " ("  +   // discipline
                lesson.at(7) + ")\n" +   // discipline_type
                lesson.at(1) + '\n');    // teacher
        }
        /// Set friday schedule
        else if(lesson.at(5) == "friday")
        {
            QString boofer = ui->friday_schedule_label->text();
            ui->friday_schedule_label->setText(
                boofer       +"\n\n" +
                lesson.at(4) + '\n'  +   // time
                lesson.at(3) + '\n'  +   // audience
                lesson.at(6) + " ("  +   // discipline
                lesson.at(7) + ")\n" +   // discipline_type
                lesson.at(1) + '\n');    // teacher
        }
        /// Set saturday schedule
        else if(lesson.at(5) == "saturday")
        {
            QString boofer = ui->saturday_schedule_label->text();
            ui->saturday_schedule_label->setText(
                boofer       +"\n\n" +
                lesson.at(4) + '\n'  +   // time
                lesson.at(3) + '\n'  +   // audience
                lesson.at(6) + " ("  +   // discipline
                lesson.at(7) + ")\n" +   // discipline_type
                lesson.at(1) + '\n');    // teacher
        }
    }
}
