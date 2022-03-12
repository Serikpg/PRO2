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

int main () 
{
	int n;
	cin >> n;
	queue<int> cua;
	int suma = 0, min = 1001, max = -1001;
	while (-1001 <= n and n <= 1000) 
	{
		if (n == -1001) 
		{
			if (cua.size() == 1)
			{
				suma -= cua.front();
				cua.pop();
				cout << 0 << endl;
			}
			else if (not cua.empty())
			{
				suma -= cua.front();
				if (cua.front() == min or cua.front() == max) {
					cua.pop();
					recalcular_minmax(cua, min, max);
				} else cua.pop();
				imprimir_resultat(min, max, mitjana(cua.size(), suma));
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else 
		{
			cua.push(n);
			if (cua.size() != 1) {
				suma += n;
				if (n > max) max = n;
				if (n < min) min = n;
			}
			else {min = n; max = n; suma = n;}
			imprimir_resultat(min, max, mitjana(cua.size(), suma));
		}
		cin >> n;
	}
}
