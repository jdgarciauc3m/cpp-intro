#ifndef FECHA_HPP
#define FECHA_HPP

struct fecha {
  int dia, mes, anyo;
};

void inicia(fecha & f, int d, int m, int a);
void suma_anyo(fecha & f, int a);
void suma_mes(fecha & f, int m);
void suma_dia(fecha & f, int d);

#endif