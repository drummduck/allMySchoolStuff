#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <QObject>
#include <QDebug>
#include <Box2D/Box2D.h>
#include <math.h>
#include <iostream>

class GameWorld : public QObject
{
    Q_OBJECT

    bool topBasketHit;
    bool rimHit;
    bool backBoardHit;
    int turnScore;
    bool ballInFlight;
    int launcherType;
    float launcherAngle;
    float launcherMagnitude;

    //launcher type constants
    constexpr static int CANNON = 0;
    constexpr static int CATAPULT = 1;
    constexpr static int TREBUCHET = 2;
    constexpr static int NONE = 3;

    //math constants
    constexpr static float PI = 3.14159;

    //world constants
    constexpr static float DYNAMITE_MAGNITUDE = 25;

public:
    //possibly unneeded
    b2Body * ball;


    //constructor
    explicit GameWorld(QObject *parent = 0, int initLauncherType = NONE);

    //destructor
    ~GameWorld();


    //Fires launcher
    void fireLauncher();

    //sets launcher type
    void setLauncherType(int type);

    //returns current angle of launcher
    double getLauncherAngle();

    //resets score to zero
    void resetScore();

    //resets ball to not be in flight
    void setBallNotInFlight();

signals:
    //signal showing basket made
    void success(std::string, int);

    //signal showing launcher angle was changed
    void launcherAngleChanged(double);

    //signal to change ball location
    void changeBallLocation(double,double);

    //signal to send dynamite sound
    void playExplosion();

public slots:

    //handles when the top basket sensor is hit
    void onTopBasketHit();

    //handles when the bot basket sensor is hit
    void onBotBasketHit();

    //handles rim being hit
    void onRimHit();

    //handles backboard being hit
    void onBackboardHit();

    //runs on ball out of bounds
    void onBallOut();

    //Changes launcher's angle by given degrees
    void changeLauncherAngle(double angle);

    //Changes launcher's power by given amt
    void changeLauncherMagnitude(double magnitude);

    //handles score when obstacle hti
    void onObstacleHit();

    //handles score when ball hits ball
    void onBallHitsBall();

    //handles actions on dynamite hit
    void onDynamiteHit(b2Body*);
};

#endif // GAMEWORLD_H
