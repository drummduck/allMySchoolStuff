#include "level.h"
#include <QString>
#include <QFile>
#include "mycanvas.h"
#include <fstream>
#include <iostream>
#include <QTextStream>
#include <QIODevice>
#include <QJsonDocument>
#include <QVariant>
#include <QVariantMap>
#include <QShortcut>
#include<QKeySequence>

/**
 * @brief Level::Level
 * @param id
 * creates and parses levels with the given id
 * Parser by jordan
 * Login and level select level by nathan
 */
Level::Level(int id)
{
    //tells ball create helper method that the first ball is being created
    firstBall = true;
    ballIndex = 0;
    levelId = id;
    isGravity = false;

    //This creates the design for the current login page
   if(id == -1) {
       /**************background texture set hardcoded for now****************/
       QResource bgImage(":/textures/textures/beautiful-mountains-wallpaper-7.png");
       backgroundTexture.loadFromMemory(bgImage.data(), bgImage.size(), sf::IntRect());

       /*********************************************************************/

        b2Vec2 gravity(0.0,9.8);
        world = new b2World(gravity);
        sf::Texture ballTexture;
        sf::Texture groundTexture;
        sf::Texture groundTexture2;
        sf::Texture worldTexture;

//        QResource worldImage(":/textures/textures/beautiful-mountains-wallpaper-7.png");
//        worldTexture.loadFromMemory(worldImage.data(), worldImage.size(), sf::IntRect());

        QResource ballImage(":/textures/textures/balls2.png");
        ballTexture.loadFromMemory(ballImage.data(), ballImage.size(), sf::IntRect());

        QResource groundImage(":/textures/textures/grass2.png");
        groundTexture.loadFromMemory(groundImage.data(), groundImage.size(), sf::IntRect(0,0,1280,720));

        QResource groundImage2(":/textures/textures/dirt2.png");
        groundTexture2.loadFromMemory(groundImage2.data(), groundImage2.size(), sf::IntRect(0,0,1280,720));

        std::string * ballTag = new std::string("primaryBall");
        std::string * obstacleTag = new std::string("obs");
        std::string * obstacleTag2 = new std::string("obs2");
        std::string * background = new std::string("background");

        createRectObject(0.0/SCALE, -300.0/SCALE, worldTexture, 0.0/SCALE, 0.0/SCALE, false, 0, 0, 0, background, 0.0);
        createRectObject(960.0/SCALE, 650.0/SCALE, groundTexture, 1920.0/SCALE, 50.0/SCALE, false, -1, -1, 0, obstacleTag, 0.0);
        createRectObject(960.0/SCALE, 680.0/SCALE, groundTexture2, 1920.0/SCALE, 50.0/SCALE, false, -1, -1, -1, obstacleTag2, 0.0);

        createCircleObject(100.0/SCALE, 200/SCALE, ballTexture, 100.0/SCALE, 100.0/SCALE, true, 1.0, 0.3, 1, ballTag);

        b2Body * b = objects[1]->getBody();
        b->SetLinearVelocity(b2Vec2(10, -4));

        launcherType = NONE;

    }

    else if(id == -2)
    {
       /**************background texture set hardcoded for now****************/
       QResource bgImage(":/textures/textures/woodwall.png");
       backgroundTexture.loadFromMemory(bgImage.data(), bgImage.size(), sf::IntRect());

       /*********************************************************************/
        leftBound = -1000.0/SCALE;
        topBound = -1000.0/SCALE;
        rightBound = 2000.0/SCALE;
        botBound = 5000.0/SCALE;

        ballRadius = 200.0/SCALE;
        ballLocationX = 200.0/SCALE;
        ballLocationY = -200.0/SCALE;
        ballWidth = 100.0/SCALE;
        ballHeight = 100.0/SCALE;
        ballDensity = 1.0;
        ballFriction = 0.3;
        ballRestitution = 0.5;


        b2Vec2 gravity(0.0,9.8);
        world = new b2World(gravity);

        sf::Texture board;
        QResource whiteboard(":/textures/textures/welcome.png");
        board.loadFromMemory(whiteboard.data(), whiteboard.size(), sf::IntRect());
        std::string * welcomeTag = new std::string ("welcome");

        //Welcome
        createRectObject(650.0/SCALE, 150.0/SCALE, board, 0, 0, false, 0 ,0 ,0, welcomeTag, 0.0);
        //Ball
        sf::Texture ballTexture;
        QResource ballImage(":/textures/textures/balls2.png");
        ballTexture.loadFromMemory(ballImage.data(), ballImage.size(), sf::IntRect());
        std::string * ballTag = new std::string ("primaryBall");

        //this->displayLessons(6);


        ballIndex = objects.size();

        //ball
        createCircleObject(200.0/SCALE, -200/SCALE, ballTexture, 100.0/SCALE, 100.0/SCALE, true, 1.0, 0.3, 0.5, ballTag);

        createBoundarySensors();
    }

    //Parser for lessons
    else if (id < 100) {
        //Open lesson and parse into json
        QString filename = ":/json/lessons/lesson" + QString::number(id) + ".txt";
        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly)) {
            std::cout << file.errorString().toStdString();
        }
        QTextStream in(&file);
        QString json;
        while(!in.atEnd()) {
            QString line = in.readLine();
            json = json + line;
        }
        QByteArray arr(json.toStdString().c_str());
        QJsonDocument jsonDoc = QJsonDocument::fromJson(arr);
        QVariantMap result = jsonDoc.toVariant().toMap();

        //pull elements defining the environment
        b2Vec2 gravity(0.0, result["gravity"].toFloat());
        world = new b2World(gravity);
        QResource ballImage(result["ballPath"].toString());
        ballTexture.loadFromMemory(ballImage.data(), ballImage.size(), sf::IntRect());
        ballRadius = result["ballRadius"].toFloat()/SCALE;
        leftBound = result["leftBound"].toFloat()/SCALE;
        topBound = result["topBound"].toFloat()/SCALE;
        rightBound = result["rightBound"].toFloat()/SCALE;
        botBound = result["botBound"].toFloat()/SCALE;
        ballLocationX = result["ballLocationX"].toFloat()/SCALE;
        ballLocationY = result["ballLocationY"].toFloat()/SCALE;
        ballWidth = result["ballWidth"].toFloat()/SCALE;
        ballHeight = result["ballHeight"].toFloat()/SCALE;
        ballDensity = result["ballDensity"].toFloat();
        ballFriction = result["ballFriction"].toFloat();
        ballRestitution = result["ballRestitution"].toFloat();
        QResource bgImage(result["bgimg"].toString());
        backgroundTexture.loadFromMemory(bgImage.data(), bgImage.size(), sf::IntRect());
        launcherType = result["launcherType"].toInt();
        if (launcherType != NONE){
            launcherAngle = result["launcherAngle"].toFloat();
            launcherMagnitude = result["launcherMagnitude"].toFloat();
        }
        else{
            launcherAngle = ballLocationY;
            launcherMagnitude = ballLocationX;
        }

        createBall();

        //pull all text boxes and create them
        foreach (const QVariant &obj, result["textBoxes"].toList()){
            QVariantMap textBox = obj.toMap();
            float xVal = textBox["xVal"].toFloat();
            float yVal = textBox["yVal"].toFloat();
            std::string text = textBox["text"].toString().toStdString();
            int textSize = textBox["textSize"].toInt();
            int r = textBox["r"].toInt();
            int g = textBox["g"].toInt();
            int b = textBox["b"].toInt();
            int a = textBox["a"].toInt();

            sf::Color color(r,g,b,a);
            bool hasContinue = textBox["hasContinue"].toBool();

            addTextBox(sf::Vector2f(xVal, yVal), text, textSize, color, hasContinue);
        }

        QResource fireImage(":/textures/textures/play_button.png");
        sf::Texture playTexture;
        fireTexture.loadFromMemory(fireImage.data(), fireImage.size(), sf::IntRect());
        playButton.setTexture(fireTexture);
        playButton.setPosition(sf::Vector2f(1100, 20));
        buttons.push_back(playButton);


        // Parse all of the rectangle objects
        foreach (const QVariant &obj, result["rectObjects"].toList()) {

            QVariantMap rectObj = obj.toMap();

            sf::Texture texture;
            std::string imagePath = rectObj["texturePath"].toString().toStdString();
            if (imagePath != "none"){
                QResource image(rectObj["texturePath"].toString());
                texture.loadFromMemory(image.data(), image.size(), sf::IntRect());
            }

            float xVal = rectObj["xVal"].toFloat()/SCALE;
            float yVal = rectObj["yVal"].toFloat()/SCALE;
            float width = rectObj["width"].toFloat()/SCALE;
            float height = rectObj["height"].toFloat()/SCALE;

            std::string * tag = new std::string(rectObj["tag"].toString().toStdString());

            createRectObject(xVal, yVal, texture, width, height, false, -1, -1, -1, tag, 0.0);
        }

        // Parse all of the polygon objects
        foreach (const QVariant &obj, result["polyObjects"].toList()){
            QVariantMap polyObj = obj.toMap();
            int numVertices = polyObj["size"].toInt();
            b2Vec2* verts = new b2Vec2[numVertices];

            //add the vertices
            int vertIndex = 0;
            foreach (const QVariant &vert, polyObj["vertices"].toList()){
                QVariantMap vertex = vert.toMap();
                verts[vertIndex] = b2Vec2(vertex["x"].toFloat()/SCALE, vertex["y"].toFloat()/SCALE);
                vertIndex = vertIndex + 1;
            }

            float xVal = polyObj["xVal"].toFloat()/SCALE;
            float yVal = polyObj["yVal"].toFloat()/SCALE;
            float density = polyObj["density"].toFloat();
            float restitution = polyObj["restitution"].toFloat();
            float friction = polyObj["friction"].toFloat();
            bool dynamic = polyObj["dynamic"].toBool();
            std::string * tag = new std::string(polyObj["tag"].toString().toStdString());
            sf::Texture texture;
            QResource image(polyObj["texturePath"].toString());
            texture.loadFromMemory(image.data(), image.size(), sf::IntRect());
            createPolyObject(xVal, yVal, verts, numVertices, texture, dynamic, density, friction, restitution, tag);

        }

        // Parse all of the circle objects
        foreach (const QVariant &obj, result["circObjects"].toList()){
            QVariantMap circObj = obj.toMap();
            float xVal = circObj["xVal"].toFloat()/SCALE;
            float yVal = circObj["yVal"].toFloat()/SCALE;
            float width = circObj["width"].toFloat();
            float height = circObj["height"].toFloat();
            float density = circObj["density"].toFloat();
            float restitution = circObj["restitution"].toFloat();
            float friction = circObj["friction"].toFloat();
            bool dynamic = circObj["dynamic"].toBool();
            std::string * tag = new std::string(circObj["tag"].toString().toStdString());
            sf::Texture texture;
            QResource image(circObj["texturePath"].toString());
            texture.loadFromMemory(image.data(), image.size(), sf::IntRect());
            createCircleObject(xVal, yVal, texture, width/SCALE, height/SCALE, dynamic,
                                    density, friction, restitution, tag);
        }

    }

    //This is the case for a playable level which gets parsed from
    //its corresponding json file
    else if (id > 100){

        //Find and parse the text file into json.
        id = id - 100;
        QString filename = ":/json/levels/level" + QString::number(id) + ".txt";
        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly)) {
            std::cout << file.errorString().toStdString();
        }
        QTextStream in(&file);
        QString fileContents;
        while(!in.atEnd()) {
            QString line = in.readLine();
            fileContents = fileContents + line;
        }
        QByteArray arr(fileContents.toStdString().c_str());
        QJsonDocument json = QJsonDocument::fromJson(arr);
        QVariantMap result = json.toVariant().toMap();

        //Pull level configurations from the json
        hoopLocationX = result["hoopLocationX"].toFloat()/SCALE;
        hoopLocationY = result["hoopLocationY"].toFloat()/SCALE;
        hoopSize = result["hoopSize"].toFloat()/SCALE;
        QResource hoopImage(result["hoopTexture"].toString());
        hoopTexture.loadFromMemory(hoopImage.data(), hoopImage.size(), sf::IntRect());
        rimWidth = result["rimWidth"].toFloat()/SCALE;
        rimHeight = result["rimHeight"].toFloat()/SCALE;
        ballRadius = result["ballRadius"].toFloat()/SCALE;
        leftBound = result["leftBound"].toFloat()/SCALE;
        topBound = result["topBound"].toFloat()/SCALE;
        rightBound = result["rightBound"].toFloat()/SCALE;
        botBound = result["botBound"].toFloat()/SCALE;
        ballLocationX = result["ballLocationX"].toFloat()/SCALE;
        ballLocationY = result["ballLocationY"].toFloat()/SCALE;
        ballWidth = result["ballWidth"].toFloat()/SCALE;
        ballHeight = result["ballHeight"].toFloat()/SCALE;
        ballDensity = result["ballDensity"].toFloat();
        ballFriction = result["ballFriction"].toFloat();
        ballRestitution = result["ballRestitution"].toFloat();
        QResource bgImage(result["bgimg"].toString());
        backgroundTexture.loadFromMemory(bgImage.data(), bgImage.size(), sf::IntRect());

        // setup gravity and the texture of the ball
        b2Vec2 gravity(0.0, result["gravity"].toDouble());
        world = new b2World(gravity);

        QResource ballImage(result["ballPath"].toString());
        ballTexture.loadFromMemory(ballImage.data(), ballImage.size(), sf::IntRect());

        // Parse all of the rectangle objects
        foreach (const QVariant &obj, result["rectObjects"].toList()) {

            QVariantMap rectObj = obj.toMap();

            sf::Texture texture;
            std::string imagePath = rectObj["texturePath"].toString().toStdString();
            if (imagePath != "none"){
                QResource image(rectObj["texturePath"].toString());
                texture.loadFromMemory(image.data(), image.size(), sf::IntRect());
            }

            float xVal = rectObj["xVal"].toFloat()/SCALE;
            float yVal = rectObj["yVal"].toFloat()/SCALE;
            float width = rectObj["width"].toFloat()/SCALE;
            float height = rectObj["height"].toFloat()/SCALE;

            std::string * tag = new std::string(rectObj["tag"].toString().toStdString());

            createRectObject(xVal, yVal, texture, width, height, false, -1, -1, -1, tag, 0.0);
        }


        // Parse all of the polygon objects
        foreach (const QVariant &obj, result["polyObjects"].toList()){

            QVariantMap polyObj = obj.toMap();
            int numVertices = polyObj["size"].toInt();
            b2Vec2* verts = new b2Vec2[numVertices];

            //add the vertices
            int vertIndex = 0;
            foreach (const QVariant &vert, polyObj["vertices"].toList()){
                QVariantMap vertex = vert.toMap();
                verts[vertIndex] = b2Vec2(vertex["x"].toFloat()/SCALE, vertex["y"].toFloat()/SCALE);
                vertIndex = vertIndex + 1;
            }

            float xVal = polyObj["xVal"].toFloat()/SCALE;
            float yVal = polyObj["yVal"].toFloat()/SCALE;
            float density = polyObj["density"].toFloat();
            float restitution = polyObj["restitution"].toFloat();
            float friction = polyObj["friction"].toFloat();
            bool dynamic = polyObj["dynamic"].toBool();
            std::string * tag = new std::string(polyObj["tag"].toString().toStdString());
            sf::Texture texture;
            QResource image(polyObj["texturePath"].toString());
            texture.loadFromMemory(image.data(), image.size(), sf::IntRect());
            createPolyObject(xVal, yVal, verts, numVertices, texture, dynamic, density, friction, restitution, tag);

        }

        // Parse all of the circle objects
        foreach (const QVariant &obj, result["circObjects"].toList()){
            QVariantMap circObj = obj.toMap();
            float xVal = circObj["xVal"].toFloat()/SCALE;
            float yVal = circObj["yVal"].toFloat()/SCALE;
            float width = circObj["width"].toFloat();
            float height = circObj["height"].toFloat();
            float density = circObj["density"].toFloat();
            float restitution = circObj["restitution"].toFloat();
            float friction = circObj["friction"].toFloat();
            bool dynamic = circObj["dynamic"].toBool();
            std::string * tag = new std::string(circObj["tag"].toString().toStdString());
            sf::Texture texture;
            QResource image(circObj["texturePath"].toString());
            texture.loadFromMemory(image.data(), image.size(), sf::IntRect());
            createCircleObject(xVal, yVal, texture, width/SCALE, height/SCALE, dynamic,
                                    density, friction, restitution, tag);
        }

        // Create universal level assets
        launcherType = result["launcherType"].toInt();
        ballIndex = objects.size();
        createBall();
        createHoop();
        createBoundarySensors();
        if(id == 2)
        {
            isGravity = true;
            addText(sf::Vector2f(20, 570), "Gravity" , 20, sf::Color::Magenta, 0.0);
        }
        createAngleLabel();
        createMagnitudeLabel();
        createButtons();

        return;
    }
}


/**
 * @brief Level::~Level
 * Level destructor
 * Author unknown?
 */
Level::~Level() {
    delete world;
    delete launcherPosition;
    for (int i = 0; i < objects.size(); i++) {
        delete objects[i]->getBody()->GetUserData();
        delete objects[i];
    }
}

/**
 * @brief Level::getWorld
 * @return
 * returns pointer to box2d world
 * AARON
 */
b2World * Level::getWorld(){
    return world;
}

/**
 * @brief Level::getLauncherType
 * @return
 * returns launcher type
 * AARON
*/
int Level::getLauncherType(){
    return launcherType;
}


/**
 * @brief Level::getObjects
 * @return
 * returns vector with all of the world objects
 * AARON
 */
std::vector<WorldObject *> Level::getObjects(){
    return objects;
}

/**
 * @brief Level::getHoopLocation
 * @return
 * returns location of the front of the rim
 * AARON
 */
b2Vec2 Level::getHoopLocation(){
    return b2Vec2(hoopLocationX, hoopLocationY);
}

/**
 * @brief Level::getHoopSize
 * @return
 * returns size of the hoop
 * AARON
 */
float Level::getHoopSize(){
    return hoopSize;
}

/**
 * @brief Level::getBallLocationX
 * @return
 * returns x location of the ball spawn point
 * AARON
 */
float Level::getBallLocationX() {
    return ballLocationX;
}

/**
 * @brief Level::getBallLocationY
 * @return
 * returns y location of the ball spawn point
 * AARON
 */
float Level::getBallLocationY() {
    return ballLocationY;
}

/**
 * @brief Level::getLauncherAngle
 * @return
 * returns angle of the launcher
 *
 */
float Level::getLauncherAngle() {
    return launcherAngle;
}

/**
 * @brief Level::getLauncherMagnitude
 * @return
 * returns magnitude of the launcher
 *
 */
float Level::getLauncherMagnitude() {
    return launcherMagnitude;
}

/**
 * @brief Level::createRectObject
 * @param x
 * @param y
 * @param t
 * @param width
 * @param height
 * @param dynamic
 * @param density
 * @param friction
 * @param restitution
 * @param dataTag
 * @param rotationAngle
 * @return
 * creates a rectangle shaped world object, adds it to the vector and also returns it
 * AARON
 */
WorldObject Level::createRectObject(float x, float y, sf::Texture t, float width, float height, bool dynamic,
                        float density, float friction, float restitution, std::string * dataTag, float32 rotationAngle) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    if(dynamic) bodyDef.type = b2_dynamicBody;
    else bodyDef.type = b2_staticBody;
    b2Body * b = world->CreateBody(&bodyDef);
    b->SetUserData(dataTag);
    b->SetTransform(b->GetPosition(), rotationAngle);
    b2PolygonShape shape;
    shape.SetAsBox(width/2, height/2);
    b2FixtureDef fixtureDef;
    if(density != -1) fixtureDef.density = density;
    if(friction!= -1) fixtureDef.friction = friction;
    if(restitution!=-1) fixtureDef.restitution = restitution;
    fixtureDef.shape = &shape;
    b->CreateFixture(&fixtureDef);
    WorldObject * o = new WorldObject(x, y, t, b, false, width, height);
    objects.push_back(o);
    return *o;
}

/**
 * @brief Level::createCircleObject
 * @param x
 * @param y
 * @param t
 * @param width
 * @param height
 * @param dynamic
 * @param density
 * @param friction
 * @param restitution
 * @param dataTag
 * creates a circle shaped world object, and adds it to the vector
 * AARON
 */
void Level::createCircleObject(float x, float y, sf::Texture t, float width, float height, bool dynamic,
                        float density, float friction, float restitution, std::string * dataTag) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    if(dynamic) bodyDef.type = b2_dynamicBody;
    else bodyDef.type = b2_staticBody;
    b2Body * b = world->CreateBody(&bodyDef);
    b->SetUserData(dataTag);
    b2CircleShape shape;
    shape.m_p.Set(0, 0);
    shape.m_radius = width/2;
    b2FixtureDef fixtureDef;
    if(density != -1) fixtureDef.density = density;
    if(friction!= -1) fixtureDef.friction = friction;
    if(restitution!=-1) fixtureDef.restitution = restitution;
    fixtureDef.shape = &shape;
    b->CreateFixture(&fixtureDef);
    WorldObject * o = new WorldObject(x, y, t, b, true, width, height);
    objects.push_back(o);
}

/**
 * @brief Level::createPolyObject
 * @param vertices
 * @param numVertices
 * @param t
 * @param dynamic
 * @param density
 * @param friction
 * @param restitution
 * @param dataTag
 * creates a polygon object with location x,y and vertices array is each vertex' position offset from the center
 * BY AARON
 */
void Level::createPolyObject(float x, float y, b2Vec2* vertices, int numVertices, sf::Texture t, bool dynamic, float density, float friction, float restitution, std::string * dataTag) {
    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    if(dynamic) bodyDef.type = b2_dynamicBody;
    else bodyDef.type = b2_staticBody;
    b2Body * b = world->CreateBody(&bodyDef);
    b->SetUserData(dataTag);
    b2PolygonShape shape;
    shape.Set(vertices, numVertices);
    b2FixtureDef fixtureDef;
    if(density != -1) fixtureDef.density = density;
    if(friction!= -1) fixtureDef.friction = friction;
    if(restitution!=-1) fixtureDef.restitution = restitution;
    fixtureDef.shape = &shape;
    b->CreateFixture(&fixtureDef);
    WorldObject * o = new WorldObject(x, y, vertices, numVertices, t, b);
    objects.push_back(o);
}

/**
 * @brief Level::createHoop
 * helper method to build the hoop and backboard and it's sensors
 * AARON
 */
void Level::createHoop() {
    sf::Texture backRimTexture;
    std::string * rimTag = new std::string("rim");

    //create objects for rim
    createCircleObject(hoopLocationX+hoopSize/2, hoopLocationY, backRimTexture, rimWidth, rimHeight, false, -1, -1, -1, rimTag);
    createCircleObject(hoopLocationX-hoopSize/2, hoopLocationY, hoopTexture, rimWidth, rimHeight, false, -1, -1, -1, rimTag);

    //TODO CREATE BACKBOARD?
    b2Vec2 * backBoardVerts = new b2Vec2[4];
    backBoardVerts[0] = b2Vec2(BACKBOARD_OFFSET_X, BACKBOARD_OFFSET_Y);
    backBoardVerts[1] = b2Vec2(BACKBOARD_OFFSET_X+BACKBOARD_WIDTH, BACKBOARD_OFFSET_Y);
    backBoardVerts[2] = b2Vec2(BACKBOARD_OFFSET_X+BACKBOARD_WIDTH, BACKBOARD_OFFSET_Y-BACKBOARD_HEIGHT);
    backBoardVerts[3] = b2Vec2(BACKBOARD_OFFSET_X, BACKBOARD_OFFSET_Y- BACKBOARD_HEIGHT);
    QResource backBoardImage(":/textures/textures/brickTexture.png");
    sf::Texture backBoardTexture;
    backBoardTexture.loadFromMemory(backBoardImage.data(), backBoardImage.size(), sf::IntRect());
    std::string * tag = new std::string("backboard");
    createPolyObject(hoopLocationX+hoopSize/2, hoopLocationY, backBoardVerts, 4, backBoardTexture, false, -1, -1, -1, tag);

    //Create Sensors
    //top
    b2BodyDef bodyDefTop;
    bodyDefTop.position.Set(hoopLocationX, hoopLocationY);
    bodyDefTop.type = b2_staticBody;
    b2Body * topBody = world->CreateBody(&bodyDefTop);
    std::string * topTag = new std::string("topSens");
    topBody->SetUserData(topTag);
    b2PolygonShape shapeTop;
    shapeTop.SetAsBox(hoopSize/2, rimHeight/2);
    b2FixtureDef fixDefTop;
    fixDefTop.shape = &shapeTop;
    fixDefTop.isSensor = true;
    topBody->CreateFixture(&fixDefTop);

    //bottom
    b2BodyDef bodyDefBot;
    bodyDefBot.position.Set(hoopLocationX, hoopLocationY+ballRadius*2);
    bodyDefBot.type = b2_staticBody;
    b2Body * botBody = world->CreateBody(&bodyDefBot);
    std::string * botTag = new std::string("botSens");
    botBody->SetUserData(botTag);
    b2PolygonShape shapeBot;
    shapeBot.SetAsBox(hoopSize/2, rimHeight/2);
    b2FixtureDef fixDefBot;
    fixDefBot.shape = &shapeBot;
    fixDefBot.isSensor = true;
    botBody->CreateFixture(&fixDefBot);
}

/**
 * @brief Level::createBoundarySensors
 * creates sensors for game world boundaries
 * AARON
 */
void Level::createBoundarySensors() {
    //create Sensors

    //top
    b2BodyDef topBodyDef;
    topBodyDef.position.Set(leftBound+(rightBound - leftBound)/2, topBound);
    topBodyDef.type = b2_staticBody;
    b2Body * topBody = world->CreateBody(&topBodyDef);
    std::string * topTag = new std::string("topBound");
    topBody->SetUserData(topTag);
    b2PolygonShape shapeTop;
    shapeTop.SetAsBox((rightBound - leftBound)/2, BOUNDARY_WIDTH/2);
    b2FixtureDef fixtureDefTop;
    fixtureDefTop.shape = &shapeTop;
    fixtureDefTop.isSensor = true;
    topBody->CreateFixture(&fixtureDefTop);

    //bot
    b2BodyDef botBodyDef;
    botBodyDef.position.Set(leftBound+(rightBound - leftBound)/2, botBound);
    botBodyDef.type = b2_staticBody;
    b2Body * botBody = world->CreateBody(&botBodyDef);
    std::string * botTag = new std::string("botBound");
    botBody->SetUserData(botTag);
    b2PolygonShape shapeBot;
    shapeBot.SetAsBox((rightBound - leftBound)/2, BOUNDARY_WIDTH/2);
    b2FixtureDef fixtureDefBot;
    fixtureDefBot.shape = &shapeBot;
    fixtureDefBot.isSensor = true;
    botBody->CreateFixture(&fixtureDefBot);

    //left
    b2BodyDef leftBodyDef;
    leftBodyDef.position.Set(leftBound, topBound+(botBound-topBound)/2);
    leftBodyDef.type = b2_staticBody;
    b2Body * leftBody = world->CreateBody(&leftBodyDef);
    std::string * leftTag = new std::string("leftBound");
    leftBody->SetUserData(leftTag);
    b2PolygonShape shapeLeft;
    shapeLeft.SetAsBox(BOUNDARY_WIDTH/2, (botBound - topBound)/2);
    b2FixtureDef fixtureDefLeft;
    fixtureDefLeft.shape = &shapeLeft;
    fixtureDefLeft.isSensor = true;
    leftBody->CreateFixture(&fixtureDefLeft);

    //right
    b2BodyDef rightBodyDef;
    rightBodyDef.position.Set(rightBound, topBound+(botBound-topBound)/2);
    rightBodyDef.type = b2_staticBody;
    b2Body * rightBody = world->CreateBody(&rightBodyDef);
    std::string * rightTag = new std::string("rightBound");
    rightBody->SetUserData(rightTag);
    b2PolygonShape shapeRight;
    shapeRight.SetAsBox(BOUNDARY_WIDTH/2, (botBound - topBound)/2);
    b2FixtureDef fixtureDefRight;
    fixtureDefRight.shape = &shapeRight;
    fixtureDefRight.isSensor = true;
    rightBody->CreateFixture(&fixtureDefRight);
}

/**
 * @brief Level::getBallIndex
 * @return
 * returns ball's index in the objects vector
 * AARON
 */
int Level::getBallIndex() {
    return ballIndex;
}

/**
 * @brief Level::createBall
 * creates the levels ball, and puts it in the objects vector
 * AARON
 */
void Level::createBall() {
    b2BodyDef bodyDef;
    bodyDef.position.Set(ballLocationX, ballLocationY);
    bodyDef.type = b2_dynamicBody;
    b2Body * b = world->CreateBody(&bodyDef);
    std::string * dataTag = new std::string("primaryBall");
    b->SetUserData(dataTag);
    b2CircleShape shape;
    shape.m_p.Set(0, 0);
    shape.m_radius = ballRadius;
    b2FixtureDef fixtureDef;
    fixtureDef.density = ballDensity;
    fixtureDef.friction = ballFriction;
    fixtureDef.restitution = ballRestitution;
    fixtureDef.shape = &shape;
    b->CreateFixture(&fixtureDef);
    if(levelId >100) b->SetAwake(false);
    WorldObject * o = new WorldObject(ballLocationX, ballLocationY, ballTexture, b, true, ballWidth, ballHeight);
    if (firstBall){
//        qDebug() << "here";
        objects.push_back(o);
        firstBall = false;
    }
    else {
        objects[ballIndex] = o;
    }
}


/**
 * @brief Level::addText
 * This methods takes in text information and adds it to the textList for the level.
 * @param position
 * @param displayText
 * @param fontSize
 * @param color
 * STONE AND AARON
 */
void Level::addText(sf::Vector2f position, std::string displayText, int fontSize, sf::Color color, float rotation){
    QResource fontSource(":/textures/textures/RobotoCondensed-Regular.ttf");
    font.loadFromMemory(fontSource.data(),fontSource.size());
    sf::Text * text = new sf::Text(displayText, font);
    text->setCharacterSize(fontSize);
    text->setStyle(sf::Text::Bold);
    text->setColor(color);
    text->setPosition(position);
    text->setRotation(rotation);
    textList.push_back(text);
}

/**
 * @brief Level::getTextList
 * gets all the text to be displayed for the level.
 * @return
 * Returns a vector list of all the text objects in the level.
 * STONE AND AARON
 */
std::vector<sf::Text *> Level::getTextList(){
    return this->textList;
}

/**
 * @brief Level::addTextBox
 * adds a textbox to the vector
 * @param position
 * @param displayText
 * @param fontSize
 * @param color
 * STONE AND AARON
 */
void Level::addTextBox(sf::Vector2f position, std::string displayText, int fontSize, sf::Color color, bool hasContinueButton) {
    TextBox * textBox = new TextBox(0, position, displayText, fontSize , color, hasContinueButton,false);
    textBoxes.push_back(textBox);
}

/**
 * @brief Level::getTextBoxes
 * gets all the textboxes for a level
 * @return
 * returns the textboxes
 * STONE AND AARON
 */
std::vector<TextBox *> Level::getTextBoxes() {
    return textBoxes;
}

/**
 * @brief Level::createAngleLabel
 * helper creates angle label
 * Aaron
 */
void Level::createAngleLabel() {
    if(launcherType != NONE) addText(sf::Vector2f(ANGLE_LABEL_X, ANGLE_LABEL_Y), "Angle (degs)" , 20, sf::Color::Magenta, 0.0);
    else addText(sf::Vector2f(ANGLE_LABEL_X, ANGLE_LABEL_Y), "Y Pos" , 20, sf::Color::Black, 0.0);
}

/**
 * @brief Level::createMagnitudeLabel
 * helper creates Magnitude label
 * Aaron
 */
void Level::createMagnitudeLabel() {
    if(launcherType == CANNON) {
        addText(sf::Vector2f(MAGNITUDE_LABEL_X, MAGNITUDE_LABEL_Y), "Force (N)" , 20, sf::Color::Magenta, 0.0);
    }
    else if(launcherType == CATAPULT) {
        addText(sf::Vector2f(MAGNITUDE_LABEL_X, MAGNITUDE_LABEL_Y), "Torque (N m)" , 20, sf::Color::Magenta, 0.0);
    }
    else if(launcherType == TREBUCHET) {
        addText(sf::Vector2f(MAGNITUDE_LABEL_X, MAGNITUDE_LABEL_Y), "Mass (Kg)" , 20, sf::Color::Black, 0.0);
    }
    else if(launcherType == NONE) {
        addText(sf::Vector2f(MAGNITUDE_LABEL_X, MAGNITUDE_LABEL_Y), "X Pos" , 20, sf::Color::Black, 0.0);
    }
}

/**
 * @brief Level::createButtons
 * creates and sets game control buttons
 * AARON, JORDAN, STONE
 */
void Level::createButtons() {
    QResource fireImage(":/textures/textures/fire2.png");
    fireTexture.loadFromMemory(fireImage.data(), fireImage.size(), sf::IntRect());
    fireButton.setTexture(fireTexture);
    fireButton.setPosition(sf::Vector2f(FIRE_POS_X, FIRE_POS_Y));

    QResource newBallImage(":/textures/textures/newBallButton2.png");
    newBallTexture.loadFromMemory(newBallImage.data(), newBallImage.size(), sf::IntRect());
    newBallButton.setTexture(newBallTexture);
    newBallButton.setPosition(sf::Vector2f(NEW_BALL_X, NEW_BALL_Y));

    QResource exitBallImage(":/textures/textures/exitButtonSmall.png");
    exitButtonTexture.loadFromMemory(exitBallImage.data(), exitBallImage.size(), sf::IntRect());
    exitButton.setTexture(exitButtonTexture);
    exitButton.setPosition(sf::Vector2f(EXIT_POS_X, EXIT_POS_Y));

    buttons.push_back(fireButton);
    buttons.push_back(newBallButton);
    buttons.push_back(exitButton);
}

std::vector<sf::Sprite> Level::getButtons(){
    return buttons;
}

bool Level::isFireClicked(float x, float y){
    return (fireButton.getGlobalBounds().contains(x, y));
}

bool Level::isPlayClicked(float x, float y){
    return (playButton.getGlobalBounds().contains(x, y));
}

bool Level::isExitClicked(float x, float y){
    return (exitButton.getGlobalBounds().contains(x,y));
}

bool Level::needNewBall(float x, float y){
    return (newBallButton.getGlobalBounds().contains(x, y));
}

/**
 * @brief Level::getLevelId
 * @return
 * returns id of current level
 * AARON
 */
int Level::getLevelId() {
    return levelId;
}

/**
 * @brief Level::resetBall
 * @param cannonAngle
 * resets location and velocity of ball
 * NATHAN, AARON, STONE
 */
void Level::resetBall(double cannonAngle)
{
    b2Body* b = objects[ballIndex]->getBody();
    if(levelId != -2) b->SetAwake(false);
    b->SetLinearVelocity(b2Vec2(0,0));
    b->SetAngularVelocity(0);
    float offSetX = 0;
    float offSetY = 0;
    if(launcherType == CANNON){
        offSetX = cos(cannonAngle*b2_pi / 180)*CANNON_OFFSET;
        offSetY = -sin(cannonAngle*b2_pi / 180)*CANNON_OFFSET;
    }
    objects[ballIndex]->getBody()->SetTransform(b2Vec2(ballLocationX+offSetX,ballLocationY+offSetY),0);
}

void Level::resetBall(){
    objects[ballIndex]->getBody()->SetTransform(b2Vec2(ballLocationX,ballLocationY),0);
}

/**
 * @brief Level::getBackgroundTexture
 * returns background texture
 * by Aaron
 * @return
 */
sf::Texture Level::getBackgroundTexture(){
    return backgroundTexture;
}

/**
 * @brief Level::displayLessons
 * Method written by Cole, and Stone.
 * This method displays the lessons on the lessonSelect screen depending
 * on the maxLevel of the user. Greyed out if they hanvt gotten that far yet
 * full color hd if they have.
 * @param maxLevel
 * Max level of the current user.
 * TRILL.
 */
void Level::displayLessons(int maxLevel){
    //Texture for planks
    QResource plankton(":/textures/textures/wood-texture-blackwhite.png");
    QResource plank(":/textures/textures/wood-texture.png");
    wbWoodTexture.loadFromMemory(plankton.data(),plankton.size(),sf::IntRect(0,0,250,40));
    woodTexture.loadFromMemory(plank.data(), plank.size(), sf::IntRect(0,0,250,40));
    std::string * levelTags[6] = {new std::string("level1"),
                                  new std::string("level2"),
                                  new std::string("level3"),
                                  new std::string("level4"),
                                  new std::string("level5"),
                                  new std::string("level6")};

    //Values for the for loop to display the lessons in the correct spot.
    sf::Vector2f textLocationArray[6] = {sf::Vector2f(130,50.0),sf::Vector2f(440,325.0),sf::Vector2f(125,430.0),
                                     sf::Vector2f(435,575.0),sf::Vector2f(1052,338.0),sf::Vector2f(838,480.0)};
    float rectLocation[12] = {190.0/SCALE,100.0/SCALE,500.0/SCALE, 300.0/SCALE,140.0/SCALE, 510.0/SCALE,
                              500.0/SCALE, 600.0/SCALE,1100.0/SCALE, 300.0/SCALE,900.0/SCALE, 490.0/SCALE};
    float rectRotationArray[6] = {0.4,-0.8,1.1,0.0,-1.1,-0.2};
    float textRotation[6] = {23.0,-45.0,62.0,0.0,-61.8,-12.0};
    float restituionArray[6] = {-1,-1,1,2,-1,3.2};
    sf::Color colorArray[6] = {sf::Color::Yellow, sf::Color::Cyan, sf::Color::Green,
                               sf::Color::Red, sf::Color::Magenta, sf::Color::White};

    for(int i =0; i < 6; i++){
        std::stringstream displayText;
        displayText << "Lesson " << i+1;

        int rectLocationCount = i*2;
        if(maxLevel >= i+1){
            WorldObject temp = createRectObject(rectLocation[rectLocationCount], rectLocation[rectLocationCount+1], woodTexture, 250.0/SCALE, 40.0/SCALE, false, -1, -1, restituionArray[i], levelTags[i], rectRotationArray[i]);
            lessons[i].setTexture(temp.getTexture());
            lessons[i].setOrigin(temp.getWidth()*SCALE/2,temp.getHeight()*SCALE/2);
            lessons[i].setPosition(temp.getBody()->GetPosition().x*SCALE,temp.getBody()->GetPosition().y*SCALE);
            lessons[i].setRotation(180/b2_pi *temp.getBody()->GetAngle());
            addText(textLocationArray[i], displayText.str() , 36, colorArray[i], textRotation[i]);
        }else{
            createRectObject(rectLocation[rectLocationCount], rectLocation[rectLocationCount+1], wbWoodTexture, 250.0/SCALE, 40.0/SCALE, false, -1, -1, restituionArray[i], levelTags[i], rectRotationArray[i]);
            addText(textLocationArray[i], displayText.str(), 36, sf::Color::White, textRotation[i]);
        }
        displayText.flush();
    }
}

bool Level::isLessonOneClicked(float xPos, float yPos)
{
    return (lessons[0].getGlobalBounds().contains(xPos,yPos));
}


bool Level::isLessonTwoClicked(float xPos, float yPos)
{
    return (lessons[1].getGlobalBounds().contains(xPos,yPos));
}

bool Level::isLessonThreeClicked(float xPos, float yPos)
{
    return (lessons[2].getGlobalBounds().contains(xPos,yPos));
}

bool Level::isLessonFourClicked(float xPos, float yPos)
{
    return (lessons[3].getGlobalBounds().contains(xPos,yPos));
}

bool Level::isLessonFiveClicked(float xPos, float yPos)
{
    return (lessons[4].getGlobalBounds().contains(xPos,yPos));
}

bool Level::isLessonSixClicked(float xPos, float yPos)
{
    return (lessons[5].getGlobalBounds().contains(xPos,yPos));
}

void Level::changeBallLocation(double x, double y){
    this->ballLocationX = x;
    this->ballLocationY = y;
    this->resetBall(NULL);
}

void Level::addUserName(std::string userName)
{
   addText(sf::Vector2f(760, 200), "Hello\n" + userName + "!", 40, sf::Color::Black, 0.0);
}

bool Level::isGravityLevel()
{
    std::cout << isGravity << std::endl;
    return isGravity;
}

void Level::changeGravity(double newGravity)
{
    world->SetGravity(b2Vec2(0.0, newGravity));
}
