#include "llegirMat.hh"

vector<list<pair<int,int>>> sumaMat (vector<list<pair<int,int>>>& mat1,
									 vector<list<pair<int,int>>>& mat2) 
// Pre:  Les dues matrius son quadrades del mateix ordre
// Post: es retorna la matriu suma resultant
{
	int mida = mat1.size();
	vector<list<pair<int,int>>> sum (mida);
	for (int i = 0; i < mida; ++i) {
		list<pair<int,int>>::iterator it1 = mat1[i].begin();
		list<pair<int,int>>::iterator it2 = mat2[i].begin();
		while (it1 != mat1[i].end() and it2 != mat2[i].end()) {
			while (it1->first < it2->first) {
				sum[i].push_back(*it1);
				it1++;
			}
			while (it1->first > it2->first) {
				sum[i].push_back(*it2);
				it2++;
			}
			pair<int,int> par;
			par.first = it1->first;
			par.second = it1->second + it2->second;
			sum[i].push_back(par);
			it1++;
			it2++;
		}
		while (it1 != mat1[i].end()) {
			sum[i].push_back(*it1); 
			it1++;
		}
		while (it2 != mat2[i].end()) {
			sum[i].push_back(*it2);
			it2++;
		}
	}
	return sum;
}

 vector<list<pair<int,int>>> prodMat (vector<list<pair<int,int>>>& mat1,
									  vector<list<pair<int,int>>>& mat2)
// Pre:  dues matrius de llistes de parells d'enters de la mateixa mida n  
// Post: retorna el producte matricial resultant
{
	int mida = mat1.size();
	vector<list<pair<int,int>>> prod (mida);
	for (int i = 0; i < mida; ++i) {
		list<pair<int,int>>::const_iterator it = mat1[i].begin();
		int count = 0; 
		while (it != mat1[i].end()) {
			pair<int,int> par;
			par.first = count; 
			par.second = 0;
			for (int k = 0; k < mida; ++k) {
				list<pair<int,int>>::iterator it2 = mat2[k].begin();
				while (it2 != mat2[k].end() and it2->first != count) ++it2;
				if (it2 != mat2[k].end()) par.second += it2->second * it->second;
			}
			prod[i].push_back(par);
			++it;
			++count;
		}
	}
	return prod;
}

int main ()
{
	int n;
	cin >> n;
    vector<list<pair<int,int>>> mat1 (n);
    vector<list<pair<int,int>>> mat2 (n);
    llegirMatriu(mat1);
	llegirMatriu(mat2);
	vector<list<pair<int,int>>> sum = sumaMat(mat1, mat2);
	cout << endl; 
    escriureMatriu(sum);
	cout << endl; 
	vector<list<pair<int,int>>> prod = prodMat(mat1, mat2);
	escriureMatriu(prod);
}
