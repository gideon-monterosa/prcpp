#include <iostream>
#include <ostream>

struct Parent {
  virtual void f() {
    std ::cout << " Parent :: f " << std ::endl;
  }
  void g() {
    std ::cout << " Parent :: g " << std ::endl;
  }
};

struct Self : public Parent {
  void f() override {
    std ::cout << " Self :: f " << std ::endl;
  }
  void g() {
    std ::cout << " Self :: g " << std ::endl;
  }
};

struct Child : public Self {
  void f() override {
    std ::cout << " Child :: f " << std ::endl;
  }
  void g() {
    std ::cout << " Child :: g " << std ::endl;
  }
};

static void sub1() {
  std::cout << "Subtask 6.1" << std::endl;
  Child c;
  c.f();  // Child f ✅
  c.g();  // Child g ✅
  std::cout << std::endl;
  Self& s = c;
  s.f();  // Child f ✅
  s.g();  // Self g ✅
  std::cout << std::endl;
  Parent p = c;
  p.f();  // Child f ❌ acutall: Parent f
  p.g();  // Parent g ✅
  std::cout << std::endl;
  Parent* q = &c;
  q->f();  // Child f ✅
  q->g();  // Parent g ✅

  /*
   * Die Methode f ist als virtual deklariert, deshalb wird immer das f des
   * dynamischen Typs (zur Laufzeit) aufgerufen. Die Methode g ist nicht als
   * virtual deklariert, deshalb wird immer das g des statischen Typs (zur
   * Kompilierzeit) aufgerufen.
   */
}

static void sub2() {
  std::cout << "Subtask 6.2" << std::endl;

  Self ss;
  Parent* p = &ss;
  if (p != nullptr) {
    std::cout << " A " << std::endl;  // Ja ✅
  }

  Self* s = static_cast<Self*>(p);
  if (s != nullptr) {
    std::cout << " B "
              << std::endl;  // Nein ❌ wird ausgegeben da static cast immer
                             // castet, hier functioniert das sogar da der
                             // dynamische typ von p Self ist
  }

  Child* c = static_cast<Child*>(p);
  if (c != nullptr) {
    std::cout << " C "
              << std::endl;  // Nein ❌ wird ausgegeben da static cast immer
                             // casted, hier ist das problematisch da p nicht
                             // vom dynaimschen typ CHild ist
  }

  s = dynamic_cast<Self*>(p);
  if (s != nullptr) {
    std::cout << " D " << std::endl;  // Ja ✅
  }

  c = dynamic_cast<Child*>(p);
  if (c != nullptr) {
    std::cout << " E " << std::endl;  // Nein ✅
  }

  /*
   * Der Unterschied zwischen den Casts static_cast und dynamic_cast ist
   * folgender: Der erste Cast wandelt zur Kompilierzeit den Typ des Zeigers wie
   * gewünscht um; dabei wird ignoriert, ob diese Umwand- lung zur Laufzeit des
   * Programms tatsächlich Sinn macht. Der zweite Cast hingegen prüft zur
   * Laufzeit des Programms, ob die Umwandlung sinnvoll ist; falls nicht, dann
   * wird der Zeiger auf nullptr gesetzt.
   */
}
class Animal {
 protected:
  std::string name;

 public:
  Animal(const std::string& name) : name(name) {}
  virtual ~Animal() = default;
  virtual void say() = 0;
};

class Cat : public Animal {
 public:
  using Animal::Animal;
  void say() override {
    std::cout << name << "says Meow!";
  }
};

class Dog : public Animal {
 public:
  using Animal::Animal;
  void say() override {
    std::cout << name << "says Woof!";
  }
};

class Bird : public Animal {
 public:
  using Animal::Animal;
  void say() override {
    std::cout << name << "says Chirp!";
  }
};

static void sub3() {
  std::cout << "Subtask 6.3" << std::endl;
  std ::array<std ::unique_ptr<Animal>, 4> animals = {
      std::make_unique<Cat>(" Milo "), std::make_unique<Dog>(" Wilma "),
      std::make_unique<Dog>(" Wiggles "), std::make_unique<Bird>(" Charlie ")};
  for (auto& animal : animals) {
    animal->say();
  }
  std::cout << std::endl;
}

void runEx6() {
  std::cout << "Exercice 6:" << std::endl;
  sub1();
  sub2();
  sub3();
}
