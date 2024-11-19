#include <iostream>

#include "PerlinNoiseGenerator.h"

double smooth(double t) {
  return 3 * t * t - 2 * t * t * t;
}

double PerlinNoiseGenerator::eval(const Vector2d& p) {
  int x0 = static_cast<int>(std::floor(p.x())) % m_gridWidth;
  int y0 = static_cast<int>(std::floor(p.y())) % m_gridHeight;
  int x1 = (x0 + 1) % m_gridWidth;
  int y1 = (y0 + 1) % m_gridHeight;

  Vector2d d00 = p - Vector2d(x0, y0);
  Vector2d d10 = p - Vector2d(x1, y0);
  Vector2d d01 = p - Vector2d(x0, y1);
  Vector2d d11 = p - Vector2d(x1, y1);

  double n00 = d00 * m_gradients[y0 * m_gridWidth + x0];
  double n10 = d10 * m_gradients[y0 * m_gridWidth + x1];
  double n01 = d01 * m_gradients[y1 * m_gridWidth + x0];
  double n11 = d11 * m_gradients[y1 * m_gridWidth + x1];

  double wx = p.x() - std::floor(p.x());
  double wy = p.y() - std::floor(p.y());

  double i0 = n00 + smooth(wx) * (n10 - n00);
  double i1 = n01 + smooth(wx) * (n11 - n01);
  double value = i0 + smooth(wy) * (i1 - i0);

  return value;
}
