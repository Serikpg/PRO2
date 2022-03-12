#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c)
{
    ParInt entrada;
    entrada.llegir();
    while (entrada.primer() != 0 or entrada.segon() != 0) 
    {
        c.push(entrada);
        entrada.llegir();
    }
}

void escriureCuaParInt(queue<ParInt> c)
{
   /* el pas per copia es adequat perque la cua es 
    * destruira en la lectura */
   while (not c.empty()) 
   {
        c.front().escriure();
        c.pop();
   }
}
