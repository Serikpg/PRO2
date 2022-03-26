#include "Prenda.hh"

Prenda::Prenda()
{
   peso = 0;
   color = false;
}

Prenda::Prenda(int pes, bool col)
{
    peso = pes;
    color = col;
}

void Prenda::modificar(int pes, bool col) 
{
    peso = pes;
    color = col;
}

int Prenda::colsul_peso()
{ return peso; }

bool Prenda::consul_color()
{ return color; }

void Prenda::escribir() 
{ cout << peso << ' ' << color; }
