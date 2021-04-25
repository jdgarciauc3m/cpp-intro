#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;

struct posicion {
  double tiempo;
  double x, y;

  posicion(double t, double cx, double cy) : tiempo(t), x(cx), y(cy) {}
  double distancia(const posicion & q) const;
};

double posicion::distancia(const posicion & q) const {
  double dx { x - q.x };
  double dy { y - q.y };
  return sqrt(dx*dx + dy*dy);
}

void lee_posiciones(vector<posicion> & vp, ifstream & fe) {
  double t, x, y;
  while (fe >> t >> x >> y) {
    if (t<0) throw runtime_error{"Tiempo negativo"};
    vp.push_back({t, x, y});
  }
}

void imprime_estadisticas(const vector<posicion> & vp) {
  double distancia{}, tiempo{};
  for (unsigned i=1; i<vp.size(); ++i) {
    distancia += vp[i].distancia(vp[i-1]);
    tiempo += vp[i].tiempo - vp[i-1].tiempo;
  }

  cout << "Distancia: " << distancia << endl;
  cout << "Tiempo: " << tiempo << endl;
  if (tiempo > 0) {
    cout << "Velocidad: " << distancia / tiempo << endl;
  }
}

int main() {
  cout << "Archivo de ruta: ";
  string nombre;
  cin >> nombre;
  ifstream fruta{nombre};
  if (!fruta) {
    throw runtime_error("No se puede abrir archivo");
  }

  vector<posicion> pos;
  lee_posiciones(pos,fruta);
  imprime_estadisticas(pos);
}
