#include "ContactListener.h"
#include "sstream"

/**
 * @brief ContactListener::BeginContact
 * Contact listener for the boujee ball app. Allows us to fire off events
 * when two objects touch.
 * @param contact
 * contact object used to decipher what type of objects touched.
 */
void ContactListener::BeginContact(b2Contact *contact) {
    void* userDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* userDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    std::string * tagA = static_cast<std::string *> (userDataA);
    std::string * tagB = static_cast<std::string *> (userDataB);
    bool oneObjBall = false;
    bool oneObjTopBasket = false;
    bool oneObjBotBasket = false;
    bool oneObjBoundary = false;
    bool oneObjRim = false;
    bool oneObjBackboard = false;
    bool oneObjObstacle = false;
    bool bothObjBall = false;
    bool oneObjPrimaryBall = false;
    bool oneObjDynamite = false;

    if(*tagA == "rim" || *tagB == "rim") oneObjRim = true;
    if(*tagA == "backboard" || *tagB == "backboard") oneObjBackboard = true;
    if(*tagA == "primaryBall" || *tagA == "secondaryBall" || *tagB == "primaryBall" || *tagB == "secondaryBall") oneObjBall = true;
    if((*tagA == "primaryBall" || *tagA == "secondaryBall" ) && (*tagB == "primaryBall" || *tagB == "secondaryBall")) bothObjBall = true;
    if(*tagA == "primaryBall" || *tagB == "primaryBall") oneObjPrimaryBall = true;
    if(*tagA == "topSens" || *tagB == "topSens") oneObjTopBasket = true;
    if(*tagA == "botSens" || *tagB == "botSens") oneObjBotBasket = true;
    if(*tagA == "topBound" || *tagA == "rightBound" || *tagA == "botBound" || *tagA == "leftBound" ||
            *tagB == "topBound" || *tagB == "rightBound" || *tagB == "botBound" || *tagB == "leftBound") oneObjBoundary = true;
    if(*tagA == "obs" || *tagB == "obs") oneObjObstacle = true;
    if(*tagA == "dynamite" || *tagB == "dynamite") oneObjDynamite = true;

    if(oneObjBall && oneObjTopBasket) emit topBasketHit();
    if(oneObjBall && oneObjBotBasket) emit botBasketHit();
    if(oneObjPrimaryBall && oneObjBoundary) emit ballOutOfBounds();
    if(oneObjBall && oneObjRim) emit rimHit();
    if(oneObjBall && oneObjBackboard) emit backboardHit();
    if(oneObjBall && oneObjObstacle) emit obstacleHit();
    if(!(oneObjTopBasket || oneObjBotBasket || oneObjBoundary) && oneObjBall)emit bounceSound();
    if(bothObjBall) emit ballHitsBall();
    if(oneObjDynamite && oneObjBall) {
        if(*tagA == "dynamite") emit dynamiteHit(contact->GetFixtureB()->GetBody());
        if(*tagB == "dynamite") emit dynamiteHit(contact->GetFixtureA()->GetBody());
    }
}

void ContactListener::EndContact(b2Contact *contact) {
}
