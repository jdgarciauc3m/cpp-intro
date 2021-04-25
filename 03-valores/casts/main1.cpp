#include <iostream>

using namespace std;

void f1() {
  int x = 1000000;
  short y = x;
  cout << "f1(): " << x << " , " << y << endl;
}


int main() {
  f1();
  return 0;
}
