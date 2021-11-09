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
//        Contiene la implementación de la clase File y sus métodos, además
//        de la definición del constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        25/10/2021 - Creación (primera versión) del código

#include "file.h"

File::File(string in_file, string out_file, string name_in) {
  in_file_.open(in_file);    // Apertura de archivo de entrada
  out_file_.open(out_file);  // Apertura de archivo de salida

  string all_line, solo_word;  // Definimos una variables de tipo string para
                               // todas las líneas
  int line{1}, line_alm{0}, contador{0};
  int just_one_loop{1}, just_one_var{1}, just_one_main{1};
  int just_one_include {1}, just_one_return {1};
  out_file_ << "PROGRAM: " << name_in << endl;
  line++;
  regex expressionSimpleComments(SimpleDoubleComment);
  regex expressionCompoundCommentStart(CompoundCommentStart);
  regex expressionCompoundCommentFinish(CompoundCommentFinish);
  regex loopfor(BucleFor);
  regex loopwhile(BucleWhile);
  regex vInt(VariableInt);
  regex vDouble(VariableDouble);
  regex expMain(ExpressionMain);
  regex expInclude(ExpressionInclude);
  regex expReturn(ExpressionReturn);
  smatch matches;

  while (getline(in_file_,
                 all_line)) {  // Obtención de los caracteres línea por línea
    istringstream in{all_line};
    while (getline(in, solo_word, '\n')) {
      save_ += solo_word + " ";
      line++;
    }
   if (regex_search(save_, matches, expressionSimpleComments) ||
        regex_search(save_, matches, expressionCompoundCommentStart) ||
        regex_search(save_, matches, expressionCompoundCommentFinish)) {
      if (line == 3) {
        out_file_ << "DESCRIPTION: " << endl;
      } else if (contador == 100) {
        out_file_ << endl;
        out_file_ << "COMMENTS: " << endl;
        out_file_ << "[Line 1-" << line_alm << "] DESCRIPTION" << endl;
        out_file_ << "[Line " << line << "] ";
        contador = 0;
      }
      line_alm++;
      out_file_ << save_ << endl;
      save_ = "";
    } else if (regex_search(save_, matches, loopfor) ||
               regex_search(save_, matches, loopwhile)) {
      contador = 100;
      if (just_one_loop == 1) {
        out_file_ << endl;
        out_file_ << "STATEMENTS: " << endl;
        just_one_loop++;
      }
      if (regex_search(save_, matches, loopfor)) {
        out_file_ << "[Line " << line << "] "
                  << "LOOP: for" << endl;
      } else {
        out_file_ << "[Line " << line << "] "
                  << "LOOP: while" << endl;
      }
      save_ = "";
    } else if ((regex_search(save_, matches, expMain) ||
                !regex_search(save_, matches, expMain)) &&
               just_one_main == 1) {
      contador = 100;
      out_file_ << endl;
      if (regex_search(save_, matches, expMain)) {
        out_file_ << "MAIN: " << endl;
        out_file_ << "True" << endl;
        just_one_main++;
      } else {
        out_file_ << "MAIN: " << endl;
        out_file_ << "False" << endl;
        just_one_main++;
      }
      save_ = "";
    } else if ((regex_search(save_, matches, vInt) ||
               regex_search(save_, matches, vDouble)) &&
               !regex_search(save_, matches, expMain)) {
      contador = 100;
      if (just_one_var == 1) {
        out_file_ << endl;
        out_file_ << "VARIABLES: " << endl;
        just_one_var++;
      }
      if (regex_search(save_, matches, vInt)) {
        out_file_ << "[Line " << line << "] "
                  << "INT: ";
        line++;
      } else {
        out_file_ << "[Line " << line << "] "
                  << "DOUBLE: ";
      }
      out_file_ << save_ << endl;
      save_ = "";
    } else if (regex_search(save_, matches, expInclude)) {
      if (just_one_include == 1) {
        out_file_ << endl;
        out_file_ << "INCLUDES: " << endl;
        just_one_include++;
      }
      out_file_ << save_ << endl;
      save_ = "";
    } else if (regex_search(save_, matches, expReturn)) {
      if (just_one_return == 1) {
        out_file_ << endl;
        out_file_ << "RETURN: " << endl;
        just_one_return++;
      }
      out_file_ << save_ << endl;
      save_ = "";
    }
    save_ = "";
  } 
}
void File::imprimir(string print) { out_file_ << print << endl; }

void File::Escribir_Archivo() {}