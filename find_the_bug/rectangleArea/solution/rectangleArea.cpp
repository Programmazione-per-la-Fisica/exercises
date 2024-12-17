#include <iostream>

class rectangle {
 private:
  double m_base;
  double m_height;

 public:
  rectangle(double base, double height) : m_base{base}, m_height{height} {}

  // Getters
  auto base() const { return m_base; }
  auto height() const { return m_height; }
};

auto calculateArea(const rectangle& rect) {
  return rect.base() * rect.height();
}

int main() {
  rectangle r{4., 5.};
  std::cout << "The area is: " << calculateArea(r) << '\n';
}
