/********************************************************************************
** Form generated from reading UI file 'methodistwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METHODISTWINDOW_H
#define UI_METHODISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MethodistWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *monday_label;
    QLabel *tuesday_label;
    QLabel *wednesday_label;
    QLabel *thursday_label;
    QLabel *friday_label;
    QLabel *saturday_label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *change_schedule_button;
    QPushButton *back_from_methodist_window_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MethodistWindow)
    {
        if (MethodistWindow->objectName().isEmpty())
            MethodistWindow->setObjectName("MethodistWindow");
        MethodistWindow->resize(859, 481);
        centralwidget = new QWidget(MethodistWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 60, 711, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        monday_label = new QLabel(layoutWidget);
        monday_label->setObjectName("monday_label");

        horizontalLayout->addWidget(monday_label);

        tuesday_label = new QLabel(layoutWidget);
        tuesday_label->setObjectName("tuesday_label");

        horizontalLayout->addWidget(tuesday_label);

        wednesday_label = new QLabel(layoutWidget);
        wednesday_label->setObjectName("wednesday_label");

        horizontalLayout->addWidget(wednesday_label);

        thursday_label = new QLabel(layoutWidget);
        thursday_label->setObjectName("thursday_label");

        horizontalLayout->addWidget(thursday_label);

        friday_label = new QLabel(layoutWidget);
        friday_label->setObjectName("friday_label");

        horizontalLayout->addWidget(friday_label);

        saturday_label = new QLabel(layoutWidget);
        saturday_label->setObjectName("saturday_label");

        horizontalLayout->addWidget(saturday_label);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(560, 370, 271, 51));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        change_schedule_button = new QPushButton(widget);
        change_schedule_button->setObjectName("change_schedule_button");

        gridLayout->addWidget(change_schedule_button, 0, 0, 1, 1);

        back_from_methodist_window_button = new QPushButton(widget);
        back_from_methodist_window_button->setObjectName("back_from_methodist_window_button");

        gridLayout->addWidget(back_from_methodist_window_button, 0, 1, 1, 1);

        MethodistWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MethodistWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 859, 23));
        MethodistWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MethodistWindow);
        statusbar->setObjectName("statusbar");
        MethodistWindow->setStatusBar(statusbar);

        retranslateUi(MethodistWindow);

        QMetaObject::connectSlotsByName(MethodistWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MethodistWindow)
    {
        MethodistWindow->setWindowTitle(QCoreApplication::translate("MethodistWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\274\320\265\321\202\320\276\320\264\320\270\321\201\321\202\320\260", nullptr));
        monday_label->setText(QCoreApplication::translate("MethodistWindow", "\320\237\320\276\320\275\320\265\320\264\320\265\320\273\321\214\320\275\320\270\320\272", nullptr));
        tuesday_label->setText(QCoreApplication::translate("MethodistWindow", "\320\222\321\202\320\276\321\200\320\275\320\270\320\272", nullptr));
        wednesday_label->setText(QCoreApplication::translate("MethodistWindow", "\320\241\321\200\320\265\320\264\320\260", nullptr));
        thursday_label->setText(QCoreApplication::translate("MethodistWindow", "\320\247\320\265\321\202\320\262\320\265\321\200\320\263", nullptr));
        friday_label->setText(QCoreApplication::translate("MethodistWindow", "\320\237\321\217\321\202\320\275\320\270\321\206\320\260", nullptr));
        saturday_label->setText(QCoreApplication::translate("MethodistWindow", "\320\241\321\203\320\261\320\261\320\276\321\202\320\260", nullptr));
        change_schedule_button->setText(QCoreApplication::translate("MethodistWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        back_from_methodist_window_button->setText(QCoreApplication::translate("MethodistWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MethodistWindow: public Ui_MethodistWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METHODISTWINDOW_H
