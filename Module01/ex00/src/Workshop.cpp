#include "Workshop.hpp"
#include <algorithm>

Workshop::Workshop(std::string workTask) {
  std::cout << "Workshop " << workTask << " created !!" << std::endl;
}

void Workshop::subscribe(Worker *worker) {

  std::vector<Worker *>::iterator it = std::find(workers.begin(), workers.end(), worker);
  if (it != workers.end())
    std::cout << "Worker " << worker->getName() << " Already subscribed to workshop " << std::endl;
  else {
    this->workers.push_back(worker);
    worker->registerWorkshops(this);
    std::cout << "Worker " << worker->getName() << " sucessfuly subscribed to workshop " << std::endl;
  }
}

void Workshop::unSubscribe(Worker *worker) {

  for (std::vector<Worker *>::iterator it = this->workers.begin();
       it != this->workers.end(); it++) {
    if (*it == worker) {
      std::cout << "Worker " << worker->getName()
                << " sucessfuly removed from workshop workers list" << std::endl;
      this->workers.erase(it);
      break;
    }
  }
}

void Workshop::executeWorkDay() {

  for (std::vector<Worker *>::iterator it = this->workers.begin();
       it != this->workers.end(); it++) {
    (*it)->work();
  }
}

Workshop::~Workshop() {}
