#pragma once

#include <cassert>
#include <iostream>
#include <memory>

#include "Point.h"

class PointVector {
  size_t m_capacity;  // die Grösse des Arrays auf dem Heap
  size_t m_size;      // Anzahl Objekte im Array: m_size <= m_capacity
  std::unique_ptr<Point[]> m_data;  // Zeiger auf den Heap

 public:
  PointVector() : m_capacity(0), m_size(0), m_data(nullptr) {}
  // copy-ctor: deep copy
  PointVector(const PointVector& pv)
      : m_capacity(pv.m_capacity),
        m_size(pv.m_size),
        m_data(std::make_unique<Point[]>(m_capacity)) {
    // copy pv.m_data to m_data
    for (size_t i = 0; i < m_size; ++i) {
      m_data[i] = pv.m_data[i];
    }
  }
  // assignment operator: deep copy
  PointVector& operator=(const PointVector& pv) {
    if (this != &pv) {
      m_capacity = pv.m_capacity;
      m_size = pv.m_size;
      m_data = std::make_unique<Point[]>(m_capacity);
      for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = pv.m_data[i];
      }
    }
    return *this;
  }

  size_t capacity() const {
    return m_capacity;
  }
  size_t size() const {
    return m_size;
  }
  bool empty() const {
    return m_size == 0;
  }

  const Point& front() const {
    assert(m_size > 0);
    return m_data[0];
  }
  const Point& back() const {
    assert(m_size > 0);
    return m_data[m_size - 1];
  }
  Point& front() {
    assert(m_size > 0);
    return m_data[0];
  }
  Point& back() {
    assert(m_size > 0);
    return m_data[m_size - 1];
  }

  void pushBack(const Point& p) {
    if (m_size == m_capacity) {
      // PointVector is full
      m_capacity = 2 * m_capacity + 1;
      auto data = std::make_unique<Point[]>(m_capacity);

      // copy m_data to data
      for (size_t i = 0; i < m_size; ++i) {
        data[i] = m_data[i];
      }

      m_data = std::move(data);  // ownership movement
    }

    // add new point
    m_data[m_size++] = p;
  }

  friend std::ostream& operator<<(std::ostream& os, const PointVector& pv) {
    os << '[';
    if (!pv.empty()) os << pv.front();
    for (size_t i = 1; i < pv.m_size; ++i) {
      os << ',' << pv.m_data[i];
    }
    return os << ']';
  }
};
