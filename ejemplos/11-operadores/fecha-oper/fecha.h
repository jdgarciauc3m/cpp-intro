#include <iostream>

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

mes & operator++(mes & m);
std::ostream & operator<<(std::ostream & os, mes m);

class fecha {
public:
  fecha(int d, mes m, int a);

  void suma_anyo(int a);
  void suma_mes(int m);
  void suma_dia(int d);

  void imprime();

private:
  int dia;
  mes mes_anyo;
  int anyo;
};

int dias_de_mes(mes m, int a);

bool es_bisiesto(int a);
