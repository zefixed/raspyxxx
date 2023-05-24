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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *change_schedule_button;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *monday_Layout;
    QLabel *monday_label;
    QLabel *monday_schedule_label;
    QVBoxLayout *tuesday_Layout;
    QLabel *tuesday_label;
    QLabel *tuesday_schedule_label;
    QVBoxLayout *wednesday_Layout;
    QLabel *wednesday_label;
    QLabel *wednesday_schedule_label;
    QVBoxLayout *thursday_Layout;
    QLabel *thursday_label;
    QLabel *thursday_schedule_label;
    QVBoxLayout *friday_Layout;
    QLabel *friday_label;
    QLabel *friday_schedule_label;
    QVBoxLayout *saturday_Layout;
    QLabel *saturday_label;
    QLabel *saturday_schedule_label;
    QPushButton *exceptions_button;
    QHBoxLayout *horizontalLayout_2;
    QLabel *input_group_label;
    QLineEdit *input_group_lineedit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(931, 630);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(917, 515));
        centralwidget->setMaximumSize(QSize(1920, 1080));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        change_schedule_button = new QPushButton(centralwidget);
        change_schedule_button->setObjectName("change_schedule_button");

        gridLayout->addWidget(change_schedule_button, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        monday_Layout = new QVBoxLayout();
        monday_Layout->setObjectName("monday_Layout");
        monday_Layout->setContentsMargins(0, -1, -1, -1);
        monday_label = new QLabel(centralwidget);
        monday_label->setObjectName("monday_label");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(monday_label->sizePolicy().hasHeightForWidth());
        monday_label->setSizePolicy(sizePolicy);

        monday_Layout->addWidget(monday_label);

        monday_schedule_label = new QLabel(centralwidget);
        monday_schedule_label->setObjectName("monday_schedule_label");
        monday_schedule_label->setMinimumSize(QSize(0, 0));

        monday_Layout->addWidget(monday_schedule_label);


        horizontalLayout->addLayout(monday_Layout);

        tuesday_Layout = new QVBoxLayout();
        tuesday_Layout->setObjectName("tuesday_Layout");
        tuesday_Layout->setContentsMargins(0, -1, -1, -1);
        tuesday_label = new QLabel(centralwidget);
        tuesday_label->setObjectName("tuesday_label");
        sizePolicy.setHeightForWidth(tuesday_label->sizePolicy().hasHeightForWidth());
        tuesday_label->setSizePolicy(sizePolicy);
        tuesday_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        tuesday_Layout->addWidget(tuesday_label);

        tuesday_schedule_label = new QLabel(centralwidget);
        tuesday_schedule_label->setObjectName("tuesday_schedule_label");
        tuesday_schedule_label->setMinimumSize(QSize(0, 0));

        tuesday_Layout->addWidget(tuesday_schedule_label);


        horizontalLayout->addLayout(tuesday_Layout);

        wednesday_Layout = new QVBoxLayout();
        wednesday_Layout->setObjectName("wednesday_Layout");
        wednesday_Layout->setContentsMargins(0, -1, -1, -1);
        wednesday_label = new QLabel(centralwidget);
        wednesday_label->setObjectName("wednesday_label");
        sizePolicy.setHeightForWidth(wednesday_label->sizePolicy().hasHeightForWidth());
        wednesday_label->setSizePolicy(sizePolicy);

        wednesday_Layout->addWidget(wednesday_label);

        wednesday_schedule_label = new QLabel(centralwidget);
        wednesday_schedule_label->setObjectName("wednesday_schedule_label");
        wednesday_schedule_label->setMinimumSize(QSize(0, 0));

        wednesday_Layout->addWidget(wednesday_schedule_label);


        horizontalLayout->addLayout(wednesday_Layout);

        thursday_Layout = new QVBoxLayout();
        thursday_Layout->setObjectName("thursday_Layout");
        thursday_Layout->setContentsMargins(0, -1, -1, -1);
        thursday_label = new QLabel(centralwidget);
        thursday_label->setObjectName("thursday_label");
        sizePolicy.setHeightForWidth(thursday_label->sizePolicy().hasHeightForWidth());
        thursday_label->setSizePolicy(sizePolicy);

        thursday_Layout->addWidget(thursday_label);

        thursday_schedule_label = new QLabel(centralwidget);
        thursday_schedule_label->setObjectName("thursday_schedule_label");
        thursday_schedule_label->setMinimumSize(QSize(0, 0));

        thursday_Layout->addWidget(thursday_schedule_label);


        horizontalLayout->addLayout(thursday_Layout);

        friday_Layout = new QVBoxLayout();
        friday_Layout->setObjectName("friday_Layout");
        friday_Layout->setContentsMargins(0, -1, -1, -1);
        friday_label = new QLabel(centralwidget);
        friday_label->setObjectName("friday_label");
        sizePolicy.setHeightForWidth(friday_label->sizePolicy().hasHeightForWidth());
        friday_label->setSizePolicy(sizePolicy);

        friday_Layout->addWidget(friday_label);

        friday_schedule_label = new QLabel(centralwidget);
        friday_schedule_label->setObjectName("friday_schedule_label");
        friday_schedule_label->setMinimumSize(QSize(0, 0));

        friday_Layout->addWidget(friday_schedule_label);


        horizontalLayout->addLayout(friday_Layout);

        saturday_Layout = new QVBoxLayout();
        saturday_Layout->setObjectName("saturday_Layout");
        saturday_Layout->setContentsMargins(0, -1, -1, -1);
        saturday_label = new QLabel(centralwidget);
        saturday_label->setObjectName("saturday_label");
        sizePolicy.setHeightForWidth(saturday_label->sizePolicy().hasHeightForWidth());
        saturday_label->setSizePolicy(sizePolicy);

        saturday_Layout->addWidget(saturday_label);

        saturday_schedule_label = new QLabel(centralwidget);
        saturday_schedule_label->setObjectName("saturday_schedule_label");
        saturday_schedule_label->setMinimumSize(QSize(0, 0));

        saturday_Layout->addWidget(saturday_schedule_label);


        horizontalLayout->addLayout(saturday_Layout);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        exceptions_button = new QPushButton(centralwidget);
        exceptions_button->setObjectName("exceptions_button");

        gridLayout->addWidget(exceptions_button, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        input_group_label = new QLabel(centralwidget);
        input_group_label->setObjectName("input_group_label");

        horizontalLayout_2->addWidget(input_group_label);

        input_group_lineedit = new QLineEdit(centralwidget);
        input_group_lineedit->setObjectName("input_group_lineedit");

        horizontalLayout_2->addWidget(input_group_lineedit);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 931, 21));
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
        change_schedule_button->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        monday_label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\275\320\265\320\264\320\265\320\273\321\214\320\275\320\270\320\272", nullptr));
        monday_schedule_label->setText(QString());
        tuesday_label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\275\320\270\320\272", nullptr));
        tuesday_schedule_label->setText(QString());
        wednesday_label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\260", nullptr));
        wednesday_schedule_label->setText(QString());
        thursday_label->setText(QCoreApplication::translate("MainWindow", "\320\247\320\265\321\202\320\262\320\265\321\200\320\263", nullptr));
        thursday_schedule_label->setText(QString());
        friday_label->setText(QCoreApplication::translate("MainWindow", "\320\237\321\217\321\202\320\275\320\270\321\206\320\260", nullptr));
        friday_schedule_label->setText(QString());
        saturday_label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\261\320\261\320\276\321\202\320\260", nullptr));
        saturday_schedule_label->setText(QString());
        exceptions_button->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
        input_group_label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
