
#ifndef __CARCPONDERE__
#define __CARCPONDERE__
#include "CArc.h"


/************************************************************
* CLASSE : Classe pour la gestion des arcs avec pondération
* ************************************************************
* ROLE : Interface de la classe CArcPondere,
* cette classe permet de gerer les liaisons entre les Sommets
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI / Milan HERGOTT
* DATE : 22/03/2024
* ************************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES :
*  pas de types particulier de déclaré
*/

/* VARIABLES :
*
*/


class CArcPondere : public CArc
{
private:
	unsigned int uiPoidsArc;
public:
	//CONSTRUCTEUR/DESTRUCTEUR
	/******************************************************
	* CArcPondere
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : l'initialisation d'un CArc
	* ****************************************************/
	CArcPondere();



	/******************************************************
	* CArcPondere
	* *****************************************************
	* Entrée : deux strings et un poids
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : l'initialisation d'un CArc avec comme depart et comme arrivé nos deux arcs et notre poids
	* ****************************************************/
	CArcPondere(string sParamDepart, string sParamArrive, unsigned int uiPoids = 0);



	//Methodes

	/******************************************************
	* ARCLirePoids
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : l'initialisation d'un CArc
	* ****************************************************/
	inline unsigned int ARCLirePoids() { return uiPoidsArc; }



	/******************************************************
	* ARCModifierPoids
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : l'initialisation d'un CArc
	* ****************************************************/
	inline void ARCModifierPoids(unsigned int uiParam) { uiPoidsArc = uiParam; }






};

#endif
