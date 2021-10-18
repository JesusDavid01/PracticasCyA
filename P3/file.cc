// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/10/2021
// Archivo file.cc: Archivo file.cc
//        Contiene la implementación de la clase File y sus métodos, además
//        de la definición del constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/10/2021 - Creación (primera versión) del código

#include "file.h"

File::File(string in_file, string out_file, int opcode) {
  in_file_.open(in_file);    // Apertura de archivo de entrada
  out_file_.open(out_file);  // Apertura de archivo de salida
  opcode_ = opcode;

  string all_line, chain;  // Definimos dos variables de tipo string para todas
                           // las lineas del archivo y la cadena
  vector<Simbolo> string_sp;  // Definimos un vector de símbolos sin espacios
  string_sp[MAX];  // Reservamos un espacio de 1000 posiciones para el vector

  while (getline(in_file_,
                 all_line)) {  // Obtención de los caracteres línea por línea
    istringstream in{all_line};
    while (
        getline(in, chain,
                ' ')) {  // Obtención de palabra por palabra en la misma línea
      string_sp.emplace_back(Simbolo(chain));
    }
    if (string_sp.back().Get_Symbol() != "&" &&
        string_sp.size() ==
            1) {  // En caso de que nos den la cadena sin el alfabeto
      for (int i = chain.size() - 1; i >= 0; i--) {
        string cadena1{chain[i]};
        string_sp.insert(string_sp.begin(), Simbolo(cadena1));
      }
    }
    chains_.emplace_back(Chain(
        string_sp, Alfabeto(string_sp)));  // Pasamos los valores a la cadena
    string_sp.clear();                     // Limpiamos la cadena sin espacios
  }
}
// Método que en función del opcode que se le pase hace una cosa u otra
void File::Operador() {
  switch (opcode_) {
    case 1:
      for (auto c : chains_) {
        WriteOut(c.Longitud());
        out_file_ << endl;
      }
      break;

    case 2:
      for (auto c : chains_) {
        WriteOut(c.Inversa());
        out_file_ << endl;
      }
      break;

    case 3:
      for (auto c : chains_) {
        out_file_ << '&' << ' ';
        WriteOut(c.Prefijos());
        out_file_ << endl;
      }
      break;

    case 4:
      for (auto c : chains_) {
        out_file_ << '&' << ' ';
        WriteOut(c.Sufijos());
        out_file_ << endl;
      }
      break;

    case 5:
      for (auto c : chains_) {
        out_file_ << '&' << ' ';
        WriteOut(c.Subcadenas());
        out_file_ << endl;
      }
      break;

    default:
      cout << "OPCODE INCORRECTO" << endl;
      break;
  }
}
// Métodos de escritura
void File::WriteOut(string print) { out_file_ << print << ' '; }
void File::WriteOut(int print) { out_file_ << print << ' '; }
// Método para imprimir los alfabetos
void File::ImprAlfabetos() {
  for (size_t i = 0; i < chains_.size(); i++) {
    for (int j = 0; j < chains_[i].Get_Alfabeto().Get_Size(); j++) {
      cout << chains_[i].Get_Alfabeto()[j] << ' ';
    }
    cout << endl;
  }
}
// Método para imprimir las cadenas
void File::ImprCadenas() {
  for (auto c : chains_) {
    cout << c.Get_Chain();
    cout << endl;
  }
}