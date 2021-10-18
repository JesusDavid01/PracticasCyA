// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/10/2021
// Archivo cadenas.h: Archivo header de la clase Chain
//        Contiene la definición de la clase Chain, la cual extrae, guarda y
//        opera con la cadena del archivo
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/10/2021 - Creación (primera versión) del código

#ifndef CADENAS_H
#define CADENAS_H

#include <assert.h>

#include <string>
#include <vector>

#include "alfabetos.h"
#include "simbolo.h"
#include "string.h"

using namespace std;

class Chain {  // Clase Chain
 public:
  Chain(vector<Simbolo> chain, Alfabeto alphabet);  // Constructor

  string Get_Chain() { return chain_; }  // Método que devuelve la cadena
  int Get_Size() {
    return chain_well_.size();
  }  // Método que devuelve el tamaño de la cadena
  Alfabeto Get_Alfabeto() {
    return alphabet_;
  }  // Método que devuelve el alfabeto de la cadena

  int Longitud();
  string Inversa();
  string Prefijos();
  string Sufijos();
  string Subcadenas();

 private:
  string chain_;                // Cadena
  vector<Simbolo> chain_well_;  // Cadena vectorizada para dividirla en símbolos
  Alfabeto alphabet_;           // Alfabeto de la cadena
};
#endif