#include "../includes/Graph.hpp"
#include <stdexcept>

Graph::Graph() : _width(5), _height(5) {}
Graph::Graph(const int width, const int height)
    : _width(width), _height(height) {}

// void Graph::setHeight(const int height) {
//   if (height <= 0)
//     throw std::runtime_error("Error: height must be greater than 0");
//   this->_height = height;
// }
//
// void Graph::setWidth(const int width) {
//   if (width <= 0)
//     throw std::runtime_error("Error: width must be greater than 0");
//   this->_width = width;
// }

void Graph::addPoint(const Vector2 *point) {
  if (point->x > this->_width)
    throw std::runtime_error("Error: width not in range of the graph");
  this->points.push_back(point);
}
