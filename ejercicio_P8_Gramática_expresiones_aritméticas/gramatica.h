// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramática para expresiones aritméticas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 24/11/2021
// Archivo gramatica.h: Archivo gramatica.h
//        Contiene la definición de la clase Gramatica y sus métodos
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        24/11/2021 - Creación (primera versión) del código

#ifndef GRAMATICA_H
#define GRAMATICA_H

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "simbolo.h"

const int size{20};
const char character_space = ' ';
const char character_flecha = '>';
const char character_guion = '-';
const char character_doublepoints = ':';
const std::string character_E = "E";
const std::string character_N = "N";
const std::string character_D = "D";
const char char_character_E = 'E';
const char char_character_N = 'N';
const char char_character_D = 'D';

class Gramatica {
 public:
  Gramatica(std::string& in_cfg, std::string& in_drv, std::string& out_file);

  void terminal_symbols(std::string symbols);
  void no_terminal_symbols(std::string symbols);
  void productions(std::string symbols);
  void eval_cfg(std::vector<Simbolo> symbols);
  void eval_drv(std::vector<Simbolo> symbols);
  void eval_gramatica();
  void make_productions();
  std::string cadena_do(std::string& anterior_aux, std::string& siguiente_aux);

 private:
  std::ifstream in_cfg_;
  std::ifstream in_drv_;
  std::ofstream out_file_;
  std::vector<Simbolo> terminal_symbols_;
  std::vector<Simbolo> no_terminal_symbols_;
  std::vector<Simbolo> before_producciones_;
  std::string producciones_[size][size];
  std::vector<Simbolo> derivaciones_;
  int contador_symbol_0_{0};
  int contador_symbol_1_{0};
  int contador_symbol_2_{0};
  std::string expresion_final_;
};
#endif