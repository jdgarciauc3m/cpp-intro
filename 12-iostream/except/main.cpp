#include <iostream>
#include <fstream>

int main()
{
  using namespace std;
  ifstream f{"no existe"};
  try {
    f.exceptions(f.failbit);
  } 
  catch (const ios_base::failure& e) {
    cerr << "Fallo de e/s" << endl;
    cerr << "Razón: " << e.what() << endl;
  }
}
