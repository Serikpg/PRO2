#include <queue>
#include "BinTreeIOParInt.hh"
using namespace std;

void treeSearch (bool& found, const BinTree<ParInt>& a, int x, int prof) 
{
	if (not a.empty()) {
		found = a.value().primer() == x;
		if(found) {
			cout << x << ' ' << a.value().segon() << ' ' << prof << endl;
		}
		else {
			treeSearch(found, a.left(), x, prof+1);
			if (not found) treeSearch(found, a.right(), x, prof+1);
		}
	}
}


int main () 
{
	BinTree<ParInt> a;
	read_bintree_parint(a);
	int x;
	while (cin >> x) {
		int prof = 0;
		bool found = false;
		treeSearch(found, a, x, prof);
		if (not found) cout << -1 << endl;
	}
}
