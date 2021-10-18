// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/10/2021
// Archivo file.h: Archivo file.h
//        Contiene la definición de la clase File y sus métodos
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/10/2021 - Creación (primera versión) del código

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "alfabetos.h"
#include "cadenas.h"

#define MAX 1000

using namespace std;

class File {  // Clase File
 public:
  File(string in_file, string out_file, int opcode);  // Constructor

  void Operador();
  void WriteOut(string);
  void WriteOut(int print);
  void ImprAlfabetos();
  void ImprCadenas();

 private:
  ifstream in_file_;      // Archivo de entrada
  ofstream out_file_;     // Archivo de salida
  int opcode_;            // Opcode
  vector<Chain> chains_;  // Cadenas
};
#endif