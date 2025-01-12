

#include <iostream>

template <typename T>
void f(T x) {
  std::cout << x << " Generic" << std::endl;
}

template <>
void f(int x) {
  std::cout << x << " Specialized" << std::endl;
}

void f(int x) {
  std::cout << x << " Overloaded" << std::endl;
}

template <typename T, typename U>
void g(T x, U y) {
  std::cout << x << y << " Generic" << std::endl;
}

template <typename U>
void g(int x, U y) {
  std::cout << x << y << " Spec" << std::endl;
}

static void sub1() {
  std::cout << "Subtask 7.1" << std::endl;

  f(1);            // O ✅
  f<double>(2);    // G ✅
  f<int>(3);       // S ✅
  f<>(4);          // O ❌ actual: S
  f(5.0);          // O ❌ actual: G
  f<double>(6.0);  // G ✅
  f<int>(7.0);     // S ✅
  f<>(8.0);        // G ✅

  g<double>(10, 125.0);
  g<>(10.0, 125.0);
  g(10, 125);
}

template <typename T1, typename T2, typename T3 = T2>
struct S {
  void f() {
    std::cout << "Generic" << std::endl;
  }
};

template <typename T2>
struct S<int, T2, char> {
  void f() {
    std::cout << "Specialized" << std::endl;
  }
};

static void sub2() {
  std::cout << "Subtask 7.2" << std::endl;

  S<char, int, int> s1;
  s1.f();  // G ✅
  S<int, char, int> s2;
  s2.f();  // G ✅
  S<int, int, char> s3;
  s3.f();  // S ✅
  S<char, int> s4;
  s4.f();  // G ✅
  S<int, char> s5;
  s5.f();  // S ✅
}

double sum() {
  return 0.0;
}

template <typename Number, typename... Numbers>
double sum(Number first, Numbers... rest) {
  return static_cast<double>(first) + sum(rest...);
}

static void sub3() {
  std::cout << "Subtask 7.3" << std::endl;
  int a = 1;
  float b = 2.5F;
  double c = 0.05;
  short d = 42;
  unsigned e = 30U;
  long double f = 2.22L;

  std::cout << sum(a, b, c, d, e, f) << std::endl;
}

void runEx7() {
  std::cout << "Exercice 7:" << std::endl;
  sub1();
  sub2();
  sub3();
}
