// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/11/2021
// Archivo cadenas.h: Archivo header de la clase Chain
//        Contiene la definición de la clase Chain, la cual extrae, guarda y
//        opera con la cadena del archivo
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/11/2021 - Creación (primera versión) del código

#ifndef CADENAS_H
#define CADENAS_H

#include <iostream>
#include <string>
#include <vector>

#include "simbolo.h"
#include "string.h"

class Chain {
 public:
  Chain(std::vector<Simbolo> chain);

  std::string Get_Chain();
  int Get_Size();
  std::vector<Simbolo> get_chain_well();

 private:
  std::string chain_;
  std::vector<Simbolo> chain_well_;
};
#endif