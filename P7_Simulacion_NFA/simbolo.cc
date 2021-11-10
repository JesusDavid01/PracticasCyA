// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/11/2021
// Archivo simbolo.cc: Archivo simbolo.cc.
//        Contiene la implementacion de la clase Simbolo
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/11/2021 - Creación (primera versión) del código

#include "simbolo.h"

Simbolo::Simbolo(std::string symbol) {
  symbol_ = symbol; 
}

// Método que devuelve el simbolo
std::string Simbolo::Get_Symbol() {
  return symbol_; 
}

// Método que establece un simbolo
void Simbolo::Set_Symbol(std::string symbol) {
  symbol_ = symbol;
};