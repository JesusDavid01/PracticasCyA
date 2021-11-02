// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Autómatas finitos y reconocimiento de patrones
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 02/11/2021
// Archivo file.cc:
//        Contiene la implementación de la clase file y el desarrollo del
//        constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        30/10/2021 - Creación (primera versión) del código

#include "file.h"

File::File(std::string dna, std::string out_file) {
  out_file_.open(out_file);  // Apertura de archivo de salida

  std::string sequence;

  for (size_t i = 0; i < dna.size();
       i++) {  // Obtenemos los símbolos de la
               // cadena y los guardamos en un string
    sequence += dna[i];
    dna_.insert(dna_.end(), sequence);
    sequence = "";
  }
}

// Funcion isString para comprobar si es una cadena
void File::isString() {
  std::string result, aux;
  std::string final_result[tam];
  int posicion{0};
  char actual_node = nodeS;
  for (size_t j = 2; j < dna_.size(); j++) {  // Bucle para obtener las cadenas por tamaño
    actual_node = nodeS;
    for (size_t i = 0; i < dna_.size(); i++) {  // Iteramos cada uno de los simbolos de la cadena
      aux = "";
      aux = dna_[i].Get_Symbol();
      switch (aux.front()) {  // Dependiendo del símbolo que obtengamos tenemos
                              // unas opciones
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
          std::cout << "La cadena introducida tiene caracteres no reconocidos "
                       "por el alfabeto. Por favor, introduzca una cadena de "
                       "caracteres válida."
                    << std::endl;
          assert((aux.front() != A || (aux.front() != C) || (aux.front() != T) || (aux.front() != G)));
          // Nos ejecuta un assert si algun elemento no pertenece al Alfabeto
          break;
      }
      if (result.size() == j &&
          ((actual_node == nodeE) || (actual_node == nodeF))) {  // Nos comprueba el nodo actual y si el tamaño coincide
                        // con el de la cadena que estamos buscando
        i = (i - (j - 1));  // Nos situamos en la ultima posición de la cadena
                            // en la que estamos situados
        final_result[posicion] = result;  // Guardamos el resultado en un arry de string
        posicion++;
        actual_node = nodeS;  // Una vez metida puesto el resultado, nos
                              // situamos de nuevo en el nodo inicial
        result = "";
      } else if ((result.size() == j) && ((actual_node == nodeD) || (actual_node == nodeB) || (actual_node == nodeO))) {  
                              // En caso de que estemos en el tamaño de cadena
                              // que buscamos pero no estemos en un estado de
                              // aceptación
        actual_node = nodeS;  // Nos situamos en el nodo inicial
        i = (i - (j - 1));    // En la ultima posición de la cadena en la que
                              // estamos situados
        result = "";          // Y vaciamos nuestra cadena resultado
      }
    }
    result = "";  // Vaciamos nuestro resultado
  }
  final_file(final_result, posicion); // Una vez tengamos el resultado, llamamos a la funcion para
                                      // eliminar las cadenas repetidas y los espacios en blanco
}

// Funcion final_file para eliminar las cadenas repetidas y los espacios en
// blanco, estableciendo el archivo final
void File::final_file(std::string final_result[], int posicion) {
  int loop{0};
  for (int i = 0; i < posicion; i++) {  // Bucle para eliminar las cadenas repetidas
    for (int j = i + 1; j < posicion; j++) {
      if (final_result[i] == final_result[j]) { // Si la cadena de la posicion i es igual a alguna
                                                // del string
        final_result[j] = "";                   // eliminamos la cadena de la posicion j
      }
    }
  }
  while (loop != tam) {  // Eliminamos las posiciones en blanco, tantas veces
                         // como cadenas podamos tener
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
  for (int i = 0; i < posicion; i++) {  // Con el resultado final, escribimos el
                                        // resultado en el archivo de salida
    if (final_result[i] != "") {
      out_file_ << final_result[i] << std::endl;
    }
  }
}