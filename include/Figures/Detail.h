#pragma once

#include "Object.h"

class Detail : public Object {
public:
  VPoint start;
  float size;
  sf::Color color;

  Detail(VPoint start, float size, sf::Color color) : start(start), size(size), color(color) {}
  ~Detail() {}

  CollisionData getCollisionData();
  sf::Color getColor();


};