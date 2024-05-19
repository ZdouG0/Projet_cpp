#include "CArcPondere.h"

/******************************************************
* CArcPondere
* *****************************************************
* Entr�e : Rien
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : l'initialisation d'un CArc
* ****************************************************/
CArcPondere::CArcPondere() : CArc() {
    uiPoidsArc = 0; // Initialisation du poids par d�faut
}

/******************************************************
* CArcPondere
* *****************************************************
* Entr�e : deux strings et un poids
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : l'initialisation d'un CArc avec comme depart et comme arriv� nos deux arcs et notre poids
* ****************************************************/
CArcPondere::CArcPondere(string sParamDepart, string sParamArrive, unsigned int uiPoids) : CArc(sParamDepart, sParamArrive) {
    uiPoidsArc = uiPoids; // Initialisation du poids avec la valeur pass�e en param�tre
}
