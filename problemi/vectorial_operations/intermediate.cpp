#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

struct Vector3 {
  double x{0.};
  double y{0.};
  double z{0.};
  Vector3& operator+=(Vector3 const& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }
  Vector3& operator*=(double other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
  }
};

Vector3 operator+(Vector3 const& l, Vector3 const& r) {
  auto result{l};
  return result += r;
}

Vector3 operator*(Vector3 const& l, double r) {
  auto result{l};
  return result *= r;
}

Vector3 operator*(double l, Vector3 const& r) {
  auto result{r};
  return result *= l;
}

Vector3 operator-(Vector3 const& l, Vector3 const& r) {
  auto result{l};
  return result += -1. * r;
}

double dot(Vector3 const& l, Vector3 const& r) {
  return l.x * r.x + l.y * r.y + l.z * r.z;
}

Vector3 cross(Vector3 const& l, Vector3 const& r) {
  return {l.y * r.z - r.y * l.z, l.z * r.x - r.z * l.x, l.x * r.y - r.x * l.y};
}

bool vector3_approx(Vector3 const& v1, Vector3 const& v2) {
  return doctest::Approx(v1.x) == v2.x && doctest::Approx(v1.y) == v2.y &&
         doctest::Approx(v1.z) == v2.z;
}

TEST_CASE("Testing the operators") {
  Vector3 v1{1.5, 3., 4.5};
  Vector3 v2{5., 12.2, -8.1};

  SUBCASE("Testing sums") {
    Vector3 r1 = v1 + v2;
    Vector3 r2{r1};
    r2 += v1;

    CHECK(vector3_approx(r1, {6.5, 15.2, -3.6}));
    CHECK(vector3_approx(r2, {8., 18.2, 0.9}));
  }

  SUBCASE("Testing difference") {
    Vector3 r1 = v2 - v1;
    CHECK(vector3_approx(r1, {3.5, 9.2, -12.6}));
  }

  SUBCASE("Testing products") {
    double c1{2.};
    double c2{0.4};

    Vector3 r1 = v1 * c1;
    Vector3 r2{v1};
    r2 *= c2;

    Vector3 r3 = c1 * v1;

    CHECK(vector3_approx(r1, {3., 6., 9.}));
    CHECK(vector3_approx(r1, {0.6, 1.2, 1.8}));
    CHECK(vector3_approx(r3, {3., 6., 9.}));
  }
}

TEST_CASE("Testing dot and cross") {
  Vector3 v1{1.5, 3., 4.5};
  Vector3 v2{5., 12.2, -8.2};
  Vector3 v3{4.5, 9., 13.5};   // parallel to v1
  Vector3 v4{-5., 1., 1.};     // orthogonal to v1
  Vector3 v5{-10., -1., -2.};  // >90 degrees w.r.t. v1

  SUBCASE("Testing dot") {
    double r1 = dot(v1, v1);
    double r2 = dot(v1, v2);
    double r3 = dot(v1, v3);
    double r4 = dot(v1, v4);
    double r5 = dot(v1, v5);

    CHECK(doctest::Approx(r1) == 31.5);
    CHECK(doctest::Approx(r2) == 7.2);
    CHECK(doctest::Approx(r3) == 94.5);
    CHECK(doctest::Approx(r4) == 0.);    // result is 0
    CHECK(doctest::Approx(r5) == -27.);  //  result < 0
  }

  SUBCASE("Testing cross") {
    Vector3 r1 = cross(v1, v2);
    Vector3 r2 = cross(v2, v1);
    Vector3 r3 = cross(v1, v3);

    CHECK(vector3_approx(r1, {-79.5, 34.8, 3.3}));
    CHECK(vector3_approx(r2, {79.5, -34.8, -3.3}));
    CHECK(vector3_approx(r3, {0., 0., 0.}));  // parallel to v1, result is 0,0,0
  }

  SUBCASE("Testing both") {
    double norm2_v1 = dot(v1, v1);
    double norm2_v4 = dot(v4, v4);
    Vector3 v1_x_v4 = cross(v1, v4);
    CHECK(doctest::Approx(dot(v1_x_v4, v1_x_v4)) == norm2_v1 * norm2_v4);
  }
}