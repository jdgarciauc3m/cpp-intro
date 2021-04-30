#include "fecha.h"
#include <stdexcept>

void inicia(fecha & f, int d, int m, int a) {
  f.dia = d;
  f.mes = m;
  f.anyo = a;
}

void suma_anyo(fecha & f, int a) {
  f.anyo += a;
}

void suma_mes(fecha & f, int m) {
  int nm = f.mes + m;
  f.mes = (nm-1) % 12 + 1;
  f.anyo += (nm - 1) / 12;
}

void suma_dia(fecha & f, int d) {
  while (d>0) {
    int dias = 0;
    switch (f.mes) {
      case 1: case 3: case 5: case 7:
      case 8: case 10: case 12:
        dias = 31;
        break;
      case 4: case 6: case 9: case 11:
        dias = 30;
        break;
      case 2:
        if ( ( (f.anyo % 4 == 0) && (f.anyo % 100 != 0) ) || (f.anyo % 400 == 0)) {
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
    if (d >= dias - f.dia + 1) {
      d -= dias - f.dia + 1;
      f.dia = 1;
      ++f.mes;
      if (f.mes > 12) {
        f.mes = 1;
        ++f.anyo;
      }
    }
    else {
      f.dia += d;
      d = 0;
    }
  }
}
