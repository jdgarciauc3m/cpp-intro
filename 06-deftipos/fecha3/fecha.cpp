#include "fecha.h"
#include <stdexcept>
#include <iostream>

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
    int dias = dias_de_mes(mes,anyo);
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

void fecha::imprime() {
  using namespace std;
  cout << dia << "/" << mes << "/" << anyo << endl;
}

bool es_bisiesto(int a) {
  return ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0));
}

int dias_de_mes(int m, int a) {
    switch (m) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
      case 4: case 6: case 9: case 11:
        return 30;
      case 2:
        if (es_bisiesto(a)) {
          return 29;
        }
        else {
          return 28;
        }
      default:
        throw std::invalid_argument{"Mes no válido"};
    }
}

