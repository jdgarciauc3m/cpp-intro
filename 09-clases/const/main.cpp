#include <iostream>
using namespace std;

void f1(int x) {
  cout << x << endl;
}

void f2(int & x) {
  ++x;
  cout << x << endl;
}

void f3(const int & x) {
  cout << x << endl;
}

void g1() {
  int z = 1;
  const int t = 2;
  f1(z);
  f1(t);
  f1(z+t);
}

void g2() {
  int z = 1;
  const int t = 2;
  f2(z);
  //f2(t); // No puede pasar objeto constante
  (void)t;
  // f2(z+t); // No puede pasar objeto temporal
}

void g3() {
  int z = 1;
  const int t = 2;
  f3(z);
  f3(t);
  f3(z+t);
}

int main() {
  g1();
  g2();
  g3();
}
