
#include <iostream>

template <typename T>
concept A = requires(T x) { x.a; };

template <typename T>
concept B = requires(T x) { typename T::b; };

template <typename T>
concept C = requires(T x) { x.c(); };

void f(A auto x) {
  std::cout << "A" << std::endl;
}

void f(B auto x) {
  std::cout << "B" << std::endl;
}

void f(C auto x) {
  std::cout << "C" << std::endl;
}

struct X1 {
  int a;
  using c = int;
  int b();
};

struct X2 {
  int b;
  using a = int;
  int c();
};

struct X3 {
  int c;
  using b = int;
  int a();
};

static void sub1() {
  std::cout << "Subtask 8.1" << std::endl;
  f(X1{});  // A
  f(X2{});  // C
  f(X3{});  // B
}

template <int N, int K>
struct Binomial {
  static constexpr int value =
      Binomial<N - 1, K - 1>::value + Binomial<N - 1, K>::value;
};

template <int N>
struct Binomial<N, 0> {
  static constexpr int value = 1;
};

template <int N>
struct Binomial<N, N> {
  static constexpr int value = 1;
};

template <>
struct Binomial<0, 0> {
  static constexpr int value = 1;
};

void runEx8() {
  std::cout << "Exercice 8:" << std::endl;
  sub1();
}
