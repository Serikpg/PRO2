#include <list>
#include <iostream>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"
using namespace std;

int main () 
{
    list<ParInt> l;
    LlegirLlistaParInt(l);
    int n = 0;
    cin >> n;
    list<ParInt>::const_iterator it = l.begin();
    while (it != l.end()) {
        ParInt par(it->primer(), it->segon()+n);
        it = l.erase(it);
        l.insert(it,par);
    }
    EscriureLlistaParInt(l);
}
