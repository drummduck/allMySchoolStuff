#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <QResource>
#include <QDebug>


class WorldObject
{
    constexpr static float SCALE = 30.0;
    float x;
    float y;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::ConvexShape shape;
    sf::Vector2f* vertices;
    int numberOfVertices;
    b2Body * body;
    bool isCircle;
    float width;
    float height;
    bool isPoly;

public:
    //constructs object with x, y loc, a sprite, and whether or not the object is dynamic
    WorldObject(float initX, float initY, sf::Texture t, b2Body* b, bool circle, float initW, float initH);
    //constructs polygon object with vertices
    WorldObject(float initX, float initY, b2Vec2* verts, int numVerts, sf::Texture t, b2Body* b);

    //Destructor
    ~WorldObject();

    //returns object's bodyDef pointer
    b2Body * getBody();

    //returns object's texture
    sf::Texture getTexture();

    //returns x value
    float getX();

    //returns y value
    float getY();

    //returns whether object is circle or not
    bool getIsCircle();

    //returns width
    float getWidth();

    //returns height
    float getHeight();

    //returns if shape is polygon
    bool isPolygon();

    //returns vertices pointer
//    b2Vec2* getVertices();
    sf::Vector2f* getVertices();

    //returns vertices count;
    int getVertexCount();

    //returns shape
    sf::ConvexShape getShape();

    //return sprite
    sf::Sprite getSprite();
};

#endif // WORLDOBJECT_H
