#ifndef ALFABETOS_H
#define ALFABETOS_H

#include <iostream>
#include <string>
#include <vector>

#include "symbol.h"

class Alfabeto {  // Clase Alfabeto
 public:
  Alfabeto(std::vector<Symbol> alphabet);

  void print();

  std::string at_symbol(int posicion) {
    return alfabeto_.at(posicion).Get_Symbol();
  };  // Devuelve el simbolo de la posición del alfabeto en
      // la que nos encontramos

  std::string operator[](int posicion) {
    return alfabeto_.at(posicion).Get_Symbol();
  };  // Devuelve el simbolo de la posición del alfabeto en
      // la que nos encontramos

  void operator=(const Alfabeto &symbol) {
    alfabeto_ = symbol.alfabeto_;
  }  // Sobrecarga del operador de igualdad

 private:
  std::vector<Symbol> alfabeto_;  // Alfabeto (vector) de símbolos
};
#endif