#ifndef FECHA_HPP
#define FECHA_HPP

#include <iostream>

// clang-format off
enum class mes {
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
// clang-format on

mes & operator++(mes & m);
mes operator++(mes & m, int);
std::ostream & operator<<(std::ostream & os, mes m);

class fecha {
public:
  fecha(int d, mes m, int a);

  void suma_anyo(int a);
  void suma_mes(int m);
  void suma_dia(int d);

  int dia() const { return dia_; }
  mes mes_anyo() const { return mes_anyo_; }
  int anyo() const { return anyo_; }

  friend std::ostream & operator<<(std::ostream & os, const fecha & f);

private:
  int dia_;
  mes mes_anyo_;
  int anyo_;
};

int dias_de_mes(mes m, int a);

bool es_bisiesto(int a);

#endif