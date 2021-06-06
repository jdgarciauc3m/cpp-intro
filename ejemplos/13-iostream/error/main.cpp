#include <cctype>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

std::string lee_nombre(const std::string & pregunta) {
  std::cout << pregunta;
  std::string nombre;
  std::cin >> nombre;
  return nombre;
}

void filtra(std::ifstream & fe, std::ofstream & fs) {
  int x;
  while (fe) {
    if (fe >> x) {
      if (x > 0) { fs << x << "\n"; }
    } else {
      if (fe.eof()) return;
      if (fe.bad()) throw std::runtime_error("Error de lectura");
      if (fe.fail()) {
        fe.clear();
        char c;
        do { fe >> c; } while (!isdigit(c) && c != '-');
        fe.unget();
      }
    }
  }
}

int main() {
  std::string nombre_entrada = lee_nombre("Archivo de entrada: ");
  std::ifstream fentrada(nombre_entrada);
  if (!fentrada) {
    std::cerr << "No se puede abrir " << nombre_entrada << "\n";
    return -1;
  }

  std::string nombre_salida = lee_nombre("Archivo de salida: ");
  std::ofstream fsalida(nombre_salida);
  if (!fsalida) {
    std::cerr << "No se puede abrir " << nombre_salida << "\n";
    return -2;
  }

  filtra(fentrada, fsalida);

  return 0;
}
