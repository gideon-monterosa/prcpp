#include <iostream>

#include "ex1.h"

static void sub1() {
  std::cout << "Subtask 1.1" << std::endl;
  // Expected: 1
  int a = 0;
  a = 1;
  std::cout << a << std::endl;

  // Expected: 1
  int b = a;
  a = 2;
  std::cout << b << std::endl;

  // Expected: 3
  int& c = a;
  a = 3;
  std::cout << c << std::endl;

  // Expected: 4
  int& d = c;
  a = 4;
  std::cout << d << std::endl;
}

static void sub2() {
  std::cout << "Subtask 1.2" << std::endl;

  int x;
  std ::cin >> x;

  int a = x + 1;
  const int b = x + 2;
  // The Value of x isnt known at compiletime
  // constexpr int c = x + 3;
  constexpr int c = 3;

  a = 1;
  // Cant modify a const
  // b = 2;
  // Cant modify a constexpr
  // c = 3;

  int& ra = a;
  // Binding this to an int drops its const qualifier
  // int& rb = b;
  const int& rb = b;
  // Binding this to an int drops its const qualifier, at runtime constexpr is
  // just a const
  // int& rc = c;
  const int& rc = c;
  ra = 1;
  // Cannot assign a new value to a const
  // rb = 2;
  // rc = 3;

  const int& cra = a;
  const int& crb = b;
  const int& crc = c;
  // Cannot assign a new value to a const
  // cra = 1;
  // crb = 2;
  // crc = 3;

  // a and b are not known at compile time so you cant assign them to a
  // constexpr constexpr int cca = a;
  // constexpr int ccb = b;
  // c itself is already a constexpr (known at compiletime so you can assing it
  // to another constexpr)
  constexpr int ccc = c;
}

// This works but isnt the most elegant solution
// you have to dereff &x when calling the function
//
// double* f(double* param) {
//   *param = *param * *param;
//   return param;
// }

double& f(double& param) {
  param = param * param;
  return param;
}

static void sub3() {
  std::cout << "Subtask 1.3" << std::endl;
  double x = 2;
  f(x);  // should calculate x^2 and save it in x
  std::cout << "X should be 4 after calling f(x): " << x << std::endl;
  x = 2;
  f(f(f(x)));
  std::cout << "X should be 256 after calling f(f(f(x))): " << x << std::endl;
}

void runEx1() {
  std::cout << "Exercice 1:" << std::endl;
  sub1();
  // sub2();
  sub3();
}
