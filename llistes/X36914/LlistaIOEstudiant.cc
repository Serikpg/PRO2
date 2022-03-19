#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l)
{
    int dni;
    double nota;
    cin >> dni >> nota;
    while (dni != 0 or nota != 0) {
        Estudiant est(dni);
        est.afegir_nota(nota);
        l.insert(l.end(), est);
        cin >> dni >> nota;
    }
}   

void EscriureLlistaEstudaint(const list<Estudiant>& l) // Opcional
{
    list<Estudiant>::const_iterator it = l.begin();
    while (it != l.end()) {
        it->escriure();
        ++it;
    }
}
