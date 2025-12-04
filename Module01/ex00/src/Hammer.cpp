#include "Hammer.hpp"


Hammer::Hammer(): Tool(15, "Hammer") {
	std::cout << "Hammer created !!" << std::endl;
}

void Hammer::use() {
  if (numberOfUses == 0)
    std::cout << "Hammer used too many times !!" << std::endl;
  else {
    numberOfUses--;
    std::cout << "Hammer the Shovel !!" << std::endl;
  }
}
