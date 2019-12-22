#include "WorldObject.h"

/**
 * @brief WorldObject::WorldObject
 * @param initX
 * @param initY
 * @param t
 * @param b
 * @param circle
 * @param initW
 * @param initH
 * world object constructor for rect and circle
 * AAARON
*/
WorldObject::WorldObject(float initX, float initY, sf::Texture t, b2Body * b, bool circle, float initW, float initH)
{
    //set members
    x = initX;
    y = initY;
    texture = t;
    body = b;
    isCircle = circle;
    width = initW;
    height = initH;
    isPoly = false;

    //create sprite
    sprite.setTexture(texture);
    float xOffset = width*SCALE/2;
    float yOffset = height*SCALE/2;
    sprite.setOrigin(xOffset, yOffset);
    sprite.setPosition(x*SCALE, y*SCALE);
    sprite.setRotation(180/b2_pi * body->GetAngle());
}

/**
 * @brief WorldObject::WorldObject
 * Constructs World Object with polygon shape
 * @param vertices
 * @param t
 * @param b
 * AARON
 */
WorldObject::WorldObject(float initX, float initY, b2Vec2* verts, int numVerts, sf::Texture t, b2Body* b){
    body = b;
    texture = t;
    vertices = new sf::Vector2f[numVerts];
    for (int i = 0; i < numVerts; i++) {
        vertices[i] = sf::Vector2f(verts[i].x, verts[i].y);
    }
    numberOfVertices = numVerts;
    isPoly = true;
    x = initX;
    y = initY;

    //create shape
    shape.setTexture(&texture);
    shape.setPosition(x*SCALE, y*SCALE);
    shape.setPointCount(numberOfVertices);
    for(int i = 0; i < numberOfVertices; i++) {
        sf::Vector2f vertex(verts[i].x*SCALE, verts[i].y*SCALE);
        shape.setPoint(i, vertex);
    }
}

/**
 * @brief WorldObject::~WorldObject
 * destructor
 * AARON
 */
WorldObject::~WorldObject() {
}

/**
 * @brief WorldObject::getBody
 * @return
 * returns pointer to objects b2body
 * AARON
 */
b2Body * WorldObject::getBody(){
    return body;
}

/**
 * @brief WorldObject::getTexture
 * @return
 * returns objects texture
 * AARON
 */
sf::Texture WorldObject::getTexture(){
    return texture;
}

/**
 * @brief WorldObject::getX
 * @return
 * returns object's initial x location
 * AARON
 */
float WorldObject::getX() {
    return x;
}


/**
 * @brief WorldObject::getY
 * @return
 * returns object's initial y location
 * AARON
 */
float WorldObject::getY() {
    return y;
}

/**
 * @brief WorldObject::getIsCircle
 * @return
 * returns if object is a circle
 * AARON
 */
bool WorldObject::getIsCircle() {
    return isCircle;
}

/**
 * @brief WorldObject::getWidth
 * @return
 * returns object's width
 * AARON
 */
float WorldObject::getWidth() {
    return width;
}

/**
 * @brief WorldObject::getHeight
 * @return
 * returns object's height
 * AARON
 */
float WorldObject::getHeight() {
    return height;
}

/**
 * @brief WorldObject::isPolygon
 * tells if Object is Polygon shape
 * @return if object is polygon shape
 * BY AARON
 */
bool WorldObject::isPolygon() {
    return isPoly;
}

/**
 * @brief WorldObject::getVertices
 * @return
 * returns pointer to polygons's vertices
 * AARON
 */
sf::Vector2f* WorldObject::getVertices(){
    return vertices;
}

/**
 * @brief WorldObject::getVertexCount
 * @return
 * returns number of vertices in object
 * AARON
 */
int WorldObject::getVertexCount(){
    return numberOfVertices;
}

/**
 * @brief WorldObject::getShape
 * @return
 * returns polygon shape of object
 * AARON
 */
sf::ConvexShape WorldObject::getShape(){
    return shape;
}

/**
 * @brief WorldObject::getSprite
 * @return
 * returns object's sprite
 * AARON
 */
sf::Sprite WorldObject::getSprite(){
    return sprite;
}
