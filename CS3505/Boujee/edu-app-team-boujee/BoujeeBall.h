#ifndef BOUJEEBALL_H
#define BOUJEEBALL_H

#include <QCloseEvent>
#include <QMainWindow>
#include <Box2D/Box2D.h>
#include "WorldObject.h"
#include "SFML/Network.hpp"
#include "level.h"
#include "GameWorld.h"
#include "ContactListener.h"
#include <SFML/Graphics.hpp>
#include "game.h"
#include <string>
#include "qsfmlcanvas.h"
#include "mycanvas.h"
#include <QTimer>
#include <sstream>
#include <iostream>
#include <queue>
#include <loginform.h>
#include "SFML/Audio.hpp"
#include "levelselector.h"
#include <QMouseEvent>
#include "QString"
#include "networkmonitor.h"
#include "soundsystem.h"
#include <QUrl>
#include <QShortcut>

namespace Ui {
class BoujeeBall;
}

class BoujeeBall : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoujeeBall(QWidget *parent = 0);
    bool didItFail();
    ~BoujeeBall();

    //Vector holding all world objects
    std::vector<WorldObject *> objects;

    //hotkeys
    QShortcut* fire1Short;
    QShortcut* fire2Short;
    QShortcut* resetShort;
    QShortcut* leaveShort;

signals:
    void accessGranted();
    void accessDenied(QString error);
    void fireButtonPressed();

private:
    QString currentUser;
    bool failed;
    int userScore;
    int lastLevel;
    Ui::BoujeeBall *ui;
    b2World *world;
    Level * l;
    GameWorld * gw;
    NetworkMonitor * nw;
    SoundSystem * ss;
    ContactListener * contactListenerInstance;
    std::queue<b2Body *> bodyDeleteQueue;
    bool ballToBeCreated;
    bool multiplayer;

    //widgets
    LoginForm * log;
    levelSelector * ls;
    Game * game;

    MyCanvas* SFMLView;
    int gameState;

    /*****SFML sprite buttons*****/
    //game buttons
    sf::Texture fireTexture;
    sf::Sprite fireButton;
    constexpr static float FIRE_POS_X = 250.0;
    constexpr static float FIRE_POS_Y = 500.0;

    sf::Sprite upButton;
    sf::Sprite downButton;

    sf::Texture newBallTexture;
    sf::Sprite newBallButton;
    constexpr static float NEW_BALL_X = 700.0;
    constexpr static float NEW_BALL_Y = 0.0;

    sf::Sprite continueButton;
    sf::Sprite facebookButton;

    //success textbox constants
    constexpr static float SUCCESS_MESSAGE_X = 100.0;
    constexpr static float SUCCESS_MESSAGE_Y = 100.0;
    constexpr static int SUCCESS_FONT_SIZE = 30;
    sf::Color SUCCESS_FONT_COLOR = sf::Color::Green;
    /********************************************/


    // Open a listener on a port
    sf::TcpListener listener;
    // Talk over a TCP socket
    sf::TcpSocket client;
    bool connected;
    constexpr static float SCALE = 30;

    //game state constants
    constexpr static int LOGIN_STATE = 0;
    constexpr static int GAME_MENU_STATE = 1;
    constexpr static int LEVEL_SELECT_STATE = 2;
    constexpr static int GAME_WORLD_STATE = 3;
    constexpr static int LESSON_STATE = 4;
    constexpr static int SUCCESS_STATE = 5;

    //launcher type constants
    constexpr static int CANNON = 0;
    constexpr static int CATAPULT = 1;
    constexpr static int TREBUCHET = 2;
    constexpr static int NONE = 3;

    //Timer to fire off for each game step
    QTimer timer;

//helper methods
    int getLevel(QString name);
    void displayTextBox();
    void setUpConnections();
    void setUpGameConnections();
    void musicSelect(int level);

protected:
    virtual void mousePressEvent(QMouseEvent *e);

public slots:
    //connecting user to server
    void handleAttemptLogin();
    void handleUpdateCurrentUser(std::string);
    void handleUpdateCurrentLevel(int);
    void handleUpdateNotification(std::string);
    void handleSignOut();

    //handle game controls
    void handleLauncherAngleChange(double);
    void handleChangeBallLocation(double,double);

    //connecting teacher to server
    void handleTeacherCreate(QString username, QString password);
    void handleTeacherUpdateLevel(QString username, int level);
    void handleTeacherDeleteLevel(QString username);

    void openHtml();
    void openWebPage();

private slots:
    void errorMsg(std::string msg);
    void onExit();
    //handle successful shot
    void onSuccess(std::string message, int score);

    //called to updaate world on timer fire
    void updateWorld();

    //Handle ball going out of bounds
    void onBallOutOfBounds();

    //load different screens
    void loadLevelScreen(int levelId);
    void loadLevelSelect();
    void loadLessonScreen(int);
    void loadLoginScreen(bool loadNetwork);

    void choseSingleMode();
    void choseMultiMode();
    void choseGuest();
    void resetLevel();
    void fireLevelLauncher();
    void changeGravity(double);

signals:
    void scoreToGame(int);
    void selectMode();
    void ballReset();
    void resetConnection();

};

#endif // BOUJEEBALL_H
