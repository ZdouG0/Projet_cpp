#include "CArc.h"

/******************************************************
* CArc
* *****************************************************
* Entr�e : Rien
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : l'initialisation d'un CArc
* ****************************************************/
CArc::CArc() {
	sARCSommetDepart = "Le sommet de depart n'a pas encore �t� parametre";
	sARCSommetArrive = "Le sommet d'arrive n'a pas encore �t� parametre";

}


/******************************************************
* CArc
* *****************************************************
* Entr�e : deux strings sParamDepart, sParamArrive
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : l'initialisation d'un CArc avec comme
* parametres sARCSommetDepart = sParamDepart et
* sARCSommetArrive = sParamArrive
* ****************************************************/
CArc::CArc(string sParamDepart, string sParamArrive) {
	sARCSommetDepart = sParamDepart;
	sARCSommetArrive = sParamArrive;

}



