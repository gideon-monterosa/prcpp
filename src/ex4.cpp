
#include <iostream>

struct S {};
struct T {
  S s;
};
void f(S& s) {  // f1
  std ::cout << " call f ( S & s ) " << std ::endl;
}
void f(S&& s) {  // f2
  std ::cout << " call f ( S && s ) " << std ::endl;
}

static void sub1() {
  std::cout << "Subtask 4.1" << std::endl;
  S s;
  T t;

  f(s);               // f1 ✅
  f(t.s);             // f1 ✅
  f(S{});             // f2 ✅
  f(T{}.s);           // f1 ❌ ist ein r-value wegen dem T{}
  f(std::move(s));    // f2 ✅
  f(std::move(t).s);  // f1 ❌ move gibt ein r-value zurück und Zugriffe auf
                      //       attribute eines r-values werden ebenfalls als
                      //       r-values betrachtet.
  f(std::move(t.s));  // f2 ✅
}

static void sub2() {
  std::cout << "Subtask 4.2" << std::endl;
  std::vector<int> v1 = {1, 2, 3, 4, 5};  // v1: 1, 2 , 3, 4 ,5
  std::vector<int> v2 = v1;               // v1 & v2: 1, 2, 3, 4, 5
  std::vector<int> v3 = std::move(v1);    // v3: 1, 2, 3, 4, 5 v1: leer
  std::vector<int> v4 = {7, 8, 9};        // v4 : 7, 8, 9
  v2 = std::move(v4);                     // v2: 7, 8, 9 v4: leer
  std::move(v3);                          // kein Effekt
}

class UniqueIntPtr {
 private:
  int* m_ptr;

 public:
  UniqueIntPtr(int* ptr) : m_ptr(ptr) {}
  ~UniqueIntPtr() {
    if (m_ptr != nullptr) {
      delete m_ptr;
    }
  }
};

static void sub3() {
  std::cout << "Subtask 4.3" << std::endl;
  // TODO: solve ex 4.3
}

void runEx4() {
  std::cout << "Exercice 4:" << std::endl;
  sub1();
  sub2();
  sub3();
}
