#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l)
{
    ParInt par;
    while (par.llegir())
        l.insert(l.end(), par);
}   

void EscriureLlistaParInt(const list<ParInt>& l) // Opcional
{
    list<ParInt>::const_iterator it = l.begin();
    while (it != l.end()) {
        (*it).escriure();
        ++it;
    }
}
