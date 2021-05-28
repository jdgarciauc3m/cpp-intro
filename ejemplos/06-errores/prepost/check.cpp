#include <iostream>
#include <stdexcept>
#include <vector>

void imprime(std::vector<std::string> personas, std::vector<int> edades)
// Pre: personas.size() == edades.size()
{
  if (personas.size() != edades.size())
    throw std::invalid_argument {"Distinta longitud"};

  const auto len = personas.size();
  for (std::size_t i = 0; i < len; ++i) {
    std::cout << personas[i] << " -> " << edades[i] << "\n";
  }
}

int main()
{
  std::vector<std::string> p {"Carlos", "Daniel", "José", "Manuel", "Maria"};
  std::vector<int> e {10, 43, 67, 98};

  int status = 0;

  try {
    imprime(p, e);
  }
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what() << "\n";
    status = -1;
  }

  e.push_back(8);

  try {
    imprime(p, e);
  }
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what() << "\n";
    status = -2;
  }

  return status;
}
