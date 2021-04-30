#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void imprime(vector<string> personas, vector<int> edades) 
// Pre: personas.size() == edades.size()
{
  const int len = personas.size();
  for (int i=0; i<len; ++i) {
    cout << personas[i] << " -> " << edades[i] << endl;
  }
}

int main() {
  vector<string> p { "Carlos", "Daniel", "José", "Manuel", "Maria"};
  vector<int> e { 10, 43, 67, 98 };

  imprime(p,e);
  
  e.push_back(8);

  imprime(p,e);

  return 0;
}
