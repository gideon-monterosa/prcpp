
#include <sys/types.h>

#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

struct Obj {
  Obj() {
    std ::cout << " default-construct " << std::endl;
  }
  Obj(const Obj& o) {
    std ::cout << " copy-construct " << std::endl;
  }
  Obj& operator=(const Obj& o) {
    std ::cout << " assign " << std::endl;
    return *this;
  }
  ~Obj() {
    std ::cout << " destroy " << std::endl;
  }
};

static void sub1() {
  std::cout << "Subtask 3.1" << std::endl;
  Obj o1;
  Obj* o2 = new Obj;
  {
    Obj o3 = o1;
  }
  Obj* o4 = new Obj(o1);
  o4 = &o1;
  delete o2;
  o1 = *o4;
}

static void sub2() {
  std::cout << "Subtask 3.2" << std::endl;
  /*
   * Read the solution for an in detail explanation.
   */
}

class ScopeLogger {
 private:
  static size_t inline scopeCounter = 0;
  std::string name = "";

 public:
  ScopeLogger(std::string name) : name(name) {
    std::cout << std::string(++scopeCounter, '.') << " Enter scope " << name
              << std::endl;
  };

  ~ScopeLogger() {
    std::cout << std::string(scopeCounter--, '.') << " Leave scope " << name
              << std::endl;
  }
};

void parity(int x) {
  ScopeLogger sl("parity");
  if (x % 2 == 0) {
    ScopeLogger sl("parity_if");
    std::cout << "Even number" << std::endl;
  } else {
    ScopeLogger sl("parity_else");
    std::cout << "Odd number" << std::endl;
  }
}

static void sub3() {
  std::cout << "Subtask 3.3" << std::endl;
  ScopeLogger sl("main");
  parity(1);
  parity(2);
}

void runEx3() {
  std::cout << "Exercice 3:" << std::endl;
  sub1();
  sub2();
  sub3();
}
