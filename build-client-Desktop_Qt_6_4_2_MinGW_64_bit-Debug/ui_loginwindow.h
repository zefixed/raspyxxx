/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *login_label;
    QLabel *pass_label;
    QLineEdit *pass_lineedit;
    QPushButton *show_pass_button;
    QLineEdit *login_lineedit;
    QPushButton *log_in_button;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(427, 153);
        LoginWindow->setFocusPolicy(Qt::TabFocus);
        verticalLayout = new QVBoxLayout(LoginWindow);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(LoginWindow);
        groupBox->setObjectName("groupBox");
        groupBox->setFocusPolicy(Qt::NoFocus);
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
        pass_lineedit->setFocusPolicy(Qt::StrongFocus);
        pass_lineedit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(pass_lineedit, 1, 1, 1, 1);

        show_pass_button = new QPushButton(groupBox);
        show_pass_button->setObjectName("show_pass_button");
        show_pass_button->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(show_pass_button, 1, 2, 1, 1);

        login_lineedit = new QLineEdit(groupBox);
        login_lineedit->setObjectName("login_lineedit");
        login_lineedit->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(login_lineedit, 0, 1, 1, 2);


        verticalLayout->addWidget(groupBox);

        log_in_button = new QPushButton(LoginWindow);
        log_in_button->setObjectName("log_in_button");
        log_in_button->setFocusPolicy(Qt::TabFocus);

        verticalLayout->addWidget(log_in_button);

        QWidget::setTabOrder(login_lineedit, pass_lineedit);
        QWidget::setTabOrder(pass_lineedit, show_pass_button);
        QWidget::setTabOrder(show_pass_button, log_in_button);

        retranslateUi(LoginWindow);

        log_in_button->setDefault(true);


        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        groupBox->setTitle(QString());
        login_label->setText(QCoreApplication::translate("LoginWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        pass_label->setText(QCoreApplication::translate("LoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        show_pass_button->setText(QCoreApplication::translate("LoginWindow", "\360\237\221\201", nullptr));
        log_in_button->setText(QCoreApplication::translate("LoginWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
