// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramática para expresiones aritméticas
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 24/11/2021
// Archivo gramatica.cc: Archivo gramatica.cc
//        Contiene la implementación de la clase Gramatica y sus métodos, además
//        de la definición del constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        24/11/2021 - Creación (primera versión) del código

#include "gramatica.h"

/**
 * @brief Construct a new Gramatica:: Gramatica object
 *        Lee tres archivos, dos de entrada y uno de salida. Del primero
 *        de entrada obtenemos la gramática. Del segundo archivo de
 *        entrada obtenemos la derivación gramática. Amba información
 *        la guardaremos en vectores de símbolos que vectorizaremos llamando
 *        a la función eval_cfg para el in_cfg y a la función eval_drv para el
 *        in_drv. Por último, en la función eval_gramatica evaluaremos nuestras
 *        derivaciones y escribiremos el archivo de salida con la información
 *        obtenida de las otras dos funciones.
 * 
 * @param in_cfg  Nombre del archivo que contiene la especificación de la
 *                gramática
 * 
 * @param in_drv  Nombre del archivo que contiene las derivaciones de la 
 *                gramática
 * 
 * @param out_file Nombre del archivo de salida 
 */
Gramatica::Gramatica(std::string& in_cfg, std::string& in_drv, std::string& out_file) {
  in_cfg_.open(in_cfg);
  in_drv_.open(in_drv);
  out_file_.open(out_file);

  std::string all_line, one_line;
  std::vector<Simbolo> ssymbols, nsymbols;

  while(getline(in_cfg_, all_line)) {
    std::istringstream symbols{all_line};
    while(getline(symbols, one_line)) {
      ssymbols.emplace_back(Simbolo(one_line));
    }
  }
  all_line = "";
  one_line = "";

  while(getline(in_drv_, all_line)) {
    std::istringstream symbols{all_line};
    while(getline(symbols, one_line)) {
      nsymbols.emplace_back(Simbolo(one_line));
    }
  }

  eval_cfg(ssymbols);
  eval_drv(nsymbols);
  eval_gramatica();
}

/**
 * @brief Evalúa la gramática. En la primera línea obtenemos los símbolos
 *        terminales, en la segunda obtenemos los símbolos no terminales
 *        y en el resto las especificaiones de nuestra gramática. Por último
 *        llamamos a una función que vectorice nuestras producciones para
 *        facilitarnos el uso
 * 
 * @param ssymbols  Vector de símbolos que contiene las líneas de texto de
 *                  nuestro archivo
 */
void Gramatica::eval_cfg(std::vector<Simbolo> ssymbols) {
  for (size_t i = 1; i < ssymbols.size(); i++) {
    switch (i) {
      case 0:
        terminal_symbols(ssymbols[i].Get_Symbol());
        break;

      case 1:
        no_terminal_symbols(ssymbols[1].Get_Symbol());
        break;

      default:
        productions(ssymbols[i].Get_Symbol());
        break;
    }
  }
  make_productions();
}

/**
 * @brief Vectoriza los símbolos terminales para facilitar su uso
 * 
 * @param symbols Contiene los símbolos terminales
 */
void Gramatica::terminal_symbols(std::string symbols) {
  for (size_t i = 0; i < symbols.size(); i++) {
    std::string aux_symbol;
    if (symbols[i] != character_space) {
      aux_symbol += symbols[i];
      terminal_symbols_.emplace_back(aux_symbol);
    } 
  }
}

/**
 * @brief Vectoriza los símbolos no terminales para facilitar su uso
 * 
 * @param symbols Contiene los simbolos no terminales
 */
void Gramatica::no_terminal_symbols(std::string symbols) {
  for (size_t i = 0; i < symbols.size(); i++) {
    std::string aux_symbol;
    if (symbols[i] != character_space) {
      aux_symbol += symbols[i];
      no_terminal_symbols_.emplace_back(aux_symbol);
    }
  }
}

/**
 * @brief Vectoriza las producciones y las empareja con un símbolo no terminal.
 *        En caso de que el caracter obtenido de la linea no sea ni un espacio,
 *        ni un guión seguido de una flecha, ni una flecha, si es la primera
 *        posicion, lo situamos en la primera posicion de vector de símbolos,
 *        si es el resto de posiciones menos la última, metemos el símbolo en
 *        el string, y si es la última posición, metemos el símbolo en el
 *        string y además, añadimos esa expresion.
 * 
 * @param symbols Contiene las producciones
 */
void Gramatica::productions(std::string symbols) {
  std::string expressions;
  for (size_t i = 0; i < symbols.size(); i++) {
    std::string aux_symbol;
    if (symbols[i] != character_space && (symbols[i] != character_guion || symbols[i+1] != character_flecha) && symbols[i] != character_flecha) {
        if (i == 0 ) {
          aux_symbol += symbols[i];
          before_producciones_.emplace_back(aux_symbol);
        } else if (i == symbols.size() - 1){
          expressions += symbols[i];
          before_producciones_.emplace_back(expressions);
        } else {
          expressions += symbols[i];
        }
    } 
  }
}

/**
 * @brief Después de establecer las producciones, para cada uno de los simbolos
 *        no terminales le corresponde una transición a una expresión. A medida
 *        que vamos leyendo, si obtenemos caracteres iguales a nuestros
 *        simbolos terminales, vamos emparejando la expresión siguiente con ese
 *        símbolo.
 * 
 */
void Gramatica::make_productions() {
  int actual_symbol{0};
  for (size_t i = 0; i < before_producciones_.size(); i++) {
    if (before_producciones_[i].Get_Symbol() == no_terminal_symbols_[0].Get_Symbol()) {
      actual_symbol = 0;
      producciones_[actual_symbol][contador_symbol_0_] = before_producciones_[i+1].Get_Symbol();
      contador_symbol_0_++;
      i++;
    } else if (before_producciones_[i].Get_Symbol() == no_terminal_symbols_[1].Get_Symbol()) {
      actual_symbol = 1;
      producciones_[actual_symbol][contador_symbol_1_] = before_producciones_[i+1].Get_Symbol();
      contador_symbol_1_++;
      i++;
    } else {
      actual_symbol = 2;
      producciones_[actual_symbol][contador_symbol_2_] = before_producciones_[i+1].Get_Symbol();
      contador_symbol_2_++;
      i++;
    }
  }
}

/**
 * @brief Establece nuestras derivaciones. Para cada uno de las líneas
 *        obtenidas como i, si nuestro caracter no es ni un espacio ni 
 *        dos puntos, establecemos en nuestro vector de símbolos lo que
 *        corresponda. En este caso, para la posición i = 0, equivale al
 *        simbolo terminal E y para la posicion i = 1, equivale un 1, esto
 *        quiere decir que para la primera transición del símbolo E debemos
 *        obtener la producción 1 del símbolo no terminal E.
 * 
 * @param symbols Contiene todas las derivaciones obtenidas del archivo 
 *                input.drv
 */
void Gramatica::eval_drv(std::vector<Simbolo> symbols) {
  for (size_t i = 0; i < symbols.size(); i++) {
    std::string aux_symbol = symbols[i].Get_Symbol();
    for (size_t j = 0; j < aux_symbol.size(); j++) {
      std::string aux_symbols;
      if (aux_symbol[j] != character_space && aux_symbol[j] != character_doublepoints) {
        aux_symbols += aux_symbol[j];
        derivaciones_.emplace_back(aux_symbols);
      } 
    }
  }
}

/**
 * @brief Es una función encargada de evaluar la gramática mediante los
 *        resultados obtenidos de las funciones anteriores. Basicamente,
 *        cada 8 iteraciones, inserta un salto de línea para que el archivo
 *        sea más visual. Luego, si el caracter obtenido concuerda con alguno
 *        de los símbolos no terminales de nuestra gramática, pasamos la
 *        expresion equivalente a ese símbolo y a su transición a un string.
 *        En siguiente lugar, llamamos a la función cadena_do para que nos
 *        devuelva la modificación del string con la derivación hecha.
 *        Establecemos el nodo anterior como el nodo actual, lo imprimimos en
 *        el archivo de salida y evaluamos la derivación siguiente.
 * 
 */
void Gramatica::eval_gramatica() {
  std::vector<Simbolo> gramatica;
  std::string anterior_aux = character_E, siguiente_aux;
  out_file_ << anterior_aux << " => ";
  for (size_t i = 0; i < derivaciones_.size(); i++) {
    if (i % 8 == 0 && i != 0) {
      out_file_ << std::endl;
    }
    if (derivaciones_[i].Get_Symbol() == character_E) {
      siguiente_aux = producciones_[0][stoi(derivaciones_[i+1].Get_Symbol()) - 1];
      cadena_do(anterior_aux, siguiente_aux);
      anterior_aux = expresion_final_;
      out_file_ << expresion_final_ << " => ";
    } else if (derivaciones_[i].Get_Symbol() == character_N) {
      siguiente_aux = producciones_[1][stoi(derivaciones_[i+1].Get_Symbol()) - 1];
      cadena_do(anterior_aux, siguiente_aux);
      anterior_aux = expresion_final_;
      out_file_ << expresion_final_ << " => ";
    } else if (derivaciones_[i].Get_Symbol() == character_D) {
      siguiente_aux = producciones_[2][stoi(derivaciones_[i+1].Get_Symbol()) - 1];
      cadena_do(anterior_aux, siguiente_aux);
      anterior_aux = expresion_final_;
      out_file_ << expresion_final_ << " => ";
    }
  }
}

/**
 * @brief Recoge dos strings que se le pasan como argumentos y mediante estas
 *        si alguno de los símbolos de anterior_aux equivale a alguno de
 *        nuestros simbolos no terminales, sustituimos ese símbolo por la 
 *        expresion almacenada en el string siguiente_aux. En caso de que no
 *        corresponda a ningún símbolo terminal, solamente vamos añadiendo 
 *        caracteres a nuestro string.
 * 
 * @param anterior_aux Contiene la derivación que vamos a evaluar
 * 
 * @param siguiente_aux Contiene la expresión por la que vamos a sustituir
 *                      el simbolo no terminal
 * 
 * @return std::string Devuelve un string con la derivación realizada
 */
std::string 
Gramatica::cadena_do(std::string& anterior_aux, std::string& siguiente_aux) {
  expresion_final_ = "";
  int times_counter{0};
  for (size_t i = 0; i < anterior_aux.size(); i++) {
    if (((anterior_aux[i] == char_character_E || anterior_aux[i] == char_character_N || anterior_aux[i] == char_character_D)) && (times_counter == 0)) {
      expresion_final_ += siguiente_aux;
      times_counter++;
    } else {
      expresion_final_ += anterior_aux[i];
    }
  }
  return expresion_final_;
}