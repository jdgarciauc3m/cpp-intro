#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string lee_nombre(string pregunta) {
  cout << pregunta;
  string nombre;
  cin >> nombre;
  return nombre;
}

void filtra(ifstream & fe, ofstream & fs) {
  int x;
  while (fe >> x) {
    if (x > 0) {
      fs << x << endl;
    }
  }
}

int main() {
  auto nombre_entrada = lee_nombre("Archivo de entrada: ");
  ifstream fentrada(nombre_entrada);
  if (!fentrada) {
    cerr << "No se puede abrir " << nombre_entrada << endl;
    return -1;
  }

  auto nombre_salida = lee_nombre("Archivo de salida: ");
  ofstream fsalida(nombre_salida);
  if (!fsalida) {
    cerr << "No se puede abrir " << nombre_salida << endl;
    return -2;
  }

  filtra(fentrada,fsalida);

  return 0;
}
