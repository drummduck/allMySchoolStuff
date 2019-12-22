#include "loginform.h"
#include "ui_loginform.h"


LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    this->ui->createUser->setVisible(false);
    this->ui->deleteUser->setVisible(false);
    this->ui->updateUserLevel->setVisible(false);
    this->ui->teacherUserName->setVisible(false);
    this->ui->teacherPassword->setVisible(false);
    this->ui->teacherDelete->setVisible(false);
    this->ui->updateTeacherUsername->setVisible(false);
    this->ui->teacherSpinBox->setVisible(false);
    this->ui->adminLabel->setVisible(false);
    this->ui->openAnalytics->setVisible(false);
    initialUserChange = false;
    initialPasswordChange = false;


    QObject::connect(this->ui->userName, SIGNAL(textChanged(QString)), this, SLOT(loginActive()));
    QObject::connect(this->ui->password, SIGNAL(textChanged(QString)), this, SLOT(loginActive()));
    QObject::connect(this->ui->password, SIGNAL(textChanged(QString)), this, SLOT(setEcho()));
    QObject::connect(this->ui->deleteUser, SIGNAL(pressed()), this, SLOT(handleDeleteTeacherClick()));
    QObject::connect(this->ui->createUser, SIGNAL(pressed()), this, SLOT(handleCreateTeacherClick()));
    QObject::connect(this->ui->updateUserLevel, SIGNAL(pressed()), this, SLOT(handleUpdateTeacherClick()));
    QObject::connect(this->ui->backToLogin, SIGNAL(pressed()), this, SLOT(handleBackButtonClick()));
    QObject::connect(this->ui->openAnalytics, SIGNAL(pressed()), this, SLOT(handleOpenAnalytics()));
    QObject::connect(this->ui->userName, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(clickedUsername()));
    QObject::connect(this->ui->password, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(clickedPassword()));
    QObject::connect(this->ui->teacherUserName, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(clickedCreateUserAdmin()));
    QObject::connect(this->ui->teacherPassword, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(clickedCreatePasswordAdmin()));
    QObject::connect(this->ui->updateTeacherUsername, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(clickedUpdateAdmin()));
    QObject::connect(this->ui->teacherDelete, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(clickedDeleteAdmin()));

    new QShortcut(QKeySequence(Qt::Key_Tab), this, SLOT(tab()));
    new QShortcut(QKeySequence(Qt::Key_Return), this, SLOT(enter()));


}

LoginForm::~LoginForm()
{
    delete ui;
}


std::string LoginForm::getUsername(){
    return ui->userName->text().toStdString();
}

std::string LoginForm::getPassword(){
    return ui->password->text().toStdString();
}

void LoginForm::setNotification(std::string error){
    ui->notification->setText(QString::fromStdString(error));
}

QPushButton* LoginForm::getLoginButton(){
    return ui->loginButton;
}

QPushButton* LoginForm::getGuestButton(){
    return ui->guestButton;
}

void LoginForm::clickedUsername()
{
    if(this->ui->userName->text() == "USERNAME")
    {
        this->ui->userName->setText("");
        this->ui->userName->setStyleSheet("color : red");
        initialUserChange = true;
    }

}

void LoginForm::clickedPassword()
{
    if(this->ui->password->text() == "PASSWORD")
    {
        this->ui->password->setText("");
        this->ui->password->setStyleSheet("color : red");
        initialPasswordChange = true;
    }
}

void LoginForm::clickedCreateUserAdmin()
{
    if(this->ui->teacherUserName->text() == "new username")
    {
        this->ui->teacherUserName->setText("");
    }
}

void LoginForm::clickedCreatePasswordAdmin()
{
    if(this->ui->teacherPassword->text() == "new password")
    {
        this->ui->teacherPassword->setText("");
    }
}

void LoginForm::clickedUpdateAdmin()
{
    if(this->ui->updateTeacherUsername->text() == "user to update")
    {
        this->ui->updateTeacherUsername->setText("");
    }
}

void LoginForm::clickedDeleteAdmin()
{
    if(this->ui->teacherDelete->text() == "user to delete")
    {
        this->ui->teacherDelete->setText("");
    }
}


void LoginForm::tab()
{
    if(this->ui->userName->hasFocus())
    {
        if(this->ui->password->text() == "PASSWORD")
        {
            this->ui->password->setText("");
            this->ui->password->setStyleSheet("color : red");
            initialPasswordChange = true;
        }
        this->ui->password->setFocus();
    }
    else if(this->ui->password->hasFocus())
    {
        if(this->ui->userName->text() == "USERNAME")
        {
            this->ui->userName->setText("");
            this->ui->userName->setStyleSheet("color : red");
            initialUserChange = true;
        }
        this->ui->userName->setFocus();
    }
}

void LoginForm::displayComponents(){
    //Title
    this->ui->gameTitle->setStyleSheet("QLabel {background-color : red; color : blue; }");
    this->ui->gameTitle->raise();
    this->ui->gameTitle->activateWindow();
    this->ui->gameTitle->setVisible(true);
    //Password slot
    this->ui->password->setStyleSheet("QLineEdit {background-color : white; color : grey; }");
    this->ui->password->raise();
    this->ui->password->setEchoMode(QLineEdit::Normal);
    this->ui->password->activateWindow();
    this->ui->password->setVisible(true);
    //Username slot
    this->ui->userName->setStyleSheet("QLineEdit {background-color : white; color : grey; }");
    this->ui->userName->raise();
    this->ui->userName->activateWindow();
    this->ui->userName->setVisible(true);
    //Login Button
    this->ui->loginButton->setStyleSheet("QPushButton {background-color : grey; color : dark-grey; }");
    this->ui->loginButton->raise();
    this->ui->loginButton->activateWindow();
    this->ui->loginButton->setVisible(true);
    //Notification message
    this->ui->notification->setStyleSheet("QLabel {background-color : transparent; color: red; }");
    this->ui->notification->raise();
    this->ui->notification->activateWindow();
    this->ui->notification->setVisible(true);
    //Guest
    this->ui->guestButton->setStyleSheet("QPushButton {background-color : red; color : blue; }");
    this->ui->guestButton->raise();
    this->ui->guestButton->activateWindow();
    this->ui->guestButton->setVisible(true);

    this->ui->userName->setFocus();

}

void LoginForm::displayTeacherComponents(){
    //Title
    this->ui->createUser->setStyleSheet("QLabel {background-color : red; color : blue; }");
    this->ui->createUser->raise();
    this->ui->createUser->activateWindow();
    this->ui->createUser->setVisible(true);
    //teacherUser
    this->ui->teacherUserName->setStyleSheet("QLineEdit {background-color : white; color : red; }");
    this->ui->teacherUserName->raise();
    this->ui->teacherUserName->activateWindow();
    this->ui->teacherUserName->setVisible(true);
    //teacherPassword
    this->ui->teacherPassword->setStyleSheet("QLineEdit {background-color : white; color : red; }");
    this->ui->teacherPassword->raise();
    this->ui->teacherPassword->activateWindow();
    this->ui->teacherPassword->setVisible(true);



    //delet user button
    this->ui->deleteUser->setStyleSheet("QLineEdit {background-color : white; color : red; }");
    this->ui->deleteUser->raise();
    this->ui->deleteUser->activateWindow();
    this->ui->deleteUser->setVisible(true);
    //delete textbox
    this->ui->teacherDelete->setStyleSheet("QLineEdit {background-color : white; color : red; }");
    this->ui->teacherDelete->raise();
    this->ui->teacherDelete->activateWindow();
    this->ui->teacherDelete->setVisible(true);


    //update level button
    this->ui->updateUserLevel->setStyleSheet("QLineEdit {background-color : white; color : red; }");
    this->ui->updateUserLevel->raise();
    this->ui->updateUserLevel->activateWindow();
    this->ui->updateUserLevel->setVisible(true);

    //update spinbox.
    this->ui->updateTeacherUsername->setStyleSheet("QLineEdit {background-color : white; color : red; }");
    this->ui->updateTeacherUsername->raise();
    this->ui->updateTeacherUsername->activateWindow();
    this->ui->updateTeacherUsername->setVisible(true);


    //update spinbox.
    this->ui->teacherSpinBox->setStyleSheet("QLineEdit {background-color : white; color : red; }");
    this->ui->teacherSpinBox->raise();
    this->ui->teacherSpinBox->activateWindow();
    this->ui->teacherSpinBox->setVisible(true);

    //update spinbox.
    this->ui->backToLogin->setStyleSheet("QLineEdit {background-color : white; color : red; }");
    this->ui->backToLogin->raise();
    this->ui->backToLogin->activateWindow();
    this->ui->backToLogin->setVisible(true);

    //update analytics.
    this->ui->openAnalytics->setStyleSheet("QLineEdit {background-color : white; color : red; }");
    this->ui->openAnalytics->raise();
    this->ui->openAnalytics->activateWindow();
    this->ui->openAnalytics->setVisible(true);

    //admin label.
    this->ui->adminLabel->setStyleSheet("QLabel {background-color : red; color : blue; }");
    this->ui->adminLabel->raise();
    this->ui->adminLabel->activateWindow();
    this->ui->adminLabel->setVisible(true);


    this->displayHelp();

}

void LoginForm::hideComponents(){
    //Title
    this->ui->gameTitle->setVisible(false);

    this->ui->password->setVisible(false);

    this->ui->userName->setVisible(false);

    this->ui->loginButton->setVisible(false);

    this->ui->notification->setVisible(false);

    this->ui->guestButton->setVisible(false);
}

void LoginForm::hideTeacherComponents(){
    this->ui->teacherDelete->setVisible(false);
    this->ui->teacherPassword->setVisible(false);
    this->ui->teacherSpinBox->setVisible(false);
    this->ui->teacherUserName->setVisible(false);
    this->ui->updateTeacherUsername->setVisible(false);
    this->ui->updateUserLevel->setVisible(false);
    this->ui->createUser->setVisible(false);
    this->ui->deleteUser->setVisible(false);
    this->ui->backToLogin->setVisible(false);
    this->ui->openAnalytics->setVisible(false);
    this->ui->adminLabel->setVisible(false);


}

/**
 * @brief LoginForm::userTrue
 */
void LoginForm::loginActive(){


    if(this->ui->userName->text().size() == 9 && initialUserChange == false)
    {
        this->ui->userName->setText(this->ui->userName->text().remove(0, this->ui->userName->text().length()-1));
        initialUserChange = true;
        this->ui->userName->setStyleSheet("color : red");
    }

    else if(this->ui->userName->text() == "USERNAM" && initialUserChange == false)
    {
        this->ui->userName->setText("");
        initialUserChange = true;
        this->ui->userName->setStyleSheet("color : red");

    }

    if(this->ui->password->text().size() == 9 && initialPasswordChange == false)
    {
        this->ui->password->setText(this->ui->password->text().remove(0, this->ui->password->text().length()-1));
        initialPasswordChange = true;
        this->ui->password->setStyleSheet("color : red");

    }

    else if(this->ui->password->text() == "PASSWOR" && initialPasswordChange == false)
    {
        this->ui->password->setText("");
        initialPasswordChange = true;
        this->ui->password->setStyleSheet("color : red");

    }

    if((this->ui->userName->text() != "" && this->ui->password->text() != "") && initialUserChange && initialPasswordChange)
    {
        this->ui->loginButton->setEnabled(true);
        this->ui->loginButton->setStyleSheet("QPushButton {background-color : blue; color : red; }");
        this->ui->loginButton->raise();
        this->ui->loginButton->activateWindow();
    }
    else
    {
        this->ui->loginButton->setEnabled(false);
        this->ui->loginButton->setStyleSheet("QPushButton {background-color : grey; color : dark-grey; }");

    }
}

void LoginForm::disableLogin(){
    this->ui->loginButton->setEnabled(false);
    this->ui->loginButton->setStyleSheet("QPushButton {background-color : grey; color : dark-grey; }");
}

void LoginForm::enableLogin(){
    this->ui->userName->clear();
    this->ui->password->clear();
    this->ui->loginButton->setEnabled(true);
    this->ui->loginButton->setStyleSheet("QPushButton {background-color : blue; color : red; }");
}

void LoginForm::modeSelect()
{
    //this->ui->createUserButton->lower();
    this->ui->guestButton->lower();
    this->ui->userName->lower();
    this->ui->password->lower();
    this->ui->loginButton->lower();
    this->ui->notification->lower();
}

void LoginForm::modeCancel()
{
    this->ui->guestButton->raise();
    this->ui->userName->raise();
    this->ui->password->raise();
    this->ui->loginButton->raise();
}

void LoginForm::handleCreateTeacherClick(){
    emit createUserTeacher(ui->teacherUserName->text(), ui->teacherPassword->text());
}

void LoginForm::handleDeleteTeacherClick(){
    emit deleteUserTeacher(ui->teacherDelete->text());
}

void LoginForm::handleUpdateTeacherClick(){
    emit updateUserLevel(ui->updateTeacherUsername->text(),ui->teacherSpinBox->value());
}

void LoginForm::handleBackButtonClick(){
    this->hideTeacherComponents();
    this->enableLogin();
    this->displayComponents();
    initialPasswordChange = false;
    initialUserChange = false;
    this->ui->userName->setText("USERNAME");
    this->ui->password->setText("PASSWORD");
}

void LoginForm::handleOpenAnalytics(){
    emit openItUp();
}

void LoginForm::displayHelp(){
    QMessageBox help;
    help.setText("This is the admin page. Use it to create new users with desired passwords, update given users last level completed, delete users, and view analytics.");
    help.exec();
}

void LoginForm::setEcho()
{
    this->ui->password->setEchoMode(QLineEdit::Password);
}

void LoginForm::enter()
{
    this->ui->loginButton->pressed();
}


