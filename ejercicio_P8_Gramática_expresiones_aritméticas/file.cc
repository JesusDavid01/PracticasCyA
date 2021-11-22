// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramática para expresiones aritméticas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 24/11/2021
// Archivo file.cc: Archivo file.cc
//        Contiene la implementación de la clase File y sus métodos, además
//        de la definición del constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        24/11/2021 - Creación (primera versión) del código

#include "file.h"

/** Abre tres archivos, dos de entrada y uno de salida. Luego se pasa a la
 *  clase Gramatica y se evalua la derivación
 * 
 * @param in_cfg  Nombre del archivo que contiene la gramática para su
 *                posterior paso a la clase Gramatica
 * 
 * @param in_drv  Nombre del archivo que contiene la derivación gramática para
 *                su posterior paso a la clase Gramatica
 * 
 * @param out_file Nombre del archivo de salida para su posterior paso a la
 *                 clase Gramatica
*/
File::File(std::string& in_cfg, std::string& in_drv, std::string& out_file) {
  Gramatica evaluar_gramatica(in_cfg, in_drv, out_file);
}