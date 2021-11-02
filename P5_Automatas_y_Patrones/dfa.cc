#include "dfa.h"

Dfa::Dfa(char nodeS, char nodeA, char nodeB, char nodeC, char nodeD, char node0) {
  nodeS_ = nodeS;
  nodeA_ = nodeA;
  nodeB_ = nodeB;
  nodeC_ = nodeC;
  nodeD_ = nodeD;
  node0_ = node0;
}
/*
char Dfa::isStringS(std::vector<Symbol> dfa, int size) {
  
}

char Dfa::currentNode(char node, int size) {
  switch (node) {
    case 'S':
      isStringS();
      break;
    
    case 'A':
      if() {

      }
      break;

    case 'B':
      if() {

      }
      break;
    
    case 'C':
      if() {

      }
      break;

    case 'D': 
      if() {

      }
      break;
    
    case '0':
      if() {

      }
      break;
  }
  return node;
}
*/