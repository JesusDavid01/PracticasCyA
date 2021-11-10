// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 10/11/2021
// Archivo main_simulacion_dfa.cc:
//        Contiene el desarrollo del main
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        10/11/2021 - Creación (primera versión) del código

#include <iostream>

#include "file.h"

int main(int argc, char* argv[]) {
  if (argc < 1 || argc > 4) { // Si hay menos de 1 argumentos, da error
    std::cout << "Error. Comando mal introducido" << std::endl;
    std::cout << "La forma correcta de introducir el comando es : ";
    std::cout << "./[nombre_de_archivo_ejecutable] [input.dfa] [input.txt] "
                 "[output.txt]"
              << std::endl;
    std::cout << "Para mas información introduzca ./dfa_simulacion --help o ./dfa_simulacion -h"
              << std::endl;
  } else if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) { // En caso de que usemos --help, imprimimos un pequeño texto con información por pantalla
    std::cout
        << "La forma correcta para utilizar este comando es introducir"
           "./{nombre del archivo main} {input.dfa} {input.txt} {output.txt}"
        << std::endl
        << "Donde nombre del archivo main es el nombre del programa que va"
           " a ejecutar"
        << std::endl
        << "input.dfa es el nombre del archivo"
           " que contiene el dfa"
        << std::endl
        << "input.txt es nombre del archivo de"
           " entrada que contiene las cadenas que vamos a evaluar"
        << std::endl
        << "Y output.txt es el nombre del archivo de salida donde vamos a "
           "imprimir nuestros resultado"
        << std::endl
        << "Para poder utilizar el programa de forma adecuada debe introducir "
           "todo lo explicado anteriormente"
        << std::endl;
    return 1;
  }
  std::string dfa(argv[1]);  // Lee el archivo de entrada con el dfa del primer argumento
  std::string in(argv[2]);     // Lee el nombre del archivo de entrada del segundo argumento
  std::string out(argv[3]);    // Lee el nombre del archivo de salida del tercer argumento
  File archivos(dfa, in, out);   // Creamos una variable archivos de la clase File
  return 0;
}