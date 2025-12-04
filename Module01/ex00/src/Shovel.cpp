#include "Shovel.hpp"

Shovel::Shovel() : Tool(10, "Shovel") {
  std::cout << "Shovel created !!" << std::endl;
}

void Shovel::use() {
  if (numberOfUses == 0)
    std::cout << "Shovel used too many times !!" << std::endl;
  else {
    numberOfUses--;
    std::cout << "Using the Shovel !!" << std::endl;
  }
}
