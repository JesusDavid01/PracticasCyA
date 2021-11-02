#include "alphabet.h"

Alfabeto::Alfabeto(std::vector<Symbol> alphabet) {
  alfabeto_ = alphabet;
}

void Alfabeto::print() {
  for (auto c : alfabeto_) {
    std::cout << c.Get_Symbol() << ' ';
  }
  std::cout << std::endl;
}