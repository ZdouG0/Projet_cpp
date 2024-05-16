#include "CArcPondere.h"

/******************************************************
* CArcPondere
* *****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : l'initialisation d'un CArc
* ****************************************************/
CArcPondere::CArcPondere() : CArc() {
    uiPoidsArc = 0; // Initialisation du poids par défaut
}

/******************************************************
* CArcPondere
* *****************************************************
* Entrée : deux strings et un poids
* Nécessite : Rien
* Sortie : Rien
* Entraîne : l'initialisation d'un CArc avec comme depart et comme arrivé nos deux arcs et notre poids
* ****************************************************/
CArcPondere::CArcPondere(string sParamDepart, string sParamArrive, unsigned int uiPoids) : CArc(sParamDepart, sParamArrive) {
    uiPoidsArc = uiPoids; // Initialisation du poids avec la valeur passée en paramètre
}
