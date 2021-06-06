#include "fecha.hpp"
#include <string>
#include <vector>

#include <mincontracts/mincontracts.hpp>

namespace calendario {

  mes_id operator++(mes_id & m) {
    m = (m == mes_id::dic) ? mes_id::ene
                           : static_cast<mes_id>(static_cast<int>(m) + 1);
    return m;
  }

  mes_id operator++(mes_id & m, int) {
    auto anterior = m;
    ++m;
    return anterior;
  }

  std::ostream & operator<<(std::ostream & os, mes_id m) {
    static const std::vector<std::string> nombres_meses {
        "enero", "febrero", "marzo",      "abril",   "mayo",      "junio",
        "julio", "agosto",  "septiembre", "octubre", "noviembre", "diciembre"};

    return os << nombres_meses[static_cast<int>(m)];
  }

  int dias_de_mes(mes_id m, int a) {
    static const std::vector<int> dias_meses {31, 28, 31, 30, 31, 30,
                                              31, 31, 30, 31, 30, 31};
    int i = static_cast<int>(m) - 1;
    CONTRACT_ASSERT(i >= 0 && i < 12);
    if (m != mes_id::febrero) return dias_meses[i];
    return (es_bisiesto(a)) ? 29 : 28;
  }

}// namespace calendario
