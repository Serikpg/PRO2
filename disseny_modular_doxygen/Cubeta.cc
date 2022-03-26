#include "Cubeta.hh"

void Cubeta::anadir_prenda(const Prenda& p) 
{
    if(p.consul_color()) ropablanca.push(p);
    else ropacolor.push(p);
}

void Cubeta::completar_lavadora(Lavadora& lav) 
{
    if (lav.consul_color())
        completar_lavadora_pila_rec(ropacolor, lav);
    else completar_lavadora_pila_it(ropablanca, lav);
}

void Cubeta::escribir()
{
    cout << "   Cubeta:" << endl << "Ropa de color de la cubeta: " << endl;
    stack<Prenda> pila (ropacolor);
    while (not pila.empty()) {
        pila.top().escribir(); 
        pila.pop();
        if (not pila.empty()) cout << ' ';
    }
    cout << endl << "Ropa de color de la cubeta: " << endl;
    stack<Prenda> pilablanc (ropablanca);
    while (not pilablanc.empty()) {
        pila.top().escribir();
        pila.pop();
        if (not pila.empty()) cout << ' ';
    }
    cout << endl;
}

static void Cubeta::completar_lavadora_pila_rec(stack<Prenda>& p, Lavadora& l)
{
    if(not p.empty() and l.consul_peso() <= l.consul_peso_maximo) {
       l.anadir_ropa(p.top());
       p.pop();
       completar_lavadora_pila_rec(p, l);
    }
}

static void Cubeta::completar_lavadora_pila_it(stack<Prenda>& p, Lavadora& l)
{   
    while(not p.empty() and l.consul_peso() <= l.consul_peso_maximo) {
        l.anadir_ropa (p.top());
        p.pop();
    }
}

static void Cubeta::escribir_pila_prenda(const stack<Prenda>& p)
{

}
