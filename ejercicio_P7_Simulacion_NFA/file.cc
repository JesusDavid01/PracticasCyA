// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/11/2021
// Archivo file.cc: Archivo file.cc
//        Contiene la implementación de la clase File y sus métodos, además
//        de la definición del constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/11/2021 - Creación (primera versión) del código

#include "file.h"

/** Abre dos archivos, uno de entrada y otro de salida. Luego se extrae el
 * contenido línea a línea. Por cada línea obtenida, creamos un objeto para
 * la clase cadena y otro para la clase Nfa. Por último se evalúa la cadena
 * y se comprueba si es aceptada o no.
 * 
 * @param nfa Nombre del archivo que contiene el Nfa para su posterior paso
 *            a la clase Nfa
 * 
 * @param in_file Nombre del archivo que contiene las cadenas a evaluar
 * 
 * @param out_file Nombre del archivo de salida
*/
File::File(std::string& nfa, std::string& in_file, std::string& out_file) {
  in_file_.open(in_file);
  out_file_.open(out_file);

  std::string all_line, one_line, aux;
  std::vector<Simbolo> chain;

  while (getline(in_file_, all_line)) {
    std::istringstream sp_chain{all_line};
    while(getline(sp_chain, one_line)) {
      for(size_t i = 0; i < one_line.size(); i++) {
        aux += one_line[i];
        for(size_t j = 0; j < aux.size(); j++) {
          chain.emplace_back(Simbolo(aux));
        }
        aux = "";
      }
    }
    Chain cadena(chain);
    Nfa prueba(nfa, chain);
    if (prueba.isAccepted(chain) == true) {
      out_file_ << cadena.Get_Chain() << " -- Accepted" << std::endl;
    } else {
      out_file_ << cadena.Get_Chain() << " -- Rejected" << std::endl;
    }
    chain.clear();
    all_line = "";
  }
}