#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main () 
{
    int n;
    cin >> n;
    vector<stack<string>> vec (n);

    while (n != -4)
    {
        int cat;
        string nom;
        switch (n) {
            case -1:
                cin >> nom;
                cin >> cat;
                vec[cat-1].push(nom);
                break;
            case -2:
                int retirats;
                cin >> retirats;
                cin >> cat;
                for (int i = 0; i < retirats; ++i) vec[cat-1].pop();
                break;
            case -3:
                cin >> cat;
                stack<string> cpy (vec[cat-1]); // crea una copia de la pila seleccionada
                cout << "Pila de la categoria " << cat << endl;
                while (not cpy.empty()) {
                    cout << cpy.top() << endl;
                    cpy.pop();
                }
                cout << endl;
                break;
        }
        cin >> n;
    }
}
