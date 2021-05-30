#include "fecha.hpp"
#include <iostream>

int main() {
  fecha f;
  f.inicia(4, 9, 1969);
  f.suma_dia(60);
  std::cout << f.dia << "/" << f.mes << "/" << f.anyo << "\n";
}
