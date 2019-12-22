/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QLabel *gameTitle;
    QLabel *notification;
    QLineEdit *password;
    QLineEdit *userName;
    QPushButton *loginButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QString::fromUtf8("LoginForm"));
        LoginForm->resize(912, 634);
        gameTitle = new QLabel(LoginForm);
        gameTitle->setObjectName(QString::fromUtf8("gameTitle"));
        gameTitle->setGeometry(QRect(280, 10, 601, 191));
        QFont font;
        font.setFamily(QString::fromUtf8("Century Schoolbook L"));
        font.setPointSize(72);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        gameTitle->setFont(font);
        gameTitle->setFrameShape(QFrame::Panel);
        gameTitle->setFrameShadow(QFrame::Raised);
        notification = new QLabel(LoginForm);
        notification->setObjectName(QString::fromUtf8("notification"));
        notification->setGeometry(QRect(410, 290, 341, 20));
        notification->setAlignment(Qt::AlignCenter);
        password = new QLineEdit(LoginForm);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(452, 370, 251, 41));
        QFont font1;
        font1.setPointSize(24);
        password->setFont(font1);
        userName = new QLineEdit(LoginForm);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setGeometry(QRect(452, 320, 251, 41));
        userName->setFont(font1);
        loginButton = new QPushButton(LoginForm);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setEnabled(false);
        loginButton->setGeometry(QRect(484, 415, 181, 51));
        QFont font2;
        font2.setPointSize(26);
        loginButton->setFont(font2);
        loginButton->setFlat(false);
        pushButton = new QPushButton(LoginForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(530, 490, 85, 26));
        pushButton_2 = new QPushButton(LoginForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(530, 530, 85, 26));

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Form", 0, QApplication::UnicodeUTF8));
        gameTitle->setText(QApplication::translate("LoginForm", "Boujee Ball", 0, QApplication::UnicodeUTF8));
        notification->setText(QApplication::translate("LoginForm", "Please enter username and password", 0, QApplication::UnicodeUTF8));
        password->setText(QString());
        loginButton->setText(QApplication::translate("LoginForm", "LOGIN", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LoginForm", "create user?", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("LoginForm", "play as guest?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
