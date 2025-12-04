#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include "Worker.hpp"
#include <ostream>
#include <vector>

class Workshop {

private:
  std::vector<Worker *> workers;

public:
  ~Workshop();
  Workshop(std::string workTask);
  void subscribe(Worker *worker);
  void unSubscribe(Worker *worker);
  const std::string &getWorkTask();
  void executeWorkDay();

  friend std::ostream &operator<<(std::ostream &os, const Workshop *wrkshp) {
	  os << "Workshop workers: ";
	  for (std::vector<Worker *>::const_iterator it = wrkshp->workers.begin(); it != wrkshp->workers.end(); it++) {
		os << (*it)->getName() << " " ;
	  }
	  os << std::endl;
      return os;
  }
};

#endif
