#include "fecha.h"
#include <iostream>
#include <string>
#include <vector>

namespace calendario {

mes_id & operator++(mes_id & m) {
  m = (m == mes_id::dic) ?
    mes_id::ene :
    static_cast<mes_id>(static_cast<int>(m) + 1);
  return m;
}

static std::vector<std::string> nombres_meses {
  "enero", "febrero", "marzo", "abril", "mayo", "junio", 
  "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"
};

static std::vector<std::string> nombres_meses_corto {
  "ene", "feb", "mar", "abr", "may", "jun", 
  "jul", "ago", "sep", "oct", "nov", "dic"
};

std::ostream & operator<<(std::ostream & os, mes_id m) {
  return os << nombres_meses[static_cast<int>(m)-1];
}

std::istream & operator>>(std::istream & is, mes_id & m) {
  using namespace std;
  string nombre;
  char c;
  while (is >> c) {
    if (isalpha(c)) nombre.push_back(c);
    else {
      is.unget();
      break;
    }
  }
  if (!is) return is;

  for (unsigned i=0; i<nombres_meses.size(); ++i) {
    if (nombres_meses[i] == nombre || nombres_meses_corto[i] == nombre) {
      m = static_cast<mes_id>(i+1);
      return is;
    }
  }

  is.clear(ios_base::failbit);
  return is;
}

int dias_de_mes(mes_id m, int a) {
    switch (m) {
      case mes_id::enero: case mes_id::marzo: case mes_id::mayo: case mes_id::julio: 
      case mes_id::agosto: case mes_id::octubre: case mes_id::diciembre:
        return 31;
      case mes_id::abril: case mes_id::junio: case mes_id::septiembre: case mes_id::noviembre:
        return 30;
      case mes_id::febrero:
        return (es_bisiesto(a)) ? 29 : 28;
    }
    throw mes_invalido{};
}

}
