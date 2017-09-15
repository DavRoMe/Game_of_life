#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class LifeCell {
private:
  sf::Sprite sprite;
  sf::Vector2u spriteSize;
  bool currentState, nextState;

public:
  LifeCell(sf::Texture& textura, int x, int y);

  static const sf::Color deadcolor;

  bool getState();

  void setNextSt(bool state);
  void setState(bool state);
  void setSize(float width, float height);
  void setColor(int red, int green, int blue);
  void setColor(sf::Color c);
  void setPosition(int x, int y);

  void update();
  void show(sf::RenderWindow& window);
};
