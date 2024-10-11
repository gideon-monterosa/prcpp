#include <iostream>

#include "other.h"

void hello1() {
  std::cout << "Main: Hello!" << std::endl;
}

int main() {
  std::cout << "Main Started" << std::endl;
  hello1();
  hello2();
}
