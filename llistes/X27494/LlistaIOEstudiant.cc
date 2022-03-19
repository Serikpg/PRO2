#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l)
{
    int dni;
    double nota;
    cin >> dni >> nota;
    while (dni != 0 or nota != 0) {
        Estudiant est(dni);
        if(0 <= nota and nota <= est.nota_maxima()) est.afegir_nota(nota);
        l.insert(l.end(), est);
        cin >> dni >> nota;
    }
}   

void EscriureLlistaEstudiant(const list<Estudiant>& l) // Opcional
{
    list<Estudiant>::const_iterator it = l.begin();
    while (it != l.end()) {
        it->escriure();
        ++it;
    }
}
