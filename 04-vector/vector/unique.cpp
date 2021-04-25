#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  vector<string> dic;
  string p;

  while (cin >> p) {
    dic.push_back(p);
  }

  sort(dic.begin(), dic.end());

  cout << endl;
  cout << dic[0] << endl;
  for (unsigned i=1; i<dic.size(); ++i) {
    if (dic[i-1] != dic[i]) {
      cout << dic[i] << endl;
    }
  }
  return 0;
}  
