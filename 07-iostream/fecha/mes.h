#ifndef CALENDARIO_MES_H
#define CALENDARIO_MES_H

#include <iostream>

namespace calendario {

class mes_invalido {};

enum class mes_id {
  enero = 1, febrero, marzo, 
  abril, mayo, junio,
  julio, agosto, septiembre, 
  octubre, noviembre, diciembre,

  // Abreviados
  ene = enero, feb = febrero, mar = marzo,
  abr = abril, may = mayo, jun = junio,
  jul = julio, ago = agosto, sep = septiembre,
  oct = octubre, nov = noviembre, dic = diciembre
};

inline mes_id a_mes_id(int n) {
  return static_cast<mes_id>( (n-1) % 12 + 1);
}

mes_id & operator++(mes_id & m);

inline int operator+(mes_id m, int n) {
  return static_cast<int>(m) + n;
}

std::ostream & operator<<(std::ostream & os, mes_id m);
std::istream & operator>>(std::istream & is, mes_id & m);

int dias_de_mes(mes_id m, int a);

inline bool es_bisiesto(int a) {
  return ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0));
}

}

#endif
