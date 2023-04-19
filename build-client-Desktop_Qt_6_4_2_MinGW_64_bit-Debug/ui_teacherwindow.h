/********************************************************************************
** Form generated from reading UI file 'teacherwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERWINDOW_H
#define UI_TEACHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherWindow
{
public:
    QWidget *centralwidget;
    QPushButton *back_from_teacher_window_button;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *monday_label;
    QLabel *tuesday_label;
    QLabel *wednesday_label;
    QLabel *thursday_label;
    QLabel *friday_label;
    QLabel *saturday_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TeacherWindow)
    {
        if (TeacherWindow->objectName().isEmpty())
            TeacherWindow->setObjectName("TeacherWindow");
        TeacherWindow->resize(800, 600);
        centralwidget = new QWidget(TeacherWindow);
        centralwidget->setObjectName("centralwidget");
        back_from_teacher_window_button = new QPushButton(centralwidget);
        back_from_teacher_window_button->setObjectName("back_from_teacher_window_button");
        back_from_teacher_window_button->setGeometry(QRect(660, 500, 121, 51));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 50, 711, 41));
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

        TeacherWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TeacherWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        TeacherWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TeacherWindow);
        statusbar->setObjectName("statusbar");
        TeacherWindow->setStatusBar(statusbar);

        retranslateUi(TeacherWindow);

        QMetaObject::connectSlotsByName(TeacherWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TeacherWindow)
    {
        TeacherWindow->setWindowTitle(QCoreApplication::translate("TeacherWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217 ", nullptr));
        back_from_teacher_window_button->setText(QCoreApplication::translate("TeacherWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        monday_label->setText(QCoreApplication::translate("TeacherWindow", "\320\237\320\276\320\275\320\265\320\264\320\265\320\273\321\214\320\275\320\270\320\272", nullptr));
        tuesday_label->setText(QCoreApplication::translate("TeacherWindow", "\320\222\321\202\320\276\321\200\320\275\320\270\320\272", nullptr));
        wednesday_label->setText(QCoreApplication::translate("TeacherWindow", "\320\241\321\200\320\265\320\264\320\260", nullptr));
        thursday_label->setText(QCoreApplication::translate("TeacherWindow", "\320\247\320\265\321\202\320\262\320\265\321\200\320\263", nullptr));
        friday_label->setText(QCoreApplication::translate("TeacherWindow", "\320\237\321\217\321\202\320\275\320\270\321\206\320\260", nullptr));
        saturday_label->setText(QCoreApplication::translate("TeacherWindow", "\320\241\321\203\320\261\320\261\320\276\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherWindow: public Ui_TeacherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW_H
