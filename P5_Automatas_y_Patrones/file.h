// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Autómatas finitos y reconocimiento de patrones
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 02/11/2021
// Archivo file.h:
//        Contiene la definición de la clase file, que lee y escribe archivos de E/S
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        30/10/2021 - Creación (primera versión) del código

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>

#include "alphabet.h"
#include "dfa.h"

const char nodeS {'S'};
const char nodeB {'B'};
const char nodeD {'D'};
const char nodeE {'E'};
const char nodeF {'F'};
const char nodeO {'0'};
const char A {'A'};
const char C {'C'};
const char T {'T'};
const char G {'G'};
const int tam {100};


class File { 
 public:
  File(std::string dna, std::string out_file);

  void imprimir(std::string print);
  void subCadenas();
  char currentNode(char node);
  void isString();
  void final_file(std::string final_result[], int posicion);
  void dfa(std::string cadena);

 private:
  std::ofstream out_file_;     // Archivo de salida
  std::vector<Symbol> dna_;
};
#endif

