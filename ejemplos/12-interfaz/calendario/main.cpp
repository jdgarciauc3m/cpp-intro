#include <iostream>
using namespace std;

#include "fecha.h"
using namespace calendario;

int main() {
  fecha f{4, mes_id::septiembre, 1969};
  f.suma_dias(60);
  cout << "Fecha: " << f << endl;
}
