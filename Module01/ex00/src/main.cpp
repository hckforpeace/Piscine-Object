#include "Position.hpp"
#include "Shovel.hpp"
#include "Statistic.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"
#include <iostream>

int main() {

  Tool *tool = new Shovel();

  Worker *w = new Worker(Position(1,1,1), Statistic(12,12), "Worker 1");
  Worker *w2 = new Worker(Position(1,1,1), Statistic(12,12), "Worker 2");
  Worker *w3 = new Worker(Position(1,1,1), Statistic(12,12), "Worker 3");

  w->setTool(tool);
  w2->setTool(tool);


  Workshop *wor1 = new Workshop("w1");

  wor1->subscribe(w);
  wor1->subscribe(w2);
  wor1->subscribe(w3);

  wor1->executeWorkDay();
  
  delete tool;
  std::cout << wor1;
  delete w;
  std::cout << wor1;
  delete w2;
  std::cout << wor1;
  delete w3;
  delete wor1;

  return 0;
}
