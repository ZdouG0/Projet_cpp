#include "CArc.h"

/******************************************************
* CArc
* *****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : l'initialisation d'un CArc
* ****************************************************/
CArc::CArc() {
	sARCSommetDepart = "Le sommet de depart n'a pas encore été parametre";
	sARCSommetArrive = "Le sommet d'arrive n'a pas encore été parametre";

}


/******************************************************
* CArc
* *****************************************************
* Entrée : deux strings sParamDepart, sParamArrive
* Nécessite : Rien
* Sortie : Rien
* Entraîne : l'initialisation d'un CArc avec comme
* parametres sARCSommetDepart = sParamDepart et
* sARCSommetArrive = sParamArrive
* ****************************************************/
CArc::CArc(string sParamDepart, string sParamArrive) {
	sARCSommetDepart = sParamDepart;
	sARCSommetArrive = sParamArrive;

}



