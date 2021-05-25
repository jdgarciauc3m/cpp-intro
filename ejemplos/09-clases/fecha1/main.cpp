#include <iostream>

#include "fecha.hpp"

int main() {
  fecha f;
  inicia(f, 4, 9, 1969);
  suma_dia(f,60);
  std::cout << f.dia << "/" << f.mes << "/" << f.anyo << "\n";
}
