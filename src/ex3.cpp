
#include <sys/types.h>

#include <iostream>

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
}

static void sub3() {
  std::cout << "Subtask 3.3" << std::endl;
}

void runEx3() {
  std::cout << "Exercice 3:" << std::endl;
  sub1();
  sub2();
  sub3();
}
