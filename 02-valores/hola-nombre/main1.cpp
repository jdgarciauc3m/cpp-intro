#include <iostream>
#include <string>

int main() {
  std::cout << "Escribe tu nombre: " << std::endl;

  std::string nombre;
  std::cin >> nombre;

  std::cout << "Hola, " << nombre << "." << std::endl;
}
