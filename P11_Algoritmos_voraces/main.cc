// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos Voraces
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 11/01/2022
// Archivo main.cc:
//        Contiene el desarrollo del main y algunas funciones de ayuda
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        11/01/2022 - Creación (primera versión) del código

#include <iostream>

#include "mochila.h"

/** Método para comprobar el número de argumentos que se pasan por pantalla
 * 
 * @param argc Contiene el número de argumentos que se leen por pantalla
 * 
 */
bool wrong_command(int argc) {
  if (argc <= 2 || argc > 3) { // Si hay menos de 1 argumentos, da error
    std::cout << "Error. Comando mal introducido" << std::endl;
    std::cout << "La forma correcta de introducir el comando es : ";
    std::cout << "./[nombre_de_archivo_ejecutable] [peso de la mochila] [fichero de configuración] " << std::endl;
    std::cout << "Para mas información introduzca ./p11_algoritmos_voraces --help o ./p11_algoritmos_voraces -h"
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
bool print_help(std::string argv) {
  if ((argv == "--help") || (argv == "-h")) { // En caso de que usemos --help, imprimimos un pequeño texto con información por pantalla
    std::cout
        << "La forma correcta para utilizar este comando es introducir"
           "./{nombre del archivo main} {peso de la mochila} {fichero de configuración}"
        << std::endl
        << "Donde nombre del archivo main es el nombre del programa que va"
           " a ejecutar"
        << std::endl
        << "peso de la mochila es el peso máximo que va a soportar la mochila"
        << std::endl
        << "fichero de configuración es nombre del archivo de"
           " entrada que contiene los detalles de los productos de la mochila"
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
  if (wrong_command(argc)) {return 1;};
  if (print_help(argv[1])) {return 1;}; 
  std::string peso (argv[1]);  // Lee el archivo de entrada con la gramatica
  std::string config_file (argv[2]);     // Lee el nombre del archivo de entrada con las reglas de produccion
  Mochila archivos(peso, config_file);   // Creamos una objeto archivos de la clase File
  return 0;
}