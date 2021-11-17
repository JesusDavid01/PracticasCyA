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

/**
 * @brief Construct a new Simbolo:: Simbolo object
 *        Iguala el simbolo que le pasamos al parámetro privado symbol
 * 
 * @param symbol 
 */
Simbolo::Simbolo(std::string symbol) {
  symbol_ = symbol; 
}

/**
 * @brief Devuelve el símbolo
 * 
 */
std::string Simbolo::Get_Symbol() {
  return symbol_; 
}

/**
 * @brief Establece un símbolo nuevo
 * 
 * @param symbol string que contiene el símbolo que vamos a establecer
 */
void Simbolo::Set_Symbol(std::string symbol) {
  symbol_ = symbol;
};