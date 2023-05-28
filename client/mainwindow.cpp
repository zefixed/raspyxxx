#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    connect(Client::getInstance(), &Client::view_group,
            this, &MainWindow::slot_on_idk);
    connect(Client::getInstance(), &Client::view_teacher,
            this, &MainWindow::slot_on_idk);
    connect(Client::getInstance(), &Client::err,
            this, &MainWindow::err_slot);
    connect(Client::getInstance(), &Client::exc_view,
            this, &MainWindow::exc_slot);
    connect(Client::getInstance(), &Client::auth,
            this, &MainWindow::set_group_completer);
    connect(Client::getInstance(), &Client::auth,
            this, &MainWindow::set_teacher_completer);
    ui->setupUi(this);

    ui->exceptions_button->hide();
    ui->change_schedule_button->hide();
    //ui->input_group_label->hide();
    //ui->input_group_lineedit->hide();


    LW = new LoginWindow(this);
    LW->show();
}

MainWindow::~MainWindow()
{
    delete group_completer;
    delete teacher_completer;
    delete ui;
}

void MainWindow::on_exceptions_button_clicked()
{
    Client::getInstance()->sendToServer("exc&view&" + QString::number(Client::getInstance()->get_account_id()));
    qDebug() << "MainWindow::on_exceptions_button_clicked\t" << "exc&view&" + QString::number(Client::getInstance()->get_account_id());
}


void MainWindow::on_change_schedule_button_clicked()
{

}

void MainWindow::err_slot(QString err)
{
    qDebug() << err;
}

void MainWindow::exc_slot(QString dataFromServ)
{
    EW = new ExceptionsWindow(this, dataFromServ);
    EW->set_data(dataFromServ);
    EW->show();
}

QString MainWindow::txt_for_pair(QStringList lesson)
{
    QString add_text = lesson.at(4) + '\n'  +   // time
                       lesson.at(3) + '\n'  +   // audience
                       lesson.at(6) + " ("  +   // discipline
                       lesson.at(7) + ")\n" +   // discipline_type
                       lesson.at(1) + '\n';     // teacher
    return add_text;
}

void MainWindow::set_group_completer(QStringList data)
{
    QStringList groups = data[3].split("|");
    QStringListModel* model = new QStringListModel(groups, group_completer);
    group_completer->setCaseSensitivity(Qt::CaseInsensitive);
    group_completer->setFilterMode(Qt::MatchContains);
    group_completer->setModel(model);
    ui->input_group_lineedit->setCompleter(group_completer);
}

void MainWindow::set_teacher_completer(QStringList data)
{
    QStringList teachers = data[4].split("|");
    QStringListModel* model = new QStringListModel(teachers, teacher_completer);
    teacher_completer->setCaseSensitivity(Qt::CaseInsensitive);
    teacher_completer->setFilterMode(Qt::MatchContains);
    teacher_completer->setModel(model);
    ui->input_teacher_lineedit->setCompleter(teacher_completer);
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

void MainWindow::on_input_teacher_lineedit_returnPressed()
{
    QString teacher = ui->input_teacher_lineedit->text();
    if (!teacher.isEmpty())
    {
        Client::getInstance()->sendToServer("view&teacher_id&" + teacher);
        ui->input_teacher_lineedit->clear();
    }
}

void MainWindow::slot_on_idk(QList<QString> ansFromServ)
{
    ui->group_doesnt_exist_label->setText("");
    ui->monday_schedule_label->setText("");
    ui->tuesday_schedule_label->setText("");
    ui->wednesday_schedule_label->setText("");
    ui->thursday_schedule_label->setText("");
    ui->friday_schedule_label->setText("");
    ui->saturday_schedule_label->setText("");

    if(ansFromServ[2] == "")
    {
        ui->group_doesnt_exist_label->setStyleSheet("QLabel { color : red }");
        if(ansFromServ[1] == "group")
            ui->group_doesnt_exist_label->setText("Введёная группа не имеет расписания");
        else if(ansFromServ[1] == "teacher")
            ui->group_doesnt_exist_label->setText("Введёный преподаватель не имеет расписания");
        return void();
    }

    // Converting the server response into a normalized list of lists
    QList<QStringList> transformed_list;
    //qDebug()<<""<<ansFromServ;

    foreach(const QString& element, ansFromServ)
    {
        QStringList splittedElements = element.split('|');
        transformed_list.append(splittedElements);
    }
    transformed_list.removeFirst();
    transformed_list.removeFirst();
    transformed_list.removeLast();

    // group|teacher|address|audience|time|weekday|discipline|discipline_type,

    // QList<QString> weekday_buttons = {"monday_schedule_label", "tuesday_schedule_label", "wednesday_schedule_label", "thursday_schedule_label", "friday_schedule_label", "saturday_schedule_label"};

    for (int i = 0; i < transformed_list.length(); i++)
    {
        QList lesson = transformed_list.at(i);

        // Set monday schedule
        if(lesson.at(5) == "Понедельник")
        {
            QString boofer = ui->monday_schedule_label->text();
            ui->monday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set tuesday schedule
        else if(lesson.at(5) == "Вторник")
        {
            QString boofer = ui->tuesday_schedule_label->text();
            ui->tuesday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set wednesday schedule
        else if(lesson.at(5) == "Среда")
        {
            QString boofer = ui->wednesday_schedule_label->text();
            ui->wednesday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set thursday schedule
        else if(lesson.at(5) == "Четверг")
        {
            QString boofer = ui->thursday_schedule_label->text();
            ui->thursday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set friday schedule
        else if(lesson.at(5) == "Пятница")
        {
            QString boofer = ui->friday_schedule_label->text();
            ui->friday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set saturday schedule
        else if(lesson.at(5) == "Суббота")
        {
            QString boofer = ui->saturday_schedule_label->text();
            ui->saturday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
    }
}

