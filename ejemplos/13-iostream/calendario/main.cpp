#include <iostream>

#include "fecha.hpp"

int main() {
  using namespace std;
  cout << "Fecha: ";

  cin.exceptions(cin.exceptions() | ios_base::failbit);
  calendario::fecha f;
  cin >> f;

  cout << "Fecha: " << f << endl;
  f.suma_dias(60);
  cout << "Fecha + 60: " << f << endl;
}
