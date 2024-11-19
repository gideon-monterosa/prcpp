#include <numbers>
#include <random>

#ifndef RANDOM_H
#define RANDOM_H

class Random {
  public:
    Random() : m_seed(0), m_gen(m_seed), m_dist(0.0, 1.0) {}
    Random(int seed) : m_seed(seed), m_gen(m_seed), m_dist(0.0, 1.0) {}
    Random(int seed, double min, double max) : m_seed(seed), m_gen(m_seed), m_dist(min, max) {}

    int seed() const { return m_seed; }
    double next() { return m_dist(m_gen); }

  private:
    int m_seed;
    std::mt19937 m_gen;
    std::uniform_real_distribution<> m_dist;
};

#endif // RANDOM_H