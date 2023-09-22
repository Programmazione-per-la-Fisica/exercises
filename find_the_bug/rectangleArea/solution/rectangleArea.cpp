#include <iostream>

class rectangle {
    private:
        double m_base;
        double m_height;
    public:
        rectangle(double base=0., double height=0.) : m_base{base}, m_height{height} {}

		// Getters
		double base() const { return m_base; }
		double height() const { return m_height; }
};

double calculateArea(const rectangle& rect) {
    return rect.base() * rect.height();
}

int main() {
    rectangle r{4., 5.};
    std::cout << "The area is: " << calculateArea(r) << '\n';
}
