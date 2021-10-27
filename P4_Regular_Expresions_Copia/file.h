// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 25/10/2021
// Archivo file.h:
//        Contiene la definición de la clase File y sus métodos
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        25/10/2021 - Creación (primera versión) del código

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

#define SimpleDoubleComment "[//]"
#define CompoundCommentStart "[/*]]"
#define CompoundCommentFinish "[*/]"
#define BucleFor "for \\("
#define BucleWhile "while"
#define VariableInt "int"
#define VariableDouble "double"
#define ExpressionMain "main"
#define Space " "
#define MAX 10000

using namespace std;

class File { 
 public:
  File(string in_file, string out_file, string name_in);

  void imprimir(string print);
  void Escribir_Archivo();

 private:
  ifstream in_file_;      // Archivo de entrada
  ofstream out_file_;     // Archivo de salida
  string save_;
};
#endif