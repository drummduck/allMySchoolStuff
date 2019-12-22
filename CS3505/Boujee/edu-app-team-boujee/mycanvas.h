/* Header file */
#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "qsfmlcanvas.h"
#include "WorldObject.h"
#include "textbox.h"
#include <iostream>

class MyCanvas : public QSFMLCanvas
{
  Q_OBJECT
  private:
  void onInit();
  void onUpdate();
  void displayText(sf::Vector2f position, std::string text, int fontSize, sf::Color color = sf::Color::Black);

  std::vector<WorldObject *> objects;
  std::vector<sf::Text *> texts;
  TextBox * currentTextBox;
  std::vector<sf::Sprite> buttons;
  sf::Texture background;
  sf::Sprite * cannon;
  sf::Sprite frontWheel;
  sf::Sprite backWheel;
  sf::Texture cannonTexture;
  sf::Texture frontWheelTexture;
  sf::Texture backWheelTexture;
  bool isLevelSelect;
  float cannonAngle;
  float cannonPosX;
  float cannonPosY;
  constexpr static float CANNON_ANGLE_OFFSET = 15;
  constexpr static float CANNON_ORIGIN_X = 35;
  constexpr static float CANNON_ORIGIN_Y = 50;
  constexpr static float FRONT_WHEEL_OFFSET_X = -40;
  constexpr static float FRONT_WHEEL_OFFSET_Y = 0;
  constexpr static float BACK_WHEEL_OFFSET_X = -5;
  constexpr static float BACK_WHEEL_OFFSET_Y = 0;
  constexpr static float SCALE = 30;

  public:
  explicit MyCanvas(QWidget *parent, const QPoint& position, const QSize& size, std::vector<WorldObject *> objsIn);
  void setObjects(std::vector<WorldObject *> objsIn);
  void setTexts(std::vector<sf::Text *> textIn);
  void updateCurrentTextBox(TextBox * newTextBox);
  void setButtons(std::vector<sf::Sprite> buttonsIn);
  void setBackground(sf::Texture);
  void addCannon(float xPos, float yPos);
  void grabScreenAndSave();
  void setIsLevelSelect(bool);

  signals:

  public slots:
  void setCannonAngle(double angle);
};

#endif // MYCANVAS_H
