#include <iostream>

#include "fecha.hpp"

int main() {
  fecha f{4, mes::septiembre, 1969};
  f.suma_dia(60);
  std::cout << "Fecha: " << f << "\n";
  auto m = f.mes_anyo();
  auto g = m++;
  std::cout << "Mes: " << g << "\n";
}
