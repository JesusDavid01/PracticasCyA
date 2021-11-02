#ifndef DFA_H
#define DFA_H

#include <iostream>
#include <string.h>
#include <vector>

#include "symbol.h"
#include "alphabet.h"

class Dfa {
 public:
  Dfa(char nodeS, char nodeA, char nodeB, char nodeC, char nodeD, char node0);
/*
  char isStringS(std::vector<Symbol> dfa, int size);
  char isStringA(std::vector<Symbol> dfa, int size);
  char isStringB(std::vector<Symbol> dfa, int size);
  char isStringC(std::vector<Symbol> dfa, int size);
  char isStringD(std::vector<Symbol> dfa, int size);
  char isString0(std::vector<Symbol> dfa, int size);
  char currentNode(char node, int size);
*/
 private:
  char nodeS_, nodeA_, nodeB_;
  char nodeC_, nodeD_, node0_;
  
};
#endif