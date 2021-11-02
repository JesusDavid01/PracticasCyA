#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <string>
#include <vector>

class Symbol {  // Clase Simbolo
 public:
  Symbol(std::string symbol) { symbol_ = symbol; };  // Constructor de símbolo
  std::string Get_Symbol() { return symbol_; };       // Devuelve el símbolo

 private:
  std::string symbol_;  // Símbolo
};

#endif