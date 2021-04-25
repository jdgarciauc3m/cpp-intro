#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

string lee_nombre(string pregunta) {
  cout << pregunta;
  string nombre;
  cin >> nombre;
  return nombre;
}

void filtra(ifstream & fe, ofstream & fs) {
  int x;
  while (fe) {
    if (fe >> x) {
      if (x > 0) {
        fs << x << endl;
      }
    }
    else {
      if (fe.eof()) return;
      if (fe.bad()) throw runtime_error("Error de lectura");
      if (fe.fail()) {
        fe.clear();
        char c;
        do {
          fe >> c;
        } while (!isdigit(c) && c!='-');
        fe.unget();
      }
    }
  }
}

int main() {
  string nombre_entrada = lee_nombre("Archivo de entrada: ");
  ifstream fentrada(nombre_entrada);
  if (!fentrada) {
    cerr << "No se puede abrir " << nombre_entrada << endl;
    return -1;
  }

  string nombre_salida = lee_nombre("Archivo de salida: ");
  ofstream fsalida(nombre_salida);
  if (!fsalida) {
    cerr << "No se puede abrir " << nombre_salida << endl;
    return -2;
  }

  filtra(fentrada,fsalida);

  return 0;
}
