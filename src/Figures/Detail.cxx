#include "Object.h"
#include "Figures/Detail.h"

CollisionData Detail::getCollisionData() {
  CollisionData data;
  data.circles.push_back(CollisionCircle(start, size));
  data.circles.push_back(CollisionCircle(start + VPoint(size*2,0), size));
  data.rectangles.push_back(CollisionRectangle(start - VPoint(0,10), start + VPoint(size * 4, 10)));
  return data;
}
sf::Color Detail::getColor() {
  return color;
}