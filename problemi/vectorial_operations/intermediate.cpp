#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

struct Vector {
  double x{};
  double y{};
  double z{};
  Vector& operator+=(Vector const& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }
  Vector& operator*=(double other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
  }
};

Vector operator+(Vector const& l, Vector const& r) {
  auto result{l};
  return result += r;
}

Vector operator*(Vector const& l, double r) {
  auto result{l};
  return result *= r;
}

Vector operator*(double l, Vector const& r) {
  auto result{r};
  return result *= l;
}

double operator*(Vector const& l, Vector const& r) {
  return l.x * r.x + l.y * r.y + l.z * r.z;
}

Vector operator-(Vector const& l, Vector const& r) {
  auto result{l};
  return result += -1 * r;
}

TEST_CASE("Testing the vectorial sums") {
  Vector v1{1.5, 3.0, 4.5};
  Vector v2{5.0, 12.2, -8.1};

  Vector r1 = v1 + v2;
  Vector r2{r1};
  r2 += v1;
  CHECK(doctest::Approx(r1.x) == 6.5);
  CHECK(doctest::Approx(r1.y) == 15.2);
  CHECK(doctest::Approx(r1.z) == -3.6);

  CHECK(doctest::Approx(r2.x) == 8.0);
  CHECK(doctest::Approx(r2.y) == 18.2);
  CHECK(doctest::Approx(r2.z) == 0.9);
}

TEST_CASE("Testing the vectorial difference") {
  Vector v1{1.5, 3.0, 4.5};
  Vector v2{5.0, 12.2, -8.1};

  Vector r1 = v2 - v1;
  CHECK(doctest::Approx(r1.x) == 3.5);
  CHECK(doctest::Approx(r1.y) == 9.2);
  CHECK(doctest::Approx(r1.z) == -12.6);
}

TEST_CASE("Testing the products between vectors and scalars") {
  Vector v1{1.5, 3.0, 4.5};
  double c1{2.0};
  double c2{0.4};

  Vector r1 = v1 * c1;
  Vector r2{v1};
  r2 *= c2;

  Vector r3 = c1 * v1;

  CHECK(doctest::Approx(r1.x) == 3.0);
  CHECK(doctest::Approx(r1.y) == 6.0);
  CHECK(doctest::Approx(r1.z) == 9.0);

  CHECK(doctest::Approx(r2.x) == 0.6);
  CHECK(doctest::Approx(r2.y) == 1.2);
  CHECK(doctest::Approx(r2.z) == 1.8);

  CHECK(doctest::Approx(r3.x) == 3.0);
  CHECK(doctest::Approx(r3.y) == 6.0);
  CHECK(doctest::Approx(r3.z) == 9.0);
}

TEST_CASE("Testing the scalar product between vectors") {
  Vector v1{1.5, 3.0, 4.5};
  Vector v2{5.0, 12.2, -8.2};
  Vector v3{-5.0, 1.0, 1.0};  // orthogonal to v1
  Vector v4{-10.0, -1.0, -2.0};  // >90 degrees w.r.t. v1

  double r1 = v1 * v1;
  double r2 = v1 * v2;
  double r3 = v1 * v3;
  double r4 = v1 * v4;

  CHECK(doctest::Approx(r1) == 31.5);
  CHECK(doctest::Approx(r2) == 7.2);
  CHECK(doctest::Approx(r3) == 0.0);  // orthogonal to v1, result is 0
  CHECK(doctest::Approx(r4) == -27.0);  // >90 degrees w.r.t. v1, result < 0
}