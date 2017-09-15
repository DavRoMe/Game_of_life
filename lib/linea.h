#ifndef LINEA_H
#define LINEA_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "vec2op.h"

class linea {
private:
  sf::RectangleShape r;
  sf::Vector2f source;
  sf::Vector2f target;
  float length;         // Cuando vale 0 es igual a la distancia entre "source" y "target" de otra forma su tamaño es fijo
  float thickness;
  float scale;
public:
  linea();
  linea(sf::Vector2f source, sf::Vector2f target, float lng = 0);
  linea(float x1, float y1, float x2, float y2, float lng = 0);

  void setLength(float lng);
  void setScale(float scl);
  void setThickness(float thckns);
  void setSource(sf::Vector2f source);
  void setTarget(sf::Vector2f target);
  void setColor(sf::Color color);

  void show(sf::RenderWindow& w);
};

#endif // LINEA_H
