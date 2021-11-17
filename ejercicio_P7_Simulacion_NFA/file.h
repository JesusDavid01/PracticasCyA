// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/11/2021
// Archivo file.h: Archivo file.h
//        Contiene la definición de la clase File y sus métodos
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/11/2021 - Creación (primera versión) del código

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "nfa.h"

class File {  // Clase File
 public:
  File(std::string& nfa, std::string& in_file, std::string& out_file);

 private:
  std::ifstream in_file_;      // Archivo de entrada
  std::ofstream out_file_;     // Archivo de salida
  std::vector<Chain> chains_;  // Cadenas
};
#endif