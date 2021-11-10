// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 10/11/2021
// Archivo cadenas.cc: Archivo para el desarrollo de la clase Chain
//        Contiene el desarrollo del constructor y de las clases de la clase
//        Chain
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        10/11/2021 - Creación (primera versión) del código

#include "cadenas.h"

// Constructor de la clase Chain, dado un vector de símbolos y un alfabeto se
// construye la cadena
Chain::Chain(std::vector<Simbolo> chain) {
  chain_ = chain.front().Get_Symbol();

  if (chain_ == "&") {
    return;
  }  // Si la cadena es la cadena vacía, chain será una cadena vacía
  std::string cadena;
  for (size_t i = 0; i < chain_.size(); i++) {  // Recorremos la cadena y
    // almacenamos los valores individualmente
    cadena += chain_[i];
    for (size_t j = 0; j < chain.size() - 1; j++) {  
      chain_well_.emplace_back(Simbolo(cadena));  // Almacenamos el símbolo 
                             // en la cadena vectorizada y limpiamos la
                            // cadena auxiliar.                
      cadena = "";
    }
  }
}

std::string Chain::Get_Chain() { return chain_; } // Método que devuelve la cadena

int Chain::Get_Size() { return chain_well_.size(); } // Método que devuelve
                                                    // el tamaño de la cadena

std::vector<Simbolo> Chain::get_chain_well() { // Método que devuelve 
  return chain_well_;                          // la cadena vectorizada
}