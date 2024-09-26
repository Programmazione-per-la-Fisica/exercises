
#include <cassert>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::vector<std::vector<int>> matrixMultiplication(
    const std::vector<std::vector<int>> &A,
    const std::vector<std::vector<int>> &B) {
  int n = A.size();
  int m = A[0].size();
  int p = B[0].size();

  assert(m == B.size());

  std::vector<std::vector<int>> C(n, std::vector<int>(p, 0));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < p; ++j) {
      for (size_t k = 0; k < m; ++k) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

TEST_CASE("Multiply 5x1 and 1x5 matrices (vectors)") {
  std::vector<std::vector<int>> A{{8}, {2}, {6}, {10}, {3}};
  std::vector<std::vector<int>> B{{9, 2, 4, 7, 11}};
  std::vector<std::vector<int>> C{{72, 16, 32, 56, 88},
                                  {18, 4, 8, 14, 22},
                                  {54, 12, 24, 42, 66},
                                  {90, 20, 40, 70, 110},
                                  {27, 6, 12, 21, 33}};
  const auto result = matrixMultiplication(A, B);

  CHECK_EQ(result.size(), 5);
  CHECK_EQ(result[0].size(), 5);
  CHECK(result == C);
}

TEST_CASE("Multiply 1x5 and 5x1 matrices (vectors)") {
  std::vector<std::vector<int>> A{{8, 2, 6, 10, 3}};
  std::vector<std::vector<int>> B{{9}, {2}, {4}, {7}, {11}};
  std::vector<std::vector<int>> C{{203}};
  const auto result = matrixMultiplication(A, B);

  CHECK_EQ(result.size(), 1);
  CHECK_EQ(result[0].size(), 1);
  CHECK(matrixMultiplication(A, B) == C);
}

TEST_CASE("Multiply 4x2 and 2x4 matrices") {
  std::vector<std::vector<int>> A{{6, 4}, {1, 11}, {10, 9}, {3, 7}};
  std::vector<std::vector<int>> B{{9, 1, 17, 12}, {7, 20, 3, 0}};
  std::vector<std::vector<int>> C{{82, 86, 114, 72},
                                  {86, 221, 50, 12},
                                  {153, 190, 197, 120},
                                  {76, 143, 72, 36}};
  const auto result = matrixMultiplication(A, B);

  CHECK_EQ(result.size(), 4);
  CHECK_EQ(result[0].size(), 4);
  CHECK(matrixMultiplication(A, B) == C);
}

TEST_CASE("Multiply 2x3 and 3x2 matrices") {
  std::vector<std::vector<int>> A{{5, 2, 3}, {8, 1, 9}};
  std::vector<std::vector<int>> B{{4, 11}, {9, 10}, {7, 8}};
  std::vector<std::vector<int>> C{{59, 99}, {104, 170}};
  const auto result = matrixMultiplication(A, B);

  CHECK_EQ(result.size(), 2);
  CHECK_EQ(result[0].size(), 2);
  CHECK(matrixMultiplication(A, B) == C);
}

TEST_CASE("Multiply 4x4 matrices") {
  std::vector<std::vector<int>> A{
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  std::vector<std::vector<int>> B{
      {16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
  std::vector<std::vector<int>> C{{80, 70, 60, 50},
                                  {240, 214, 188, 162},
                                  {400, 358, 316, 274},
                                  {560, 502, 444, 386}};
  const auto result = matrixMultiplication(A, B);

  CHECK_EQ(result.size(), 4);
  CHECK_EQ(result[0].size(), 4);
  CHECK(matrixMultiplication(A, B) == C);
}
