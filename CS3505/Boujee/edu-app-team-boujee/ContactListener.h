#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <QObject>
#include <Box2D/Box2D.h>
#include <QDebug>
#include <iostream>

/**
 * @brief The ContactListener class
 * This class is the main contact listner for the boujee ball application.
 */
class ContactListener : public QObject, public b2ContactListener
{
    Q_OBJECT
    void BeginContact(b2Contact *contact);
    void EndContact(b2Contact *contact);

signals:
    //top basket hit signal
    void topBasketHit();
    //bot basket hit signal
    void botBasketHit();
    //ball goes out of bounds signal
    void ballOutOfBounds();
    //ball hits rim
    void rimHit();
    //ball hits backboard
    void backboardHit();
    //Emit for when ball hits an object to play sound.
    void bounceSound();
    //ball hits an obstacle
    void obstacleHit();
    //ball hits ball
    void ballHitsBall();
    //ball hits dynamite ball body pointer as arg
    void dynamiteHit(b2Body*);
public slots:
};

#endif // CONTACTLISTENER_H
