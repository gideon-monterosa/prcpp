#include "Person.h"

int Person::getAge() const {
  return m_age;
}

void Person::setName(const std::string& name) {
  m_name = name;
}

std::string Person::getName() const {
  return m_name;
}

void Person::setAge(int age) {
  m_age = age;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
  return os << p.m_name << " ist " << p.m_age << " Jahre alt.";
}
