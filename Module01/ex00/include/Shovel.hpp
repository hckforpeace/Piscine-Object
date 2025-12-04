#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Tool.hpp"
#include <iostream>

class Shovel : public Tool {
public:
  Shovel();
  ~Shovel() { std::cout << "Shovel deleted !!" << std::endl; }

  void use();
};

#endif
