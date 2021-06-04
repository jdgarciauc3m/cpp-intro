#include "fecha.hpp"

#include <iostream>
#include <stdexcept>

#include <mincontracts/mincontracts.hpp>

fecha::fecha(int d, mes_id m, int a)
    : dia {d}, mes {m}, anyo {a} {}

void fecha::suma_anyo(int a) {
  anyo += a;
}

void fecha::suma_mes(int m) {
  int nm = static_cast<int>(mes) + m;
  mes = static_cast<mes_id>((nm - 1) % 12 + 1);
  anyo += (nm - 1) / 12;
}

void fecha::suma_dia(int d) {
  while (d > 0) {
    auto dias = dias_de_mes(mes, anyo);
    if (d >= dias - dia + 1) {
      d -= dias - dia + 1;
      dia = 1;
      mes = static_cast<mes_id>(static_cast<int>(mes) + 1);
      if (static_cast<int>(mes) > 12) {
        mes = mes_id::enero;
        ++anyo;
      }
    } else {
      dia += d;
      d = 0;
    }
  }
}

void fecha::imprime() {
  std::cout << dia << "/" << static_cast<int>(mes) << "/" << anyo << "\n";
}

bool es_bisiesto(int a) {
  return ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0));
}

int dias_de_mes(mes_id m, int a) {
  switch (m) {
    case mes_id::enero:
    case mes_id::marzo:
    case mes_id::mayo:
    case mes_id::julio:
    case mes_id::agosto:
    case mes_id::octubre:
    case mes_id::diciembre:
      return 31;
    case mes_id::abril:
    case mes_id::junio:
    case mes_id::septiembre:
    case mes_id::noviembre:
      return 30;
    case mes_id::febrero:
      return (es_bisiesto(a)) ? 29 : 28;
    default:
      CONTRACT_ASSERT(false);
  }
}
