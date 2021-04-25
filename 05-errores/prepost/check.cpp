#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

void imprime(vector<string> personas, vector<int> edades) 
// Pre: personas.size() == edades.size()
{
  if (personas.size() != edades.size())
    throw invalid_argument{"Distinta longitud"};

  const int len = personas.size();
  for (int i=0; i<len; ++i) {
    cout << personas[i] << " -> " << edades[i] << endl;
  }
}

int main() {
  vector<string> p { "Carlos", "Daniel", "José", "Manuel", "Maria"};
  vector<int> e { 10, 43, 67, 98 };

  int status = 0;

  try {
    imprime(p,e);
  }
  catch (exception & e) {
    cerr << "Error: " << e.what() << endl;
    status = -1;
  }

  e.push_back(8);

  try {
    imprime(p,e);
  }
  catch (exception & e) {
    cerr << "Error: " << e.what() << endl;
    status = -2;
  }

    return status;
}
