#include <cassert>
#include <vector>

#ifndef IMAGE_H
#define IMAGE_H

class Image {
  public:
    Image() = delete;
    Image(size_t width, size_t height) : m_width(width), m_height(height), m_data() {
        m_data.resize(m_width * m_height);
    }

    size_t width() const { return m_width; }
    size_t height() const { return m_height; }

    uint8_t at(size_t x, size_t y) const {
        assert(x < m_width && y < m_height);
        return m_data[m_width * y + x];
    }

    uint8_t& at(size_t x, size_t y) {
        assert(x < m_width && y < m_height);
        return m_data[m_width * y + x];
    }

  private:
    size_t m_width;
    size_t m_height;
    std::vector<uint8_t> m_data;
};

#endif // IMAGE_H