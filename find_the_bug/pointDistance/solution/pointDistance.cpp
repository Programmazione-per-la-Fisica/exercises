#include <cmath>
#include <iostream>

template <typename T>
class Point {
    private:
        T m_x;
        T m_y;

    public:
        Point() = default;
        Point(T x, T y) : m_x{x}, m_y{y} {}

        // Getters
        T x() const {
            return m_x;
		}
        T y() const {
            return m_y;
        } 

        // Setters
        void set_x(T x) {
            m_x = x;
        }
        void set_y(T y) {
            m_y = y;
        }
};

template <typename T>
double distance(const Point<T>& p1, const Point<T>& p2) {
    return sqrt(pow(p1.x() - p2.x(), 2) + pow(p1.y() - p2.y(), 2));
}

int main() {
    Point<int> p1{2, 3};
    Point<int> p2{4, 1};

    std::cout << "The result is: " << distance(p1, p2) << '\n';
    std::cout << "The expected result is: " << 2*sqrt(2) << '\n';
}
