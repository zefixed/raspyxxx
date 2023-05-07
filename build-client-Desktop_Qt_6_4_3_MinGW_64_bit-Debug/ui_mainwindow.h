/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QWidget *layoutWidget;
    QHBoxLayout *week_Layout;
    QLabel *monday_label;
    QLabel *tuesday_label;
    QLabel *wednesday_label;
    QLabel *thursday_label;
    QLabel *friday_label;
    QLabel *saturday_label;
    QPushButton *change_schedule_button;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *input_group_label;
    QLineEdit *input_group_lineedit;
    QPushButton *exceptions_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(817, 415);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 30, 771, 31));
        week_Layout = new QHBoxLayout(layoutWidget);
        week_Layout->setObjectName("week_Layout");
        week_Layout->setContentsMargins(0, 0, 0, 0);
        monday_label = new QLabel(layoutWidget);
        monday_label->setObjectName("monday_label");

        week_Layout->addWidget(monday_label);

        tuesday_label = new QLabel(layoutWidget);
        tuesday_label->setObjectName("tuesday_label");

        week_Layout->addWidget(tuesday_label);

        wednesday_label = new QLabel(layoutWidget);
        wednesday_label->setObjectName("wednesday_label");

        week_Layout->addWidget(wednesday_label);

        thursday_label = new QLabel(layoutWidget);
        thursday_label->setObjectName("thursday_label");

        week_Layout->addWidget(thursday_label);

        friday_label = new QLabel(layoutWidget);
        friday_label->setObjectName("friday_label");

        week_Layout->addWidget(friday_label);

        saturday_label = new QLabel(layoutWidget);
        saturday_label->setObjectName("saturday_label");

        week_Layout->addWidget(saturday_label);

        change_schedule_button = new QPushButton(centralwidget);
        change_schedule_button->setObjectName("change_schedule_button");
        change_schedule_button->setGeometry(QRect(25, 312, 151, 41));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(280, 0, 275, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        input_group_label = new QLabel(layoutWidget_2);
        input_group_label->setObjectName("input_group_label");

        horizontalLayout_2->addWidget(input_group_label);

        input_group_lineedit = new QLineEdit(layoutWidget_2);
        input_group_lineedit->setObjectName("input_group_lineedit");

        horizontalLayout_2->addWidget(input_group_lineedit);

        exceptions_button = new QPushButton(centralwidget);
        exceptions_button->setObjectName("exceptions_button");
        exceptions_button->setGeometry(QRect(24, 310, 111, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 817, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Raspyxxx", nullptr));
        monday_label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\275\320\265\320\264\320\265\320\273\321\214\320\275\320\270\320\272", nullptr));
        tuesday_label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\275\320\270\320\272", nullptr));
        wednesday_label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\260", nullptr));
        thursday_label->setText(QCoreApplication::translate("MainWindow", "\320\247\320\265\321\202\320\262\320\265\321\200\320\263", nullptr));
        friday_label->setText(QCoreApplication::translate("MainWindow", "\320\237\321\217\321\202\320\275\320\270\321\206\320\260", nullptr));
        saturday_label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\261\320\261\320\276\321\202\320\260", nullptr));
        change_schedule_button->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        input_group_label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213:", nullptr));
        exceptions_button->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
