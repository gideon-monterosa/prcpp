#include <iostream>
#include <ostream>

char f() {  // f1
  return '\n';
}
// bool f() { // f2: Clashes with f1
//   return true;
// }
void f(char a) {}  // f3
// void f(char b) {}  // f4: Clashes with f3
void f(bool a) {}          // f5
void f(char a, bool b) {}  // f6
void f(bool a, char b) {}  // f7
void f(int& i) {}          // f8
void f(int&& i) {}         // f9
void f(const int& i) {}    // f10

static void sub1() {
  std::cout << "Subtask 5.1" << std::endl;
}

struct Rational {
  int m_num, m_denom;
  Rational(int num, int denom = 1) : m_num(num), m_denom(denom) {}
  // TODO: ask why friend is needed here?
  friend bool operator<(const Rational& lhs, const Rational& rhs) {
    return lhs.m_num * rhs.m_denom < rhs.m_num * lhs.m_denom;
  }
};

static void sub2() {
  std::cout << "Subtask 5.2" << std::endl;
  Rational r = {1, 2}, s = {3, 4};
  if (r < s) {  // Rational < Rational
    std::cout << "in 1" << std::endl;
  }
  if (s < 5) {  // Rational < int
    std::cout << "in 2" << std::endl;
  }
  if (6 < r) {  // int < Rational
    std::cout << "in 3" << std::endl;
  }
  if (7 < 8) {  // int < int
    std::cout << "in 4" << std::endl;
  }
}

class FancyVector {
 private:
  std::vector<int> m_vec;

 public:
  explicit FancyVector() : m_vec(5, 0) {
    for (int i = 0; i < 5; i++) {
      m_vec[i] = i;
    }
  }

  explicit FancyVector(size_t size, int value = 0) : m_vec(size, value) {}

  int& operator[](int i) {
    int size = static_cast<int>(m_vec.size());
    while (i < 0) {
      i += size;
    }
    return m_vec[i];
  }

  const int& operator[](int i) const {
    int size = static_cast<int>(m_vec.size());
    while (i < 0) {
      i += size;
    }
    return m_vec[i];
  }
};

static void sub3() {
  std::cout << "Subtask 5.3" << std::endl;
  FancyVector fv = FancyVector();
  std::cout << "Value[0]: " << fv[0] << std::endl;
  std::cout << "Value[3]: " << fv[3] << std::endl;
  std::cout << "Value[4]: " << fv[4] << std::endl;
  std::cout << "Value[-1]: " << fv[-1] << std::endl;
  std::cout << "Value[-2]: " << fv[-2] << std::endl;
}

void runEx5() {
  std::cout << "Exercice 5:" << std::endl;
  sub1();
  sub2();
  sub3();
}
