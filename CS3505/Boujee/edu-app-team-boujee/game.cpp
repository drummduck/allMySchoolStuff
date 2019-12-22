#include "game.h"
#include "ui_game.h"
#include <QShortcut>
#include <QKeySequence>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

void Game::updateScore(int score)
{
    this->ui->lcdNumber->display(score);
}

void Game::displayComponents() {
    //magnitude text entry
    this->ui->magnitude->setStyleSheet("QDoubleSpinBox {background-color : white; color : red; }");
    this->ui->magnitude->raise();
    this->ui->magnitude->activateWindow();
    this->ui->magnitude->setVisible(true);

    //angle text entry
    this->ui->angle->setStyleSheet("QDoubleSpinBox {background-color : white; color : red; }");
    this->ui->angle->raise();
    this->ui->angle->activateWindow();
    this->ui->angle->setVisible(true);

    //Gravity box
    this->ui->gravity->setVisible(false);



    //enable hotkeys?

    //LESSON hotkeys Same for given spinboxes - regardless of how we got here.
    new QShortcut(QKeySequence(Qt::Key_D), this, SLOT(incMag()));
    new QShortcut(QKeySequence(Qt::Key_A), this, SLOT(decMag()));
    new QShortcut(QKeySequence(Qt::Key_Right), this, SLOT(incMag()));
    new QShortcut(QKeySequence(Qt::Key_Left), this, SLOT(decMag()));

    //new QShortcut(QKeySequence(Qt::Key_D), this, SLOT(incMag()));
    new QShortcut(QKeySequence(Qt::Key_W), this, SLOT(incAng()));
    new QShortcut(QKeySequence(Qt::Key_S), this, SLOT(decAng()));
    new QShortcut(QKeySequence(Qt::Key_Up), this, SLOT(incAng()));
    new QShortcut(QKeySequence(Qt::Key_Down), this, SLOT(decAng()));

    //Gravity control
    new QShortcut(QKeySequence(Qt::SHIFT + Qt::Key_Up), this, SLOT(incGrav()));
    new QShortcut(QKeySequence(Qt::SHIFT + Qt::Key_Down), this, SLOT(decGrav()));


}

/**
  hides ui components
  AARON
 * @brief Game::hideComponents
 */
void Game::hideComponents() {
    this->ui->magnitude->setVisible(false);

    this->ui->angle->setVisible(false);

    this->ui->gravity->setVisible(false);
}

void Game::incMag() {
    this->ui->magnitude->stepUp();
}

void Game::decMag() {
    this->ui->magnitude->stepDown();
}

void Game::incAng() {
    this->ui->angle->stepUp();
}

void Game::decAng() {
    this->ui->angle->stepDown();
}

void Game::incGrav()
{
    this->ui->gravity->stepDown();
}

void Game::decGrav()
{
    this->ui->gravity->stepUp();
}

void Game::displayGravityBox()
{

    //Gravity box
    this->ui->gravity->setStyleSheet("QDoubleSpinBox {background-color : white; color : red; }");
    this->ui->gravity->raise();
    this->ui->gravity->activateWindow();
    this->ui->gravity->setVisible(true);
}

/**
 * @brief Game::getMagnitudeSpinBox
 * returns reference to the magnitude spinbox
 * AARON
 * @return
 */
QDoubleSpinBox* Game::getMagnitudeSpinBox(){
    return ui->magnitude;
}

/**
 * @brief Game::getAngleSpinBox
 * returns reference to angle spinbox
 * AARON
 * @return
 */
QDoubleSpinBox* Game::getAngleSpinBox(){
    return ui->angle;
}

QDoubleSpinBox* Game::getGravitySpinBox()
{
    return ui->gravity;
}
