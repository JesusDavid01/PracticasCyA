// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/11/2021
// Archivo simbolo.h: Archivo header de la clase Simbolo.
//        Contiene la definicion de la clase Simbolo, la cual guarda los
//        símbolos de la cadena
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/11/2021 - Creación (primera versión) del código

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include <string>

class Simbolo {
 public:
  Simbolo(std::string symbol);

  std::string Get_Symbol();

  void Set_Symbol(std::string);

 private:
  std::string symbol_;
};

#endif