#include "Graph.hpp"
#include "Vector2.hpp"
#include <iostream>
#include <stdexcept>
// Private
bool Graph::isPresent(const Vector2 *v) {
  for (std::vector<const Vector2 *>::iterator it = points.begin();
       it != points.end(); it++) {
    if (*(*it) == *v)

      return true;
  }
  return false;
}

// Public

Graph::Graph() : _width(5), _height(5) {}

Graph::Graph(const unsigned int width, const unsigned int height)
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
  if (point->x > this->_width - 1 || point->x > this->_height - 1)
    throw std::runtime_error("Error: width not in range of the graph");
  if (isPresent(point))
    throw std::runtime_error("Error: the point is already present");

  this->points.push_back(point);
}

void Graph::draw() {

  Vector2 *temp = new Vector2();
  for (int j = 0; j < this->_height; j++) {

    for (int i = 0; i < this->_width; i++) {

      if (i == 0)
        std::cout << (this->_height - 1 - j) << " ";

      temp->x = i;
      temp->y = (this->_height - 1 - j);

      if (isPresent(temp))
        std::cout << " X ";
      else
        std::cout << " . ";

      if (i == (this->_width - 1))
        std::cout << std::endl;
    }
  }

  std::cout << "  ";
  for (int i = 0; i < this->_width; i++) {
	std::cout << " " << i << " ";
  }
  std::cout << std::endl;

}
