#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>
class Graph;

struct Vector2 {
private:
  unsigned int x;
  unsigned int y;

public:
  Vector2();
  Vector2(const unsigned int x, const unsigned int y);
  bool operator==(const Vector2 &v) const {
    return this->y == v.y && this->x == v.x ? true : false;
  }
  friend Graph;
};

#endif
