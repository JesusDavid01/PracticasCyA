// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos Voraces
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 11/01/2022
// Archivo mochila.h:
//        Contiene la definición de la clase Mochila y sus métodos
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        11/01/2022 - Creación (primera versión) del código

#ifndef MOCHILA_H
#define MOCHILA_H

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

const int size{20};
const char space = ' ';

class Mochila {
 public:
  Mochila(std::string peso, std::string config_file);

  std::string eval_mochila();
  void make_weight_utility(std::vector<std::string>);
  void make_utility();
  void make_knapsack();
  void make_weight();


 private:
  float peso_mochila_;
  float peso_[size];
  float bondad_[size];
  float utilidad_[size];
  float utilidad_ordenada_[size];
  float beneficio_;
  int posicion_[size];
  int numero_objetos_;
  std::string solucion_;
  std::ifstream config_file_;

};
#endif