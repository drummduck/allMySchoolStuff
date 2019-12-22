#include "BoujeeBall.h"
#include "ui_BoujeeBall.h"
#include "loginform.h"
#include <QLCDNumber>
#include <QMessageBox>
#include <QString>
#include <QObject>
#include <QTime>
#include <QShortcut>
#include <QDesktopServices>
#include <QUrl>
#include <QKeySequence>
#include <QDesktopServices>

/**
 * @brief BoujeeBall::BoujeeBall
 * @param parent
 * boujee ball widget constructor
 */
BoujeeBall::BoujeeBall(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoujeeBall)
{

    ui->setupUi(this);

    this->loadLoginScreen(true);
    this->setUpConnections();

    //setup hotkeys
    fire1Short = new QShortcut(QKeySequence(Qt::Key_Space), this, SLOT(fireLevelLauncher()));
    fire2Short = new QShortcut(QKeySequence(Qt::Key_Enter), this, SLOT(fireLevelLauncher()));
    resetShort = new QShortcut(QKeySequence(Qt::Key_E), this, SLOT(resetLevel()));
    leaveShort = new QShortcut(QKeySequence(Qt::Key_Escape), this, SLOT(onExit()));

    //disable hotkeys
    fire1Short->setEnabled(false);
    fire2Short->setEnabled(false);
    resetShort->setEnabled(false);
    leaveShort->setEnabled(false);
}

BoujeeBall::~BoujeeBall()
{
    delete ui;
    delete fire1Short;
    delete fire2Short;
    delete resetShort;
    delete leaveShort;
}

void BoujeeBall::loadLoginScreen(bool loadNetwork){
    //creates sprite buttons
    if(loadNetwork){
        nw = new NetworkMonitor();
    }
    gameState = LOGIN_STATE;
    l = new Level(-1);
    world = l->getWorld();
    contactListenerInstance = new ContactListener();
    world->SetContactListener(contactListenerInstance);
    objects = l->getObjects();
    gw = new GameWorld();
    ss = new SoundSystem();
    gw->ball = objects[l->getBallIndex()]->getBody();

    //ball does not need to be created
    ballToBeCreated = false;

    // Create a SFML view inside the main frame
    //Create widgets
    log = new LoginForm();
    ls = new levelSelector();
    //    game = new Game();


    this->ui->widgetLayout->addWidget(log);
    SFMLView = new MyCanvas(log, QPoint(0, 0), QSize(1280, 720), l->getObjects());
    SFMLView->setBackground(l->getBackgroundTexture());
    SFMLView->setFramerateLimit(60);
    SFMLView->show();

    timer.start(1000/60);

    log->displayComponents();

    QPixmap bkgnd(":/textures/textures/beautiful-mountains-wallpaper-7.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->ui->centralWidget->setPalette(palette);
    failed = false;
    ss->playLoginMusic();



}

/**
 * @brief BoujeeBall::didItFail
 * This method is to be used in the constructor. If something bad happens on initilization set failed = true
 * and return and application will exit gracefully.
 * @return
 * Returns if initialization failed.
 */
bool BoujeeBall::didItFail(){
    return failed;
}

void BoujeeBall::onExit(){
    //disable hotkeys
    fire1Short->setEnabled(false);
    fire2Short->setEnabled(false);
    resetShort->setEnabled(false);
    leaveShort->setEnabled(false);

    gameState = SUCCESS_STATE;
}

/**
 * @brief BoujeeBall::onSuccess
 * @param message
 * @param score
 * displays success textbox and plays noise when basket has been made
 * AARON AND STONE
 */
void BoujeeBall::onSuccess(std::string message, int score) {
    if(gameState == GAME_WORLD_STATE)
    {
        userScore = score;
        emit scoreToGame(userScore);
        if((l->getLevelId()-100) >= this->lastLevel && this->currentUser.toStdString() != "GUEST"){
            this->handleUpdateCurrentLevel((l->getLevelId()-100) +1);
        }

        //If it is the swoosh
        if(message == "SWOOSH!"){
            ss->playBallin();
        }else{
            ss->playYay();
        }

        gameState = SUCCESS_STATE;
        std::string successMessage = message + "\nScore: ";
        successMessage += std::to_string(score);
        TextBox * successBox = new TextBox(this, sf::Vector2f(SUCCESS_MESSAGE_X, SUCCESS_MESSAGE_Y), successMessage, SUCCESS_FONT_SIZE, SUCCESS_FONT_COLOR, true,true);
        continueButton = successBox ->getContinueButton();
        facebookButton = successBox ->getFacebookButton();
        SFMLView->updateCurrentTextBox(successBox);
    }

}

/**
 * @brief BoujeeBall::updateWorld
 * Handles b2world step
 * AARON
 */
void BoujeeBall::updateWorld() {
    timer.stop();
    world->Step(1/20.0, 8, 3);

    if(ballToBeCreated) {
        //Reset the ball when the angle gets changed, else reset ball at origin for level select.
        if(gameState ==GAME_WORLD_STATE){
            l->resetBall(gw->getLauncherAngle());
        }
        else if (gameState != SUCCESS_STATE) l->resetBall(0.0);
        gw->onBallOut();
        ballToBeCreated = false;
    }
    timer.start();
}

/**
 * @brief BoujeeBall::onBallOutOfBounds
 * handles process when ball is signalled out of bounds
 * AARON
 */
void BoujeeBall::onBallOutOfBounds() {
    ballToBeCreated = true;
}

/**
 * @brief BoujeeBall::loadLevelScreen
 * @param levelId
 * Takes in level id and loads screen w/ that level
 * AARON and others
 */
void BoujeeBall::loadLevelScreen(int levelId) {

    game = new Game();


    QObject::connect(this, SIGNAL(scoreToGame(int)), game, SLOT(updateScore(int)));
    QObject::connect(game->getAngleSpinBox(), SIGNAL(valueChanged(double)), gw, SLOT(changeLauncherAngle(double)));
    QObject::connect(game->getMagnitudeSpinBox(), SIGNAL(valueChanged(double)), gw, SLOT(changeLauncherMagnitude(double)));
    if (levelId == 102)
    {
    QObject::connect(game->getGravitySpinBox(), SIGNAL(valueChanged(double)), this, SLOT(changeGravity(double)));
    }
    //enable hotkeys
    fire1Short->setEnabled(true);
    fire2Short->setEnabled(true);
    resetShort->setEnabled(true);
    leaveShort->setEnabled(true);

    ui->widgetLayout->addWidget(game);
    l = new Level(levelId);
    world = l->getWorld();
    objects = l->getObjects();
    world->SetContactListener(contactListenerInstance);
    gw->ball = objects[l->getBallIndex()]->getBody();
    gw->setLauncherType(l->getLauncherType());
    gw->changeLauncherAngle(0.0);
    gw->changeLauncherMagnitude(0.0);
    gw->setBallNotInFlight();
    l->resetBall(gw->getLauncherAngle());



    gameState = GAME_WORLD_STATE;

    SFMLView = new MyCanvas(game, QPoint(0, 0), QSize(1280, 720), l->getObjects());
    SFMLView->setFramerateLimit(60);
    SFMLView->setTexts(l->getTextList());
    if(l->getTextBoxes().size() > 0) SFMLView->updateCurrentTextBox(l->getTextBoxes()[0]);
    else SFMLView->updateCurrentTextBox(nullptr);
    SFMLView->setObjects(objects);
    if(l->getLauncherType() == CANNON) {
        SFMLView->addCannon(l->getBallLocationX()*SCALE, l->getBallLocationY()*SCALE);
        SFMLView->setCannonAngle(0.0);
    }
    SFMLView->setBackground(l->getBackgroundTexture());
    SFMLView->setButtons(l->getButtons());
    SFMLView->show();

    if(l->getLauncherType() == CANNON) QObject::connect(game->getAngleSpinBox(), SIGNAL(valueChanged(double)), SFMLView, SLOT(setCannonAngle(double)));
    if(l->getLauncherType() == NONE) QObject::connect(gw, SIGNAL(changeBallLocation(double,double)),this,SLOT(handleChangeBallLocation(double,double)));
    QObject::connect(gw,SIGNAL(launcherAngleChanged(double)), this, SLOT(handleLauncherAngleChange(double)));
    QObject::connect(gw, SIGNAL(playExplosion()), ss, SLOT(playExplosion()));
    QObject::connect(contactListenerInstance, SIGNAL(dynamiteHit(b2Body*)), gw, SLOT(onDynamiteHit(b2Body*)));
    QObject::connect(contactListenerInstance, SIGNAL(obstacleHit()), gw, SLOT(onObstacleHit()));
    //    QObject::connect(game->getAngleSpinBox(), SIGNAL(valueChanged(double)), l, SLOT(resetBall(double)));

       game->displayComponents();

       if(l->isGravityLevel())
       {
           game->displayGravityBox();
       }

   musicSelect(levelId);


}

void BoujeeBall::choseMultiMode()
{
    multiplayer = true;
    loadLevelSelect();

}

void BoujeeBall::choseSingleMode()
{
    loadLevelSelect();
}

void BoujeeBall::choseGuest()
{
    currentUser = QString::fromStdString("GUEST");
    this->lastLevel = 6;
    this->choseSingleMode();
}

/**
 * @brief BoujeeBall::loadLevelSelect
 * loads level select screen into the window
 * AARON and others
 */
void BoujeeBall::loadLevelSelect(){

    delete SFMLView;
    if(gameState == LOGIN_STATE) {
        ui->widgetLayout->removeWidget(log);
        log->hideComponents();
        delete log;
        ss->playLoginMusic();
        ss->playLevelSelect();
    }
    else if (gameState == SUCCESS_STATE) {
        ui->widgetLayout->removeWidget(game);
        game->hideComponents();
        delete game;
        ss->playLevelSelect();
    }

    gameState = LEVEL_SELECT_STATE;

    ls = new levelSelector();
    QObject::connect(ls, SIGNAL(signOut()),this, SLOT(handleSignOut()));
    QObject::disconnect(contactListenerInstance, SIGNAL(obstacleHit()), gw, SLOT(onObstacleHit()));

    //does not need level
    ui->widgetLayout->addWidget(ls);
    l = new Level(-2);
    l->displayLessons(this->lastLevel);
    l->addUserName(currentUser.toStdString());
    world = l->getWorld();
    world->SetContactListener(contactListenerInstance);

    objects = l->getObjects();
    gw->ball = objects[l->getBallIndex()]->getBody();

    SFMLView = new MyCanvas(ls, QPoint(0, 0), QSize(1280, 720), l->getObjects());
    SFMLView->setIsLevelSelect(true);
    SFMLView->setFramerateLimit(60);
    SFMLView->setBackground(l->getBackgroundTexture());
    SFMLView->setTexts(l->getTextList());
    SFMLView->setObjects(objects);
    SFMLView->show();
    ls->displayComponents();
\
}

/**
 * @brief BoujeeBall::handleLauncherAngleChange
 * @param angle
 * resets ball when launcher angle is changed
 * AARON AND STONE
 */
void BoujeeBall::handleLauncherAngleChange(double angle){
    if(l->getLauncherType() == CANNON){
        l->resetBall(angle);
        gw->resetScore();
    }
}

/**
 * @brief BoujeeBall::fireLevelLauncher
 * tells gameworld to fire launcher
 *
 */
void BoujeeBall::fireLevelLauncher() {
    gw->fireLauncher();
}

void BoujeeBall::resetLevel() {
    l->resetBall(gw->getLauncherAngle());
    gw->resetScore();
    ballToBeCreated = true;
}

/**
 * @brief BoujeeBall::mousePressEvent
 * @param event
 * handles mouse being pressed
 * AARON, JORDAN, STONE, NATHAN
 */
void BoujeeBall::mousePressEvent(QMouseEvent *event) {
    float xPos = static_cast<float>(event->pos().x());
    float yPos = static_cast<float>(event->pos().y());


    if(gameState == GAME_WORLD_STATE && l != nullptr) {
        if (l->isFireClicked(xPos, yPos)){
            gw->fireLauncher();
        }
        if (l->needNewBall(xPos, yPos)){
            resetLevel();
        }
        if(l->isExitClicked(xPos,yPos)){
            this->onExit();
            musicSelect(l->getLevelId());
            loadLevelSelect();
        }
    }

    else if(gameState == LEVEL_SELECT_STATE && l != nullptr)
    {
        if(l->isLessonOneClicked(xPos, yPos))
        {
            loadLessonScreen(1);
            ss->playLevelSelect();
            ss->playLessonMusic();
        }
        if(l->isLessonTwoClicked(xPos, yPos))
        {
            loadLessonScreen(2);
            ss->playLevelSelect();
            ss->playLessonMusic();

        }
        if(l->isLessonThreeClicked(xPos, yPos))
        {
            loadLessonScreen(3);
            ss->playLevelSelect();
            ss->playLessonMusic();

        }
        if(l->isLessonFourClicked(xPos, yPos))
        {
            loadLessonScreen(4);
            ss->playLevelSelect();
            ss->playLessonMusic();

        }
        if(l->isLessonFiveClicked(xPos, yPos))
        {
            loadLessonScreen(5);
            ss->playLevelSelect();
            ss->playLessonMusic();

        }
        if(l->isLessonSixClicked(xPos, yPos))
        {
            loadLessonScreen(6);
            ss->playLevelSelect();
            ss->playLessonMusic();

        }
    }

    else if(gameState == LESSON_STATE){
        if(continueButton.getGlobalBounds().contains(xPos, yPos)) displayTextBox();

        if (l->isPlayClicked(xPos, yPos)){
            gw->fireLauncher();
        }
    }
    //On continue head to next screen if completed the level.
    else if(gameState == SUCCESS_STATE){

        if(continueButton.getGlobalBounds().contains(xPos, yPos))
        {
            musicSelect(l->getLevelId());
            loadLevelSelect();
        }
        //Share to facebook if they decided too.
        if(facebookButton.getGlobalBounds().contains(xPos, yPos)){
            this->SFMLView->grabScreenAndSave();
            nw->handleFacebookShare("CHECK OUT MY SCORE ON BOUJEE BALL! #BOUJEBOIS",QString::fromStdString("../edu-app-team-boujee/facebook.png"));
            qDebug() << "FACEBOOK";

        }

    }
}


int BoujeeBall::getLevel(QString name){
    if (name == "levelOne"){
        return 1;
    }
    else{
        return -1;
    }
}


/**
 * @brief BoujeeBall::handleAttempLogin
 * This sends username and password to database
 * @param username
 * Username of intended sign in.
 * @param password
 * Pasword associated with that user.
 */
void BoujeeBall::handleAttemptLogin(){
    if(log->getUsername() == "TEACHER" && log->getPassword() == "TEACHER"){
        log->hideComponents();
        log->displayTeacherComponents();
    }else if(log->getUsername() == "RICK" && log->getPassword() == "ROLL"){
        QString link = "http://www.youtube.com/watch?v=dQw4w9WgXcQ";
        QUrl url = QUrl(link.toHtmlEscaped());
        QDesktopServices webpage;
        webpage.openUrl(url);
    }else{
    nw->handleAttemptLogin(log->getUsername(),log->getPassword(), false);
    }
}

void BoujeeBall::handleUpdateCurrentUser(std::string newUser){
    this->currentUser = QString::fromStdString(newUser);
}
void BoujeeBall::handleUpdateCurrentLevel(int newLevel){
    if(currentUser != QString::fromStdString("GUEST")){
        this->lastLevel = newLevel;
        nw->handleUpdateLastLevel(currentUser.toStdString(),newLevel);
    }
}
void BoujeeBall::handleUpdateNotification(std::string newNot){
    log->setNotification(newNot);
}

/**
 * @brief BoujeeBall::loadLessonScreen
 * @param i
 * loads lesson into widget with given id
 * AARON and others
 */
void BoujeeBall::loadLessonScreen(int i){
    int levelId = i;
    delete SFMLView;
    if(gameState == LEVEL_SELECT_STATE) {
        ui->widgetLayout->removeWidget(ls);
        ls->hideComponents();
        delete ls;
    }
    l = new Level(levelId);
    world = l->getWorld();
    objects = l->getObjects();
    world->SetContactListener(contactListenerInstance);
    gw->ball = objects[l->getBallIndex()]->getBody();
    gw->setLauncherType(l->getLauncherType());
    gw->changeLauncherAngle(l->getLauncherAngle());
    gw->changeLauncherMagnitude(l->getLauncherMagnitude());
    l->resetBall(gw->getLauncherAngle());

    gameState = LESSON_STATE;

    SFMLView = new MyCanvas(this->centralWidget(), QPoint(0, 0), QSize(1280, 720), l->getObjects());
    SFMLView->setFramerateLimit(60);
    SFMLView->setTexts(l->getTextList());
    SFMLView->updateCurrentTextBox(nullptr);
    SFMLView->setBackground(l->getBackgroundTexture());
    displayTextBox();
    SFMLView->setObjects(objects);
    SFMLView->setButtons(l->getButtons());
    SFMLView->show();
    if(l->getLauncherType() == CANNON){
        SFMLView->addCannon(l->getBallLocationX()*SCALE, l->getBallLocationY()*SCALE);
        SFMLView->setCannonAngle(l->getLauncherAngle());
    }
}

void BoujeeBall::displayTextBox() {
    static int index = 0;
    if(index == l->getTextBoxes().size()) {
        loadLevelScreen(l->getLevelId()+100);
        index = 0;
    }
    else{
        SFMLView->updateCurrentTextBox(l->getTextBoxes()[index]);
        continueButton = l->getTextBoxes()[index]->getContinueButton();
        facebookButton = l->getTextBoxes()[index]->getFacebookButton();
        index++;
    }
}

void BoujeeBall::handleSignOut(){
    ls->~levelSelector();
    this->gameState = LOGIN_STATE;
    this->currentUser = QString();
    this->lastLevel = NULL;
    ss->playLevelSelect();
    this->loadLoginScreen(false);
    this->setUpGameConnections();
}

/**
 * @brief BoujeeBall::setUpConnections
 * Setting all connections.
 */
void BoujeeBall::setUpConnections(){
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(updateWorld()));
    QObject::connect(nw, SIGNAL(updateCurrentUser(std::string)), this, SLOT(handleUpdateCurrentUser(std::string)));
    QObject::connect(nw, SIGNAL(updateCurrentLevel(int)), this, SLOT(handleUpdateCurrentLevel(int)));
    QObject::connect(nw, SIGNAL(updateNotification(std::string)), this, SLOT(handleUpdateNotification(std::string)));
    QObject::connect(contactListenerInstance, SIGNAL(topBasketHit()), gw, SLOT(onTopBasketHit()));
    QObject::connect(contactListenerInstance, SIGNAL(botBasketHit()), gw, SLOT(onBotBasketHit()));
    QObject::connect(contactListenerInstance, SIGNAL(ballOutOfBounds()), this, SLOT(onBallOutOfBounds()));
    QObject::connect(contactListenerInstance, SIGNAL(ballOutOfBounds()), gw, SLOT(onBallOut()));
    QObject::connect(contactListenerInstance, SIGNAL(backboardHit()), gw, SLOT(onBackboardHit()));
    QObject::connect(contactListenerInstance, SIGNAL(rimHit()), gw, SLOT(onRimHit()));
    QObject::connect(contactListenerInstance, SIGNAL(bounceSound()), ss, SLOT(playBounce()));
    QObject::connect(gw, SIGNAL(success(std::string, int)), this, SLOT(onSuccess(std::string,int)));
    QObject::connect(gw,SIGNAL(success(std::string, int)), ss,SLOT(playYay()));
    QObject::connect(log->getGuestButton(), SIGNAL(pressed()), this, SLOT(choseGuest()));
    QObject::connect(this, SIGNAL(selectMode()), log, SLOT(modeSelect()));
    //On login succes play success sound effect, and change mode.
    QObject::connect(nw, SIGNAL(accessGranted()), this, SLOT(choseSingleMode()));
    QObject::connect(nw, SIGNAL(accessGranted()), ss, SLOT(playSuccess()));
    QObject::connect(nw,SIGNAL(accessDenied()),log, SLOT(enableLogin()));
    QObject::connect(log->getLoginButton(), SIGNAL(pressed()), this, SLOT(handleAttemptLogin()));
    QObject::connect(this, SIGNAL(resetConnection()), nw, SLOT(resetListener()));
    QObject::connect(nw, SIGNAL(errorMessageFromServer(std::string)),this, SLOT(errorMsg(std::string)));


    //ADMIN CONNECTIONS
    QObject::connect(log, SIGNAL(createUserTeacher(QString,QString)),this, SLOT(handleTeacherCreate(QString,QString)));
    QObject::connect(log, SIGNAL(updateUserLevel(QString,int)),this, SLOT(handleTeacherUpdateLevel(QString,int)));
    QObject::connect(log, SIGNAL(deleteUserTeacher(QString)),this, SLOT(handleTeacherDeleteLevel(QString)));
    QObject::connect(log, SIGNAL(openItUp()),this, SLOT(openHtml()));
    QObject::connect(nw, SIGNAL(openUpWebpage()), this, SLOT(openWebPage()));

}

/**
 * @brief BoujeeBall::setUpGameConnections
 * Sets up all connections besides the timer.
 */
void BoujeeBall::setUpGameConnections(){
    //QObject::connect(nw, SIGNAL(updateCurrentUser(std::string)), this, SLOT(handleUpdateCurrentUser(std::string)));
    //QObject::connect(nw, SIGNAL(updateCurrentLevel(int)), this, SLOT(handleUpdateCurrentLevel(int)));
    //QObject::connect(nw, SIGNAL(updateNotification(std::string)), this, SLOT(handleUpdateNotification(std::string)));
    QObject::connect(contactListenerInstance, SIGNAL(topBasketHit()), gw, SLOT(onTopBasketHit()));
    QObject::connect(contactListenerInstance, SIGNAL(botBasketHit()), gw, SLOT(onBotBasketHit()));
    QObject::connect(contactListenerInstance, SIGNAL(ballOutOfBounds()), this, SLOT(onBallOutOfBounds()));
    QObject::connect(contactListenerInstance, SIGNAL(ballOutOfBounds()), gw, SLOT(onBallOut()));
    QObject::connect(contactListenerInstance, SIGNAL(backboardHit()), gw, SLOT(onBackboardHit()));
    QObject::connect(contactListenerInstance, SIGNAL(rimHit()), gw, SLOT(onRimHit()));
    QObject::connect(contactListenerInstance, SIGNAL(bounceSound()), ss, SLOT(playBounce()));
    QObject::connect(contactListenerInstance, SIGNAL(obstacleHit()), gw, SLOT(onObstacleHit()));
    QObject::connect(gw, SIGNAL(success(std::string, int)), this, SLOT(onSuccess(std::string, int)));
    QObject::connect(gw,SIGNAL(success(std::string, int)), ss,SLOT(playYay()));
    QObject::connect(log->getGuestButton(), SIGNAL(pressed()), this, SLOT(choseGuest()));
    QObject::connect(this, SIGNAL(selectMode()), log, SLOT(modeSelect()));
    //On login succes play success sound effect, and change mode.
    //QObject::connect(nw, SIGNAL(accessGranted()), this, SLOT(choseSingleMode()));
    //QObject::connect(nw, SIGNAL(accessGranted()), ss, SLOT(playSuccess()));
    //QObject::connect(nw,SIGNAL(accessDenied()),log, SLOT(enableLogin()));
    QObject::connect(log->getLoginButton(), SIGNAL(pressed()), this, SLOT(handleAttemptLogin()));
    //QObject::connect(this, SIGNAL(resetConnection()), nw, SLOT(resetListener()));
    //QObject::connect(nw, SIGNAL(errorMessageFromServer(std::string)),this, SLOT(errorMsg(std::string)));


    //ADMIN CONNECTIONS
    QObject::connect(log, SIGNAL(createUserTeacher(QString,QString)),this, SLOT(handleTeacherCreate(QString,QString)));
    QObject::connect(log, SIGNAL(updateUserLevel(QString,int)),this, SLOT(handleTeacherUpdateLevel(QString,int)));
    QObject::connect(log, SIGNAL(deleteUserTeacher(QString)),this, SLOT(handleTeacherDeleteLevel(QString)));
    QObject::connect(log, SIGNAL(openItUp()),this, SLOT(openHtml()));
    QObject::connect(nw, SIGNAL(openUpWebpage()),this, SLOT(openWebpage()));
}

/**
 * @brief BoujeeBall::handleChangeBallLocation
 * Method fired when ball changes location. Used to alert
 * level.
 * @param x
 * new x coord
 * @param y
 * new y coord
 */
void BoujeeBall::handleChangeBallLocation(double x, double y){
    l->changeBallLocation(x,y);
}

void BoujeeBall::errorMsg(std::string msg){
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(msg));
    msgBox.exec();
}

void BoujeeBall::musicSelect(int level)
{
    switch(level)
    {
    case 101:
    {
        if(gameState == SUCCESS_STATE || gameState == LEVEL_SELECT_STATE)
        {
            ss->playOneMusic();
            break;
        }

        else
        {
            ss->playLessonMusic();
            ss->playOneMusic();
            break;
        }
    }

    case 102:
    {
        if(gameState == SUCCESS_STATE || gameState == LEVEL_SELECT_STATE)
        {
            ss->playTwoMusic();
            break;
        }

        else
        {
            ss->playLessonMusic();
            ss->playTwoMusic();
            break;
        }
    }

    case 103:
    {
        if(gameState == SUCCESS_STATE || gameState == LEVEL_SELECT_STATE)
        {
            ss->playThreeMusic();
            break;
        }

        else
        {
            ss->playLessonMusic();
            ss->playThreeMusic();
            break;
        }
    }

    case 104:
    {
        if(gameState == SUCCESS_STATE || gameState == LEVEL_SELECT_STATE)
        {
            ss->playFourMusic();
            break;
        }

        else
        {
            ss->playLessonMusic();
            ss->playFourMusic();
            break;
        }
    }
    case 105:
    {
        if(gameState == SUCCESS_STATE || gameState == LEVEL_SELECT_STATE)
        {
            ss->playFiveMusic();
            break;
        }

        else
        {
            ss->playLessonMusic();
            ss->playFiveMusic();
            break;
        }
    }
    case 106:
    {
        if(gameState == SUCCESS_STATE || gameState == LEVEL_SELECT_STATE)
        {
            ss->playSixMusic();
            break;
        }

        else
        {
            ss->playLessonMusic();
            ss->playSixMusic();
            break;
        }
    }
    default:
    {
        break;
    }

    }
}

//TEACHER ADMIN HANDLERS





void BoujeeBall::handleTeacherCreate(QString username, QString password){
    nw->handleTeacherCreate(username.toStdString(),password.toStdString());
}

void BoujeeBall::handleTeacherDeleteLevel(QString username){
    nw->handleDeleteUser(username.toStdString());
}

void BoujeeBall::handleTeacherUpdateLevel(QString username, int level){
    nw->handleUpdateLastLevel(username.toStdString(),level);
}

void BoujeeBall::openHtml(){
    nw->handleUpdateAnaltics(true);
}

void BoujeeBall::openWebPage(){
    QDesktopServices::openUrl(QUrl("../edu-app-team-boujee/analytics.html"));

}

void BoujeeBall::changeGravity(double gravity)
{
    this->l->getWorld()->SetGravity(b2Vec2(0.0,gravity));
}

