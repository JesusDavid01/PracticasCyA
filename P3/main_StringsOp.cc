// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 18/10/2021
// Archivo main_StringsOp.cc: Archivo Main
//        Contiene la entrada por pantalla de archivos y la salida por archivo
//        del resultado del programa
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        18/10/2021 - Creación (segunda versión) del código

#include "file.h"

using namespace std;

// MAIN
int main(int argc, char* argv[]) {
  if (argc < 4) {
    cout << "Error. Comando mal introducido" << endl;
    return 1;
  }
  string in(argv[1]);
  string out(argv[2]);
  int opcode = stoi(string(argv[3]));
  File work(in, out, opcode);
  work.Operador();
  return 0;
}