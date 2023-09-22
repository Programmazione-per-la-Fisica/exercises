#include <iostream>
#include <numeric>
#include <vector>

double return_sum(const std::vector<double>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0.);
}

int main() {
    std::cout << "Expected result: " << 16.5 << '\n';
    std::cout << "Obtained result: " << return_sum({3.5, 10.4, 2.6}) << '\n';
}
