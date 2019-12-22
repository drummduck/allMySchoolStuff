#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QPushButton>
#include <iostream>
#include <QKeySequence>
#include <QShortcut>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();
    void displayComponents();
    void hideComponents();
    void hideTeacherComponents();
    void displayTeacherComponents();
    std::string getUsername();
    std::string getPassword();
    bool initialUserChange;
    bool initialPasswordChange;
    void setNotification(std::string);
    QPushButton* getLoginButton();
    QPushButton* getGuestButton();
    QPushButton* getSingleplayerButton();
    QPushButton* getMultiplayerButton();
    void disableLogin();
    void getCenterpos();
    void displayHelp();



private:
    Ui::LoginForm *ui;

public slots:
    void loginActive();
    void enableLogin();
    //void createUser();
    void modeSelect();
    void modeCancel();
    //Handlers for admin.
    void handleCreateTeacherClick();
    void handleUpdateTeacherClick();
    void handleDeleteTeacherClick();
    void handleBackButtonClick();
    void handleOpenAnalytics();


private slots:
    void clickedUsername();
    void clickedPassword();
    void clickedCreateUserAdmin();
    void clickedCreatePasswordAdmin();
    void clickedUpdateAdmin();
    void clickedDeleteAdmin();
    void setEcho();
    void tab();
    void enter();


signals:
    void createUserTeacher(QString username, QString password);
    void updateUserLevel(QString username, int level);
    void deleteUserTeacher(QString username);
    void openItUp();

};

#endif // LOGINFORM_H
