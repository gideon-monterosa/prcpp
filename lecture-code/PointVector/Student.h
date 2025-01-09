#pragma once

#include "Person.h"

class Student : public Person {
  int m_studentNuber;

 public:
  Student(const std::string& name, int age, int studentNumber)
      : Person(name, age), m_studentNuber(studentNumber) {

        };

  int getStudentNumber() const {
    return m_studentNuber;
  }

  void print(std::ostream& os) override {
    os << *this;
  }

 private:
  friend std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << static_cast<const Person&>(s)
       << ", Studenten Nummer: " << s.getStudentNumber();
    return os;
  }
};
