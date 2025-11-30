#include "Graph.hpp"
#include "Vector2.hpp"
#include <exception>
#include <iostream>

int main() {

  Graph g = Graph(10, 10);
  Vector2 *v1 = new Vector2();
  Vector2 *v2 = new Vector2(4, 5);
  Vector2 *v3 = new Vector2(9, 9);
  Vector2 *v4 = new Vector2(7, 3);
  Vector2 *v5 = new Vector2(2, 9);
  // Vector2 *v2 = new Vector2();

  g.addPoint(v1);
  g.addPoint(v2);
  g.addPoint(v3);
  g.addPoint(v4);
  g.addPoint(v5);
  // try {
  //
  //   g.addPoint(v2);
  // } catch (const std::exception &e) {
  //   std::cerr << e.what() << std::endl;
  // }

  g.draw();
  return 0;
}
