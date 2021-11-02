// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Autómatas finitos y reconocimiento de patrones
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 02/11/2021
// Archivo main.cc:
//        Contiene el desarrollo del main
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        30/10/2021 - Creación (primera versión) del código

#include <iostream>
#include <cmath>

#include "file.h"
#include "dfa.h"

int main(int argc, char* argv[]) {
if (argc < 2) {
    std::cout << "Error. Comando mal introducido" << std::endl;
    std::cout << "La forma correcta de introducir el comando es : ";
    std::cout << "./[nombre_de_archivo_ejecutable] [cadena_de_entrada] [archivo_de_salida]";
    return 1;
  }
  std::string dna(argv[1]);
  std::string out(argv[2]);
  File work(dna, out);
  work.isString();
  
  return 0;
}