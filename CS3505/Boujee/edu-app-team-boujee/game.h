#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QLCDNumber>
#include <QDoubleSpinBox>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

    //displays ui components
    void displayComponents();
    //hides ui components
    void hideComponents();
    //returns reference to magnitude spinbox
    QDoubleSpinBox* getMagnitudeSpinBox();
    //returns reference to magnitude spinbox
    QDoubleSpinBox* getAngleSpinBox();

    QDoubleSpinBox* getGravitySpinBox();

    void displayGravityBox();

private:
    Ui::Game *ui;

public slots:
    void updateScore(int);

    //for hotkeys
    void incMag();
    void decMag();
    void incAng();
    void decAng();
    void incGrav();
    void decGrav();
};

#endif // GAME_H
