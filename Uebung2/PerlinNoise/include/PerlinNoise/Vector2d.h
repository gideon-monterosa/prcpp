#include <cmath>
#include <utility>

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2d {
 public:
  Vector2d() : m_x(0.0), m_y(0.0) {}
  Vector2d(double x, double y) : m_x(x), m_y(y) {}

  Vector2d(const Vector2d& other) : m_x(other.m_x), m_y(other.m_y) {}

  Vector2d& operator=(const Vector2d& other) {
    if (this != &other) {
      m_x = other.m_x;
      m_y = other.m_y;
    }
    return *this;
  }

  Vector2d(Vector2d&& other) noexcept
      : m_x(std::exchange(other.m_x, 0.0)),
        m_y(std::exchange(other.m_y, 0.0)) {}

  Vector2d& operator=(Vector2d&& other) noexcept {
    if (this != &other) {
      m_x = std::exchange(other.m_x, 0.0);
      m_y = std::exchange(other.m_y, 0.0);
    }
    return *this;
  }

  double x() const {
    return m_x;
  }
  double y() const {
    return m_y;
  }
  void setX(double x) {
    m_x = x;
  }
  void setY(double y) {
    m_y = y;
  }

  Vector2d operator+(const Vector2d& other) const {
    return Vector2d(m_x + other.m_x, m_y + other.m_y);
  }

  Vector2d operator-(const Vector2d& other) const {
    return Vector2d(m_x - other.m_x, m_y - other.m_y);
  }

  Vector2d operator-(Vector2d&& other) const {
    other.m_x -= m_x;
    other.m_y -= m_y;
    return std::move(other);
  }

  Vector2d operator*(double scalar) const {
    return Vector2d(m_x * scalar, m_y * scalar);
  }

  friend Vector2d operator*(double scalar, const Vector2d& v) {
    return v * scalar;
  }

  Vector2d operator/(double scalar) const {
    return Vector2d(m_x / scalar, m_y / scalar);
  }

  double operator*(const Vector2d& other) const {
    return m_x * other.m_x + m_y * other.m_y;
  }

  void normalize() {
    double length = norm();
    if (length > 0) {
      m_x /= length;
      m_y /= length;
    }
  }

  Vector2d normalized() const {
    double length = norm();
    if (length > 0) {
      return Vector2d(m_x / length, m_y / length);
    }
    return Vector2d();
  }

  double norm() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
  }

 private:
  double m_x;
  double m_y;
};

#endif
