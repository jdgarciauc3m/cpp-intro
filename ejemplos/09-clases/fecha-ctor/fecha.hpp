#ifndef FECHA_HPP
#define FECHA_HPP

class fecha {
public:
  fecha(int d, int m, int a);

  void imprime();

  void suma_anyo(int a);
  void suma_mes(int m);
  void suma_dia(int d);

private:
  int dia, mes, anyo;
};

int dias_de_mes(int m, int a);
bool es_bisiesto(int a);

#endif