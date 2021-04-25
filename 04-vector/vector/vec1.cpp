#include <vector>
#include <iostream>

int main() {
  using namespace std;

  vector<int> v(5);
  v[0] = 1;
  v[1] = 2;
  v[2] = 4;
  v[3] = 8;
  v[4] = 16;

  cout << v[3] << endl;
 
  return 0;
}
