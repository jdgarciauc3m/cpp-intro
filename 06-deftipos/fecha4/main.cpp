#include <iostream>
using namespace std;

#include "fecha.h"

int main() {
  fecha f{4, 9, 1969};
  f.suma_dia(60);
  cout << "Fecha: ";
  f.imprime();
}
