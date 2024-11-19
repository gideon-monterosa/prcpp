#include <filesystem>
#include <iostream>
#include <string>

#ifndef UTIL_H
#define UTIL_H

namespace fs = std::filesystem;

namespace Util {

void parse_pargs(int argc, char* argv[], size_t& imageWidth, size_t& imageHeight, double& cellSize, int& seed,
                 fs::path& outputFile) {

    if (argc >= 3) {
        imageWidth = std::atol(argv[1]);
        imageHeight = std::atol(argv[2]);
    }

    if (argc >= 4) {
        cellSize = std::atof(argv[3]);
    }

    if (argc >= 5) {
        seed = atoi(argv[4]);
    }

    if (argc >= 6) {
        outputFile = std::string(argv[5]);
    }
}
} // namespace Util

#endif // UTIL_H