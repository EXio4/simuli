#include "Object.h"
#include "Figures/Detail.h"

CollisionData Detail::getCollisionData() {
  CollisionData data;
  data.circles.push_back(CollisionCircle(start, size/2));
  data.circles.push_back(CollisionCircle(start + VPoint(size/2,0), size/4));
  data.rectangles.push_back(CollisionRectangle(start - VPoint(size/5, size/5), start + VPoint(size/5, size/5)));
  return data;
}
sf::Color Detail::getColor() {
  return color;
}