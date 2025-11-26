#include "../include/Bank.hpp"
#include <algorithm>
#include <climits>
#include <stdexcept>

// Bank

void Bank::createAccount(float value) {
  if (value < 0)
    throw std::runtime_error("Account value can't be negative");
  if (_maxId == INT_MAX)
    throw std::runtime_error("Reached Maximum number of Accounts");

  this->_inflowValue += value * this->_inflowPrct;
  Account *account =
      new Account(value - (value * this->_inflowPrct), this->_maxId);

  this->_maxId++;
  this->_clientAccounts.push_back(account);
}

void Bank::deleteAccount(int id) {

  for (std::vector<Account *>::iterator it = this->_clientAccounts.begin();
       it != this->_clientAccounts.end(); it++) {
    if ((*it)->getId() == id) {
      this->_clientAccounts.erase(it);
      delete (*it);
      return;
    }
  }

  std::cerr << "Account with id: " << id << " was not found" << std::endl;
}

void Bank::displayAccounts() {

  for (std::vector<Account *>::iterator it = this->_clientAccounts.begin();
       it != this->_clientAccounts.end(); it++) {
    std::cout << (**it) << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bank &bank) {
  os << "maxId: " << bank._maxId << ",inflowPrct: " << bank._inflowPrct
     << ",_inflowValue: " << bank._inflowValue << std::endl;
  return os;
}

// Acount

Bank::Account::Account(float value, int id) : _value(value), _id(id) {

  Bank::Account::_value = value;
}

int Bank::Account::getId() const { return this->_id; }

void Bank::depositAccount(int id, float value) {

  std::vector<Account *>::iterator it =
      std::find_if(this->_clientAccounts.begin(), this->_clientAccounts.end(),
                   [id](const Account *a) { return a->getId() == id; });
  if (it != this->_clientAccounts.end())
    (*it)->deposit(value);
  else
    std::cerr << "Account with id: " << id << " was not found" << std::endl;
}

void Bank::Account::deposit(int deposit) { this->_value += deposit; }

std::ostream &operator<<(std::ostream &os, const Bank::Account &account) {
  os << "Account(id=" << account._id << ", value=" << account._value << ")";
  return os;
}
