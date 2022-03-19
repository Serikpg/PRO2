#ifndef LLISTA_IO_ESTUDIANT
#define LLISTA_IO_ESTUDIANT

#include "Estudiant.hh"
#include <list>
#include <iostream>

using namespace std;

void LlegirLlistaEstudiant(list<Estudiant>& l);
// Pre:  l es buida; el canal estandar d'entrada conte parelles
//       de valors <enter, double>, acabat per un parell 0 0
// Post: s'han afegit al final de l els estudaints llegits fins al 0 0 
//       (no inclos)
void EscriureLlistaEstudiant(const list<Estudiant>& l); // Opcional
// Pre:  Cert
// Post: s'han escrit al canal estandar de sortida els elements de l 

#endif
