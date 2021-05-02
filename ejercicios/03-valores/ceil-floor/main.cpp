#include <iostream>
#include <cmath>

int main() {
  std::cout << "Valor:";
  double x;
  std::cin >> x;

  auto bajo = std::lrint(std::floor(x));
  auto alto = static_cast<long>(std::ceil(x));

  std::cout << "Inferior: " << bajo << "\n";
  std::cout << "Alto: " << alto << "\n";
}
