#include "golCells.h"

using namespace std;

LifeCell::LifeCell(sf::Texture& textura, int x, int y) {
  sprite.setTexture(textura);
  sprite.setPosition(x, y);
  spriteSize = textura.getSize();
  currentState = false;        // Alive
  nextState = false;          //Dead
  setColor(deadcolor);
}

const sf::Color LifeCell::deadcolor = sf::Color(25, 25, 25);

bool LifeCell::getState() {
  return currentState;
}

void LifeCell::setNextSt(bool state) {
  nextState = state;
}
void LifeCell::setState(bool state) {
  currentState = state;
  nextState = state;
}
void LifeCell::setSize(float width, float height) {
  sprite.setScale(width / spriteSize.x, height / spriteSize.y);
}
void LifeCell::setColor(int red, int green, int blue) {
  sprite.setColor(sf::Color(red, green, blue, 255));
}
void LifeCell::setColor(sf::Color c) {
  sprite.setColor(c);
}
void LifeCell::setPosition(int x, int y) {
  sprite.setPosition(x, y);
}

void LifeCell::update() {
  currentState = nextState;
}
void LifeCell::show(sf::RenderWindow& window) {
  window.draw(sprite);
}

