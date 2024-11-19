#include <cassert>
#include <memory>
#include <numbers>
#include <random>
#include <vector>

#include "Random.h"
#include "Vector2d.h"

#ifndef PERLIN_NOISE_GENERATOR_H
#define PERLIN_NOISE_GENERATOR_H

class PerlinNoiseGenerator {
 public:
  PerlinNoiseGenerator() = delete;
  PerlinNoiseGenerator(size_t gridSize)
      : PerlinNoiseGenerator(gridSize, gridSize, 0) {}
  PerlinNoiseGenerator(size_t gridWidth, size_t gridHeight)
      : PerlinNoiseGenerator(gridWidth, gridHeight, 0) {}
  PerlinNoiseGenerator(size_t gridWidth, size_t gridHeight, int seed)
      : m_rand(seed),
        m_gridWidth(gridWidth),
        m_gridHeight(gridHeight),
        m_gradients(std::make_unique<Vector2d[]>(gridWidth * gridHeight)) {
    for (size_t y = 0; y < m_gridHeight; ++y) {
      for (size_t x = 0; x < m_gridWidth; ++x) {
        double angle = m_rand.next() * 2 * PI;
        m_gradients[y * m_gridWidth + x] =
            Vector2d(std::cos(angle), std::sin(angle));
      }
    }
  }

  int seed() const {
    return m_rand.seed();
  }
  double eval(const Vector2d& p);

 private:
  static constexpr double PI = 3.1415926535897932384;

 private:
  Random m_rand;
  size_t m_gridWidth;
  size_t m_gridHeight;
  std::unique_ptr<Vector2d[]> m_gradients;
};

#endif  // PERLIN_NOISE_GENERATOR_H
