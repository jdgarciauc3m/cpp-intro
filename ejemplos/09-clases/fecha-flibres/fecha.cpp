#include "fecha.hpp"
#include <mincontracts/mincontracts.hpp>
#include <vector>

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

namespace {
  bool es_bisiesto(int a) {
    return ((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0);
  }

  int dias_mes(int m, int a) {
    CONTRACT_PRE(m > 0);
    CONTRACT_PRE(m <= 12)
    auto post = CONTRACT_POST_RESULT(r, r >= 28 && r <= 31);

    std::vector<int> dias {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2) {
      return post(es_bisiesto(a) ? 29 : 28);
    } else {
      return post(dias[m - 1]);// indices comienzan en cero
    }
  }
}// namespace

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
    } else {
      f.dia += d;
      d = 0;
    }
  }
}
