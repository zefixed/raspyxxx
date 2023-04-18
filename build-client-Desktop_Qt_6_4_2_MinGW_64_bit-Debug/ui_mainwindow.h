/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *login_label;
    QLabel *pass_label;
    QLineEdit *pass_lineedit;
    QPushButton *show_pass_button;
    QLineEdit *login_lineedit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *log_in_button_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(432, 197);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        login_label = new QLabel(groupBox);
        login_label->setObjectName("login_label");

        gridLayout->addWidget(login_label, 0, 0, 1, 1);

        pass_label = new QLabel(groupBox);
        pass_label->setObjectName("pass_label");

        gridLayout->addWidget(pass_label, 1, 0, 1, 1);

        pass_lineedit = new QLineEdit(groupBox);
        pass_lineedit->setObjectName("pass_lineedit");
        pass_lineedit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(pass_lineedit, 1, 1, 1, 1);

        show_pass_button = new QPushButton(groupBox);
        show_pass_button->setObjectName("show_pass_button");

        gridLayout->addWidget(show_pass_button, 1, 2, 1, 1);

        login_lineedit = new QLineEdit(groupBox);
        login_lineedit->setObjectName("login_lineedit");

        gridLayout->addWidget(login_lineedit, 0, 1, 1, 2);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        log_in_button_2 = new QPushButton(centralwidget);
        log_in_button_2->setObjectName("log_in_button_2");

        horizontalLayout_2->addWidget(log_in_button_2);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 432, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        log_in_button_2->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Raspyxxx", nullptr));
        groupBox->setTitle(QString());
        login_label->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        pass_label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        show_pass_button->setText(QCoreApplication::translate("MainWindow", "\360\237\221\201", nullptr));
        log_in_button_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
