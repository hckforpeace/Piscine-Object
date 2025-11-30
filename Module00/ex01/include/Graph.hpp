#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vector2.hpp"
#include <vector>

class Graph {
private:
  std::vector<const Vector2 *> points;
  const unsigned int _width;
  const unsigned int _height;
  bool isPresent(const Vector2 *v);

public:
  Graph();
  Graph(const unsigned int height, const unsigned int width);
  void addPoint(const Vector2 *point);
  void draw();
};

#endif
