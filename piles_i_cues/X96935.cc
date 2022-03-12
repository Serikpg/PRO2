#include <iostream>
#include <stack>
using namespace std;

int main ()
{
    stack <int> pila;
    int n;
    cin >> n;
    for (int i = 0; i < n/2; ++i) {
        int entrada;
        cin >> entrada;
        pila.push(entrada);
    }
    if (n % 2 != 0) {int entrada; cin >> entrada;}
    bool palindrom = true;
    for (int i = 0; palindrom and i < n/2; ++i) {
        int entrada;
        cin >> entrada;
        if (pila.top() != entrada) palindrom = false;
        pila.pop();
    }
    cout << (palindrom ? "SI" : "NO") << endl;
}
