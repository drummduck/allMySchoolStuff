#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <QObject>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <QResource>

class TextBox : public QObject
{
    Q_OBJECT

private:
    sf::Vector2f position;
    std::string displayText;
    sf::Texture texture;
    int fontSize;
    sf::Color textColor; //= sf::Color::Black;
    sf::Text text;
    sf::Font font;
    float textOffsetX;
    float textOffsetY;
    sf::Sprite continueButton;
    sf::Sprite facebookButton;
    sf::Texture continueTexture;
    sf::Texture facebookTexture;
    bool continueButtonBool;
    bool facebookButtonBool;
    constexpr static float CONTINUE_OFFSET_X = 500.0;
    constexpr static float CONTINUE_OFFSET_Y = 228.0;
    constexpr static float FACEBOOK_OFFSET_X = 750.0;
    constexpr static float FACEBOOK_OFFSET_Y = 228.0;

public:
    explicit TextBox(QObject *parent, sf::Vector2f position, std::string displayText, int fontSize, sf::Color color, bool hasContinueButton, bool hasFacebookButton);
    sf::Texture getTexture();
    sf::Text getText();
    void generateText();
    sf::Vector2f getPosition();
    sf::Sprite getContinueButton();
    sf::Sprite getFacebookButton();
    bool hasFacebookButton();
    bool hasContinueButton();

signals:

public slots:
};

#endif // TEXTBOX_H
