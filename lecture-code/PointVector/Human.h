#pragma once

#include <iostream>

class Human {
 public:
  virtual void print(std::ostream& os) = 0;
};
