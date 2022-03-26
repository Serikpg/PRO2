#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a)
{
	ParInt par;
	if (par.llegir()) {
		BinTree<ParInt> esq;
		BinTree<ParInt> dre;
		read_bintree_parint(esq);
		read_bintree_parint(dre);
		a = BinTree<ParInt> (par, esq, dre);
	}
}

void write_bintree_parint(const BinTree<ParInt>& a) // (opcional)
{
	if(not a.empty()) {
		write_bintree_parint(a.left());
		cout << a.value().primer() << ' ' << a.value().segon() << endl;
		write_bintree_parint(a.right());
	}
}
