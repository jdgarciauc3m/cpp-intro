#include <iostream>

double cuadrado(double x) { return x * x; }

int cuadrado(int x);

int main() {
  using namespace std;
  cout << cuadrado(2) << endl;
  return 0;
}
