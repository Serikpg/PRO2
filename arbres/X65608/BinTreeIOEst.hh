#ifndef BINTREE_IO_EST
#define BINTREE_IO_EST

#include <iostream>
#include "BinTree.hh"
#include "Estudiant.hh"
using namespace std;

void read_bintree_est(BinTree<Estudiant>& a);
// Pre:  a es buit; el canal estandar d'entrada conte una sequencia
//		 de parells <int, double> que representa un arbre binari d'estudiants
//		 en preordre, on un parell amb l'int ''marca'' representa un arbre buit
// Post: a conte l'arbre que hi havia al canal estandar d'entrada

void write_bintree_est(const BinTree<Estudiant>& a );
// Pre:  a = A
// Post: s'han escrit al canal estandar de sortida els elements
//		 d'a recorreguts en inordre, a = A

#endif
