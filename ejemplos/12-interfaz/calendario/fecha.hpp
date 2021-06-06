#ifndef CALENDARIO_FECHA_HPP
#define CALENDARIO_FECHA_HPP

#include "mes.hpp"

namespace calendario {

  class fecha {
  public:
    fecha() = default;
    fecha(int d, mes_id m, int a);

    [[nodiscard]] int dia() const { return dia_; }
    [[nodiscard]] mes_id mes() const { return mes_; }
    [[nodiscard]] int anyo() const { return anyo_; }

    void suma_anyos(int n);
    void suma_meses(int n);
    void suma_dias(int n);

  private:
    int dia_ {1};
    mes_id mes_ {mes_id::enero};
    int anyo_ {2000};
  };

  std::ostream & operator<<(std::ostream & os, const fecha & f);

}// namespace calendario

#endif
