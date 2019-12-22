/* Source file */
#include "mycanvas.h"

/**
 * @brief MyCanvas::MyCanvas
 * @param parent
 * @param position
 * @param size
 * @param objsIn
 * MyCanvas constructor
 * AARON, ROB, STONE
 */
MyCanvas::MyCanvas(QWidget *parent, const QPoint& position, const QSize& size, std::vector<WorldObject *> objsIn) :
QSFMLCanvas(parent, position, size)
{
    objects = objsIn;
    currentTextBox = nullptr;
    cannon = nullptr;
    isLevelSelect = false;
}

void MyCanvas::onInit()
{

}

/**
 * @brief MyCanvas::onUpdate
 * updates and draws the current frame on the window
 * AARON
 */
void MyCanvas::onUpdate()
{
    sf::RenderWindow::clear(sf::Color::White);

    //draws background first
    sf::Sprite bg;
    bg.setTexture(background);
    bg.setPosition(0.0, 0.0);
    sf::RenderWindow::draw(bg);
    //draw world objects
    for (int i = 0; i < objects.size(); i++) {
        if(i == 1 && isLevelSelect)
        {
            sf::RenderWindow::draw(*texts[texts.size()-1]);
        }
        if (objects[i]->isPolygon()) {
            b2Body* body = objects[i]->getBody();
            sf::ConvexShape shape = objects[i]->getShape();
            b2Vec2 pos;
            pos = body->GetPosition();
            shape.setPosition(pos.x*SCALE, pos.y*SCALE);
            shape.setRotation(180/b2_pi * body->GetAngle());

            sf::RenderWindow::draw(shape);
        }
        else {
            sf::Sprite s = objects[i]->getSprite();
            b2Body* body = objects[i]->getBody();
            s.setPosition(body->GetPosition().x*SCALE, body->GetPosition().y*SCALE);
            s.setRotation(180/b2_pi * body->GetAngle());

            sf::RenderWindow::draw(s);

        }
    }
    if(cannon != nullptr) {
        sf::RenderWindow::draw(backWheel);
        sf::RenderWindow::draw(*cannon);
        sf::RenderWindow::draw(frontWheel);
    }

    //draw texts
    for(int i = 0; i < texts.size(); i++)
    {
        if(isLevelSelect && i == texts.size()-1)
        {
            continue;
        }

        else sf::RenderWindow::draw(*texts[i]);
    }


    //draw buttons
    for(int i = 0; i < buttons.size(); i++) {
        sf::Sprite s;
        s.setTexture(*buttons[i].getTexture());
        s.setPosition(buttons[i].getPosition());
        sf::RenderWindow::draw(s);
    }

    //draw textboxes
    if(currentTextBox != nullptr){
        sf::Sprite s;
        sf::Texture t = currentTextBox->getTexture();
        s.setTexture(t);
        s.setPosition(currentTextBox->getPosition());
        sf::RenderWindow::draw(s);
        sf::Text text = currentTextBox->getText();
        sf::RenderWindow::draw(text);
        if(currentTextBox->hasContinueButton()) {
            sf::RenderWindow::draw(currentTextBox->getContinueButton());
        }
        if(currentTextBox->hasFacebookButton()){
            sf::RenderWindow::draw(currentTextBox->getFacebookButton());
        }
    }
    //display window
    sf::RenderWindow::display();

}

/**
 * @brief MyCanvas::setObjects
 * @param objsIn
 * sets the class' object vector
 * AARON
 */
void MyCanvas::setObjects(std::vector<WorldObject *> objsIn) {
    objects = objsIn;
}

/**
 * @brief MyCanvas::setTexts
 * @param textIn
 * sets text vector
 * AARON
 */
void MyCanvas::setTexts(std::vector<sf::Text *> textIn){
    texts = textIn;
}

/**
 * @brief MyCanvas::updateCurrentTextBox
 * @param newTextBox
 * changes the class' textbox to be drawn
 * AARON
 */
void MyCanvas::updateCurrentTextBox(TextBox * newTextBox){
    currentTextBox  = newTextBox;
}

/**
 * @brief MyCanvas::setButtons
 * @param buttonsIn
 * sets buttons vector to be drawn
 * AARON
 */
void MyCanvas::setButtons(std::vector<sf::Sprite> buttonsIn) {
    buttons = buttonsIn;
}

/**
 * @brief MyCanvas::setBackground
 * @param t
 * sets the background of the scene
 * AARON
 */
void MyCanvas::setBackground(sf::Texture t) {
    background = t;
}

/**
 * @brief MyCanvas::addCannon
 * @param xPos
 * @param yPos
 * adds the cannon to the scene
 * AARON
 */
void MyCanvas::addCannon(float xPos, float yPos){
    cannon = new sf::Sprite();
    QResource cannonImg(":/textures/textures/cannon_body.png");
    cannonTexture.loadFromMemory(cannonImg.data(), cannonImg.size(), sf::IntRect());
    cannon->setTexture(cannonTexture);
    cannonPosX = xPos;
    cannonPosY = yPos;
    cannon->setPosition(cannonPosX, cannonPosY);
    cannon->setOrigin(CANNON_ORIGIN_X, CANNON_ORIGIN_Y);
    cannon->setRotation(CANNON_ANGLE_OFFSET);

    QResource frontWheelImg(":/textures/textures/front_wheel.png");
    frontWheelTexture.loadFromMemory(frontWheelImg.data(), frontWheelImg.size(), sf::IntRect());
    frontWheel.setTexture(frontWheelTexture);
    frontWheel.setPosition(cannonPosX + FRONT_WHEEL_OFFSET_X, cannonPosY + FRONT_WHEEL_OFFSET_Y);

    QResource backWheelImg(":/textures/textures/back_wheel.png");
    backWheelTexture.loadFromMemory(backWheelImg.data(), backWheelImg.size(), sf::IntRect());
    backWheel.setTexture(backWheelTexture);
    backWheel.setPosition(cannonPosX + BACK_WHEEL_OFFSET_X, cannonPosY + BACK_WHEEL_OFFSET_Y);
}

/**
 * @brief MyCanvas::setCannonAngle
 * @param angle
 * changes the angle for the cannon to be drawn at
 * AARON
 */
void MyCanvas::setCannonAngle(double angle){
    cannon->setRotation(-angle + CANNON_ANGLE_OFFSET);
}


void MyCanvas::grabScreenAndSave(){
    sf::Image test = sf::RenderWindow::capture();
    test.saveToFile("../edu-app-team-boujee/facebook.png");
}

void MyCanvas::setIsLevelSelect(bool maybeBaby)
{
    isLevelSelect = maybeBaby;
}

