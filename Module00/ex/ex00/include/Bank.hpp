#include <iostream>
#include <map>
#include <ostream>

class Bank {

public:
  class Account {
  private:
    const int _id;
    float _value;

  public:
    Account(float value, int id);
    const int &getId() const;
    const float &getValue() const;

    friend std::ostream &operator<<(std::ostream &os, const Bank::Account *account) {
      os << "Account(id=" << account->_id << ", value=" << account->_value
         << ")";
      return os;
    }
    friend class Bank;
  };

private:
  int _maxId;
  const float _inflowPrct;
  float _inflowValue;
  std::map<int, Account *> _clientAccounts;
  Account *findAccount(int id);
  void applyInflow(Account *account, int value);

public:
  ~Bank();
  Bank() : _maxId(0), _inflowPrct(0.05), _inflowValue(0) {};
  // methods
  void createAccount(float value);
  void deleteAccount(int id);
  void depositAccount(int id, float value);
  void displayAccounts();
  void applyLoan(float amount, int id);
  void transfer(int clientId, int recpientId, float amount);
  friend std::ostream &operator<<(std::ostream &os, const Bank &bank);

  const Bank::Account *operator[](const int id) {
    if (_clientAccounts.find(id) != _clientAccounts.end())
      return _clientAccounts[id];
    else
      return NULL;
  }
};
