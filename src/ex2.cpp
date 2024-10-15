#include <cstddef>
#include <iostream>

#include "ex1.h"

static void sub1() {
  std::cout << "Subtask 2.1" << std::endl;
  // Wo: Stack
  // Lebensdauer: Bis Ende des Blocks
  int a = 1;
  a = 4;
  std::cout << "a: " << a << std::endl;

  // Wo: Heap
  // Lebensdauer: Bis delete aufgerufen wird
  int* b = new int(2);
  *b = 4;
  std::cout << "b: " << *b << std::endl;
  delete b;

  // Wo: Heap
  // Lebensdauer: Solange der einzige Pointer (Owner) auf die Variable zeigt.
  // D.h. der Speicher wird am Ende der Funktion automatisch wider freigegeben.
  std::unique_ptr<int> c = std::make_unique<int>(3);
  *c = 4;
  std::cout << "c: " << *c << std::endl;
}

static void sub2() {
  std::cout << "Subtask 2.2" << std::endl;

  // 1 2 ✔
  int i1 = 1;
  int i2 = 2;
  std::cout << i1 << " " << i2 << std::endl;

  // 2 1 ✔
  int* p1 = &i2;
  int* p2 = &i1;
  std::cout << *p1 << " " << *p2 << std::endl;

  // didnt know, actuall: 1 2
  int** pp1 = &p2;
  int** pp2 = &p1;
  std::cout << **pp1 << " " << **pp2 << std::endl;

  // 4 3 ✔
  *p1 = 3;
  *p2 = 4;
  std::cout << i1 << " " << i2 << std::endl;

  // 4 3 ✔
  *pp1 = &i2;
  *pp2 = &i1;
  std::cout << *p1 << " " << *p2 << std::endl;

  // 4 3 ✔
  pp1 = &p1;
  pp2 = &p2;
  std::cout << **pp1 << " " << **pp2 << std::endl;
}

int* max(int* first, size_t length) {
  int* max = first;
  for (size_t i = 1; i < length; i++) {
    if (*max < *(first + i)) {
      max = first + i;
    }
  }
  return max;
}

static void sub3() {
  std::cout << "Subtask 2.3" << std::endl;
  int array[] = {4, 3, 1, 6, 7, 9, 0, 2, 5, 8};
  if (*max(array, 10) == 9) {
    std::cout << "Correct!" << std::endl;
  } else {
    std::cout << "Incorrect!" << std::endl;
  }
}

void runEx2() {
  std::cout << "Exercice 2:" << std::endl;
  sub1();
  sub2();
  sub3();
}
