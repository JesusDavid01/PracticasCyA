// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de DFAs
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 10/11/2021
// Archivo dfa.cc: Archivo dfa.cc
//        Contiene la implementación de la clase Dfa y sus métodos, además
//        de la definición del constructor
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        10/11/2021 - Creación (primera versión) del código

#include "dfa.h"

Dfa::Dfa(std::string dfa_file, std::vector<Simbolo> chain) {
  dfa_file_.open(dfa_file);

  std::string aux;
  std::vector<Simbolo> chain_aux;
  getline(dfa_file_, aux);
  unsigned int auxiliar = stoi(aux, nullptr); // Obtenemos la primera linea del archivo y lo establecemos como el numero de estados
  set_numero_estados(auxiliar);
  aux = "";

  getline(dfa_file_, aux);
  auxiliar = stoi(aux, nullptr); // Obtenemos la segunda linea del archivo y lo establecemos como el estado de arranque
  set_estado_arranque(auxiliar);
  aux = "";

  int num_estado {0}; // Creamos una variable int para saber en que estado estamos
  while(getline(dfa_file_, aux, '\n')) {
    make_estados(aux, num_estado); // Para las siguientes lineas del archivo creamos los estados del dfa
  }
  isAllOk(); // Una vez creados comprobamos si todo está correcto
  estado_actual_ = estado_arranque_; // El estado inicial es el estado de arranque
  aux = ""; // Vaciamos la cadena axuiliar
  aux = chain.front().Get_Symbol(); // Pasamos el primer valor de la cadena a la cadena auxiliar

  if (aux == "&") { // Si la cadena auxiliar es la cadena vacía, la cadena será la cadena vacía
    aux = "";
    return;
  }
  std::string cadena;
  for (size_t i = 0; i < aux.size(); i++) {  // Recorremos la cadena y
    // cuando encontramos un símbolo en ella lo almacenamos.
    cadena += aux[i];
    for (size_t j = 0; j < cadena.size(); j++) {  
      chain_aux.emplace_back(Simbolo(cadena));  
                              // Almacenamos el símbolo en la cadena
                             // vectorizada y limpiamos la cadena auxiliar.
    }
    cadena = "";
  }
  isAccepted(chain_aux); // Vemos si la cadena vectorizada es una cadena aceptada por el lenguaje o no
}

void Dfa::set_estado_arranque(unsigned int estado_arranque) {
  estado_arranque_ = estado_arranque;
}

void Dfa::set_estado_actual(unsigned int estado_actual) {
  estado_actual_ = estado_actual;
}

void Dfa::set_numero_estados(unsigned int numero_estados) {
  numero_estados_ = numero_estados;
}

void Dfa::make_estados(std::string estados, int num_estado) {
  int transicion {0};
  std::vector<Simbolo> line_dfa;
  std::string aux;
  std::istringstream line{estados};
  while(getline(line, aux, ' ')){
    line_dfa.emplace_back(Simbolo(aux)); // Obtenemos caracter a caracter el string y dependiendo de cada uno
                                        // de los valores obtenidos y la posicion creamos nuestro dfa 
  }
  for (size_t i = 0; i < line_dfa.size(); i++) { // Para cada posicion del caracter del string
    switch (i) {
      case 0: // Si es la primera posicion, el resultado es el nombre del estado
        num_estado = stoi(line_dfa[i].Get_Symbol());
        nombre_estado_[num_estado] = stoi(line_dfa[i].Get_Symbol());
        break;

      case 1: // Si es la segunda posicion, el resultado es si el estado es de aceptacion o no
        if (stoi(line_dfa[i].Get_Symbol()) == 0) { // Si el valor es 0, el estado no es de aceptacion
          aceptacion_[num_estado] = false;
        } else {
          aceptacion_[num_estado] = true; // Si el valor es 1, el estado es de aceptacion
        }
        break;

      case 2: // Si es la tercera posicion, el resultado es el numero de transiciones
        transiciones_[num_estado] = stoi(line_dfa[i].Get_Symbol(), nullptr);
        break;

      default:                                                                      // En el caso por defecto
        if (!isNumber(line_dfa[i].Get_Symbol())) {                                  // Si el caracter no es numero, es decir, es letra, obtenemos el simbolo y
          simbolo_[num_estado][transicion] = line_dfa[i].Get_Symbol();              // lo almacenamos en el estado actual y para una unica transicion. Luego 
          transicion_[num_estado][transicion] = stoi(line_dfa[i + 1].Get_Symbol()); // obtenemos a que estado nos movemos con el siguiente caracter que si es 
          transicion++;                                                             // numerico y lo almacenamos para el estado actual. Con esto nos queda
        }                                                                           // que para cada posicion tenemos un simbolo y una transicion al estado siguiente
        break;
    }
  }
  num_simbolos_ = transicion; // Numero de simbolos es igual al numero de transiciones por cada estado
}

// Método para comprobar si el caracter es numero
bool Dfa::isNumber(std::string aux) { 
  for (char c : aux) {
    if(std::isdigit(c) == 0) return false;
  }
  return true;
}

// Método para imprimir informacion del dfa
void Dfa::printdfa() {
  for (size_t i = 0; i < numero_estados_; i++) {
    for (int j = 0; j < num_simbolos_; j++) {
      std::cout << "Estado: " << nombre_estado_[i] << std::endl;
      std::cout << "Aceptacion: " << aceptacion_[i] << std::endl;
      std::cout << "Transiciones: " << transiciones_[i] << std::endl;
      std::cout << "Simbolo: " << simbolo_[i][j] << " Siguiente estado: " << transicion_[i][j] << std::endl;
      std::cout << std::endl;
    }
  }
}

// Método para comprobar que todo en el dfa está correcto
int Dfa::isAllOk() {
   for (size_t i = 0; i < numero_estados_; i++) {
    for (int j = i+1; j < num_simbolos_; j++) {
      if (nombre_estado_[i] == nombre_estado_ [j] ||
      simbolo_[i][i] == simbolo_[i][j]) { // Si alguno de los simbolos es igual a otro o hay dos estado iguales, da error
        std::cout << "ERROR. HAY MAS DE UN SIMBOLO IGUAL. SOLO SE PERMITE UNA "
        "TRANSICION POR SIMBOLO" << std::endl;
        return 0;
      } 
    }
  }
  return 1;
}

// Método para comprobar si la cadena es aceptada por el lenguaje o no
bool Dfa::isAccepted(std::vector<Simbolo> chain) {
  for(size_t i = 0; i < chain.size(); i++) { // Para cada valor de la cadena vectorizada
  int contador {0};
    while(contador != num_simbolos_) { // Mientras la variable contador no sea igual al numero de simbolos
      if (chain[i].Get_Symbol() == simbolo_[estado_actual_][contador]) { // Si el simbolo de la cadena es igual a
        estado_actual_ = transicion_[estado_actual_][contador];          // alguno de los caraceteres del dfa, tomamos
        contador++;                                                      // el estado siguiente y lo establecemos como el estado actual
      } else {
        contador++;
      }
    }
  }
  if (aceptacion_[estado_actual_] == 1) { // Si el último estado es de aceptación, devolvemos true y la cadena es aceptada
    return true;                          
  } else {  
    return false;                         // En caso contrario devolvemos false y la cadena no es aceptada
  }
}