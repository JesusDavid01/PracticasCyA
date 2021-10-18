// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/10/2021
// Archivo cadenas.cc: Archivo para el desarrollo de la clase Chain
//        Contiene el desarrollo del constructor y de las clases de la clase
//        Chain
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/10/2021 - Creación (primera versión) del código

#include "cadenas.h"

using namespace std;

// Constructor de la clase Chain, dado un vector de símbolos y un alfabeto se
// construye la cadena
Chain::Chain(vector<Simbolo> chain, Alfabeto alphabet) : alphabet_(alphabet) {
  chain_ = chain.back().Get_Symbol();  // Cadena sería el último elemento de la
                                       // linea en el archivo

  if (chain_ == "&") {
    chain_ = "";
    return;
  }  // Si la cadena es la cadena vacía, chain será una cadena vacía
  string cadena;
  for (size_t i = 0; i < chain_.size();
       i++) {  // Recorremos la cadena y cuando encontramos un símbolo en ella
               // lo almacenamos.
    cadena += chain_[i];
    for (size_t j = 0; j < chain.size() - 1; j++) {
      if (cadena ==
          chain[j].Get_Symbol()) {  // Comparamos el recorrido de la cadena con
                                    //  los simbolos del alfabeto para ver si
                                    // coincide
        chain_well_.emplace_back(
            Simbolo(cadena));  // Si encontramos que existe una igualdad,
                               // almacenamos el símbolo en la cadena
                               // vectorizada y limpiamos la cadena auxiliar.
        cadena = "";
      }
    }
  }
}
// Método que devuelve la longitud de la cadena
int Chain::Longitud() { return Get_Size(); };
// Método que devuelve la inversa de la cadena
string Chain::Inversa() {
  string resultado = "";
  if (Get_Size() == 0) return "&";
  for (int i = Get_Size() - 1; i >= 0; i--) {
    resultado += chain_well_[i].Get_Symbol();
  }
  return resultado;
};
// Método que devuelve los prefijos de la cadena
string Chain::Prefijos() {
  string resultado = "";
  string cadena = "";
  for (int i = 0; i < Get_Size(); i++) {
    cadena += chain_well_[i].Get_Symbol();
    resultado += cadena + ' ';
  }
  return resultado;
};
// Método que devuelve los sufijos de la cadena
string Chain::Sufijos() {
  string resultado = "";
  string cadena = "";
  for (int i = Get_Size() - 1; i >= 0; i--) {
    cadena += chain_well_[i].Get_Symbol();
    resultado += cadena + ' ';
  }
  return resultado;
};
// Método para obterner las subcadenas de la cadena
string Chain::Subcadenas() {
  string resultado = "";
  string cadena = "";

  for (int i = 0; i < Get_Size(); i++) {    // Recorre los simbolos uno a uno
    for (int j = i; j < Get_Size(); j++) {  // Recorre los simbolos uno a uno
                                            // desde el simbolo del primer bucle
      cadena +=
          chain_well_[j]
              .Get_Symbol();  // Los símbolos se concatenan para ir comprobando
                              // las posibilidades hasta comprobarlas todas
      resultado += cadena + ' ';
    }
    cadena = "";
  }
  return resultado;
};