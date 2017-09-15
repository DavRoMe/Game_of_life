#include "vec2op.h"

using namespace std;

/// Operaciones con vectores ////////////////////////////////////////////////////////////////////
sf::Vector2f normalize(sf::Vector2f vect) {
  float magn = getMagnitude(vect);
  vect.x /= magn;
  vect.y /= magn;
  return vect;
}
sf::Vector2f setMagnitude(sf::Vector2f vect, float mag) {
  vect = normalize(vect);
  return vect * mag;
}
float getMagnitude(sf::Vector2f vect) {
  return sqrt(vect.x * vect.x + vect.y * vect.y);
}
float getAngle(sf::Vector2f vect) {
  /// Regresa un angulo medido en sentido de las manecillas del reloj ///

  float legAd = vect.x;     // Cateto adyacente
  float legOp = vect.y;     // Cateto opuesto

  if(legAd == 0) {
    if(legOp > 0) {
      return 90;
    } else return 270;
  }
  if(legOp == 0) {
    if(legAd > 0) {
      return 0;
    } else return 180;
  }

  if(legAd > 0 && legOp > 0) {
    return((180/PI)*atan(legOp / legAd));
  } else if(legAd < 0 && legOp > 0) {
    legAd *= -1;
    return 180 - ((180/PI)*atan(legOp / legAd));
  } else if(legAd < 0 && legOp < 0) {
    legAd *= -1;
    legOp *= -1;
    return 180 + ((180/PI)*atan(legOp / legAd));
  } else {                                  // (legAd > 0 && legOp < 0)
    legOp *= -1;
    return 360 - ((180/PI)*atan(legOp / legAd));
  }
}













