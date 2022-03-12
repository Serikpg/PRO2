#include <vector>
using namespace std;

#include "Estudiant.hh"
// #include "vectorIOEstudiant.hh"

pair<int,int> max_min_vest(const vector<Estudiant>& v)
/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component 
 * del resultat es la posicio de l'estudiant de nota maxima de v i la 
 * segona component es la posicio de l'estudiant de nota minima de v 
 * (si hi ha empats, s'obte en cada cas la posicio de l'estudiant amb 
 * minim DNI); si no hi ha cap estudiant amb nota, totes dues components 
 * valen -1 */
{
    pair<int, int> res;
    bool hi_ha = false;
    int i = 0;
    // res quedara amb l'index del primer estudiant amb nota
    while (not hi_ha and i < v.size()) {
        if (v[i].te_nota()) {
            res.first = i;   // index element maxim
            res.second = i;  // index element minim
            hi_ha = true;
        }
        ++i;
    }
    // si no es troba cap estudiant amb nota retorna -1 -1
    if (not hi_ha) {
        res.first = -1;
        res.second = -1;
        return res;
    }
    while (i < v.size())
    {
        if (v[i].te_nota()) {
            if (v[i].consultar_nota() > v[res.first].consultar_nota()) res.first = i;
            else if (v[i].consultar_nota() == v[res.first].consultar_nota() and v[i].consultar_DNI() < v[res.first].consultar_DNI())
                res.first = i;
            if (v[i].consultar_nota() < v[res.second].consultar_nota()) res.second = i;
            else if (v[i].consultar_nota() == v[res.second].consultar_nota() and v[i].consultar_DNI() < v[res.first].consultar_DNI())
                res.second = i;
        }
        ++i;
    }
    return res;
}

// int main () 
// {
//     vector<Estudiant> v;
//     leer_vector_Estudiant(v);
//     pair<int, int> max_min = max_min_vest(v);
//     cout << "L'index del maxim es: " << max_min.first << endl;
//     cout << "L'index del minim es: " << max_min.second << endl;
// }
