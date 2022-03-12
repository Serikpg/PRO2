#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"

using namespace std;

bool hi_es (const vector<int>& v, int n) 
{
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == n) return true;
	}
	return false;
}

bool order (const Estudiant& a, const Estudiant& b) 
{
	if (a.consultar_nota() > b.consultar_nota()) return true;
	if (a.consultar_nota() < b.consultar_nota()) return false;
	if (a.consultar_DNI() <= b.consultar_DNI()) return true;
	return false;
}

int main ()
{
	int M, N, S;
	// M - nre estudiants | N - nre assig | S - assig selec
	cin >> M >> N >> S;
	vector<int> sel (S);
	for (int i = 0; i < S; ++i)	cin >> sel[i];
	vector<Estudiant> v;
	for (int i = 0; i < M; ++i) {
		int dni;
		cin >> dni;
		Estudiant est (dni);
		double sum = 0;
		for (int j = 0; j < N; ++j) {
			double nota;
			cin >> nota;
			if (hi_es(sel, j+1)) {
				sum += nota;
			}
		}
		sum /= double(S);
		if (0 <= sum and sum <= est.nota_maxima()) {
			est.afegir_nota(sum);
		}
		v.push_back(est);
	}
	sort(v.begin(), v.end(), order);
	for (int i = 0; i < v.size(); ++i) v[i].escriure();
} 
