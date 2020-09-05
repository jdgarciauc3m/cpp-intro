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

class fecha {
public:
  fecha(int d, mes_id m, int a);

  void suma_anyo(int a);
  void suma_mes(int m);
  void suma_dia(int d);

  void imprime();

private:
  int dia;
  mes_id mes;
  int anyo;
};

int dias_de_mes(mes_id m, int a);

bool es_bisiesto(int a);
