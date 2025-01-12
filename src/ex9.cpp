#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Student {
 public:
  bool m_bachelor;               // Boolean mit Wahr oder Falsch
  std::string m_name;            // Zeichenkette mit Buchstaben und Leerzeichen
  std::vector<double> m_grades;  // Vektor mit beliebig vielen Zahlen

  friend std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.m_bachelor << ' ' << s.m_name;
    for (size_t i = 0; i < s.m_grades.size(); i++) {
      os << ' ' << s.m_grades[i];
    }
    os << std::endl;
    return os;
  };

  friend std::istream& operator>>(std::istream& is, Student& s) {
    is >> s.m_bachelor >> s.m_name;

    std::vector<double> grades;
    while (is.good() && is.peek() != '\n') {
      double grade;
      is >> grade;
      grades.push_back(grade);
    }

    s.m_grades = grades;
    return is;
  };
};

static void sub3() {
  std::cout << "Subtask 9.3" << std::endl;
  Student s1{false, "Nico", std::vector<double>{6.0, 5.5, 5.0}};

  std::cout << "Original Student (s1): " << s1;

  std::istringstream iss;
  std::ostringstream oss;
  oss << s1;
  iss.str(oss.str());

  Student s2;
  iss >> s2;

  std::cout << "New Student (s2): " << s2;
}

void runEx9() {
  std::cout << "Exercice 9:" << std::endl;
  sub3();
}
