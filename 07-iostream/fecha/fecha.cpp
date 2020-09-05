#include "fecha.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

namespace calendario {

fecha::fecha(int d, mes_id m, int a) :
  dia_{d},
  mes_{m},
  anyo_{a}
{
}

void fecha::suma_anyos(int a) {
  anyo_ += a;
}

void fecha::suma_meses(int m) {
  int nm = mes_ + m;
  anyo_ = (nm - 1) / 12;
  mes_ = a_mes_id(nm);
}

void fecha::suma_dias(int d) {
  while (d>0) {
    int dias_resto = dias_de_mes(mes_,anyo_);
    if (d >= dias_resto - dia_ + 1) {
      d -= dias_resto - dia_ + 1;
      dia_ = 1;
      ++mes_;
      if (mes_ == mes_id::enero) {
        ++anyo_;
      }
    }
    else {
      dia_ += d;
      d = 0;
    }
  }
}

std::ostream & operator<<(std::ostream & os, const fecha & f) {
  return os << f.dia() << "/" << f.mes() << "/" << f.anyo();
}

std::istream & operator>>(std::istream & is, fecha & f) {
  using namespace std;

  int d, a;
  mes_id m;
  char s1, s2;
  is >> d >> s1 >> m >> s2 >> a;
  if (!is) return is;
  if (s1 != '/' || s2 != '/') {
    is.clear(ios_base::failbit);
    return is;
  }
  f = fecha{d,m,a};
  return is;
}

}
