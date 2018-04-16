#pragma once

#include "CollisionData.h"
#include <SFML/Graphics.hpp>

class Object {
public:
  virtual ~Object() {};
  virtual CollisionData getCollisionData() = 0;
  virtual sf::Color getColor() = 0;

};