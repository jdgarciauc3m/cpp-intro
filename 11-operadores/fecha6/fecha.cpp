#include "fecha.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

mes & operator++(mes & m) {
  m = (m == mes::dic) ?
    mes::ene :
    static_cast<mes>(static_cast<int>(m) + 1);
  return m;
}

std::vector<std::string> nombres_meses {
  "enero", "febrero", "marzo", "abril", "mayo", "junio", 
  "julio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"
};

std::ostream & operator<<(std::ostream & os, mes m) {
  return os << nombres_meses[static_cast<int>(m)];
}


fecha::fecha(int d, mes m, int a) :
  dia{d},
  mes_anyo{m},
  anyo{a}
{
}

void fecha::suma_anyo(int a) {
  anyo += a;
}

void fecha::suma_mes(int m) {
  int nm = static_cast<int>(mes_anyo) + m;
  mes_anyo = static_cast<mes>((nm-1) % 12 + 1);
  anyo += (nm - 1) / 12;
}

void fecha::suma_dia(int d) {
  while (d>0) {
    int dias_resto = dias_de_mes(mes_anyo,anyo);
    if (d >= dias_resto - dia + 1) {
      d -= dias_resto - dia + 1;
      dia = 1;
      ++mes_anyo;
      if (mes_anyo == mes::enero) {
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
  cout << dia << "/" << mes_anyo << "/" << anyo << endl;
}

bool es_bisiesto(int a) {
  return ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0));
}

int dias_de_mes(mes m, int a) {
    switch (m) {
      case mes::enero: case mes::marzo: case mes::mayo: 
      case mes::julio: case mes::agosto: case mes::octubre: 
      case mes::diciembre:
        return 31;
      case mes::abril: case mes::junio: case mes::septiembre: 
      case mes::noviembre:
        return 30;
      case mes::febrero:
        return (es_bisiesto(a)) ? 29 : 28;
    }
    throw std::logic_error("Mes no válido");
}

