#pragma once

#include "Point.h"
#include <vector>

struct CollisionCircle {
  VPoint center;
  float radius;
  CollisionCircle(VPoint center, float radius) : center(center), radius(radius) {};
};

struct CollisionRectangle {
  VPoint p1;
  VPoint p2;
  CollisionRectangle(VPoint p1, VPoint p2) : p1(p1), p2(p2) {};
};

class CollisionData {
public:
  std::vector<CollisionCircle> circles;
  std::vector<CollisionRectangle> rectangles;
};