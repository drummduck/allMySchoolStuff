 #include "levelselector.h"
#include "ui_levelselector.h"

levelSelector::levelSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::levelSelector)
{
    ui->setupUi(this);
    QObject::connect(ui->signOutButton,SIGNAL(pressed()),this,SLOT(handleSignOutPressed()));
    this->ui->signOutButton->setStyleSheet("QPushButton {border-Image : url(:/textures/textures/go-back.png); }");
}

levelSelector::~levelSelector()
{
    delete ui;
}


void levelSelector::displayComponents(){

    this->ui->signOutButton->raise();
    this->ui->signOutButton->activateWindow();
}

void levelSelector::hideComponents() {
}

QPushButton* levelSelector::getLevelOneButton(){
}

void levelSelector::handleSignOutPressed(){
    emit signOut();
}
