/********************************************************************************
** Form generated from reading UI file 'studentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW_H
#define UI_STUDENTWINDOW_H

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

class Ui_StudentWindow
{
public:
    QWidget *centralwidget;
    QPushButton *back_from_student_window_button;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *monday_label;
    QLabel *tuesday_label;
    QLabel *wednesday_label;
    QLabel *thursday_label;
    QLabel *friday_label;
    QLabel *saturday_label;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *input_group_label;
    QLineEdit *input_group_lineedit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName("StudentWindow");
        StudentWindow->resize(821, 522);
        centralwidget = new QWidget(StudentWindow);
        centralwidget->setObjectName("centralwidget");
        back_from_student_window_button = new QPushButton(centralwidget);
        back_from_student_window_button->setObjectName("back_from_student_window_button");
        back_from_student_window_button->setGeometry(QRect(680, 420, 111, 41));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 80, 711, 41));
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

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(270, 30, 255, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        input_group_label = new QLabel(layoutWidget1);
        input_group_label->setObjectName("input_group_label");

        horizontalLayout_2->addWidget(input_group_label);

        input_group_lineedit = new QLineEdit(layoutWidget1);
        input_group_lineedit->setObjectName("input_group_lineedit");

        horizontalLayout_2->addWidget(input_group_lineedit);

        StudentWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StudentWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 821, 25));
        StudentWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StudentWindow);
        statusbar->setObjectName("statusbar");
        StudentWindow->setStatusBar(statusbar);

        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StudentWindow)
    {
        StudentWindow->setWindowTitle(QCoreApplication::translate("StudentWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        back_from_student_window_button->setText(QCoreApplication::translate("StudentWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        monday_label->setText(QCoreApplication::translate("StudentWindow", "\320\237\320\276\320\275\320\265\320\264\320\265\320\273\321\214\320\275\320\270\320\272", nullptr));
        tuesday_label->setText(QCoreApplication::translate("StudentWindow", "\320\222\321\202\320\276\321\200\320\275\320\270\320\272", nullptr));
        wednesday_label->setText(QCoreApplication::translate("StudentWindow", "\320\241\321\200\320\265\320\264\320\260", nullptr));
        thursday_label->setText(QCoreApplication::translate("StudentWindow", "\320\247\320\265\321\202\320\262\320\265\321\200\320\263", nullptr));
        friday_label->setText(QCoreApplication::translate("StudentWindow", "\320\237\321\217\321\202\320\275\320\270\321\206\320\260", nullptr));
        saturday_label->setText(QCoreApplication::translate("StudentWindow", "\320\241\321\203\320\261\320\261\320\276\321\202\320\260", nullptr));
        input_group_label->setText(QCoreApplication::translate("StudentWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
