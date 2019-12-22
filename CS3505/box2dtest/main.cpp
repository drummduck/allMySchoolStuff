#include "boomchicka.h"
#include <QApplication>
#include "Box2D-master/Box2D/Box2D/Box2D.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    boomchicka w;
    w.show();

    b2Vec2 gravity(0, -9.8); //normal earth gravity, 9.8 m/s/s straight down!

    b2World *myWorld = new b2World(gravity);
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(0, 20); //set the starting position
    myBodyDef.angle = 0; //set the starting angle
    b2Body* dynamicBody = myWorld->CreateBody(&myBodyDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(1,1);


    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;
    dynamicBody->CreateFixture(&boxFixtureDef);

    return a.exec();
}
