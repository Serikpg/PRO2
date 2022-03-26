#include "Lavadora.hh"

Lavadora::Lavadora()
{
    ini = false;
}

void Lavadora::inicializar(int pmax, bool col) 
{
    if(0 < pmax) {
        pesmax = pmax;
        this.col = col;
        pes = 0;
        ini = true;
    }
}

void Lavadora::anadir_prenda(const Prenda& p)
{
    int pesRoba = p.consultar_peso();
    pes += pesRoba;
    prendas.push_back(p);
}

void Lavadora::lavado()
{
    ini = false;
    prendas.clear();
}

bool Lavadora::esta_inicializada()
{ return ini; }

bool Lavadora::consultar_color()
{ return col; }

int Lavadora::consultar_peso()
{ return pes; }

int Lavadora::consultar_peso_maximo()
{ return pesmax; }

void Lavadora::escribir()
{
    cout << "   Lavadora:" << endl;
    list<Prenda>::const_iterato{r it(prendas.begin());
    cout << "Lavadora de color, con peso actual " << pes
         << " y peso maximo " << pesmax << "; sus prendas son" << endl;
    while(it != prendas.end()) {
        (*it).escribir();
        if(it != prendas.end()-1) cout << ' ';
        ++it;
    }
    cout << endl;
}
