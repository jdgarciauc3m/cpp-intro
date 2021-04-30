#include <iostream>
using namespace std;

#include "fecha.h"

int main() {
  fecha f;
  inicia(f, 4, 9, 1969);
  suma_dia(f,60);
  cout << f.dia << "/" << f.mes << "/" << f.anyo << endl;
}
