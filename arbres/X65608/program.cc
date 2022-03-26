#include "BinTreeIOEst.hh"

void cerca_bintree_est(bool& prim, const BinTree<Estudiant>& a, int dni, int prof, int& p, double& nota)
{
	if(not a.empty()) {
		if(a.value().consultar_DNI() == dni and (prim or prof <= p)) {
			p = prof;
			if(a.value().te_nota()) nota = a.value().consultar_nota();
			prim = false; 
		}
		else {
			cerca_bintree_est(prim, a.right(), dni, prof+1, p, nota);
			cerca_bintree_est(prim, a.left(), dni, prof+1, p, nota);
		}
	}
}

int main()
// Pre:  Donat un arbre d'estudiants en preodre on cada estudiant es representa per
//		 un dni i una nota <int, double> i 0 0 representa un node buit; una sequencia de dnis
// Post: La sortida per a un estudiant x pot ser:
//		- x y z  --> Si l'estudiant hi es, la seva profunditat es y i la seva nota es z
//		- x y -1 --> Si l'estudiant hi es, la seva profunditat es y i no te nota
//		- x -1   --> Si l'estudiant no hi es
{
	BinTree<Estudiant> a;
	read_bintree_est(a);

	int dni;
	while (cin >> dni) {
		int prof = 0;
		double nota = -1;
		bool prim = true;
		cerca_bintree_est(prim, a, dni, 0, prof, nota);
		if(not prim) cout << dni << ' ' << prof << ' ' << nota << endl;
		else cout << dni << " -1\n";
	}	
}
