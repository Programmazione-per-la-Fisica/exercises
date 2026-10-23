
#include <cassert>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& matrix) {
  const size_t rows = matrix.size();
  const size_t cols = matrix[0].size();
  std::vector<std::vector<int>> result(cols, std::vector<int>(rows));
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      result[j][i] = matrix[i][j];
    }
  }
  return result;
}

TEST_CASE("Transpose 2x5 matrix") {
  std::vector<std::vector<int>> A{{8, 2, 6, 10, 3}, {9, 2, 4, 7, 11}};
  std::vector<std::vector<int>> A_t{{8, 9}, {2, 2}, {6, 4}, {10, 7}, {3, 11}};
  const auto result = transpose(A);
  CHECK_EQ(result.size(), 5);
  CHECK_EQ(result[0].size(), 2);
  CHECK(result == A_t);
}

TEST_CASE("Transpose 5x2 matrix") {
  std::vector<std::vector<int>> A{{8, 9}, {2, 2}, {6, 4}, {10, 7}, {3, 11}};
  std::vector<std::vector<int>> A_t{{8, 2, 6, 10, 3}, {9, 2, 4, 7, 11}};
  const auto result = transpose(A);

  CHECK_EQ(result.size(), 2);
  CHECK_EQ(result[0].size(), 5);
  CHECK(result == A_t);
}

TEST_CASE("Transpose 5x5 matrix") {
  std::vector<std::vector<int>> A{{8, 2, 6, 10, 3},
                {9, 2, 4, 7, 11},
                {1, 5, 7, 3, 2},
                {4, 6, 8, 9, 10},
                {3, 1, 2, 4, 5}};
  std::vector<std::vector<int>> A_t{{8, 9, 1, 4, 3},
                  {2, 2, 5, 6, 1},
                  {6, 4, 7, 8, 2},
                  {10, 7, 3, 9, 4},
                  {3, 11, 2, 10, 5}};
  const auto result = transpose(A);

  CHECK_EQ(result.size(), 5);
  CHECK_EQ(result[0].size(), 5);
  CHECK(result == A_t);
}
