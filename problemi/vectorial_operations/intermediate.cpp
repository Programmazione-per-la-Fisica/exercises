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

Vector operator-(Vector const& l, Vector const& r) {
  auto result{l};
  return result += -1 * r;
}

double dot(Vector const& l, Vector const& r) {
  return l.x * r.x + l.y * r.y + l.z * r.z;
}

Vector cross(Vector const& l, Vector const& r) {
  return {l.y * r.z - r.y * l.z, l.z * r.x - r.z * l.x, l.x * r.y - r.x * l.y};
}

bool vector_approx(Vector v1, Vector v2) {
  return doctest::Approx(v1.x) == v2.x && doctest::Approx(v1.y) == v2.y &&
         doctest::Approx(v1.z) == v2.z;
}

TEST_CASE("Testing the operators") {
  Vector v1{1.5, 3.0, 4.5};
  Vector v2{5.0, 12.2, -8.1};

  SUBCASE("Testing sums") {
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

  SUBCASE("Testing difference") {
    Vector r1 = v2 - v1;
    CHECK(doctest::Approx(r1.x) == 3.5);
    CHECK(doctest::Approx(r1.y) == 9.2);
    CHECK(doctest::Approx(r1.z) == -12.6);
  }

  SUBCASE("Testing products") {
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
}

TEST_CASE("Testing dot and cross") {
  Vector v1{1.5, 3.0, 4.5};
  Vector v2{5.0, 12.2, -8.2};
  Vector v3{4.5, 9.0, 13.5};     // parallel to v1
  Vector v4{-5.0, 1.0, 1.0};     // orthogonal to v1
  Vector v5{-10.0, -1.0, -2.0};  // >90 degrees w.r.t. v1

  SUBCASE("Testing dot") {
    double r1 = dot(v1, v1);
    double r2 = dot(v1, v2);
    double r3 = dot(v1, v3);
    double r4 = dot(v1, v4);
    double r5 = dot(v1, v5);

    CHECK(doctest::Approx(r1) == 31.5);
    CHECK(doctest::Approx(r2) == 7.2);
    CHECK(doctest::Approx(r3) == 94.5);
    CHECK(doctest::Approx(r4) == 0.0);    // result is 0
    CHECK(doctest::Approx(r5) == -27.0);  //  result < 0
  }

  SUBCASE("Testing cross") {
    Vector r1 = cross(v1, v2);
    Vector r2 = cross(v2, v1);
    Vector r3 = cross(v1, v3);

    CHECK(vector_approx(r1, {-79.5, 34.8, 3.3}));
    CHECK(vector_approx(r2, {79.5, -34.8, -3.3}));
    CHECK(vector_approx(r3, {0.0, 0.0, 0.0}));  // parallel to v1, result is 0
  }

  SUBCASE("Testing both") {
    double norm2_v1 = dot(v1, v1);
    double norm2_v4 = dot(v4, v4);
    Vector v1_x_v4 = cross(v1, v4);
    CHECK(doctest::Approx(dot(v1_x_v4, v1_x_v4)) == norm2_v1 * norm2_v4);
  }
}