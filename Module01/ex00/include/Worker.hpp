#ifndef WORKER_HPP
#define WORKER_HPP

#include "Position.hpp"
#include "Shovel.hpp"
#include "Statistic.hpp"
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Workshop;

class Worker {
private:
  Position coordonnee;
  Statistic stat;
  Shovel *shovel;
  std::string name;
  std::map<std::string, Tool *> tools;
  std::vector<Workshop*> workshops;

public:
  Worker(const Position &coordonnee, const Statistic &stat, const std::string& name);
  ~Worker();
  void setTool(Tool *t);

  const Position &getPosition();
  const Statistic &getStatistic();
  std::string getName();
  void removeTool(Tool *tool);
  void registerWorkshops(Workshop* wrkshps);
  void work();
};

#endif
