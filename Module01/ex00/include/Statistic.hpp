#ifndef STATISTIC_HPP
#define STATISTIC_HPP

#include <iostream>

struct Statistic {

  int level;
  int exp;
  Statistic(int level, int exp): level(level), exp(exp) { std::cout << "Statistic Created !!" << std::endl;}
  Statistic() { std::cout << "Statistic Created !!" << std::endl;}
  ~Statistic() { std::cout << "Statistic Destroyed !!" << std::endl;}
};

#endif
