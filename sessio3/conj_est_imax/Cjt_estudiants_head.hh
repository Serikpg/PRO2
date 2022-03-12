#ifndef CONJ_EST_HPP
#define CONJ_EST_HPP

#include "Estudiant.hh"
#include <vector>

class Cjt_estudiants {

private:

  // Tipus de mòdul: dades
  // Descripció del tipus:  Representa un conjunt ordenat per DNI d'estudiants.
  // Es poden consultar i modificar els seus elements (de tipus Estudiant) 
  // donat un DNI o per posició en l'ordre.

  vector<Estudiant> vest; 
  int nest; // mida del vector vest
  int imax; /* index que apunta a l'estudiant de nota maxima
			   valdra -1 en cas que cap estudiant tingui nota */
  static const int MAX_NEST = 5;
  /* 
     Invariant de la representació: 
     - vest[0..nest-1] està ordenat creixentment pels DNI dels estudiants i
       no conté estudiants repetits
     - 0 <= nest <= vest.size() = MAX_NEST
  */

  void ordenar_cjt_estudiants ();
  /* Pre: cert */
  /* Post: els elements rellevants del paràmetre implícit estan ordenats 
     creixentment pels seus DNI */

  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: vest[left..right] està ordenat creixentment per DNI,  
     0<=left, right<vest.size() */
  /* Post: si a vest[left..right] hi ha un element amb DNI = x, el resultat és 
     una posició que el conté; si no, el resultat és -1 */

  bool es_maxim (const Estudiant& est);
  
  void recalcular_posicio_imax();
  /* Pre: cert */
  /* Post: el camp imax conté la posició de l'element del paràmetre
     implícit amb la nota més gran */

public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: el resultat és un conjunt d'estudiants buit */

  //Destructora

  ~Cjt_estudiants();
   
  //Modificadores

  void afegir_estudiant(const Estudiant &est);
  /* Pre: el paràmetre implícit no conté cap estudiant amb el dni d'est; el
     nombre d'estudiants del p.i. es menor que la mida maxima permesa */
  /* Post: s'ha afegit l'estudiant est al paràmetre implícit */

  void modificar_estudiant(const Estudiant &est);
  /* Pre: existeix un estudiant al paràmetre implícit amb el DNI d'est  */
  /* Post: l'estudiant del paràmetre implícit original amb el dni
     d'est, ha quedat substituït per est */
		
  void modificar_iessim(int i, const Estudiant &est);
  /* Pre: 1 <= i <= nombre d'estudiants del paràmetre implícit,
     l'element i-èssim del conjunt en ordre creixent per DNI conté 
     un estudiant amb el mateix DNI que est */
  /* Post: l'estudiant est ha substituït l'estudiant i-èssim
     del paràmetre implícit */

  void esborrar_estudiant(int dni);
  /* Pre: existeix un estudiant al parametre impl¿cit amb DNI = dni */
  /* Post: el parametre impl¿cit conte els mateixos estudiants que 
     l¿original menys l¿estudiant amb DNI = dni */

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: el resultat és el nombre d'estudiants del paràmetre implícit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat és el nombre maxim d'estudiants que pot arribar
     a tenir el paràmetre implícit */

  bool existeix_estudiant(int dni) const;
  /* Pre: dni >= 0 */
  /* Post: el resultat indica si existeix un estudiant al paràmetre implícit
     amb DNI = dni */

  Estudiant consultar_estudiant(int dni) const;
  /* Pre: existeix un estudiant al paràmetre implícit amb DNI = dni */
  /* Post: el resultat és l'estudiant amb DNI = dni que conté el 
     paràmetre implícit */

  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que conté el paràmetre implícit */
  /* Post: el resultat és l'estudiant i-èssim del paràmetre implícit 
     en ordre creixent per DNI */
		
  Estudiant estudiant_nota_max( ) const;
  /* Pre: el parametre impl¿cit conte almenys un estudiant amb nota */
  /* Post: el resultat es l¿estudiant del parametre impl¿cit amb 
     nota maxima; si en te mes d¿un, es el de DNI mes petit */

  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal estàndar d'entrada un enter (entre 0 i la
     mida màxima permesa per a la classe), que representa el nombre d'elements 
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el paràmetre implícit conté el conjunt d'estudiants llegits
     del canal estàndard d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal estàndard de sortida els estudiants del
     paràmetre implícit en ordre ascendent per DNI */
};
#endif
