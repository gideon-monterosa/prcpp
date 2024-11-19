#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "Image.h"
#include "PGMWriter.h"
#include "PerlinNoiseGenerator.h"
#include "Util.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  size_t imageWidth = 1000;
  size_t imageHeight = 1000;
  double cellSize = 50;
  int seed = 0;
  fs::path outputFile;

  Util::parse_pargs(argc, argv, imageWidth, imageHeight, cellSize, seed,
                    outputFile);

  const std::string fileName =
      std::string("perlinNoise_") + std::to_string(seed) + ".pgm";
  outputFile = fs::path(PROJECT_SOURCE_DIR) / "output" / fileName;

  std::cout << "image_width = " << imageWidth << std::endl;
  std::cout << "image_height = " << imageHeight << std::endl;
  std::cout << "cellSize = " << cellSize << std::endl;
  std::cout << "seed = " << seed << std::endl;
  std::cout << "outputFile = " << outputFile << std::endl;

  PerlinNoiseGenerator perlin(imageWidth / cellSize, imageHeight / cellSize,
                              seed);
  Image image(imageWidth, imageHeight);

  for (int y = 0; y < imageHeight; ++y) {
    for (int x = 0; x < imageWidth; ++x) {
      Vector2d p(static_cast<double>(x) / cellSize,
                 static_cast<double>(y) / cellSize);
      double noiseValue = perlin.eval(p);

      int pixelValue = static_cast<int>((noiseValue + 1.0) * 0.5 * 255);
      image.at(x, y) = static_cast<uint8_t>(pixelValue);
    }
  }

  PGMWriter::write(outputFile, image);

  return 0;
}
