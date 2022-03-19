#ifndef LLEGIR_MAT
#define LLEGIR_MAT

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void llegirMatriu(vector<list<pair<int,int>>>& mat);
// Pre:  la matriu de tipus [vector<list<pair<int, int>>>] 
//       referenciada es buida; la matriu es quadrada
// Post: retorna una matriu amb aquest format llegint la entrada

void escriureMatriu (const vector<list<pair<int,int>>>& mat);
// Pre:  la matriu es quadrada
// Post: s'ha impres la matriu en format matriu a traves del canal
//       estandar d'entrada/sortida

#endif 
