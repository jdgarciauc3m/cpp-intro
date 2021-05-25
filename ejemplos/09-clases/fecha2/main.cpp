#include <iostream>
using namespace std;

#include "fecha.h"

int main() {
  fecha f;
  f.inicia(4, 9, 1969);
  f.suma_dia(60);
  cout << f.dia << "/" << f.mes << "/" << f.anyo << endl;
}
