// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Autómatas finitos y reconocimiento de patrones
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 02/11/2021
// Archivo symbol.h:
//        Contiene la definición de la clase simbolo y su implementación
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        30/10/2021 - Creación (primera versión) del código

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