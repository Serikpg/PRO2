#include <iostream>
using namespace std;

#include "Estudiant.hh"
#include "vectorIOEstudiant.hh"

// Pre:  donat un vector d'estudiants i un dni
// Post: retorna la posicio de l'estudiant amb "dni" 
//       al vector en cas que hi sigui o -1 en cas +
//       que no existeixi dins el vector
int busqueda_lin_vest(const vector<Estudiant>& v, int dni) 
{
    int index = -1;
    int tam = v.size();
    int i = 0;
    while (index == -1 and i<tam) {
        if (v[i].consultar_DNI() == dni) index = i; 
        else ++i;
    }
    return index;
}

int main()
{
    vector<Estudiant> v;
    leer_vector_Estudiant(v); 
    cout << "Escriu l'alumne a buscar: " << endl;
    int dni;
    cin >> dni; 
    int index = busqueda_lin_vest(v, dni);
    if (index != -1)  cout << "L'estudiant esta en la posicio: " << index << endl;
    else cout << "L'estudiant " << dni << " no esta en el vector." << endl << endl;
}
