#include <iostream>
using namespace std;

#include "fecha.h"
using namespace calendario;

int main() {
  cout << "Fecha: ";

  cin.exceptions(cin.exceptions() | ios_base::failbit);
  fecha f;
  cin >> f;

  cout << "Fecha: " << f << endl;
  f.suma_dias(60);
  cout << "Fecha + 60: " << f << endl;
}
