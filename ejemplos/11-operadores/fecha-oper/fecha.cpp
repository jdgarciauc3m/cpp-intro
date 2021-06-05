#include "fecha.hpp"

#include <iostream>
#include <string>
#include <vector>

#include <mincontracts/mincontracts.hpp>

mes & operator++(mes & m) {
  m = (m == mes::dic) ? mes::ene : static_cast<mes>(static_cast<int>(m) + 1);
  return m;
}

mes operator++(mes & m, int) {
  mes ant{m};
  ++m;
  return ant;
}

std::ostream & operator<<(std::ostream & os, mes m) {
  static std::vector<std::string> nombres_meses {
      "enero", "febrero", "marzo",      "abril",   "mayo",      "junio",
      "julio", "agosto",  "septiembre", "octubre", "noviembre", "diciembre"};

  return os << nombres_meses[static_cast<int>(m)-1];
}

fecha::fecha(int d, mes m, int a) : dia_{d}, mes_anyo_{m}, anyo_{a} {}

void fecha::suma_anyo(int a) {
  anyo_ += a;
}

void fecha::suma_mes(int m) {
  int nm = static_cast<int>(mes_anyo_) + m;
  mes_anyo_ = static_cast<mes>((nm - 1) % 12 + 1);
  anyo_ += (nm - 1) / 12;
}

void fecha::suma_dia(int d) {
  while (d > 0) {
    int dias_resto = dias_de_mes(mes_anyo_, anyo_);
    if (d >= dias_resto - dia_ + 1) {
      d -= dias_resto - dia_ + 1;
      dia_ = 1;
      ++mes_anyo_;
      if (mes_anyo_ == mes::enero) { ++anyo_; }
    } else {
      dia_ += d;
      d = 0;
    }
  }
}

std::ostream & operator<<(std::ostream & os, const fecha & f) {
  os << f.dia_ << "/" << f.mes_anyo_ << "/" << f.anyo_;
  return os;
}

bool es_bisiesto(int a) {
  return ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0));
}

int dias_de_mes(mes m, int a) {
  switch (m) {
    case mes::enero:
    case mes::marzo:
    case mes::mayo:
    case mes::julio:
    case mes::agosto:
    case mes::octubre:
    case mes::diciembre: return 31;
    case mes::abril:
    case mes::junio:
    case mes::septiembre:
    case mes::noviembre: return 30;
    case mes::febrero: return (es_bisiesto(a)) ? 29 : 28;
    default:
      CONTRACT_ASSERT(false);
  }
}
