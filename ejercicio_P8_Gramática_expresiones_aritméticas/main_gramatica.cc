// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramática para expresiones aritméticas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 24/11/2021
// Archivo main_simulacion_nfa.cc:
//        Contiene el desarrollo del main y algunas funciones de ayuda
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        24/11/2021 - Creación (primera versión) del código

#include <iostream>

#include "file.h"

/** Método para comprobar el número de argumentos que se pasan por pantalla
 * 
 * @param argc Contiene el número de argumentos que se leen por pantalla
 * 
 */
bool notusable(int argc) {
  if (argc <= 1 || argc > 4) { // Si hay menos de 1 argumentos, da error
    std::cout << "Error. Comando mal introducido" << std::endl;
    std::cout << "La forma correcta de introducir el comando es : ";
    std::cout << "./[nombre_de_archivo_ejecutable] [input.cfg] [input.drv] "
                 "[output.txt]"
              << std::endl;
    std::cout << "Para mas información introduzca ./p08_grammar --help o ./p08_grammar -h"
              << std::endl;
    return true;
  }
  return false;
}

/** Método para mostar la ayuda por pantalla
 * 
 * @param argv Contiene el nombre del primer argumento después de la llamada
 *             a la función
 * 
 */
bool help(std::string argv) {
  if ((argv == "--help") || (argv == "-h")) { // En caso de que usemos --help, imprimimos un pequeño texto con información por pantalla
    std::cout
        << "La forma correcta para utilizar este comando es introducir"
           "./{nombre del archivo main} {input.cfg} {input.drv} {output.txt}"
        << std::endl
        << "Donde nombre del archivo main es el nombre del programa que va"
           " a ejecutar"
        << std::endl
        << "input.cfg es el nombre del archivo"
           " que contiene la gramática"
        << std::endl
        << "input.drv es nombre del archivo de"
           " entrada que contiene las reglas de produccion que vamos a evaluar"
        << std::endl
        << "Y output.txt es el nombre del archivo de salida donde vamos a "
           "imprimir nuestros resultado"
        << std::endl
        << "Para poder utilizar el programa de forma adecuada debe introducir "
           "todo lo explicado anteriormente"
        << std::endl;
    return true;
  }
  return false;
}

/**
 * @param argc Contiene el número de argumentos que se leen por pantalla
 * @param argv Contiene el nombre de los argumentos después de la llamada
 *             a la función
 */
int main(int argc, char* argv[]) {
  if(notusable(argc)) {return 1;};
  if(help(argv[1])) {return 1;}; 
  std::string in_cfg(argv[1]);  // Lee el archivo de entrada con la gramatica
  std::string in_drv(argv[2]);     // Lee el nombre del archivo de entrada con las reglas de produccion
  std::string out(argv[3]);    // Lee el nombre del archivo de salida del tercer argumento
  File archivos(in_cfg, in_drv, out);   // Creamos una objeto archivos de la clase File
  return 0;
}