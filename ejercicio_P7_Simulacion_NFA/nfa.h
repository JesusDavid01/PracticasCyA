// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/11/2021
// Archivo nfa.h: Archivo nfa.h
//        Contiene la definición de la clase Nfa y sus métodos
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/11/2021 - Creación (primera versión) del código

#ifndef NFA_H
#define NFA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "cadenas.h"

const int size{20};
const std::string symbol_0{'0'};
const std::string symbol_1{'1'};
const std::string symbol_2{'2'};
const std::string symbol_eps{'&'};
const std::string symbol_a{'a'};
const std::string symbol_b{'b'};
const int estado0{0};
const int estado1{1};
const int estado2{2};
const int estado3{3};
const int estado4{4};
const int estado5{5};
const int estado6{6};
const int estado7{7};

class Nfa {
 public:
  Nfa(std::string& nfa, std::vector<Simbolo>& cadena);

  unsigned int get_estado_actual();
  unsigned int get_estado_arranque();

  void set_estado_arranque(unsigned int estado_arranque);
  void set_estado_actual(unsigned int estado_actual);
  void set_numero_estados(unsigned int numero_estados);
  void make_estados(std::string estados, int num_estado);
  bool isNumber(std::string aux);
  bool isAccepted(std::vector<Simbolo> chain);
  int isAllOk();

 private:
  unsigned int estado_actual_;
  unsigned int numero_estados_;
  unsigned int estado_arranque_;
  int num_simbolos_[size];
  std::ifstream nfa_file_;
  int nombre_estado_[size];
  bool aceptacion_[size];
  int transiciones_[size];
  std::string simbolo_[size][size];
  int transicion_[size][size];
};
#endif