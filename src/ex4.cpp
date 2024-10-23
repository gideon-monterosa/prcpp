
#include <iostream>

struct S {};
struct T {
  S s;
};
void f(S& s) {
  std ::cout << " call f ( S & s ) " << std ::endl;
}
void f(S&& s) {
  std ::cout << " call f ( S && s ) " << std ::endl;
}

static void sub1() {
  std::cout << "Subtask 4.1" << std::endl;
  S s;
  T t;
  f(s);
  f(t.s);
  f(S{});
  f(T{}.s);
  f(std ::move(s));
  f(std ::move(t).s);
  f(std ::move(t.s));
}

static void sub2() {
  std::cout << "Subtask 4.2" << std::endl;
}

static void sub3() {
  std::cout << "Subtask 4.3" << std::endl;
}

void runEx4() {
  std::cout << "Exercice 4:" << std::endl;
  sub1();
  sub2();
  sub3();
}
