// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 10/11/2021
// Archivo cadenas.h: Archivo header de la clase Chain
//        Contiene la definición de la clase Chain, la cual extrae, guarda y
//        opera con la cadena del archivo
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        10/11/2021 - Creación (primera versión) del código

#ifndef CADENAS_H
#define CADENAS_H

#include <iostream>
#include <string>
#include <vector>

#include "simbolo.h"
#include "string.h"

class Chain {  // Clase Chain
 public:
  Chain(std::vector<Simbolo> chain);  // Constructor

  std::string Get_Chain();  // Método que devuelve la cadena
  int Get_Size();           // Método que devuelve el tamaño de la cadena
  std::vector<Simbolo> get_chain_well(); // Método que devuelve 
                                        // la cadena vectorizada

 private:
  std::string chain_;  // Cadena
  std::vector<Simbolo> chain_well_;  // Cadena 
                                    // vectorizada para dividirla en símbolos
};
#endif