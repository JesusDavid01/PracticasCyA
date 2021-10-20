// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 18/10/2021
// Archivo simbolo.h: Archivo header de la clase Simbolo.
//        Contiene la definicion de la clase Simbolo, la cual guarda los
//        símbolos de la cadena
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        18/10/2021 - Creación (segunda versión) del código

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <string>
#include <vector>

using namespace std;

class Simbolo {  // Clase Simbolo
 public:
  Simbolo(string symbol) { symbol_ = symbol; };  // Constructor de símbolo
  string Get_Symbol() { return symbol_; };       // Devuelve el símbolo

 private:
  string symbol_;  // Símbolo
};

#endif