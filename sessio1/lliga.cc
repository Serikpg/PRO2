#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int PUNTS_GUANYAT = 3;
const int PUNTS_EMPAT = 1;

struct Equip
{
    int numero, punts, marcats, rebuts;
};

typedef vector<vector<pair<int, int>>> Matriu;

void entrada_matriu(Matriu& entrada)
{
    int n;
    cin >> n;
    entrada = Matriu (n, vector<pair<int, int>> (n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) 
    {
        cin >> entrada[i][j].first >> entrada[i][j].second;
    }
}

void inicialitzar_classificacio (vector<Equip>& v)
{
    for (int i = 0; i < v.size(); ++i) 
    {
        v[i].numero = i+1;
        v[i].punts = 0;
        v[i].marcats = 0;
        v[i].rebuts = 0;
    }
}

void llegir_classificacio(const Matriu& m, vector<Equip>& v)
{
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m.size(); ++j) {
            if (i != j) {
                v[i].marcats += m[i][j].first;
                v[j].marcats += m[i][j].second;
                v[i].rebuts += m[i][j].second;
                v[j].rebuts += m[i][j].first;
                
                if (m[i][j].first > m[i][j].second) {
                    v[i].punts += PUNTS_GUANYAT;
                }
                else if (m[i][j].first < m[i][j].second) {
                    v[j].punts += PUNTS_GUANYAT;
                }
                else {
                    v[i].punts += PUNTS_EMPAT;
                    v[j].punts += PUNTS_EMPAT;
                }
            }
        }
    }
}

bool ordre (const Equip& a, const Equip& b)
{
    if (a.punts > b.punts) return true;
    if (a.punts < b.punts) return false;
    if ((a.marcats - a.rebuts) > (b.marcats - b.rebuts)) return true;
    if ((a.marcats - a.rebuts) < (b.marcats - b.rebuts)) return false;
    if (a.numero < b.numero) return true;
    return false;
}

void imprimir_classificacio (const vector<Equip>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i].numero << ' ';
        cout << v[i].punts  << ' ';
        cout << v[i].marcats << ' ';
        cout << v[i].rebuts;
        cout << endl;
    }
}   

int main ()
{
    Matriu partits;
    entrada_matriu(partits);    
    vector<Equip> classificacio (partits.size());
    inicialitzar_classificacio (classificacio);
    llegir_classificacio(partits, classificacio);
    sort(classificacio.begin(), classificacio.end(), ordre);
    imprimir_classificacio(classificacio);
}
