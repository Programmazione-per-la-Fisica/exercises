
#include <cassert>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::vector<std::vector<int>> matrixSum(
    const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B) {
  const size_t n = A.size();
  const size_t m = A[0].size();
  assert(n == B.size());
  assert(m == B[0].size());

  std::vector<std::vector<int>> C(n, std::vector<int>(m, 0));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }

  return C;
}

TEST_CASE("Test rectangular matrices") {
  const std::vector<std::vector<int>> A{{1, 2, 3}, {4, 5, 6}};
  const std::vector<std::vector<int>> B{{6, 5, 4}, {3, 2, 1}};
  const std::vector<std::vector<int>> C{{7, 7, 7}, {7, 7, 7}};
  const auto result = matrixSum(A, B);

  CHECK_EQ(result.size(), 2);
  CHECK_EQ(result[0].size(), 3);
  CHECK(result == C);

  const std::vector<std::vector<int>> D{{1, 2}, {3, 4}, {5, 6}};
  const std::vector<std::vector<int>> E{{6, 5}, {4, 3}, {2, 1}};
  const std::vector<std::vector<int>> F{{7, 7}, {7, 7}, {7, 7}};
  const auto result2 = matrixSum(D, E);

  CHECK_EQ(result2.size(), 3);
  CHECK_EQ(result2[0].size(), 2);
  CHECK(result2 == F);
}

TEST_CASE("Test square matrices") {
  const std::vector<std::vector<int>> A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  const std::vector<std::vector<int>> B{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  const std::vector<std::vector<int>> C{
      {10, 10, 10}, {10, 10, 10}, {10, 10, 10}};
  const auto result = matrixSum(A, B);

  CHECK_EQ(result.size(), 3);
  CHECK_EQ(result[0].size(), 3);
  CHECK(result == C);
}
