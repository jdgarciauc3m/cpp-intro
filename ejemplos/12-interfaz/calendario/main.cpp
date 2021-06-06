#include <iostream>
using namespace std;

#include "fecha.hpp"
using namespace calendario;

int main() {
  fecha f{4, mes_id::septiembre, 1969};
  f.suma_dias(60);
  f.dia();
  cout << "Fecha: " << f << endl;
}
