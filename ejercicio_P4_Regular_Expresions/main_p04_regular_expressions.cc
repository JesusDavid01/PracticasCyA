// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones Regulares
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 25/10/2021
// Archivo file.cc:
//        Contiene la implementación la funcion main
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        25/10/2021 - Creación (primera versión) del código

#include "file.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 3) {
    cout << "Error. Comando mal introducido" << endl;
    cout << "La forma correcta de introducir el comando es : ";
    cout << "./[nombre_de_archivo_ejecutable] [archivo_de_entrada] [archivo_de_salida]";
    return 1;
  }
  string in(argv[1]);
  string out(argv[2]);
  File work(in, out, in);
  work.Escribir_Archivo();
  return 0;
}