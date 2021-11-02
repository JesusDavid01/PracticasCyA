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

#include "symbol.h"

const char nodeS {'S'}; // Estado inicial
const char nodeB {'B'}; 
const char nodeD {'D'};
const char nodeE {'E'}; // Estado de aceptacion
const char nodeF {'F'}; // Estado de aceptacion
const char nodeO {'0'}; // Estado vacío o estado de muerte
const char A {'A'}; // Caracter A del alfabeto
const char C {'C'}; // Caracter C del alfabeto
const char T {'T'}; // Caracter T del alfabeto
const char G {'G'}; // Caracter G del alfabeto
const int tam {100};


class File { 
 public:
  File(std::string dna, std::string out_file);

  void isString(); // Funcion para comprobar si son cadenas validas
  void final_file(std::string final_result[], int posicion); // Funcion para limpiar el archivo de cadenas repetidas y espacios en blanco

 private:
  std::ofstream out_file_;     // Archivo de salida
  std::vector<Symbol> dna_;
};
#endif

