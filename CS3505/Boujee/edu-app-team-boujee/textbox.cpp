#include "textbox.h"

/**
 * @brief TextBox::TextBox
 * @param parent
 * @param position
 * @param displayText
 * @param fontSize
 * @param color
 * @param hasContinueButton
 * @param hasFacebookButton
 * Textbox constructor
 * AARON AND STONE
 */
TextBox::TextBox(QObject *parent, sf::Vector2f position, std::string displayText, int fontSize, sf::Color color, bool hasContinueButton, bool hasFacebookButton) : QObject(parent)
{
    this->position = position;
    this->displayText = displayText;
    this->fontSize = fontSize;
    this->textColor = color;



    QResource textureSource(":/textures/textures/textbox.png");
    this->texture.loadFromMemory(textureSource.data(),textureSource.size(), sf::IntRect());

    //TODO possibly some sort of conditional if different textboxes?!
    textOffsetX = 240.0;
    textOffsetY = 125.0;

    if(hasContinueButton) {
        QResource continueImage(":/textures/textures/continue.png");
        continueTexture.loadFromMemory(continueImage.data(), continueImage.size(), sf::IntRect());
        continueButton.setTexture(continueTexture);
        continueButton.setPosition(sf::Vector2f(position.x+CONTINUE_OFFSET_X, position.y+CONTINUE_OFFSET_Y));
        continueButtonBool = true;
    }

    if(hasFacebookButton) {
        QResource facebookImage(":/textures/textures/fb.png");
        facebookTexture.loadFromMemory(facebookImage.data(), facebookImage.size(), sf::IntRect());
        facebookButton.setTexture(facebookTexture);
        facebookButton.setPosition(sf::Vector2f(position.x+FACEBOOK_OFFSET_X, position.y+FACEBOOK_OFFSET_Y));
        facebookButtonBool = true;
    }else{
        facebookButtonBool = false;
    }

    generateText();
}

/**
 * @brief TextBox::getTexture
 * gets texture of textbox object.
 * @return
 * AARON AND STONE
 */
sf::Texture TextBox::getTexture(){
    return this->texture;
}

/**
 * @brief TextBox::getText
 * @return
 * returns the sf text object of the textbox
 * AARON AND STONE
 */
sf::Text TextBox::getText(){
    return text;
}

/**
 * @brief TextBox::getPosition
 * @return
 * returns a sf vector with the position of the textbox
 * AARON AND STONE
 */
sf::Vector2f TextBox::getPosition(){
    return position;
}

/**
 * @brief MyCanvas::displayText
 * Displays text on the screen at given position, size, and color.
 * BY STONE, AND AARON.
 * @param position
 * @param displayText
 * @param fontSize
 * @param color
 */
void TextBox::generateText(){
    QResource fontSource(":/textures/textures/RobotoCondensed-Regular.ttf");
    font.loadFromMemory(fontSource.data(),fontSource.size());
    sf::Text newText(this->displayText, font);
    newText.setCharacterSize(this->fontSize);
    newText.setStyle(sf::Text::Bold);
    newText.setColor(this->textColor);
    sf::Vector2f textPosition;
    textPosition.x = position.x + textOffsetX;
    textPosition.y = position.y + textOffsetY;
    newText.setPosition(textPosition);
    text = newText;
}

/**
 * @brief TextBox::getContinueButton
 * @return
 * returns the continue button of the textbox
 * AARON
 */
sf::Sprite TextBox::getContinueButton() {
    return continueButton;
}

/**
 * @brief TextBox::hasContinueButton
 * @return
 * returns whether the textbox has a continue button or not
 */
bool TextBox::hasContinueButton() {
    return continueButtonBool;
}

/**
 * @brief TextBox::getFacebookButton
 * @return
 * returns the facebook button
 * STONE
 */
sf::Sprite TextBox::getFacebookButton() {
    return facebookButton;
}

/**
 * @brief TextBox::hasFacebookButton
 * @return
 * returns if the textbox has a facebook button
 * STONE
 */
bool TextBox::hasFacebookButton() {
    return facebookButtonBool;
}
