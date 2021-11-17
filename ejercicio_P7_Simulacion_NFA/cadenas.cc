// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/11/2021
// Archivo cadenas.cc: Archivo para el desarrollo de la clase Chain
//        Contiene el desarrollo del constructor y de las clases de la clase
//        Chain
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/11/2021 - Creación (primera versión) del código

#include "cadenas.h"

/**
 * @brief Construct a new Chain:: Chain object
 *        Se le pasa un vector de símbolos y se transforma en una cadena 
 *        vectorizada. En caso de ser la cadena vacía, se retorna la propia
 *        cadena
 * 
 * @param chain Contiene la cadena en un vector de símbolos
 */
Chain::Chain(std::vector<Simbolo> chain) {
  for (size_t i = 0; i < chain.size(); i++) {
    chain_ += chain[i].Get_Symbol();
  }

  if (chain_ == "&") {
    return;
  }
  std::string cadena;
  for (size_t i = 0; i < chain_.size(); i++) {
    cadena += chain_[i];
    for (size_t j = 0; j < chain.size() - 1; j++) {  
      chain_well_.emplace_back(Simbolo(cadena));              
      cadena = "";
    }
  }
}

/**
 * @brief Retorna la cadena
 * 
 */
std::string Chain::Get_Chain() { return chain_; } // Método que devuelve la cadena

/**
 * @brief Devuelve el tamaño de la cadena
 * 
 */
int Chain::Get_Size() { return chain_well_.size(); }

/**
 * @brief Devuelve la cadena vectorizada
 * 
 */
std::vector<Simbolo> Chain::get_chain_well() {
  return chain_well_;
}