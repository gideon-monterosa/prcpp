#pragma once

#include <cmath>
#include <iostream>

struct Point {   // struct = class public:
  int m_x, m_y;  // x und y sind public

  Point(int x = 0, int y = 0) : m_x(x), m_y(y) {
    // std::cout << "Point ctor " << *this << std::endl;
  }
  ~Point() {
    // std::cout << "Point dtor " << *this << std::endl;
  }

  Point& operator+=(const Point& p) {
    m_x += p.m_x;
    m_y += p.m_y;
    return *this;
  }

  friend Point operator+(Point lhs, const Point& rhs) {
    return lhs += rhs;
  }

  friend Point operator+(Point&& lhs, const Point& rhs) {
    return lhs += rhs;
  }

  friend Point operator+(const Point& lhs, Point&& rhs) {
    return rhs += lhs;
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p.m_x << ',' << p.m_y << ')';
    return os;
  }

  double dist(const Point& p) const {
    const int dx = p.m_x - m_x;
    const int dy = p.m_y - m_y;
    return hypot(dx, dy);
  }

};  // ; ist zwingend notwendig hier
