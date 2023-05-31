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
    //connect(Client::getInstance(), &Client::auth,
    //        this, &MainWindow::set_teacher_completer);
    connect(Client::getInstance(), &Client::get,
            this, &MainWindow::set);

    ui->setupUi(this);

    ui->exceptions_button->hide();
    ui->change_schedule_button->hide();
    ui->edit_teachers_button->hide();
    ui->edit_groups_button->hide();
    ui->edit_disciplines_button->hide();

    //ui->input_group_label->hide();
    //ui->input_group_lineedit->hide();

    Client::getInstance()->sendToServer("get");

    set_textedit_style();

    LW = new LoginWindow(this);
    LW->show();
}

MainWindow::~MainWindow()
{
    delete group_completer;
    delete teacher_completer;
    delete discipline_completer;
    delete ui;
}

void MainWindow::on_exceptions_button_clicked()
{
    Client::getInstance()->sendToServer("exc&view&" + QString::number(Client::getInstance()->get_account_id()));
    qDebug() << "MainWindow::on_exceptions_button_clicked\t" << "exc&view&" + QString::number(Client::getInstance()->get_account_id());
}


void MainWindow::on_change_schedule_button_clicked()
{
    if(ui->monday_schedule_label->isReadOnly())
    {
        ui->monday_schedule_label->setReadOnly(false);
        ui->tuesday_schedule_label->setReadOnly(false);
        ui->wednesday_schedule_label->setReadOnly(false);
        ui->thursday_schedule_label->setReadOnly(false);
        ui->friday_schedule_label->setReadOnly(false);
        ui->saturday_schedule_label->setReadOnly(false);
    }
    else
    {
        ui->monday_schedule_label->setReadOnly(true);
        ui->tuesday_schedule_label->setReadOnly(true);
        ui->wednesday_schedule_label->setReadOnly(true);
        ui->thursday_schedule_label->setReadOnly(true);
        ui->friday_schedule_label->setReadOnly(true);
        ui->saturday_schedule_label->setReadOnly(true);
    }
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

void MainWindow::set_textedit_style()
{
    QList<QTextEdit*> text_edits;
    text_edits << ui->monday_schedule_label
               << ui->tuesday_schedule_label
               << ui->wednesday_schedule_label
               << ui->thursday_schedule_label
               << ui->friday_schedule_label
               << ui->saturday_schedule_label;

    for(auto text_edit : text_edits)
    {
        text_edit->setFrameStyle(QFrame::NoFrame);
        text_edit->setStyleSheet("background-color: transparent");
        text_edit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_edit->setReadOnly(true);
        text_edit->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        text_edit->setTextColor(Qt::black);
        text_edit->setFont(QFont("Arial", 10));
    }
}

void MainWindow::set_group_completer()
{
    QStringListModel* model = new QStringListModel(this->groups, group_completer);
    group_completer->setCaseSensitivity(Qt::CaseInsensitive);
    group_completer->setFilterMode(Qt::MatchContains);
    group_completer->setModel(model);
    ui->input_group_lineedit->setCompleter(group_completer);
}

void MainWindow::set_discipline_completer()
{
    QStringListModel* model = new QStringListModel(this->disciplines, discipline_completer);
    discipline_completer->setCaseSensitivity(Qt::CaseInsensitive);
    discipline_completer->setFilterMode(Qt::MatchContains);
    discipline_completer->setModel(model);
    //ui->input_group_lineedit->setCompleter(discipline_completer);
}

void MainWindow::set_teacher_completer()
{
    QStringListModel* model = new QStringListModel(this->teachers, teacher_completer);
    teacher_completer->setCaseSensitivity(Qt::CaseInsensitive);
    teacher_completer->setFilterMode(Qt::MatchContains);
    teacher_completer->setModel(model);
    ui->input_teacher_lineedit->setCompleter(teacher_completer);
}

void MainWindow::set(QStringList set_data)
{
    this->teachers = set_data[0].split('|');
    this->groups = set_data[1].split('|');
    this->disciplines = set_data[2].split('|');
    set_teacher_completer();
    set_group_completer();
    set_discipline_completer();
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
            QString boofer = ui->monday_schedule_label->toPlainText();
            ui->monday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set tuesday schedule
        else if(lesson.at(5) == "Вторник")
        {
            QString boofer = ui->tuesday_schedule_label->toPlainText();
            ui->tuesday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set wednesday schedule
        else if(lesson.at(5) == "Среда")
        {
            QString boofer = ui->wednesday_schedule_label->toPlainText();
            ui->wednesday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set thursday schedule
        else if(lesson.at(5) == "Четверг")
        {
            QString boofer = ui->thursday_schedule_label->toPlainText();
            ui->thursday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set friday schedule
        else if(lesson.at(5) == "Пятница")
        {
            QString boofer = ui->friday_schedule_label->toPlainText();
            ui->friday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
        // Set saturday schedule
        else if(lesson.at(5) == "Суббота")
        {
            QString boofer = ui->saturday_schedule_label->toPlainText();
            ui->saturday_schedule_label->setText(boofer + "\n\n" + txt_for_pair(lesson));
        }
    }
}

void MainWindow::on_edit_teachers_button_clicked()
{
    Client::getInstance()->sendToServer("get"); // Need to fix this by using "wait for answer"
    QStringList teachers_for_edw = this->teachers;
    teachers_for_edw.prepend("teachers");
    EdW = new EditWindow(this, teachers_for_edw);
    EdW->resize(400, 120);
    EdW->show();
}

void MainWindow::on_edit_groups_button_clicked()
{
    Client::getInstance()->sendToServer("get");
    QStringList groups_for_edw = this->groups;
    groups_for_edw.prepend("groups");
    EdW = new EditWindow(this, groups_for_edw);
    EdW->resize(400, 120);
    EdW->show();
}

void MainWindow::on_edit_disciplines_button_clicked()
{
    Client::getInstance()->sendToServer("get");
    QStringList disciplines_for_edw = this->disciplines;
    disciplines_for_edw.prepend("disciplines");
    EdW = new EditWindow(this, disciplines_for_edw);
    EdW->resize(400, 120);
    EdW->show();
}
