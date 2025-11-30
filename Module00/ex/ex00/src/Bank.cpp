#include "Bank.hpp"
#include <climits>
#include <stdexcept>

// Bank

// Private

void Bank::applyInflow(Account *account, int value) {
  if (!account)
    return;
  this->_inflowValue += value * this->_inflowPrct;
  account->_value += value - (value * this->_inflowPrct);
}

// Public

Bank::~Bank() {
  for (std::map<int, Account *>::iterator it = this->_clientAccounts.begin();
       it != this->_clientAccounts.end(); it++) {
    delete it->second;
  }
}

void Bank::createAccount(float value) {
  if (value < 0)
    throw std::runtime_error("Error: account value can't be negative");
  if (_maxId == INT_MAX)
    throw std::runtime_error("Error: reached Maximum number of Accounts");

  Account *account = new Account(0, this->_maxId);

  applyInflow(account, value);
  this->_clientAccounts[this->_maxId] = account;
  this->_maxId++;
}

void Bank::deleteAccount(int id) {

  Account *account;
  if ((account = findAccount(id)) != NULL) {
    std::cout << "deleting: " << (this->_clientAccounts[id]) << std::endl;
    delete this->_clientAccounts[id];
    this->_clientAccounts.erase(this->_clientAccounts.find(id));
    std::cout << "Accont: " << id << " Successfully deleted" << std::endl;
  } else
    throw std::runtime_error("Error: account not found");
}

void Bank::displayAccounts() {

  for (std::map<int, Account *>::iterator it = this->_clientAccounts.begin();
       it != this->_clientAccounts.end(); it++) {
    std::cout << (*it).second << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bank &bank) {
  os << "maxId: " << bank._maxId << ",inflowPrct: " << bank._inflowPrct
     << ",_inflowValue: " << bank._inflowValue << std::endl;
  return os;
}

void Bank::depositAccount(int id, float value) {
  Account *account;

  if ((account = findAccount(id)) != NULL) {
    applyInflow(account, value);
    std::cout << "Desposite of: " << value << " on Account: " << id << " successful"<< std::endl;
  }
  else
    throw std::runtime_error("Error: account not found");
}

Bank::Account *Bank::findAccount(int id) {

  if (this->_clientAccounts.find(id) != this->_clientAccounts.end())
    return this->_clientAccounts[id];
  else
    return NULL;
}

void Bank::applyLoan(float amount, int id) {
  Account *account;

  if ((account = findAccount(id)) != NULL) {
    if (amount < this->_inflowValue) {
      this->_inflowValue -= amount;
      account->_value += amount;
    } else
      throw std::runtime_error("Error: loan refused inflowValue too low");
  } else
    throw std::runtime_error("Error: account not found");

  std::cout << "Loan approved amount: " << amount << " was transfered to account: " << id << std::endl;
}

void Bank::transfer(int clientId, int recpientId, float amount) {

  Account *sender = findAccount(clientId);
  if (!sender)
    throw std::runtime_error("Error: client sender was not found");
  Account *receiver = findAccount(recpientId);
  if (!receiver)
    throw std::runtime_error("Error: client receiver was not found");
  if (sender->_value < amount)
    throw std::runtime_error(
        "Error: client sender doesn't have enough fonds for transfer");

  sender->_value -= amount;
  receiver->_value += amount;
  std::cout << "Tranfer of " << amount << " from acount id: " << clientId << " to account id:" << recpientId << " SUCCESSFUL!!!" << std::endl;
}

// Account

Bank::Account::Account(float value, int id) : _id(id), _value(value) {

  Bank::Account::_value = value;
}

const int &Bank::Account::getId() const { return this->_id; }

const float &Bank::Account::getValue() const { return this->_value; }
//
