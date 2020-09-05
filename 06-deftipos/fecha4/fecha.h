class fecha {
public:
  fecha(int d, int m, int a);

  void suma_anyo(int a);
  void suma_mes(int m);
  void suma_dia(int d);

  void imprime();

private:
  int dia, mes, anyo;
};

int dias_de_mes(int m, int a);
bool es_bisiesto(int a);
