// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/10/2021
// Archivo alfabetos.h: Archivo header de la clase Alfabeto.
//        Contiene la definicion de la clase Alfabeto, la cual guarda el
//        alfabeto de entrada del archivo
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/10/2021 - Creación (primera versión) del código

#ifndef ALFABETOS_H
#define ALFABETOS_H

#include <iostream>
#include <string>
#include <vector>

#include "simbolo.h"

using namespace std;

class Alfabeto {  // Clase Alfabeto
 public:
  Alfabeto(vector<Simbolo> alphabet);

  void print();

  string at_symbol(int posicion) {
    return alfabeto_.at(posicion).Get_Symbol();
  };  // Devuelve el simbolo de la posición del alfabeto en
      // la que nos encontramos

  string operator[](int posicion) {
    return alfabeto_.at(posicion).Get_Symbol();
  };  // Devuelve el simbolo de la posición del alfabeto en
      // la que nos encontramos
  int Get_Size() {
    return alfabeto_.size();
  }  // Devuelve el tamaño del vector alfabeto

  void operator=(const Alfabeto &symbol) {
    alfabeto_ = symbol.alfabeto_;
  }  // Sobrecarga del operador de igualdad

 private:
  vector<Simbolo> alfabeto_;  // Alfabeto (vector) de símbolos
};
#endif