#include "llegirMat.hh"

void llegirMatriu(vector<list<pair<int,int>>>& mat)
{
    int mida = mat.size();
    for (int i = 0; i < mida; ++i) 
        for (int j = 0; j < mida; ++j) {
            int in;
            cin >> in;
            if (in != 0) {
                pair<int,int> par;
                par.first = j;
                par.second = in;
                mat[i].push_back(par);
            }
        }
}

void escriureMatriu(const vector<list<pair<int,int>>>& mat)
{
    int mida = mat.size();
    for (int i = 0; i < mida; ++i) { // llista act: mat[i]
        list<pair<int,int>>::const_iterator it = mat[i].begin();
        int count = 0;
        while (it != mat[i].end()) {
            while (count < it->first) {
                cout << 0 << ' ';
                ++count;
            }
            cout << it->second << ' ';
			++count;
            ++it;
        }
		while (count < mida) {
			cout << 0 << ' ';
			++count;
		}
        cout << endl;
    }
}
