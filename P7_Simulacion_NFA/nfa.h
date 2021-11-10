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

const int size {20}; // Constante para tamaño

class Nfa {
 public:
  Nfa(std::string nfa, std::vector<Simbolo> cadena);

  unsigned int get_estado_actual();
  unsigned int get_estado_arranque();

  void set_estado_arranque(unsigned int estado_arranque);
  void set_estado_actual(unsigned int estado_actual);
  void set_numero_estados(unsigned int numero_estados);
  void make_estados(std::string estados, int num_estado); // Método que establece los estados
  bool isNumber(std::string aux); // Método que comprueba si el caracter es numero
  bool isAccepted(std::vector<Simbolo> chain); // Método que comprueba si se acepta la cadena
  int isAllOk(); // Método que comprueba si no hay simbolos repetidos
  void printnfa(); // Método que imprime el nfa

 private:
  unsigned int estado_actual_;
  unsigned int numero_estados_;
  unsigned int estado_arranque_;
  int num_simbolos_;
  std::ifstream nfa_file_;
  int nombre_estado_[size]; // Array que almacena el nombre del estado
  bool aceptacion_[size]; // Array que almacena si el estado es de aceptacion o no
  int transiciones_[size]; // Array que almacena el numero de transiciones
  std::string simbolo_[size][size]; // Array doble que almacena el simbolo correspondiente al estado de nombre X
  int transicion_[size][size]; // Array doble que almacena el estado siguiente correspondiente al estado de nombre X y al simbolo Y
};
#endif