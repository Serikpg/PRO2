#include <list>
#include <iostream>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"
using namespace std;

int main () 
{
    list<ParInt> l;
    LlegirLlistaParInt(l);

    int n;
    cin >> n;
    list<ParInt>::const_iterator it = l.begin();
    int apar = 0;
    int suma = 0;
    while (it != l.end()) {
        if (it->primer() == n) {
            suma += it->segon();
            ++apar;
        }
        ++it;
    }

    cout << n << ' ' << apar << ' ' << suma << endl;
}
