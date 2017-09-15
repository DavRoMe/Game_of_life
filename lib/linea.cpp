#include "linea.h"

using namespace std;

/// Constructores /////////////////////////////////////////////////////////////////////
linea::linea() {
  setSource(sf::Vector2f(0, 0));
  setTarget(sf::Vector2f(0, 0));
  setThickness(1);
  setScale(1);
  setLength(0);
  setColor(sf::Color(255, 255, 255, 255));
}
linea::linea(sf::Vector2f source, sf::Vector2f target, float lng) {
  setSource(source);
  setTarget(target);
  setThickness(1);
  setScale(1);
  setLength(lng);
  setColor(sf::Color(255, 255, 255, 255));
}
linea::linea(float x1, float y1, float x2, float y2, float lng) {
  setSource(sf::Vector2f(x1, y1));
  setTarget(sf::Vector2f(x2, y2));
  setThickness(1);
  setScale(1);
  setLength(lng);
  setColor(sf::Color(255, 255, 255, 255));
}

/// Editar propiedades /////////////////////////////////////////////////////////////////
void linea::setLength(float lng) {length = lng;}
void linea::setThickness(float thckns) {thickness = thckns;}
void linea::setSource(sf::Vector2f source) {this->source = source;}
void linea::setTarget(sf::Vector2f target) {this->target = target;}
void linea::setScale(float scl) {scale = scl;}
void linea::setColor(sf::Color color) {r.setFillColor(color);}

void linea::show(sf::RenderWindow& w) {
  if(length == 0) {
    r.setSize(sf::Vector2f(getMagnitude(target - source) * scale, thickness));
  } else
    r.setSize(sf::Vector2f(length * scale, thickness));

  r.setOrigin(0, thickness / 2);
  r.setRotation(getAngle(target - source));
  r.setPosition(source);
  w.draw(r);
}
