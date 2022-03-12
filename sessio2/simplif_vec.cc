#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;

/* Leer vector */
void leer_vector_Estudiant(vector<Estudiant>& v) {// version accion
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  
  for (int i=0; i<numEst;++i) v[i].llegir();
}

/* Escribir vector */
void escribir_vector_Estudiant(const vector<Estudiant>& v) {
    for (int i=0; i<v.size();++i) {
        cout << v[i].consultar_DNI() << ' ';
        if (v[i].te_nota()) {
            cout << v[i].consultar_nota() << endl;
        }
        else {
            cout << "NP" << endl;
        }
    }
}

vector<Estudiant> simp_vec_Estudiant (const vector<Estudiant>& v)
/* Pre:  Donat un vector d'estudiants */
/* Post: Retornar el vector donat simplificat */
{
	vector<Estudiant> u;
	int i = 0; // Punter sobre v
	while (i < v.size()) {
		int dni = v[i].consultar_DNI();
		Estudiant act(dni);
		double max = -1;
		if (v[i].te_nota()) max = v[i].consultar_nota();
		while (i < v.size() and v[i].consultar_DNI() == dni) {
			if (v[i].te_nota() and v[i].consultar_nota() > max) 
				max = v[i].consultar_nota();
			++i;
		}
		if (0 <= max and max <= act.nota_maxima()) 
			act.afegir_nota(max);
		u.push_back(act);
	}
	return u;
}

int main ()
{
    vector<Estudiant> v;
    leer_vector_Estudiant(v);
    vector<Estudiant> u = simp_vec_Estudiant(v);
    escribir_vector_Estudiant(u);
}
