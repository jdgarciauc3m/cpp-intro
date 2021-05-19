#include <iostream>
#include <vector>
#include <stdexcept>

#include <mincontracts/mincontracts.hpp>

using namespace std;

void imprime(vector<string> personas, vector<int> edades)
{
  CONTRACT_PRE(personas.size() == edades.size());

  const auto len = personas.size();
  for (std::size_t i=0; i<len; ++i) {
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
