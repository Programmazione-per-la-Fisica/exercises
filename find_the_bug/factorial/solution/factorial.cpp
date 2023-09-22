#include <iostream>

long long int factorial(long long int x) {
    if (x == 0 || x == 1) {
        return 1;
    } else {
        return x * factorial(x-1);
    }
}

int main() {
    std::cout << "Result: " << factorial(13) << '\n';
    std::cout << "Expected result: " << 6227020800 << std::endl;
}
