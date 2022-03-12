#include <iostream>
#include <stack>
using namespace std;

int main () 
{
    bool corr = true;
    stack<char> pila;

    char entrada;
    cin >> entrada;
    while (corr and entrada != '.') 
    {
        if (entrada == '(' or entrada == '[') pila.push(entrada);
        else {
            if (entrada == ')') entrada = '(';
            else entrada = '[';
            if (not pila.empty() and entrada == pila.top()) pila.pop();
            else corr = false;
        }
        cin >> entrada;
    }
    corr = corr and pila.empty();
    cout << ((corr) ? "Correcte" : "Incorrecte") << endl; 
}
