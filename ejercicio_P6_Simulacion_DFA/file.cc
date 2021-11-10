// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 10/11/2021
// Archivo file.cc: Archivo file.cc
//        Contiene la implementación de la clase File y sus métodos, además
//        de la definición del constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        10/11/2021 - Creación (primera versión) del código

#include "file.h"

File::File(std::string dfa, std::string in_file, std::string out_file) {
  in_file_.open(in_file);    // Apertura de archivo de entrada
  out_file_.open(out_file);  // Apertura de archivo de salida

  std::string all_line, one_line;
  std::vector<Simbolo> chain;

  while (getline(in_file_, all_line)) { // Obtenemos la linea entera
    std::istringstream sp_chain{all_line};
    while(getline(sp_chain, one_line)) { // Metemos cada caracter en un vector de simbolos
      chain.emplace_back(Simbolo(one_line));
    }
    Chain cadena(chain); // Creamos un objeto cadena de la clase Chain
    Dfa cadenas(dfa, chain); // Creamos un objeto cadenas de la clase Dfa
    if (cadenas.isAccepted(chain) == true) { // Si la cadena es aceptada, escribimos en el archivo de salida la cadena y que está aceptada
      out_file_ << cadena.Get_Chain() << " -- Accepted" << std::endl;
    } else {  // En caso contrario, escribimos en el archivo de salida la cadena y que ha sido rechazada
      out_file_ << cadena.Get_Chain() << " -- Rejected" << std::endl;
    }
    chain.clear(); // Limpiamos la cadena para obtener la siguiente
    all_line = ""; // Vaciamos el string del que obtenemos la cadena
  }
}