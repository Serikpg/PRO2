#include <iostream>
#include <vector>

using namespace std;

bool hi_es (const vector<double>& v, double n) 
{
	for (int i = 0; i < v.size(); ++i) 
		if (v[i] == n) return true;
	return false;
}

int main () 
{
	int  M, N, S; 
	// M - nre d'estudiants | N - nre assignatures | S - assignatures seleccionades
	cin >> M >> N >> S;
	vector<double> sel (S);
	for (int i = 0; i < S; ++i) cin >> sel[i];

	for (int i = 0; i < M; ++i) {
		int dni;
		cin >> dni;
		cout << dni << ' ';
		double sum = 0;
		for (int j = 0; j < N; ++j) {
			double nota;
			cin >> nota;
			if (hi_es(sel, j+1)) sum += nota;
		}
		cout << sum/S << endl;
	}
}
