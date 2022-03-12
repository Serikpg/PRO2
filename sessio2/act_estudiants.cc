#include "Cjt_estudiants.hh"

void actualitzar_estudiants(Cjt_estudiants& a, const Cjt_estudiants& b)
{
	if (a.mida() == b.mida()) // nomes opera en cas que les mides siguin les mateixes
	{
		for (int i = 1; i <= a.mida(); ++i) {
			Estudiant est_a = a.consultar_iessim(i);
			Estudiant est_b = b.consultar_iessim(i);
			if (not est_a.te_nota() or (est_a.te_nota() and est_b.te_nota() and
				est_a.consultar_nota() < est_b.consultar_nota()))
				a.modificar_iessim(i, est_b);
		}
	}
}

int main () 
{
	// 1. Declaracions
	Cjt_estudiants eval1;
	Cjt_estudiants eval2;
	// 2. Llegir el 1r conjunt d'estudiants mitjancant Cjt_estudiants::llegir()
	eval1.llegir();
	// 3. Llegir el 2n conjunt d'estudiants mitjancant Cjt_estudiants::llegir()
	eval2.llegir();
	// 4. Actualitzar el 1r conjunt mijtancant la nova operacio
	actualitzar_estudiants(eval1, eval2);
	// 5. Escriure el 1r conjunt actualitzat mitjancant Cjt_estudiants::escriure()
	eval1.escriure();
}
