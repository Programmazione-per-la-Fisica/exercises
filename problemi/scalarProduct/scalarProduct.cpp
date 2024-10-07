
#include <cassert>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int scalarProduct(const std::vector<int>& v, const std::vector<int>& w) {
	assert(v.size() == w.size());
	const size_t n = v.size();

	int result = 0;
	for (size_t i = 0; i < n; ++i) {
		result += v[i] * w[i];
	}

	return result;
}

TEST_CASE("Test scalar product") {
	const std::vector<int> v{1, 2, 3};
	const std::vector<int> w{4, 5, 6};
	CHECK_EQ(scalarProduct(v, w), 32);

	const std::vector<int> x{1, 2, 3, 4};
	const std::vector<int> y{5, 6, 7, 8};
	CHECK_EQ(scalarProduct(x, y), 70);

	const std::vector<int> z{3};
	const std::vector<int> t{2};
	CHECK_EQ(scalarProduct(z, t), 6);
}
