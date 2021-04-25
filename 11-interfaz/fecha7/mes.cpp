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

const std::vector<std::string> nombres_meses {
  "enero", "febrero", "marzo", "abril", 
  "mayo", "junio", "julio", "agosto", 
  "septiembre", "octubre", "noviembre", "diciembre"
};

std::ostream & operator<<(std::ostream & os, mes_id m) {
  return os << nombres_meses[static_cast<int>(m)];
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
