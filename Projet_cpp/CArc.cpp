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
	uiARCPoids = 0;
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
	uiARCPoids = 0;
}



/******************************************************
* CArc
* *****************************************************
* Entrée : deux strings sParamDepart, sParamArrive et un entier non signé
* Nécessite : Rien
* Sortie : Rien
* Entraîne : l'initialisation d'un CArc avec comme
* parametres sARCSommetDepart = sParamDepart et
* sARCSommetArrive = sParamArrive et uiARCPoids = uiParam
* ****************************************************/
CArc::CArc(string sParamDepart, string sParamArrive, unsigned int uiParam) {
	sARCSommetDepart = sParamDepart;
	sARCSommetArrive = sParamArrive;
	uiARCPoids = uiParam;
}