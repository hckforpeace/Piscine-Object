#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

struct Position {
  int x;
  int y;
  int z;
  Position(int x, int y, int z): x(x), y(y), z(z) {std::cout << "Position Created !" << std::endl;}
  Position() {std::cout << "Position Created !" << std::endl;}
  ~Position() {std::cout << "Position Deleted !" << std::endl;}
};

#endif
