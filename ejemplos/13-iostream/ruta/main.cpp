#include <cmath>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct posicion {
  double tiempo;
  double x, y;

  posicion(double t, double cx, double cy) : tiempo(t), x(cx), y(cy) {}
  [[nodiscard]] double distancia(const posicion & q) const;
};

double posicion::distancia(const posicion & q) const {
  double dx {x - q.x};
  double dy {y - q.y};
  return std::sqrt(dx * dx + dy * dy);
}

void lee_posiciones(std::vector<posicion> & vp, std::ifstream & fe) {
  double t, x, y;
  while (fe >> t >> x >> y) {
    if (t < 0) throw std::runtime_error {"Tiempo negativo"};
    posicion p {t, x, y};
    vp.push_back(p);
  }
}

void imprime_estadisticas(const std::vector<posicion> & vp) {
  double distancia {}, tiempo {};
  for (unsigned i = 1; i < vp.size(); ++i) {
    distancia += vp[i].distancia(vp[i - 1]);
    tiempo += vp[i].tiempo - vp[i - 1].tiempo;
  }

  std::cout << "Distancia: " << distancia << "\n";
  std::cout << "Tiempo: " << tiempo << "\n";
  if (tiempo > 0) { std::cout << "Velocidad: " << distancia / tiempo << "\n"; }
}

int main() {
  std::cout << "Archivo de ruta: ";
  std::string nombre;
  std::cin >> nombre;
  std::ifstream fruta {nombre};
  if (!fruta) { throw std::runtime_error("No se puede abrir archivo"); }

  std::vector<posicion> pos;
  lee_posiciones(pos, fruta);
  imprime_estadisticas(pos);
}
