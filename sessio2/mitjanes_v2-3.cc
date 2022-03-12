#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"

using namespace std;

void seleccio (vector<bool>& v, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int assig;
		cin >> assig;
		v[assig - 1] = true;
	}
}

void mitjanes (vector<Estudiant>& est, const vector<bool>& selec, int sel)
{
	int mida = est.size();
	int assig = selec.size();
	for (int i = 0; i < mida; ++i)
	{
		int dni;
		cin >> dni;
		Estudiant estu(dni);
		est[i] = estu;
		double mitj = 0;
		for (int j = 0; j < assig; ++j)
		{
			double nota;
			cin >> nota;
			if (selec[j]) mitj += nota;
		}
		mitj /= sel;
		est[i].afegir_nota(mitj);
	}
}

bool comp(const Estudiant& v, const Estudiant& u) 
{
	if (v.consultar_nota() == u.consultar_nota())
		return v.consultar_DNI() < u.consultar_DNI();
	return v.consultar_nota() > u.consultar_nota();
}

int main () {
	int nestudiants, nassignatures, seleccionades;
	cin >> nestudiants >> nassignatures >> seleccionades;
	vector<bool> assig_selec(nassignatures, false);
	seleccio(assig_selec, seleccionades);
	vector<Estudiant> estudiants(nestudiants);
	mitjanes(estudiants, assig_selec, seleccionades);
	sort (estudiants.begin(), estudiants.end(), comp);
	for (int i = 0; i < nestudiants; i++) estudiants[i].escriure();
}
