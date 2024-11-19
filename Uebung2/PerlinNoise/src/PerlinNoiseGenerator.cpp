#include <cmath>

#include "PerlinNoiseGenerator.h"

double fade(double t) {
  // 6t^5 - 15t^4 + 10t^3
  return t * t * t * (t * (t * 6 - 15) + 10);
}

double lerp(double a, double b, double t) {
  return a + t * (b - a);
}

double PerlinNoiseGenerator::eval(const Vector2d& p) {
  int x0 = static_cast<int>(std::floor(p.x()));
  int y0 = static_cast<int>(std::floor(p.y()));
  int x1 = x0 + 1;
  int y1 = y0 + 1;

  double sx = p.x() - x0;
  double sy = p.y() - y0;

  double u = fade(sx);
  double v = fade(sy);

  auto getGradient = [&](int x, int y) -> Vector2d& {
    x = x % static_cast<int>(m_gridWidth);
    y = y % static_cast<int>(m_gridHeight);
    if (x < 0) x += m_gridWidth;
    if (y < 0) y += m_gridHeight;
    return m_gradients[y * m_gridWidth + x];
  };

  Vector2d d0(sx, sy);
  Vector2d d1(sx - 1, sy);
  Vector2d d2(sx, sy - 1);
  Vector2d d3(sx - 1, sy - 1);

  double dot0 = getGradient(x0, y0) * d0;
  double dot1 = getGradient(x1, y0) * d1;
  double dot2 = getGradient(x0, y1) * d2;
  double dot3 = getGradient(x1, y1) * d3;

  double ix0 = lerp(dot0, dot1, u);
  double ix1 = lerp(dot2, dot3, u);

  double value = lerp(ix0, ix1, v);

  if (value < -1.0) value = -1.0;
  if (value > 1.0) value = 1.0;

  return value;
}
