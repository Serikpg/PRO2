#include <iostream>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

using namespace std;

double redondear(double r)
{  
	return int(10.*(r + 0.05)) / 10.0;
}

int main () 
{
	Cjt_estudiants v;
	v.llegir();
	int in;
	cin >> in;
	while (in != -6)
	{
		int dni;
		switch (in) {
			case -1: // afegir nou estudiant
				cin >> dni;
				if (v.existeix_estudiant(dni)) 
					cout << "el estudiante " << dni << " ya estaba" << endl << endl;
				else if (v.mida()+1 <= v.mida_maxima()) {
					Estudiant est (dni);
					double nota;
					cin >> nota;
					if (0 <= nota and nota <= est.nota_maxima()) 
						est.afegir_nota(nota);
					v.afegir_estudiant(est);
				}
				else cout << "el conjunto esta lleno" << endl << endl;
				break;
			case -2: // consultar nota d'un estudiant per DNI
				cin >> dni;
				cout << "el estudiante " << dni;
				if (v.existeix_estudiant(dni)) {
					Estudiant est = v.consultar_estudiant(dni);
					if (est.te_nota()) 
						cout << " tiene nota " << est.consultar_nota() << endl << endl;
					else 
						cout << " no tiene nota" << endl << endl;
				}
				else cout << " no esta" << endl << endl;
				break;
			case -3: // modificar la nota d'un estudiant per DNI
				cin >> dni;
				double nota;
				cin >> nota;
				if (v.existeix_estudiant(dni)) {
					Estudiant est = v.consultar_estudiant(dni);
					if (est.te_nota()) est.modificar_nota(nota);
					else est.afegir_nota(nota);
					v.modificar_estudiant(est);
				}
				else cout << "el estudiante " << dni << " no esta" << endl << endl;
				break;
			case -4: // arrodonir la nota de tots els estudiants
				for (int i = 1; i <= v.mida(); ++i) {
					Estudiant est = v.consultar_iessim(i);
					if (est.te_nota()) {
						double nota = est.consultar_nota();
						nota = redondear(nota);
						est.modificar_nota(nota);
						v.modificar_iessim(i, est);
					}
				}
				break;
			case -5: // escriure el conjunt d'estudiants
				v.escriure();
				cout << endl;
				break;
		}
		cin >> in;
	}
}
