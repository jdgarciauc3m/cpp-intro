#include <iostream>

using namespace std;

void f1() {
  int x1 { 1000000 };
  short x2 { 1000 };
  //short x3 { 1000000 }; // Error: narrowing
  //short x4 { x1 }; // Error: narrowing
  cout << x1;
  cout << x2;
  //cout << x3;
  //cout << x4;
}


int main() {
  f1();
  return 0;
}
