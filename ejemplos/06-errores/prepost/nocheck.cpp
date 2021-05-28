#include <iostream>
#include <stdexcept>
#include <vector>

void imprime(std::vector<std::string> personas, std::vector<int> edades)
// Pre: personas.size() == edades.size()
{
  const auto len = personas.size();
  for (std::size_t i = 0; i < len; ++i) {
    std::cout << personas[i] << " -> " << edades[i] << "\n";
  }
}

int main() {
  std::vector<std::string> p {"Carlos", "Daniel", "José", "Manuel", "Maria"};
  std::vector<int> e {10, 43, 67, 98};

  imprime(p, e);

  e.push_back(8);

  imprime(p, e);

  return 0;
}
