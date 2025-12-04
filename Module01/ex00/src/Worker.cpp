#include "Worker.hpp"
#include "Workshop.hpp"
#include <stdexcept>
#include <vector>

Worker::~Worker() {
  for (std::vector<Workshop *>::iterator it = this->workshops.begin();
       it != this->workshops.end(); it++) {
	  (*it)->unSubscribe(this);
  }
}

Worker::Worker(const Position &coordonnee, const Statistic &stat,
               const std::string &name)
    : coordonnee(coordonnee), stat(stat), name(name) {

  std::cout << "Worker created !!" << std::endl;
  tools["Shovel"] = NULL;
  tools["Hammer"] = NULL;
}

const Position &Worker::getPosition() { return coordonnee; }

const Statistic &Worker::getStatistic() { return stat; }

void Worker::setTool(Tool *t) {
  if (t->getName().compare("Shovel") == 0)
    std::cout << "Adding Shovel Tool To Worker " << this->name << std::endl;
  else if (t->getName().compare("Shovel") == 0)
    std::cout << "Adding Hammer Tool To Worker " << this->name << std::endl;

  if (t->worker != NULL)
    t->worker->removeTool(t);

  t->worker = this;
  this->tools["Shovel"] = t;
}

void Worker::removeTool(Tool *tool) {
  if (tool->getName().compare("Shovel") == 0) {
    std::cout << "Removing Shovel Tool To Worker " << this->name << std::endl;
    this->tools["Shovel"] = NULL;
  } else if (tool->getName().compare("Hammer") == 0) {
    std::cout << "Adding Hammer Tool To Worker " << this->name << std::endl;
    this->tools["Hammer"] = NULL;
  }
  tool->worker = NULL;
}

void Worker::registerWorkshops(Workshop *wrkshps) {
  std::vector<Workshop *>::iterator it =
      std::find(this->workshops.begin(), this->workshops.end(), wrkshps);
  if (it == this->workshops.end())
    this->workshops.push_back(wrkshps);
  else {
    std::cerr << "workshop already added" << std::endl;
  }
}

std::string Worker::getName() { return this->name; }

void Worker::work() {
  if (this->workshops.empty()) {
    throw std::runtime_error("Workshops not found");
  }
  std::cout << "Worker " << this->name << " executing work..." << std::endl;
}
