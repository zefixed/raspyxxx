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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *label_2;

    void setupUi(QDialog *EditWindow)
    {
        if (EditWindow->objectName().isEmpty())
            EditWindow->setObjectName("EditWindow");
        EditWindow->resize(400, 100);
        gridLayout = new QGridLayout(EditWindow);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(EditWindow);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(EditWindow);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(EditWindow);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(EditWindow);
        pushButton_3->setObjectName("pushButton_3");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(EditWindow);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        label_2 = new QLabel(EditWindow);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(EditWindow);

        QMetaObject::connectSlotsByName(EditWindow);
    } // setupUi

    void retranslateUi(QDialog *EditWindow)
    {
        EditWindow->setWindowTitle(QCoreApplication::translate("EditWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EditWindow", "\320\244\320\230\320\236", nullptr));
        pushButton->setText(QCoreApplication::translate("EditWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("EditWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EditWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditWindow: public Ui_EditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
