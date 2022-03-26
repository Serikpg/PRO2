/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main ()
{
    Lavadora rent;
    Cubeta cub;
    int n;
    cin >> n;
    while (n != -8)
    {
        if (n == -1) {
            int pes;
            cin >> pes;
            if(0 < pes) rent.inicializar(pes, readbool());
            else cout << "pes menor a 0" << endl;
        }
        else if (n == -2) {
            int pes;
            cin >> pes;
            Prenda roba (pes, readbool());
            rent.anadir_prenda(roba);
        }
        else if (n == -3) {
            int pes;
            cin >> pes;
            Prenda roba (pes, readbool());
            cub.anadir_prenda(roba); 
        }
        else if (n == -4) {
            cub.completar_lavadora(rent);
        }
        else if (n == -5) {
            rent.lavado(); 
        }
        else if (n == -6) {
            cub.escribir();  
        }
        else if (n == -7) {
           rent.escribir();
        }
        cin >> n;
    }
}
