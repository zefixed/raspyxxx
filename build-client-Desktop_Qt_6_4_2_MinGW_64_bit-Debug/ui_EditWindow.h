/********************************************************************************
** Form generated from reading UI file 'EditWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *teacher_label;
    QComboBox *teacher_comboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *group_label;
    QComboBox *group_comboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *discipline_label;
    QComboBox *discipline_comboBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *teacher_line_label;
    QLineEdit *teacher_lineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *group_line_label;
    QLineEdit *group_lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *discipline_line_label;
    QLineEdit *discipline_lineEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *add_button;
    QPushButton *update_button;
    QPushButton *delete_button;

    void setupUi(QDialog *EditWindow)
    {
        if (EditWindow->objectName().isEmpty())
            EditWindow->setObjectName("EditWindow");
        EditWindow->resize(400, 262);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditWindow->sizePolicy().hasHeightForWidth());
        EditWindow->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(EditWindow);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, -1, 0);
        teacher_label = new QLabel(EditWindow);
        teacher_label->setObjectName("teacher_label");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(teacher_label->sizePolicy().hasHeightForWidth());
        teacher_label->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(teacher_label);

        teacher_comboBox = new QComboBox(EditWindow);
        teacher_comboBox->setObjectName("teacher_comboBox");

        horizontalLayout_3->addWidget(teacher_comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, 0, -1, -1);
        group_label = new QLabel(EditWindow);
        group_label->setObjectName("group_label");
        sizePolicy1.setHeightForWidth(group_label->sizePolicy().hasHeightForWidth());
        group_label->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(group_label);

        group_comboBox = new QComboBox(EditWindow);
        group_comboBox->setObjectName("group_comboBox");

        horizontalLayout_6->addWidget(group_comboBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(-1, 0, -1, -1);
        discipline_label = new QLabel(EditWindow);
        discipline_label->setObjectName("discipline_label");
        sizePolicy1.setHeightForWidth(discipline_label->sizePolicy().hasHeightForWidth());
        discipline_label->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(discipline_label);

        discipline_comboBox = new QComboBox(EditWindow);
        discipline_comboBox->setObjectName("discipline_comboBox");

        horizontalLayout_7->addWidget(discipline_comboBox);


        verticalLayout->addLayout(horizontalLayout_7);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        teacher_line_label = new QLabel(EditWindow);
        teacher_line_label->setObjectName("teacher_line_label");
        sizePolicy1.setHeightForWidth(teacher_line_label->sizePolicy().hasHeightForWidth());
        teacher_line_label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(teacher_line_label);

        teacher_lineEdit = new QLineEdit(EditWindow);
        teacher_lineEdit->setObjectName("teacher_lineEdit");

        horizontalLayout->addWidget(teacher_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        group_line_label = new QLabel(EditWindow);
        group_line_label->setObjectName("group_line_label");
        sizePolicy1.setHeightForWidth(group_line_label->sizePolicy().hasHeightForWidth());
        group_line_label->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(group_line_label);

        group_lineEdit = new QLineEdit(EditWindow);
        group_lineEdit->setObjectName("group_lineEdit");

        horizontalLayout_8->addWidget(group_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        discipline_line_label = new QLabel(EditWindow);
        discipline_line_label->setObjectName("discipline_line_label");
        sizePolicy1.setHeightForWidth(discipline_line_label->sizePolicy().hasHeightForWidth());
        discipline_line_label->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(discipline_line_label);

        discipline_lineEdit = new QLineEdit(EditWindow);
        discipline_lineEdit->setObjectName("discipline_lineEdit");

        horizontalLayout_9->addWidget(discipline_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_9);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        label_2 = new QLabel(EditWindow);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        add_button = new QPushButton(EditWindow);
        add_button->setObjectName("add_button");

        horizontalLayout_2->addWidget(add_button);

        update_button = new QPushButton(EditWindow);
        update_button->setObjectName("update_button");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(update_button->sizePolicy().hasHeightForWidth());
        update_button->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(update_button);

        delete_button = new QPushButton(EditWindow);
        delete_button->setObjectName("delete_button");

        horizontalLayout_2->addWidget(delete_button);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);


        retranslateUi(EditWindow);

        QMetaObject::connectSlotsByName(EditWindow);
    } // setupUi

    void retranslateUi(QDialog *EditWindow)
    {
        EditWindow->setWindowTitle(QCoreApplication::translate("EditWindow", "Dialog", nullptr));
        teacher_label->setText(QCoreApplication::translate("EditWindow", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        group_label->setText(QCoreApplication::translate("EditWindow", "\320\223\321\200\321\203\320\277\320\277\320\260", nullptr));
        discipline_label->setText(QCoreApplication::translate("EditWindow", "\320\224\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\320\260", nullptr));
        teacher_line_label->setText(QCoreApplication::translate("EditWindow", "\320\244\320\230\320\236", nullptr));
        group_line_label->setText(QCoreApplication::translate("EditWindow", "\320\223\321\200\321\203\320\277\320\277\320\260", nullptr));
        discipline_line_label->setText(QCoreApplication::translate("EditWindow", "\320\224\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\320\260", nullptr));
        label_2->setText(QString());
        add_button->setText(QCoreApplication::translate("EditWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        update_button->setText(QCoreApplication::translate("EditWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        delete_button->setText(QCoreApplication::translate("EditWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditWindow: public Ui_EditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
