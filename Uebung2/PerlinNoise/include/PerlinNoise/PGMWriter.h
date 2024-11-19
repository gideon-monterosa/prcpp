#include <filesystem>
#include <fstream>

#include "Image.h"

#ifndef PGM_WRITER_H
#define PGM_WRITER_H

namespace fs = std::filesystem;

namespace PGMWriter {
void write(fs::path filePath, const Image& image) {

    if (!filePath.has_extension()) {
        filePath = filePath.string() + ".pgm";
    }

    std::ofstream file(filePath, std::ios::binary);

    file << "P5\n" << image.width() << ' ' << image.height() << "\n255\n";

    for (size_t y = 0; y < image.height(); ++y) {
        for (size_t x = 0; x < image.width(); ++x) {
            file << image.at(x, y);
        }
    }
}
} // namespace PGMWriter

#endif // PGM_WRITER_H