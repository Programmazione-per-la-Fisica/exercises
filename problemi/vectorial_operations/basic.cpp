#include <cstdlib>
#include <iostream>

int main() {
  int x1;
  int y1;
  int z1;
  std::cin >> x1 >> y1 >> z1;

  char op;
  std::cin >> op;

  int x2;
  int y2;
  int z2;
  std::cin >> x2 >> y2 >> z2;

  int xr{};
  int yr{};
  int zr{};

  switch (op) {
    case '+':
      xr = x1 + x2;
      yr = y1 + y2;
      zr = z1 + z2;
      break;
    case '*':
      xr = x1 * x2;
      yr = y1 * y2;
      zr = z1 * z2;
      break;
    case 'x':
      xr = y1 * z2 - y2 * z1;
      yr = z2 * x1 - z1 * x2;
      zr = x1 * y2 - x2 * y1;
      break;
    default:
      std::cout << "Operation " << op << " is not valid\n";
      return EXIT_FAILURE;
  }
  std::cout << "Operation " << op << " result: ( " << xr << " , " << yr << " , "
            << zr << " )\n";
}