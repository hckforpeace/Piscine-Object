#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "Tool.hpp"
#include <iostream>

class Hammer : public Tool {
public:
  Hammer();
  ~Hammer() { std::cout << "Hammer deleted !!" << std::endl; }

  void use();
};

#endif
