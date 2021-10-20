// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con cadenas y lenguajes
// Autor: Jesús David Suárez Baute
// Correo: alu0101345482@ull.edu.es
// Fecha: 18/10/2021
// Archivo cadenas.cc: Archivo para el desarrollo de la clase Chain
//        Contiene el desarrollo del constructor y de las clases de la clase
//        Chain
// Referencias:
//        https://stackoverflow.com/
// Historial de revisiones
//        18/10/2021 - Creación (segunda versión) del código

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
// Método que compara dos cadenas
string Chain::Comparacion(string cadena) {
  string resultadoequal = "", resultadonotequal = "";
  string resultadosub = "", resultadosub1 = "", temporal = "";
  int igual = 0;  // Entero para valorar las opciones de igualdad, desigualdad o
                  // subcadena
  vector<Simbolo> aux;  // Creo un vector de simbolos auxiliar
  aux[MAX];             // Le reservo un espacio de 1000

  for (size_t i = 0; i < cadena.size();
       i++) {  // Almaceno los valores de la string en un vector de simbolos
    temporal += cadena[i];
    aux.emplace_back(Simbolo(temporal));
    temporal = "";
  }
  for (size_t i = 0; i < chain_well_.size();
       i++) {  // Almaceno la cadena del archivo en una string
    temporal += chain_well_[i].Get_Symbol();
  }
  if (cadena == "&") {  // Si la cadena leida por teclado es la cadena vacía, la
                        // implementamos como ""
    cadena = "";
  }
  if (temporal == "" &&
      cadena !=
          "") {  // Si la cadena del archivo es igual a la cadena vacía y la
                 // cadena leida por teclado no devolvemos una desigualdad
    temporal += " != " + cadena;
    return temporal;
  }
  if (temporal == "" &&
      cadena == "") {  // Si la cadena del archivo es igual a la cadena vacía y
                       // la cadena leida por teclado no devolvemos la igualdad
    temporal += " == ";
    return temporal;
  }
  temporal = "";  // Inicializamos la string temporal para un uso futuro
  for (size_t i = 0; i < Menor(aux, chain_well_).size();
       i++) {  // Recorre los simbolos de la cadena mas pequeña
    for (size_t j = 0; j < Mayor(aux, chain_well_).size();
         j++) {  // Recorre los símbolos de la cadena mas grande
      if (aux[i].Get_Symbol() == chain_well_[i].Get_Symbol() &&
          aux.size() == chain_well_.size() &&
          igual !=
              1) {  // Compara si los símbolos son iguales y las cadenas
                    // tienen el mismo tamaño, además de si no son diferentes
        igual = 0;  // Pongo la opcion en 0, que equivale a igualdad
        resultadosub1 +=
            aux[i].Get_Symbol();  // En caso afirmativo, guardo en un string
                                  // resultadosub1, el mismo más el símbolo que
                                  // obtengo de la cadena
        break;  // Rompo el bucle
      } else if (Menor(aux, chain_well_)[i].Get_Symbol() ==
                 Mayor(aux, chain_well_)[j]
                     .Get_Symbol()) {  // Compara si el simbolo de la cadena
                                       // menor y de la cadena mayor son iguales
        if ((Menor(aux, chain_well_)[i - 1].Get_Symbol() ==
                 Mayor(aux, chain_well_)[j - 1].Get_Symbol() &&
             resultadosub1 == "") ||
            (i == 0 &&
             j == 0)) {  // En caso afirmativo, compara si el simbolo anterior
                         // al actual de la cadena mas pequeña es igual al
                         // simbolo anterior de la cadena mas larga y si la
                         // cadena resultadosub1 está vacía o si los iteradores
                         // del bucle son iguales a 0
          resultadosub1 +=
              Menor(aux, chain_well_)[i - 1].Get_Symbol() +
              Menor(aux, chain_well_)[i]
                  .Get_Symbol();  // En caso afirmativo, incluye dentro del
                                  // string resultadosub1, lo que ya contenga
                                  // mas el simbolo anterior al actual y el
                                  // simbolo actual
        } else if ((Menor(aux, chain_well_)[i - 1].Get_Symbol() ==
                        Mayor(aux, chain_well_)[j - 1].Get_Symbol() ||
                    (i != 0 ||
                     j !=
                         0))) {  // Compara si en caso de que no se de la
                                 // primera condicion, si el simbolo anterior al
                                 // actual de la cadena mas pequeña es igual al
                                 // simbolo anterior de la cadena mas larga o si
                                 // alguno de los iteradores es distinto de 0
          resultadosub1 +=
              Menor(aux, chain_well_)[i]
                  .Get_Symbol();  // En caso afirmativo, incluye dentro del
                                  // string resultadosub1 lo que ya tiene mas el
                                  // simbolo actual de la cadena
        } else if (resultadosub1 != "" &&
                   (i <= j)) {  // Compara si el string resultadosub1 está vacío
                                // y si el iterador i es mejor o igual que el
                                // iterador j, en caso de que no se den ninguna
                                // de las dos condiciones anteriores
          resultadosub1 = "";  // Vacío la cadena
        } else {  // En caso de que no se cumplan el resto de condiciones
          resultadosub1 = resultadosub1;  // La cadena es igual a ella misma
        }
        igual = 2;  // Pongo la opcion en 2, que equivale a subcadena
        break;      // Rompo el bucle
      } else {
        igual = 1;  // Pongo la opcion en 1, que equivale a desigualdad
      }
    }
  }
  if (igual != 0) {  // Si la opcion no es equivale a igualdad
    for (size_t i = 0; i < Menor(aux, chain_well_).size();
         i++) {  // Recorre los simbolos de la cadena mas pequeña y los almacena
                 // en el string temporal
      temporal += Menor(aux, chain_well_)[i].Get_Symbol();
    }
    if (resultadosub1 ==
        temporal) {  // Si el string resultado de la subcadena es igual a la
                     // cadena mas pequeña ponemos la opcion a 2, pues sería
                     // subcadena
      igual = 2;
    } else {  // En caso contrario no serían iguales, por lo que ponemos la
              // opción a 1 (desigualdad)
      igual = 1;
    }
  }
  if (igual == 0) {  // Si la opcion es la de igualdad
    for (size_t i = 0; i < chain_well_.size();
         i++) {  // Recorro la cadena simbolo a simbolo obtenida del archivo y
                 // la almaceno en un string
      resultadoequal += chain_well_[i].Get_Symbol();
    }
    resultadoequal += " == ";  // Almaceno el caracter de igualdad en el string
    for (size_t i = 0; i < aux.size();
         i++) {  // Por último almaceno la cadena obtenida por teclado simbolo a
                 // simbolo en el string tambien
      resultadoequal += aux[i].Get_Symbol();
    }
    return resultadoequal;  // Devuelvo el string con las cadenas y el operador
                            // de igualdad
  } else if (igual == 1) {  // En caso de que la opcion sea desigualdad
    for (size_t i = 0; i < chain_well_.size();
         i++) {  // Recorro la cadena simbolo a simbolo obtenida del archivo y
                 // la almaceno en un string
      resultadonotequal += chain_well_[i].Get_Symbol();
    }
    resultadonotequal +=
        " != ";  // Almaceno el caracter de desigualdad en el string
    for (size_t i = 0; i < aux.size();
         i++) {  // Por último almaceno la cadena obtenida por teclado simbolo a
                 // simbolo en el string tambien
      resultadonotequal += aux[i].Get_Symbol();
    }
    return resultadonotequal;  // Devuelvo el string con las cadenas y el
                               // operador de desigualdad
  } else {                     // En caso de que la opcion no sea ni 1 ni 2
    for (size_t i = 0; i < Mayor(aux, chain_well_).size();
         i++) {  // Recorro la cadena mas grande simbolo a simbolo obtenida del
                 // archivo y la almaceno en un string
      resultadosub += Mayor(aux, chain_well_)[i].Get_Symbol();
    }
    resultadosub +=
        " > " +
        resultadosub1;  // Almaceno el caracter de comparacion en el string en
                        // el que tenemos la cadena mas larga y, a continuacion
                        // del operador de comparacion insertamos la cadena más
                        // pequeña almacenada en el string resultadosub1
    return resultadosub;  // Devuelvo el string con ambas cadenas y el operador
                          // de comparacion
  }
};
// Método para obtener la cadena de mayor tamaño
vector<Simbolo> Chain::Mayor(vector<Simbolo> uno, vector<Simbolo> dos) {
  if (uno.size() >= dos.size()) {
    return uno;
  }
  return dos;
}
// Método para obtener la cadena de menor tamaño
vector<Simbolo> Chain::Menor(vector<Simbolo> uno, vector<Simbolo> dos) {
  if (uno.size() < dos.size()) {
    return uno;
  }
  return dos;
}
// Método que concatena dos cadenas
string Chain::Concatenacion(string cadena) {
  string resultado = "";
  for (size_t i = 0; i < chain_well_.size();
       i++) {  // Recorro la cadena obtenida del archivo simbolo a simbolo y la
               // almaceno en un string
    resultado += chain_well_[i].Get_Symbol();
  }
  resultado +=
      cadena;  // Al string resultante le añado la cadena obtenida por teclado
  return resultado;  // Devuelvo las cadenas concatenadas
}
// Método que eleva a la potencia una cadenas
string Chain::Potencia(int potencia) {
  string resultado = "";
  for (int i = 0; i < potencia; i++) {  // Eleva la cadena tantas veces como se
                                        // dicen en la variable potencia
    for (size_t j = 0; j < chain_well_.size();
         j++) {  // Recorro la cadena obtenida del archivo y la almaceno en un
                 // string. Esto lo hago tantas veces como se pida
      resultado += chain_well_[j].Get_Symbol();
    }
  }
  return resultado;  // Devuelvo el resultado de la potencia
}