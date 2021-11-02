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
//        Contiene la implementación de la clase file y el desarrollo del
//        constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        30/10/2021 - Creación (primera versión) del código


#include "file.h"



File::File(std::string dna, std::string out_file) {
  out_file_.open(out_file);  // Apertura de archivo de salida

  std::string all_line, sequence;  // Definimos una variables de tipo string para todas las líneas

  for (size_t i = 0; i < dna.size(); i++) {
      sequence += dna[i];
      dna_.insert(dna_.end(), sequence);
      sequence = "";
  }
}

void File::isString() {
  std::string result, aux, result_ant, save_result;
  std::string final_result[tam];
  int posicion {0};
  char actual_node = nodeS;
  for (size_t j = 2; j < dna_.size(); j++) {
    actual_node = nodeS;
    for (size_t i = 0; i < dna_.size(); i++) {
      aux = "";
      aux = dna_[i].Get_Symbol();
      switch (aux.front()) {
        case T:
          if (actual_node == nodeS) {
            result += aux;
            actual_node = nodeD;
            break;
          } else {
            switch (actual_node) {
              case nodeD: 
              actual_node = nodeF;
              break;

              case nodeB:
              actual_node = nodeB;
              break;

              case nodeE:
              actual_node = nodeB;
              break;

              case nodeF:
              actual_node = nodeF;
              break;

              default:
              actual_node = nodeO;
              break;
            }
            result += aux;
            break;
          }

        case A:
          if (actual_node == nodeS) {
            result += aux;
            actual_node = nodeB;
            break;
          } else {
            switch (actual_node) {
              case nodeD: 
              actual_node = nodeD;
              break;

              case nodeF:
              actual_node = nodeD;
              break;

              case nodeB:
              actual_node = nodeE;
              break;

              case nodeE:
              actual_node = nodeE;
              break;

              default:
              actual_node = nodeO;
              break;
            }
            result += aux;
            break;
          }

        case G:
          if (actual_node == nodeS) {
            actual_node = nodeS;
            break;
          } else {
            switch (actual_node) {
              case nodeD: 
              actual_node = nodeD;
              break;

              case nodeF:
              actual_node = nodeD;
              break;

              case nodeE:
              actual_node = nodeB;
              break;

              case nodeB:
              actual_node = nodeB;
              break;

              default:
              actual_node = nodeO;
              break;
            }
            result += aux;
            break;
          }
        
        case C:
          if (actual_node == nodeS) {
            actual_node = nodeS;
            break;
          } else {
            switch (actual_node) {
              case nodeD: 
              actual_node = nodeD;
              break;

              case nodeF:
              actual_node = nodeD;
              break;

              case nodeE:
              actual_node = nodeB;
              break;

              case nodeB:
              actual_node = nodeB;
              break;

              default:
              actual_node = nodeO;
              break;
            }
            result += aux;
            break;
          }

        default:
          std::cout << "La cadena introducida tiene caracteres no reconocidos por el alfabeto. Por favor, introduzca una cadena de caracteres válida." << std::endl;
          assert((aux.front() != A || (aux.front() != C) || (aux.front() != T) || (aux.front() != G)));
          break;
      }
      if (result.size() == j && ((actual_node == nodeE ) || (actual_node == nodeF))) {
        i = (i - (j - 1));
        final_result[posicion] = result;
        posicion++;
        actual_node = nodeS;
        result = "";
      } else if ((result.size() == j) && ((actual_node == nodeD ) || (actual_node == nodeB) || (actual_node == nodeO))) {
        actual_node = nodeS;
        i = (i - (j - 1));
        result = "";
      }
    }
    result = "";
  }
  final_file(final_result, posicion);
}

void File::final_file(std::string final_result[], int posicion) {
  int loop {0};
  for (int i = 0; i < posicion; i++) {
    for (int j = i + 1; j < posicion; j++) {
      if (final_result[i] == final_result[j]) {
        final_result[j] = "";
      }
    }
  }
  while (loop != tam) {
    for (int i = 0; i < posicion; i++) {
      for (int j = i, k = j + 1; j < posicion; j++, k++) {
        if (final_result[j] == "") {
          final_result[j] = final_result[k];
          final_result[k] = "";
        }
      }
    }
    loop++;
  }
  for (int i = 0; i < posicion; i++) {
    out_file_ << final_result[i] << std::endl;
  }
}