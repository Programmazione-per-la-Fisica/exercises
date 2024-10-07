
#include <cassert>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::vector<int> vectorProduct(const std::vector<int>& v, const std::vector<int>& w) {
	assert(v.size() == w.size());
	assert(v.size() == 3);

	std::vector<int> result(3);
	result[0] = v[1] * w[2] - v[2] * w[1];
	result[1] = v[2] * w[0] - v[0] * w[2];
	result[2] = v[0] * w[1] - v[1] * w[0];

	return result;
}

// utility only used for testing
std::vector<int> negate(const std::vector<int>& vec) {
  std::vector<int> result(vec.size());
	for (size_t i = 0; i < vec.size(); ++i) {
		result[i] = -vec[i];
	}
	return result;
}

TEST_CASE("Test vector product of 2D vectors") {
  const std::vector<int> v{1, 0, 0};
  const std::vector<int> w{0, 1, 0};
  const std::vector<int> product{0, 0, 1};
  const auto result = vectorProduct(v, w);

  CHECK_EQ(result.size(), 3);
  CHECK(result == product);

  // check opposite
  const auto result2 = vectorProduct(w, v);
  CHECK_EQ(result2.size(), 3);
  CHECK(result2 == negate(product));
}

TEST_CASE("Test vector product") {
  const std::vector<int> v{1, 2, 3};
  const std::vector<int> w{4, 5, 6};
  const std::vector<int> product{-3, 6, -3};
  const auto result = vectorProduct(v, w);

  CHECK_EQ(result.size(), 3);
  CHECK(result == product);

  // check opposite
  const auto result2 = vectorProduct(w, v);
  CHECK_EQ(result2.size(), 3);
  CHECK(result2 == negate(product));
}

TEST_CASE("Test vector product of overlapping vectors") {
  const std::vector<int> v{1, 2, 3};
  const std::vector<int> w{2, 4, 6};
  const std::vector<int> product{0, 0, 0};
  const auto result = vectorProduct(v, w);

  CHECK_EQ(result.size(), 3);
  CHECK(result == product);

  const auto result2 = vectorProduct(w, v);
  CHECK_EQ(result2.size(), 3);
  CHECK(result2 == product);
  CHECK(result2 == negate(product));
}
