#include <vector>
#include <iostream>

int main() {
  using namespace std;

  vector<double> notas;

  double x;
  while (cin >> x) { // x leído correcto
    notas.push_back(x);
  }

  double media = 0.0;
  double max = notas[0];
  double min = notas[0];
  for (auto x : notas) {
    media += x;
    max = (x>max) ? x : max;
    min = (x<min) ? x : min;
  }
  media /= notas.size();

  cout << "Media: " << media << endl;
  cout << "Máximo: " << max << endl;
  cout << "Mínimo: " << min << endl;

  return 0;
}
