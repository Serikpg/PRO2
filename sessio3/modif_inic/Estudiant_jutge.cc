#include "Estudiant.hh"

/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0;
  nota = -1; // nota outofbounds com a senyal de no tenir nota
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4);
  this->dni = dni;
  nota = -1; // nota outofbounds com a senyal de no tenir nota
}

void Estudiant::operator=(const Estudiant& est)
/* Pre: cert */
/* Post: el p.i. passa a ser una copia de est */
{
   nota = est.nota;
   dni = est.dni;
}

Estudiant::Estudiant(const Estudiant& e)
{
   nota = e.nota;
   dni = e.dni;
}

void Estudiant::afegir_nota(double nota)
{
  if (te_nota()) 
    throw PRO2Excepcio(ER3);
  if (nota < 0 or nota > MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  this->nota = nota; 
}

void Estudiant::modificar_nota(double nota)
{ 				
  if (not te_nota()) 
    throw PRO2Excepcio(ER1);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2);
  this->nota = nota;
}

// apt. La funcio te_nota() es pot utilitzar dins les altres funcions de
//		la classe, dins el mateix arxiu on s'ha declarat ¡!
bool Estudiant::te_nota() const
{
  return (nota != -1);
}

double Estudiant::consultar_nota() const
{
  if (not te_nota()) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

bool Estudiant::comp(const Estudiant& e1, const Estudiant& e2)
{
  return (e1.dni < e2.dni);  
}

void Estudiant::llegir()
{
  cin >> dni;
  if (dni<0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
  }
  else nota = -1;
}

void Estudiant::escriure() const
{
  if (te_nota())
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}
