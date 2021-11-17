// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Simulación de NFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 17/11/2021
// Archivo nfa.cc: Archivo nfa.cc
//        Contiene la implementación de la clase Nfa y sus métodos, además
//        de la definición del constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        17/11/2021 - Creación (primera versión) del código

#include "nfa.h"

/**
 * @brief Construct a new Nfa:: Nfa object
 *        Abrimos el archivo que contiene el Nfa. Leemos la primera línea que 
 *        equivale al número de estados. Luego leemos la segunda línea que 
 *        equivale al estado de arranque. A partir de la tercera línea el 
 *        resto equivale a los diferentes Nfa. Para cada uno de ellos 
 *        establecemos un Nfa nuevo. Luego comprobamos si está todo correcto.
 *        Luego para cada uno de los símbolos de la cadena, los situamos en una
 *        posición diferente y creamos un vector de símbolos. Una vez obtenido
 *        el vector de símbolos, lo evaluamos para saber si la cadena es 
 *        aceptada o no.
 * 
 * @param nfa_file Contiene el nombre del fichero que vamos a leer para
 *                 obtener el nfa
 * @param chain Contiene la cadena a evaluar
 */
Nfa::Nfa(std::string& nfa_file, std::vector<Simbolo>& chain) {
  nfa_file_.open(nfa_file);

  std::string aux;
  std::vector<Simbolo> chain_aux;
  getline(nfa_file_, aux);
  unsigned int auxiliar = stoi(aux, nullptr);
  set_numero_estados(auxiliar);
  aux = "";

  getline(nfa_file_, aux);
  auxiliar = stoi(aux, nullptr);
  set_estado_arranque(auxiliar);
  aux = "";

  int num_estado{0};
  while(getline(nfa_file_, aux, '\n')) {
    make_estados(aux, num_estado);
  }
  isAllOk();
  estado_actual_ = num_estado;
  aux = "";
  aux = chain.front().Get_Symbol();

  if (aux == "&") {
    aux = "";
    return;
  }
  std::string cadena;
  for (size_t i = 0; i < aux.size(); i++) {
    cadena += aux[i];
    for (size_t j = 0; j < cadena.size(); j++) {  
      chain_aux.emplace_back(Simbolo(cadena));  
    }
    cadena = "";
  }
  isAccepted(chain_aux);
}

/**
 * @brief Establece el estado de arranque
 * 
 * @param estado_arranque Contiene el nombre del estado de arranque
 */
void Nfa::set_estado_arranque(unsigned int estado_arranque) {
  estado_arranque_ = estado_arranque;
}

/**
 * @brief Establece el estado actual
 * 
 * @param estado_actual Contiene el nombre del estado actual
 */
void Nfa::set_estado_actual(unsigned int estado_actual) {
  estado_actual_ = estado_actual;
}

/**
 * @brief Establece el numero de estados del Nfa
 * 
 * @param numero_estados Contiene el número de estados del Nfa
 */
void Nfa::set_numero_estados(unsigned int numero_estados) {
  numero_estados_ = numero_estados;
}

/**
 * @brief Crea los diferentes estados del Nfa. Obtenemos un string para la
 *        línea correspondiente a cada uno de los estados y sacamos información
 *        de ahí. La primera posición es para el nombre del estado. La segunda
 *        es para determinar si es un estado de aceptación o no. La tercera
 *        equivale al número de transiciones y el resto es, para cada símbolo
 *        su transición al estado siguiente.
 * 
 * @param estados String que contiene la información para crear el Nfa
 * @param num_estado Número de estado que equivale al nombre del estado.
 */
void Nfa::make_estados(std::string estados, int num_estado) {
  int transicion{0};
  std::vector<Simbolo> line_nfa;
  std::string aux;
  std::istringstream line{estados};
  while(getline(line, aux, ' ')){
    line_nfa.emplace_back(Simbolo(aux));
  }
  for (size_t i = 0; i < line_nfa.size(); i++) {
    switch (i) {
      case 0:
        num_estado = stoi(line_nfa[i].Get_Symbol());
        nombre_estado_[num_estado] = stoi(line_nfa[i].Get_Symbol());
        break;

      case 1:
        if (stoi(line_nfa[i].Get_Symbol()) == 0) {
          aceptacion_[num_estado] = false;
        } else {
          aceptacion_[num_estado] = true;
        }
        break;

      case 2:
        transiciones_[num_estado] = stoi(line_nfa[i].Get_Symbol(), nullptr);
        break;

      default:
        if (!isNumber(line_nfa[i].Get_Symbol())) {                                  
          simbolo_[num_estado][transicion] = line_nfa[i].Get_Symbol();              
          transicion_[num_estado][transicion] = stoi(line_nfa[i + 1].Get_Symbol()); 
          transicion++;                                                             
        }                                                                           
        break;
    }
  }
  num_simbolos_[num_estado] = transicion;
}


/**
 * @brief Comprueba si el string leido es un número o no
 * 
 * @param aux string que contiene el símbolo
 */
bool Nfa::isNumber(std::string aux) { 
  for (char c : aux) {
    if(std::isdigit(c) == 0) return false;
  }
  return true;
}

/**
 * @brief Método para comprobar que todo en el nfa está correcto, es decir
 *        si hay dos estados iguales devuelve error.
 * 
 */
int Nfa::isAllOk() {
   for (size_t i = 0; i < numero_estados_; i++) {
    for (unsigned int j = i+1; j < numero_estados_; j++) {
      if (nombre_estado_[i] == nombre_estado_ [j]) { // Si 
        std::cout << "ERROR." << std::endl;
        return 0;
      } 
    }
  }
  return 1;
}

/**
 * @brief Método para comprobar si la cadena es aceptada por el lenguaje o no. 
 *        Si la cadena tiene un tamaño menor de 3, no la aceptamos. Luego, para
 *        cada valor de la cadena vectorizada, evaluamos las posibilidades. Si
 *        el último valor es una a o una b, la cadena se acepta y el estado
 *        actual es el final. En caso contrario devuelve false. Con la
 *        penúltima posición, si es una a o una b, aceptacion = true y el
 *        estado es el 2. Para la antepenúltima posición, si tenemos una b,
 *        aceptación = true y el estado sería el 1. Para el resto de símbolos,
 *        si son a, b o &, el estado actual sería el 0 y aceptación = true. En
 *        este caso, si el estado final es el 0, se acepta la cadena.
 * 
 * @param chain Contiene la cadena a evaluar. Se trata de una cadena vectorizada.
 */
bool Nfa::isAccepted(std::vector<Simbolo> chain) {
  if(chain.size() < 3) return false;
  int chain_size = chain.size();
  for(size_t i = 0; i < chain.size(); i++) {
    chain_size--;
    switch (i){
      case 0:
        if ((chain[chain_size].Get_Symbol() == symbol_a) || (chain[chain_size].Get_Symbol() == symbol_b)) {
          estado_actual_ = nombre_estado_[estado3];
        } else {
          return false;
        }
        break;

      case 1:
        if ((chain[chain_size].Get_Symbol() == symbol_a) || (chain[chain_size].Get_Symbol() == symbol_b)) {
          estado_actual_ = nombre_estado_[estado2];
        } else {
          return false;
        }
        break;

      case 2:
        if (chain[chain_size].Get_Symbol() == symbol_b) {
          estado_actual_ = nombre_estado_[estado1];
        } else {
          return false;
        }
        break;

      default:
        if ((chain[chain_size].Get_Symbol() == symbol_a) || (chain[chain_size].Get_Symbol() == symbol_b) || (chain[chain_size].Get_Symbol() == symbol_eps)) {
          estado_actual_ = nombre_estado_[estado0];
        } else {
          return false;
        }
        break;
    }
  }
  return true;                                                
}