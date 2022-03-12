#include <iostream>
#include <queue>
using namespace std;

void imprimir_resultat(int min, int max, double mijt) 
{cout << "min " << min << "; max " << max << "; media " << mijt << endl;}

void recalcular_minmax (queue<int> cua, int& min, int& max) 
{
	min = 1001;
	max = -1002;
	while (not cua.empty()) 
	{
		if (min > cua.front()) min = cua.front();
		if (max < cua.front()) max = cua.front();
		cua.pop();
	}
}

double mitjana(int mida, int suma)
{return double(suma)/double(mida);}

int main() 
{
	int n;
	cin >> n;
	int suma = 0, min = 1001, max = -1002;
	queue<int> cua;
	while (-1001 <= n and n <= 1000) 
	{
		if (n == -1001) {
			if (not cua.empty()) {
				// if (cua.front() == min or cua.front() == max) 
				suma -= cua.front();
				cua.pop();
				recalcular_minmax(cua, min, max);
				if (not cua.empty())
					imprimir_resultat(min, max, mitjana(cua.size(), suma));
				else cout << 0 << endl;
			}
			else cout << 0 << endl;
		}
		else {
			cua.push(n);
			if (cua.size() == 1) {min = n; max = n;}
			suma += n;
			if (n > max) max = n;
			if (n < min) min = n;
			imprimir_resultat(min, max, mitjana(cua.size(), suma));
		}
		cin >> n;
	}
}
