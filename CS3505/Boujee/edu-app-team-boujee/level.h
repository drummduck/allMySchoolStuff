#ifndef LEVEL_H
#define LEVEL_H
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "WorldObject.h"
#include "SFML/Audio.hpp"
#include "textbox.h"
#include "GameWorld.h"
#include <QString>
#include <sstream>
#include <math.h>
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

class Level
{

    int levelId;
    b2World * world;
    int launcherType;
    std::vector<sf::Sprite> buttons;
    b2Vec2 * launcherPosition;
    float hoopSize;
    float hoopLocationX;
    float hoopLocationY;
    float gravityStrength;
    bool firstBall;
    sf::Texture backgroundTexture;
    //vector of objects
    std::vector<WorldObject *> objects;
    float rimWidth;
    float rimHeight;
    float ballRadius;
    float leftBound;
    float rightBound;
    float topBound;
    float botBound;
    float ballLocationX;
    float ballLocationY;
    float ballWidth;
    float ballHeight;
    float ballDensity;
    float ballRestitution;
    float ballFriction;
    float launcherAngle;
    float launcherMagnitude;
    sf::Texture ballTexture;
    sf::Texture hoopTexture;
    int ballIndex;
    constexpr static float SCALE = 30;
    constexpr static float BOUNDARY_WIDTH = 5;
    std::vector<sf::Text *> textList;
    std::vector<TextBox *> textBoxes;
    bool isGravity;

    

    //launcher type constants
    constexpr static int CANNON = 0;
    constexpr static int CATAPULT = 1;
    constexpr static int TREBUCHET = 2;
    constexpr static int NONE = 3;

    //Label location constants
    constexpr static float ANGLE_LABEL_X = 10.0;
    constexpr static float ANGLE_LABEL_Y = 630.0;
    constexpr static float MAGNITUDE_LABEL_X = 10.0;
    constexpr static float MAGNITUDE_LABEL_Y = 600.0;

    //cannon constant length
    constexpr static float CANNON_OFFSET = 100/SCALE;

    //Backboard constants
    constexpr static float BACKBOARD_HEIGHT = 200/SCALE;
    constexpr static float BACKBOARD_WIDTH = 30/SCALE;
    constexpr static float BACKBOARD_OFFSET_X = 10/SCALE;
    constexpr static float BACKBOARD_OFFSET_Y = 35/SCALE;

    /*****SFML sprite buttons*****/
    //game buttons
    sf::Texture fireTexture;
    sf::Sprite playButton;
    sf::Sprite fireButton;
    constexpr static float FIRE_POS_X = 300.0;
    constexpr static float FIRE_POS_Y = 550.0;

    //exit level buttons
    sf::Texture exitButtonTexture;
    sf::Sprite exitButton;
    constexpr static float EXIT_POS_X = 10.0;
    constexpr static float EXIT_POS_Y = 10.0;

    /******SFML lesson buttons ****/
    //lesson buttons
    sf::Texture woodTexture; sf::Texture wbWoodTexture;
    sf::Sprite lessons[6];

    /*******Up down Buttons*****/
    sf::Sprite upButton;
    sf::Sprite downButton;

    sf::Texture newBallTexture;
    sf::Sprite newBallButton;
    constexpr static float NEW_BALL_X = 450.0;
    constexpr static float NEW_BALL_Y = 550.0;

    //I don't like this here, but I kinda had to put it here temporarily
    sf::Font font;

public:
    //Constructs a level and parses by id
    Level(int id);

    //Destructor
    ~Level();

    //returns a pointer to the parsed game world
    b2World * getWorld();

    //returns the level's objects as vector
    std::vector<WorldObject *> getObjects();

    //returns location of the front of the rim
    b2Vec2 getHoopLocation();

    //returns size of the hoop
    float getHoopSize();

    //returns ball location x
    float getBallLocationX();

    //returns ball location y
    float getBallLocationY();

    //create new ball in objects
    void createBall();

    //gets index of ball in objects
    int getBallIndex();

    float getLauncherAngle();

    float getLauncherMagnitude();

    //Gets all the texts for level.
    std::vector<sf::Text *> getTextList();

    //Gets all the textboxes for the level
    std::vector<TextBox *> getTextBoxes();

    //returns launcher type
    int getLauncherType();

    //returns background texture
    sf::Texture getBackgroundTexture();

    void displayLessons(int maxLevel);

    std::vector<sf::Sprite> getButtons();

    bool isFireClicked(float x, float y);

    bool isPlayClicked(float x, float y);

    bool needNewBall(float x, float y);

    bool isExitClicked(float x, float y);

    void resetBall(double cannonAngle);

    void resetBall();

    void changeBallLocation(double x, double y);

    //gets id
    int getLevelId();

    bool isLessonOneClicked(float, float);
    bool isLessonTwoClicked(float, float);
    bool isLessonThreeClicked(float, float);
    bool isLessonFourClicked(float, float);
    bool isLessonFiveClicked(float, float);
    bool isLessonSixClicked(float, float);
    bool isGravityLevel();
    void changeGravity(double);
    void addUserName(std::string);


private:
    //creates a gameworld Object with a rectangle shape
    WorldObject createRectObject(float x, float y, sf::Texture t, float width, float height, bool dynamic,
                       float density, float friction, float restitution, std::string * dataTag, float32 rotationAngle);
    //creates a gameworld Object with a circle shape
    void createCircleObject(float x, float y, sf::Texture t, float width, float height, bool dynamic,
                       float density, float friction, float restitution, std::string * dataTag);
    //creates gameworld Object with poly shape
    void createPolyObject(float x, float y, b2Vec2* vertices, int numVertices, sf::Texture t, bool dynamic,
                          float density, float friction, float restitution, std::string * dataTag);

    //creates the hoop gameworld objects
    void createHoop();

    //creates level boundaries
    void createBoundarySensors();

    //adds sf::text to textVector.
    void addText(sf::Vector2f position, std::string displayText, int fontSize, sf::Color color, float rotation);

    //adds a textbox to vector
    void addTextBox(sf::Vector2f position, std::string displayText, int fontSize, sf::Color color, bool hasContinueButton);

    //adds magnitude label to textVector
    void createMagnitudeLabel();

    //adds Angle Label to text vector
    void createAngleLabel();

    void createButtons();
};

#endif // LEVEL_H
