#include <gtest/gtest.h>
#include <random>

#include "PerlinNoiseGenerator.h"
#include "Vector2d.h"

TEST(Vector2d, Components) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    double x = dist(gen);
    double y = dist(gen);

    const Vector2d v(x, y);

    EXPECT_DOUBLE_EQ(v.x(), x);
    EXPECT_DOUBLE_EQ(v.y(), y);
}

TEST(Vector2d, Addition) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v1(dist(gen), dist(gen));
    Vector2d v2(dist(gen), dist(gen));

    Vector2d vRes = v1 + v2;

    EXPECT_DOUBLE_EQ(vRes.x(), v1.x() + v2.x());
    EXPECT_DOUBLE_EQ(vRes.y(), v1.y() + v2.y());
}

TEST(Vector2d, Subtraction) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v1(dist(gen), dist(gen));
    Vector2d v2(dist(gen), dist(gen));

    Vector2d vRes = v1 - v2;

    EXPECT_DOUBLE_EQ(vRes.x(), v1.x() - v2.x());
    EXPECT_DOUBLE_EQ(vRes.y(), v1.y() - v2.y());
}

TEST(Vector2d, SubtractionLHSRValue) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v1(dist(gen), dist(gen));
    Vector2d v1Copy(v1);

    Vector2d v2(dist(gen), dist(gen));

    Vector2d vRes = std::move(v1) - v2;

    EXPECT_DOUBLE_EQ(vRes.x(), v1Copy.x() - v2.x());
    EXPECT_DOUBLE_EQ(vRes.y(), v1Copy.y() - v2.y());
    EXPECT_DOUBLE_EQ(v1.x(), 0.0);
    EXPECT_DOUBLE_EQ(v1.y(), 0.0);
}

TEST(Vector2d, SubtractionRHSRValue) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v1(dist(gen), dist(gen));
    Vector2d v2(dist(gen), dist(gen));
    Vector2d v2Copy(v2);

    Vector2d vRes = v1 - std::move(v2);

    EXPECT_DOUBLE_EQ(vRes.x(), v1.x() - v2Copy.x());
    EXPECT_DOUBLE_EQ(vRes.y(), v1.y() - v2Copy.y());
    EXPECT_DOUBLE_EQ(v2.x(), 0.0);
    EXPECT_DOUBLE_EQ(v2.y(), 0.0);
}

TEST(Vector2d, MultiplicationWithConstant) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v(dist(gen), dist(gen));
    double c = dist(gen);

    Vector2d vRes = v * c;

    EXPECT_DOUBLE_EQ(vRes.x(), v.x() * c);
    EXPECT_DOUBLE_EQ(vRes.y(), v.y() * c);

    vRes = c * v;

    EXPECT_DOUBLE_EQ(vRes.x(), c * v.x());
    EXPECT_DOUBLE_EQ(vRes.y(), c * v.y());
}

TEST(Vector2d, MultiplicationWithConstantRValue) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v(dist(gen), dist(gen));
    Vector2d vCopy(v);

    double c = dist(gen);

    Vector2d vRes = std::move(v) * c;

    EXPECT_DOUBLE_EQ(vRes.x(), vCopy.x() * c);
    EXPECT_DOUBLE_EQ(vRes.y(), vCopy.y() * c);

    EXPECT_DOUBLE_EQ(v.x(), 0.0);
    EXPECT_DOUBLE_EQ(v.y(), 0.0);

    v = Vector2d(dist(gen), dist(gen));
    vCopy = v;
    vRes = c * std::move(v);

    EXPECT_DOUBLE_EQ(vRes.x(), c * vCopy.x());
    EXPECT_DOUBLE_EQ(vRes.y(), c * vCopy.y());

    EXPECT_DOUBLE_EQ(v.x(), 0.0);
    EXPECT_DOUBLE_EQ(v.y(), 0.0);
}

TEST(Vector2d, DivisionWithConstant) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v(dist(gen), dist(gen));
    double c = dist(gen);

    Vector2d vRes = v / c;

    EXPECT_DOUBLE_EQ(vRes.x(), v.x() / c);
    EXPECT_DOUBLE_EQ(vRes.y(), v.y() / c);
}

TEST(Vector2d, DivisionWithConstantRValue) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v(dist(gen), dist(gen));
    Vector2d vCopy(v);

    double c = dist(gen);

    Vector2d vRes = std::move(v) / c;

    EXPECT_DOUBLE_EQ(vRes.x(), vCopy.x() / c);
    EXPECT_DOUBLE_EQ(vRes.y(), vCopy.y() / c);
    EXPECT_DOUBLE_EQ(v.x(), 0.0);
    EXPECT_DOUBLE_EQ(v.y(), 0.0);
}

TEST(Vector2d, DotProduct) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v1(dist(gen), dist(gen));
    Vector2d v2(dist(gen), dist(gen));

    double dotP = v1 * v2;

    EXPECT_DOUBLE_EQ(dotP, v1.x() * v2.x() + v1.y() * v2.y());
}

TEST(Vector2d, Norm) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);

    Vector2d v(dist(gen), dist(gen));

    double dotP = v.norm();

    EXPECT_DOUBLE_EQ(dotP, std::sqrt(v.x() * v.x() + v.y() * v.y()));
}

TEST(Vector2d, Normalized) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(1, 2);

    const Vector2d v(dist(gen), dist(gen));

    Vector2d vRes = v.normalized();
    double vResNorm = std::sqrt(vRes.x() * vRes.x() + vRes.y() * vRes.y());

    EXPECT_DOUBLE_EQ(vResNorm, 1.0);
}

TEST(Vector2d, Normalize) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(1, 2);

    Vector2d v(dist(gen), dist(gen));

    v.normalize();
    double vResNorm = std::sqrt(v.x() * v.x() + v.y() * v.y());

    EXPECT_DOUBLE_EQ(vResNorm, 1.0);
}

TEST(Vector2d, PerlinNoiseGeneratorEval) {
    size_t gridSize = 5;
    PerlinNoiseGenerator perlin(5);

    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            double val = perlin.eval(Vector2d(y + 0.5, x + 0.5));

            EXPECT_GE(val, -1.0);
            EXPECT_LE(val, 1.0);
        }
    }
}