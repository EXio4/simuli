#pragma once

#include <cstdint>

struct Virtual {
  using Type = float;
};

struct Real {
  using Type = int32_t;
};

template <typename T>
class Point {

public:
  typename T::Type x;
  typename T::Type y;

  Point(typename T::Type x, typename T::Type y) : x(x), y(y) {}
  Point() : x(0), y(0) {}

  Point operator+(const Point<T>& other) {
    return Point(x + other.x, y + other.y);
  }
  Point operator-(const Point<T>& other) {
    return Point(x - other.x, y - other.y);
  }

  Point& operator+=(const Point<T>& other) {
    x += other.x; y += other.y;
    return *this;
  }

  Point& operator-=(const Point<T>& other) {
    x -= other.x; y -= other.y;
    return *this;
  }

  bool out() {
    return (x < 0) || (y < 0);
  }

};

using VPoint = Point<Virtual>;
using RPoint = Point<Real>;