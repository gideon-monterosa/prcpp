#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <ostream>

#include "ex1.h"
#include "ex2.h"
#include "ex3.h"
#include "ex4.h"
#include "ex5.h"
#include "ex6.h"

struct C {
  float m_x;
};

constexpr auto potenz(int x, int y) {
  int result = 1;
  for (int i = 0; i < y; i++) result *= x;
  return result;
}

int main() {
  // runEx1();
  // runEx2();
  // runEx3();
  // runEx4();
  // runEx5();
  // runEx6();
  constexpr int p = potenz(5, 3);
  std::cout << p << std::endl;

  C c;
  c.m_x = 0;
  C* pc = &c;
  C& rc = c;
  C*& rpc = pc;
  C a = *new C();

  C* ar = new C[1000];

  const int x = 5;
  constexpr int y = x;
  std::cout << y << std::endl;
}

enum Color : uint8_t { NO_COLOR = 0, SILVER = 1, GOLD = 2 };

class ColorCode {
 private:
  std::array<Color, 6> colors;
  size_t count;

 public:
  ColorCode(std::array<Color, 6>& colors, size_t count = 4)
      : colors(colors), count(count) {
    assert(count <= 6 && count >= 4);
  }
};
