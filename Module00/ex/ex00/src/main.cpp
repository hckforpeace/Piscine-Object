#include "Bank.hpp"
#include <exception>
#include <iostream>
#include <ostream>

int main() {
  Bank b;
  b.createAccount(452);
  b.createAccount(4000);
  b.createAccount(123);
  b.createAccount(444);
  b.createAccount(100);
  b.createAccount(0);

  try {
    b.createAccount(-1);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "dsiplaying with operator [] " << b[0] << std::endl;

  b.displayAccounts();

  b.depositAccount(0, 400.0);
  std::cout << "dsiplaying with operator [] " << b[0] << std::endl;


  b.deleteAccount(0);
  b.deleteAccount(1);
  b.deleteAccount(2);
  b.deleteAccount(3);
  b.deleteAccount(4);
  b.deleteAccount(5);
  //
  // b.displayAccounts();
  std::cout << b;
  return (0);
}

// Loans
// int main() {
//
//   Bank b;
//   b.createAccount(452);
//   b.createAccount(4000);
//
//   try {
//     b.applyLoan(10000, 0);
//   } catch (const std::exception &e) {
//     std::cout << e.what() << std::endl;
//   }
//
//   std::cout << b << std::endl;
//   b.displayAccounts();
//
//   try {
//     b.applyLoan(200, 0);
//   } catch (const std::exception &e) {
//     std::cout << e.what() << std::endl;
//   }
//
//   std::cout << b << std::endl;
//   b.displayAccounts();
//
//   return 0;
// }

// acount creation
// int main() {
//
//   Bank b;
//   try {
//     b.createAccount(0);
//     b.createAccount(-1);
//
//   } catch (const std::exception &exception) {
//     std::cout << exception.what() << std::endl;
//   }
//
//   b.displayAccounts();
//
//   return (0);
// }

// Account deletion
// int main() {
//
//   Bank b;
//   b.createAccount(0);
//   b.createAccount(4512);
//
//   try {
//     b.deleteAccount(1);
//     b.deleteAccount(4545);
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << std::endl;
//   }
//
//   b.displayAccounts();
//   return (0);
// }

// Deposit Account
// int main() {
//
//   Bank b;
//   b.createAccount(0);
//   b.createAccount(4512);
//
//   b.displayAccounts();
//
//   try {
//     b.depositAccount(0, 45);
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << std::endl;
//   }
//
//   b.displayAccounts();
//
//   try {
//     b.depositAccount(654, 45);
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << std::endl;
//   }
//
//   b.displayAccounts();
//
//   return (0);
// }

// // Transfer
// int main() {
//
//   Bank b;
//   b.createAccount(452);
//   b.createAccount(4000);
//   b.displayAccounts();
//   b.transfer(0, 1, 400);
//   b.displayAccounts();
//
//   try {
//     b.transfer(0, 1, 400);
//   } catch (const std::exception &exception) {
//     std::cerr << exception.what() << std::endl;
//   }
// }
