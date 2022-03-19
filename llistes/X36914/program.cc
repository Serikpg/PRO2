#include <list>
#include <iostream>
#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"

using namespace std;

int main () 
{
    list<Estudiant> l;
    LlegirLlistaEstudiant(l);
    list<Estudiant>::const_iterator it = l.begin();
    int dni, apar = 0; 
    cin >> dni;
    while (it != l.end()) {
        if (it->consultar_DNI() == dni) ++apar;
        ++it;
    }
    cout << dni << ' ' << apar << endl;
}
