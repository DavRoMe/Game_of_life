#ifndef VEC2OP_H
#define VEC2OP_H

#include <SFML/System/Vector2.hpp>
#include <cmath>

const float PI = std::atan(1)*4;

sf::Vector2f normalize(sf::Vector2f vect);
sf::Vector2f setMagnitude(sf::Vector2f vect, float mag);
float getMagnitude(sf::Vector2f vect);
float getAngle(sf::Vector2f vect);

#endif // VEC2OP_H
