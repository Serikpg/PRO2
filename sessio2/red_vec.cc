#include "Estudiant.hh"
#include "vectorIOEstudiant.hh"

using namespace std;

void redondear_e_a(Estudiant& est)
/* Pre: est tiene nota */
/* Post: est pasa a tener su nota original redondeada */
{
    est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

void redondear_vector(vector<Estudiant>& v)
/* Pre: v un vector no buit */
/* Post: totes les notes dels estudiants de v queden arrodonides */
{
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].te_nota()) {
            redondear_e_a(v[i]);
        }
    }
}

int main () 
{
    vector<Estudiant> v;
    leer_vector_Estudiant(v);
    redondear_vector(v);
    escribir_vector_Estudiant(v);
}
