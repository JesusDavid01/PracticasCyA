// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramática para expresiones aritméticas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 24/11/2021
// Archivo file.h: Archivo file.h
//        Contiene la definición de la clase File y sus métodos
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        24/11/2021 - Creación (primera versión) del código

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "gramatica.h"


class File {
 public:
  File(std::string& nfa, std::string& in_file, std::string& out_file);
};
#endif