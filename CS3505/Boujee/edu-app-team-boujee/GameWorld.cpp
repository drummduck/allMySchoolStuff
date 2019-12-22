#include "GameWorld.h"

/**
 * @brief GameWorld::GameWorld
 * @param parent
 * @param initLauncherType
 * GameWorld Constructor
 * AARON
 */
GameWorld::GameWorld(QObject * parent, int initLauncherType) : QObject(parent){
    ballInFlight = false;
    topBasketHit = false;
    launcherType = initLauncherType;
}

/**
  * @brief GameWorld::~GameWorld
  * GameWorld Destructor
  * AARON
  */
 GameWorld::~GameWorld() {
}

 /**
 * @brief GameWorld::changeLauncherAngle
 * @param angle
 * handles changing the current angle of the launcher
 * AARON
 */
void GameWorld::changeLauncherAngle(double angle){
    launcherAngle = angle;
    ballInFlight = false;
    resetScore();
    //Signal for when we have cannon.
    emit launcherAngleChanged(angle);
    //Signal for when it is a NONE LAUNCHER>>!!>!>!
    emit changeBallLocation(this->launcherMagnitude,this->launcherAngle);
}

/**
 * @brief GameWorld::changeLauncherMagnitude
 * @param magnitude
 * changes current magnitued of the launcher
 * Aaron
 */
void GameWorld::changeLauncherMagnitude(double magnitude){
    launcherMagnitude = magnitude;
    emit changeBallLocation(this->launcherMagnitude, this->launcherAngle);
}

/**
 * @brief GameWorld::getLauncherAngle
 * @return
 * returns current angle of launcher
 * AARON
 */
double GameWorld::getLauncherAngle(){
    return launcherAngle;
}

/**
 * @brief GameWorld::fireLauncher
 * handles when launcher is fired
 * AARON
 */
void GameWorld::fireLauncher(){
    //TODO fire launcher
    if(!ballInFlight) {
        turnScore = 0;
        if(launcherType == CANNON) {
            float xMag = launcherMagnitude * cos(launcherAngle * PI / 180);
            float yMag = -launcherMagnitude * sin(launcherAngle * PI /180);
            ball->ApplyForceToCenter(b2Vec2(xMag, yMag), true);
            emit playExplosion();
        }
        else if (launcherType == NONE) {
            ball->SetTransform(b2Vec2(launcherMagnitude, launcherAngle), 0.0);
            ball->SetAwake(true);
        }
    }
    ballInFlight = true;
}

/**
 * @brief GameWorld::onTopBasketHit
 * handles when top basket sensor is hit
 * AARON
 */
void GameWorld::onTopBasketHit() {
      topBasketHit = true;
}

/**
 * @brief GameWorld::onBotBasketHit
 * handles when bottom basket sensor is hit
 * AARON
 */
void GameWorld::onBotBasketHit() {
    //if shot is a swoosh
    if(topBasketHit && !rimHit && !backBoardHit)
    {
        turnScore += 3000;
        emit success("SWOOSH!", turnScore);
        turnScore = 0;
        launcherMagnitude = 0;
        launcherAngle = 0;
        topBasketHit = false;
        rimHit = false;
        backBoardHit = false;

        ballInFlight = false;
        return;
    }
    //if shot is success or bankshot
    if(topBasketHit)
    {
        turnScore += 1000;
        if(backBoardHit) emit success("BANK SHOT!", turnScore);
        else emit success("SUCCESS!", turnScore);
        turnScore = 0;
        launcherMagnitude = 0;
        launcherAngle = 0;
        topBasketHit = false;
        rimHit = false;
        backBoardHit = false;
        ballInFlight = false;
        return;
    }
}

/**
 * @brief GameWorld::onRimHit
 * handles when rim is hit
 * AARON
  */
void GameWorld::onRimHit()
{
    rimHit = true;
}

/**
 * @brief GameWorld::onBackboardHit
 * handles backboard being hit
 * AARON
 */
void GameWorld::onBackboardHit()
{
    backBoardHit = true;
}

/**
 * @brief GameWorld::setLauncherType
 * @param type
 * sets the given launcher type
 * AARON
 */
void GameWorld::setLauncherType(int type){
    launcherType = type;
}

/**
 * @brief GameWorld::onBallOut
 * handles when ball goes out of bounds
 * AARON
 */
void GameWorld::onBallOut(){
    ballInFlight = false;
    resetScore();
}

/**
 * @brief GameWorld::onObstacleHit
 * handles when ball bounces off an obstacle
 * AARON
 */
void GameWorld::onObstacleHit(){
    turnScore += 300;
}

/**
 * @brief GameWorld::resetScore
 * resets score and booleans keeping track of state of game
 * AARON
 */
void GameWorld::resetScore(){
    topBasketHit = false;
    rimHit = false;
    backBoardHit = false;
    turnScore = 0;
}

/**
 * @brief GameWorld::onBallHitsBall
 * Handles scoring when ball hits another ball
 * AARON
 */
void GameWorld::onBallHitsBall(){
    turnScore += 500;
}

/**
 * @brief GameWorld::setBallNotInFlight
 * resets ballin flight status
 * AARON
 */
void GameWorld::setBallNotInFlight(){
    ballInFlight = false;
}

/**
 * @brief GameWorld::onDynamiteHit
 * @param dynaBall
 * handles when dynamite is hit
 * AARON
 */
void GameWorld::onDynamiteHit(b2Body * dynaBall){
    dynaBall->SetLinearVelocity(b2Vec2(0, -DYNAMITE_MAGNITUDE));
    emit playExplosion();
}
