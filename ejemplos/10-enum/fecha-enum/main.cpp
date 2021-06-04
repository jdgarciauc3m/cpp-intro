#include "fecha.hpp"

#include <iostream>

int main() {
  fecha f{4, mes_id::septiembre, 1969};
  f.suma_dia(60);
  std::cout << "Fecha: ";
  f.imprime();
}
