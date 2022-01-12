// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos Voraces
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 11/01/2022
// Archivo mochila.cc:
//        Contiene el desarrollo de la clase Mochila y su constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        11/01/2022 - Creación (primera versión) del código

#include "mochila.h"

Mochila::Mochila(std::string peso, std::string config_file) {
  peso_mochila_ = stoi(peso);
  config_file_.open(config_file);

  std::string all_line, one_line;
  std::vector<std::string> aux;
  int contador{0};
  
  while(getline(config_file_, all_line)) {
    std::istringstream numbers{all_line};
    while(getline(numbers, one_line)) {
      aux.emplace_back(std::string(one_line));
      contador++;
    }
  }
  make_weight_utility(aux);
  make_utility();
  make_knapsack();
  make_weight();
}


void
Mochila::make_weight_utility(std::vector<std::string> aux) {
  int k{1};
  for (int i = 0; i <= 5; ++i) {
    std::string aux_numbers = "";
    std::string numbers = "";
    int contador{0};
    aux_numbers = aux[i];
    for (int j = 0; j < 8; j++) {
      switch (i) {
        case 0:
          aux_numbers = aux_numbers[i];
          numero_objetos_ = stoi(aux_numbers);
          break;

        default:
          if (aux_numbers[j] == space && contador == 0) {
            peso_[k] = stoi(numbers);
            contador++;
            numbers = "";
          } else if (aux_numbers[j] == space && contador == 1) { 
            bondad_[k] = stoi(numbers);
            contador++;
            numbers = "";
            ++k;
          } else {
            numbers += aux_numbers[j];
          }
          break;
      }
    }
  }
}

void
Mochila::make_utility() {
  for (int i = 1; i <= numero_objetos_; ++i) {
    utilidad_[i] = bondad_[i]/peso_[i];
  }
}


void
Mochila::make_knapsack() {
  int contador{1};
  float max;
  for (int i = 1; i <= numero_objetos_; ++i) {
      max = utilidad_[1];
    for (int j = 1; j <= numero_objetos_; ++j) {
      if (max < utilidad_[j]) {
      max = utilidad_[j];
      }
    }
    for (int j = 1; j <= numero_objetos_; ++j) {
      if (max == utilidad_[j]) {
        posicion_[i] = j;
        utilidad_[j] = 0;
        j = numero_objetos_;
      }
    }
    utilidad_ordenada_[contador] = max;
    contador++;
  }
}


void
Mochila::make_weight() {
  float peso_dinamico{0};
  std::string solucion = "Solucion: ";
  float final_beneficio{0};
  for (int i = 1; i <= numero_objetos_; ++i) {
    if ((peso_dinamico + peso_[posicion_[i]]) < peso_mochila_) {
      peso_dinamico += peso_[posicion_[i]];
      std::string aux(std::to_string(posicion_[i]));
      solucion += aux;
      solucion += ":";
      solucion += "1, ";
      final_beneficio += bondad_[posicion_[i]];
    } else {
      float peso_aux, peso_nuevo;
      peso_aux = peso_mochila_ - peso_dinamico;
      peso_nuevo = peso_aux / peso_[posicion_[i]];
      peso_dinamico += peso_nuevo * peso_[posicion_[i]] / utilidad_ordenada_[i];
      std::string aux(std::to_string(posicion_[i]));
      solucion += aux;
      solucion += ":";
      std::string aux1(std::to_string(peso_nuevo));
      solucion += aux1;
      final_beneficio += peso_aux * utilidad_ordenada_[i];
      break;
    }
  }
  std::cout << "Beneficio: " << final_beneficio << std::endl;
  std::cout << "Peso: " << peso_mochila_ << std::endl;
  std::cout << "Solución: " << solucion << std::endl;
}