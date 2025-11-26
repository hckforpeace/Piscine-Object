#include "Bank.cpp"
#include <iostream>

int main() {
  Bank b;
  b.createAccount(452);
  b.createAccount(4000);
  b.createAccount(123);
  b.createAccount(444);
  b.createAccount(100);
  b.displayAccounts();
  b.deleteAccount(0);
  std::cout << b;
  return (0);
}
