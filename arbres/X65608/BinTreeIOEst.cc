#include "BinTreeIOEst.hh"

void read_bintree_est(BinTree<Estudiant>& a)
{
	int dni; double nota;
	cin >> dni >> nota;
	if(dni != 0 or nota != 0) {
		Estudiant est(dni);
		if (0 <= nota and nota <= est.nota_maxima()) est.afegir_nota(nota);
		BinTree<Estudiant> esq, dre;
		read_bintree_est(esq);
		read_bintree_est(dre);
		a = BinTree<Estudiant> (est, esq, dre);
	}
}

void write_bintree_est(const BinTree<Estudiant>& a )
{
	// Implementem algorisme d'inordre
	if(not a.empty()) {
		write_bintree_est(a.left());
		a.value().escriure();
		write_bintree_est(a.right());
	}
}
