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

  Point(typename T::Type v) : x(v), y(v) {}
  Point(typename T::Type x, typename T::Type y) : x(x), y(y) {}
  Point() : x(0), y(0) {}
};

template <typename T>
Point<T> operator+(const Point<T>& self, const Point<T>& other) {
  return Point<T>(self.x + other.x, self.y + other.y);
}
template <typename T>
Point<T> operator-(const Point<T>& self, const Point<T>& other) {
  return Point<T>(self.x - other.x, self.y - other.y);
}
template <typename T>
Point<T> operator*(const Point<T>& self, const Point<T>& other) {
  return Point<T>(self.x * other.x, self.y * other.y);
}
template <typename T>
Point<T> operator/(const Point<T>& self, const Point<T>& other) {
  return Point<T>(self.x / other.x, self.y / other.y);
}

template <typename T>
Point<T>& operator+=(Point<T>& self, const Point<T>& other) {
  self.x += other.x; self.y += other.y;
  return self;
}
template <typename T>
Point<T>& operator-=(Point<T>& self, const Point<T>& other) {
  self.x -= other.x; self.y -= other.y;
  return self;
}
template <typename T>
Point<T>& operator*=(Point<T>& self, const Point<T>& other) {
  self.x *= other.x; self.y *= other.y;
  return self;
}
template <typename T>
Point<T>& operator/=(Point<T>& self, const Point<T>& other) {
  self.x /= other.x; self.y /= other.y;
  return self;
}


using VPoint = Point<Virtual>;
using RPoint = Point<Real>;