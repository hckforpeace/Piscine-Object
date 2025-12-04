#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>
class Worker;
class Tool {

protected:
  unsigned int numberOfUses;
  Worker *worker;
  std::string name;

public:
  Tool(unsigned int numberOfUses, std::string name);

  // void setWorker(Worker *worker);
  const std::string getName() const;

  virtual ~Tool() { std::cout << "Tool delete !!" << std::endl; }
  virtual void use() = 0;
  friend Worker;
};

#endif
