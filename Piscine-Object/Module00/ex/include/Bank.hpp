#include <iostream>
#include <ostream>
#include <vector>

#define RATE 0.05;

class Bank {

public:
  class Account {
  private:
    const int _id;
    float _value;

  public:
    Account(float value, int id);
    int getId() const;
    void deposit(int deposit);

    friend std::ostream &operator<<(std::ostream &os, const Account &account);
  };

private:
  int _maxId;
  const float _inflowPrct = RATE ;
  float _inflowValue;
  std::vector<Account *> _clientAccounts;

public:
  Bank() : _maxId(0), _inflowValue(0) {};
  void createAccount(float value);
  void deleteAccount(int id);
  void depositAccount(int id, float value);
  void displayAccounts();
  friend std::ostream &operator<<(std::ostream &os, const Bank &bank);
};
