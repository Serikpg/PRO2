#include "vectorIOEstudiant.hh"

/* Leer vector */
void leer_vector_Estudiant(vector<Estudiant>& v) {// version accion
  cout<<"Escribe el tamaño del vector:"<<endl;
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  
  cout<<"Escribe los elementos del vector Estudiant<DNI nota>:"<<endl;  
  for (int i=0; i<numEst;++i) v[i].llegir();
}

/* Escribir vector */
void escribir_vector_Estudiant(const vector<Estudiant>& v) {
    for (int i=0; i<v.size();++i) {
        cout << v[i].consultar_DNI() << ' ';
        if (v[i].te_nota()) {
            cout << v[i].consultar_nota() << endl;
        }
        else {
            cout << "NP" << endl;
        }
    }
}
