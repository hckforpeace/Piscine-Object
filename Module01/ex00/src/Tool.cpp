#include "Tool.hpp"
#include "Worker.hpp"
#include <string>

Tool::Tool(unsigned int numberOfUses, std::string name)
    : numberOfUses(numberOfUses), name(name) {
  worker = NULL;
  std::cout << "Tool created !!" << std::endl;
}

// void Tool::setWorker(Worker *w) {
//   if (this->worker != NULL) {
//     worker->removeTool(this);
//   }
//   this->worker = w;
// }

const std::string Tool::getName() const { return name; }
