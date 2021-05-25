#include "fecha.hpp"
#include <cassert>

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
  f.mes = (nm - 1) % 12 + 1;
  f.anyo += (nm - 1) / 12;
}

bool es_bisiesto(int a) {
  return ((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0);
}

int dias_mes(int m, int a) {
  switch (m) {
    case 1: case 3: case 5: case 7:
    case 8: case 10: case 12:
      return 31;
    case 4: case 6: case 9: case 11:
      return 30;
    case 2:
      return es_bisiesto(a) ? 29 : 28;
    default:
      assert(false);
  }
}

void suma_dia(fecha & f, int d) {
  while (d > 0) {
    int dias = dias_mes(f.mes, f.anyo);

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
