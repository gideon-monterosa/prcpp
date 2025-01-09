#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "Human.h"

class Person : public Human {
  std::string m_name;
  int m_age;
  std::weak_ptr<Person> m_brother;

 public:
  Person(const std::string& name, int age) : m_name(name), m_age(age) {}
  virtual ~Person() {
    std::cout << "dtor von " << m_name << std::endl;
  }

  int getAge() const;
  std::string getName() const;
  void setAge(int age);
  void setName(const std::string& name);
  void setBrother(const std::shared_ptr<Person>& brother) {
    m_brother = brother;
  }

  void print(std::ostream& os) override {
    os << *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
