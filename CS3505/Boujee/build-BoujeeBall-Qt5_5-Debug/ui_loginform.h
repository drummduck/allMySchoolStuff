/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QLabel *gameTitle;
    QLabel *notification;
    QLineEdit *password;
    QLineEdit *userName;
    QPushButton *loginButton;
    QPushButton *guestButton;
    QPushButton *createUser;
    QPushButton *updateUserLevel;
    QPushButton *deleteUser;
    QLineEdit *teacherPassword;
    QLineEdit *teacherUserName;
    QLineEdit *updateTeacherUsername;
    QSpinBox *teacherSpinBox;
    QLineEdit *teacherDelete;
    QLabel *adminLabel;
    QPushButton *backToLogin;
    QPushButton *openAnalytics;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QStringLiteral("LoginForm"));
        LoginForm->resize(1014, 634);
        gameTitle = new QLabel(LoginForm);
        gameTitle->setObjectName(QStringLiteral("gameTitle"));
        gameTitle->setGeometry(QRect(310, 10, 611, 191));
        QFont font;
        font.setFamily(QStringLiteral("Century Schoolbook L"));
        font.setPointSize(72);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        gameTitle->setFont(font);
        gameTitle->setFrameShape(QFrame::Panel);
        gameTitle->setFrameShadow(QFrame::Raised);
        notification = new QLabel(LoginForm);
        notification->setObjectName(QStringLiteral("notification"));
        notification->setGeometry(QRect(440, 280, 341, 20));
        notification->setAlignment(Qt::AlignCenter);
        password = new QLineEdit(LoginForm);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(482, 360, 251, 41));
        QFont font1;
        font1.setPointSize(24);
        password->setFont(font1);
        password->setEchoMode(QLineEdit::Password);
        userName = new QLineEdit(LoginForm);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setGeometry(QRect(482, 310, 251, 41));
        userName->setFont(font1);
        loginButton = new QPushButton(LoginForm);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setEnabled(false);
        loginButton->setGeometry(QRect(440, 410, 331, 41));
        QFont font2;
        font2.setPointSize(20);
        loginButton->setFont(font2);
        guestButton = new QPushButton(LoginForm);
        guestButton->setObjectName(QStringLiteral("guestButton"));
        guestButton->setEnabled(true);
        guestButton->setGeometry(QRect(540, 460, 151, 31));
        QFont font3;
        font3.setPointSize(12);
        guestButton->setFont(font3);
        createUser = new QPushButton(LoginForm);
        createUser->setObjectName(QStringLiteral("createUser"));
        createUser->setGeometry(QRect(440, 410, 141, 41));
        updateUserLevel = new QPushButton(LoginForm);
        updateUserLevel->setObjectName(QStringLiteral("updateUserLevel"));
        updateUserLevel->setGeometry(QRect(617, 410, 141, 41));
        deleteUser = new QPushButton(LoginForm);
        deleteUser->setObjectName(QStringLiteral("deleteUser"));
        deleteUser->setGeometry(QRect(790, 370, 151, 26));
        teacherPassword = new QLineEdit(LoginForm);
        teacherPassword->setObjectName(QStringLiteral("teacherPassword"));
        teacherPassword->setGeometry(QRect(442, 370, 141, 25));
        teacherUserName = new QLineEdit(LoginForm);
        teacherUserName->setObjectName(QStringLiteral("teacherUserName"));
        teacherUserName->setGeometry(QRect(440, 340, 141, 25));
        updateTeacherUsername = new QLineEdit(LoginForm);
        updateTeacherUsername->setObjectName(QStringLiteral("updateTeacherUsername"));
        updateTeacherUsername->setGeometry(QRect(620, 340, 131, 25));
        teacherSpinBox = new QSpinBox(LoginForm);
        teacherSpinBox->setObjectName(QStringLiteral("teacherSpinBox"));
        teacherSpinBox->setGeometry(QRect(707, 370, 41, 25));
        teacherSpinBox->setMinimum(1);
        teacherSpinBox->setMaximum(6);
        teacherDelete = new QLineEdit(LoginForm);
        teacherDelete->setObjectName(QStringLiteral("teacherDelete"));
        teacherDelete->setGeometry(QRect(790, 340, 151, 25));
        adminLabel = new QLabel(LoginForm);
        adminLabel->setObjectName(QStringLiteral("adminLabel"));
        adminLabel->setGeometry(QRect(50, 10, 321, 101));
        QFont font4;
        font4.setFamily(QStringLiteral("Courier 10 Pitch"));
        font4.setPointSize(40);
        font4.setBold(true);
        font4.setWeight(75);
        adminLabel->setFont(font4);
        backToLogin = new QPushButton(LoginForm);
        backToLogin->setObjectName(QStringLiteral("backToLogin"));
        backToLogin->setGeometry(QRect(440, 510, 161, 81));
        openAnalytics = new QPushButton(LoginForm);
        openAnalytics->setObjectName(QStringLiteral("openAnalytics"));
        openAnalytics->setGeometry(QRect(770, 510, 171, 81));

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Form", 0));
        gameTitle->setText(QApplication::translate("LoginForm", "Boujee Ball", 0));
        notification->setText(QApplication::translate("LoginForm", "Please enter username and password", 0));
        password->setText(QApplication::translate("LoginForm", "PASSWORD", 0));
        userName->setText(QApplication::translate("LoginForm", "USERNAME", 0));
        loginButton->setText(QApplication::translate("LoginForm", "LOGIN/CREATE USER", 0));
        guestButton->setText(QApplication::translate("LoginForm", "Play As Guest", 0));
        createUser->setText(QApplication::translate("LoginForm", "Create User", 0));
        updateUserLevel->setText(QApplication::translate("LoginForm", "Update User Level", 0));
        deleteUser->setText(QApplication::translate("LoginForm", "Delete User", 0));
        teacherPassword->setText(QApplication::translate("LoginForm", "new password", 0));
        teacherUserName->setText(QApplication::translate("LoginForm", "new username", 0));
        updateTeacherUsername->setText(QApplication::translate("LoginForm", "user to update", 0));
        teacherDelete->setText(QApplication::translate("LoginForm", "user to delete", 0));
        adminLabel->setText(QApplication::translate("LoginForm", "Admin Page", 0));
        backToLogin->setText(QApplication::translate("LoginForm", "Back to Login", 0));
        openAnalytics->setText(QApplication::translate("LoginForm", "Open Analytics", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
