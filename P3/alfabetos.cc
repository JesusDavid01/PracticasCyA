// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 18/10/2021
// Archivo alfabetos.cc: Archivo para el desarrollo de la clase Alfabeto.
//        Contiene el desarrollo del constructor y de las clases
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        18/10/2021 - Creación (segunda versión) del código

#include "alfabetos.h"

using namespace std;
// Constructor de la clase Alfabeto. Se le pasa un vector de símbolos y guarda
// lo que necesita y elimina el último elemento, la cadena
Alfabeto::Alfabeto(vector<Simbolo> alphabet) {
  alfabeto_ = alphabet;
  alfabeto_.erase(alfabeto_.end());
}
// Método para imprimir por pantalla
void Alfabeto::print() {
  for (auto c : alfabeto_) {
    cout << c.Get_Symbol() << ' ';
  }
  cout << endl;
}