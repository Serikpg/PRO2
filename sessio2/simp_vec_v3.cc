// Aquest programa es una 3a versio

#include <vector>
#include "Estudiant.hh"

using namespace std;

void simplificar_vector(vector<Estudiant>& v, int& pos)
/* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
/* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */
{
	int i = 0;	// i sera el punter sobre lectura
	pos = 0;	// pos sera el punter sobre escriptura
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
		v[pos] = act;
		++pos;
	}
	--pos;
}
