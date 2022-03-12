#include "CuaIOParInt.hh"
#include "ParInt.hh"

int main ()  
{
    queue<ParInt> lectura;
    llegirCuaParInt(lectura);

    queue<ParInt> new1;
    queue<ParInt> new2;
    int espera1 = 0, espera2 = 0;
              
    while (not lectura.empty())
    {
		ParInt element = lectura.front();
		lectura.pop();
		if (espera1 <= espera2) {
			espera1 += element.segon();
			new1.push(element);
		}
		else {
			espera2 += element.segon();
			new2.push(element);
		}
    }

	escriureCuaParInt(new1);
	cout << endl;
	escriureCuaParInt(new2);
}
