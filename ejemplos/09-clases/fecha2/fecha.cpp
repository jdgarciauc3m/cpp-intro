#include "fecha.h"
#include <stdexcept>

void fecha::inicia(int d, int m, int a) {
  dia = d;
  mes = m;
  anyo = a;
}

void fecha::suma_anyo(int a) {
  anyo += a;
}

void fecha::suma_mes(int m) {
  int nm = mes + m;
  mes = (nm-1) % 12 + 1;
  anyo += (nm - 1) / 12;
}

void fecha::suma_dia(int d) {
  while (d>0) {
    int dias = 0;
    switch (mes) {
      case 1: case 3: case 5: case 7:
      case 8: case 10: case 12:
        dias = 31;
        break;
      case 4: case 6: case 9: case 11:
        dias = 30;
        break;
      case 2:
        if ( ( (anyo % 4 == 0) && (anyo % 100 != 0) ) || (anyo % 400 == 0)) {
          dias = 29;
        }
        else {
          dias = 28;
        }
        break;
      default:
        throw std::logic_error{"Fecha en mes no válido"};
    }
    using namespace std;
    if (d >= dias - dia + 1) {
      d -= dias - dia + 1;
      dia = 1;
      ++mes;
      if (mes > 12) {
        mes = 1;
        ++anyo;
      }
    }
    else {
      dia += d;
      d = 0;
    }
  }
}
