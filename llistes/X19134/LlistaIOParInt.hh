#ifndef LLISTA_IO_PARINT
#define LLISTA_IO_PARINT

#include "ParInt.hh"
#include <list>
#include <iostream>

using namespace std;

void LlegirLlistaParInt(list<ParInt>& l);
// Pre:  l es buida; el canal estandar d'entrada conte un nombre
//       parell d'enters, acabat pel parell 0 0
// Post: s'han afegit al final de l els parells llegits fins al 0 0 

void EscriureLlistaParInt(const list<ParInt>& l); // Opcional
// Pre:  Cert
// Post: s'han escrit al canal estandar de sortida els elements de l

#endif
