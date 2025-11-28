#include <cstdlib>
#include <iostream>

int main() {
  double x1;
  double y1;
  double z1;
  std::cin >> x1 >> y1 >> z1;

  if (std::cin.fail()) {
    std::cerr << "One or more vector-1 input parameters are not valid\n";
    return EXIT_FAILURE;
  }

  char op;
  std::cin >> op;

  if (std::cin.fail()) {
    std::cerr << "Operator is not a valid char\n";
    return EXIT_FAILURE;
  }

  double x2;
  double y2;
  double z2;
  std::cin >> x2 >> y2 >> z2;

  if (std::cin.fail()) {
    std::cerr << "One or more vector-2 input parameters are not valid\n";
    return EXIT_FAILURE;
  }

  double xr{0.};
  double yr{0.};
  double zr{0.};

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
      yr = z1 * x2 - z2 * x1;
      zr = x1 * y2 - x2 * y1;
      break;
    default:
      std::cerr << "Operation " << op << " is not valid\n";
      return EXIT_FAILURE;
  }
  std::cout << "Operation " << op << " result: ( " << xr << " , " << yr << " , "
            << zr << " )\n";
}