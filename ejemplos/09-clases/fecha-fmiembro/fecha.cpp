#include "fecha.hpp"
#include <mincontracts/mincontracts.hpp>
#include <vector>

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
  mes = (nm - 1) % 12 + 1;
  anyo += (nm - 1) / 12;
}

namespace {

  bool es_bisiesto(int a) {
    return ((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0);
  }

  int dias_mes(int m, int a) {
    CONTRACT_PRE(m > 0);
    CONTRACT_PRE(m <= 12);
    auto post = CONTRACT_POST_RESULT(r, r >= 28 && r <= 31);

    std::vector<int> dias {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2) {
      return post(es_bisiesto(a) ? 29 : 28);
    } else {
      return post(dias[m - 1]);// indices comienzan en cero
    }
  }

}// namespace

void fecha::suma_dia(int d) {
  CONTRACT_PRE(d >= 0);
  while (d > 0) {
    int dias_suma = dias_mes(mes, anyo);
    if (d >= dias_suma - dia + 1) {
      d -= dias_suma - dia + 1;
      dia = 1;
      ++mes;
      if (mes > 12) {
        mes = 1;
        ++anyo;
      }
    } else {
      dia += d;
      d = 0;
    }
  }
}
