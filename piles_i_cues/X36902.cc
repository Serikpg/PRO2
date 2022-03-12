#include <iostream>
#include <stack>
using namespace std;

int main ()
{
    stack<char> pila;
    bool correcte = true;
    char entrada;
    cin >> entrada;
    while (correcte and entrada != '.')
    {
        if (entrada == '(' or entrada == '[') pila.push(entrada);
        else if (entrada == ')') {
            if (pila.empty()) correcte = false;
            else if (pila.top() == '(') pila.pop();
            else correcte = false;
        }
        else if (entrada == ']') {
            if (pila.empty()) correcte = false;
            else if (pila.top() == '[') pila.pop();
            else correcte = false;
        }
        cin >> entrada;
    }
    cout << (correcte ? "Correcte" : "Incorrecte") << endl; 
}
