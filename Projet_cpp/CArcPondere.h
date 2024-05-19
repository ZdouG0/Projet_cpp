
#ifndef __CARCPONDERE__
#define __CARCPONDERE__
#include "CArc.h"


/************************************************************
* CLASSE : Classe pour la gestion des arcs avec pond�ration
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
*  pas de types particulier de d�clar�
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
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : l'initialisation d'un CArc
	* ****************************************************/
	CArcPondere();



	/******************************************************
	* CArcPondere
	* *****************************************************
	* Entr�e : deux strings et un poids
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : l'initialisation d'un CArc avec comme depart et comme arriv� nos deux arcs et notre poids
	* ****************************************************/
	CArcPondere(string sParamDepart, string sParamArrive, unsigned int uiPoids = 0);



	//Methodes

	/******************************************************
	* ARCLirePoids
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : l'initialisation d'un CArc
	* ****************************************************/
	inline unsigned int ARCLirePoids() { return uiPoidsArc; }



	/******************************************************
	* ARCModifierPoids
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : l'initialisation d'un CArc
	* ****************************************************/
	inline void ARCModifierPoids(unsigned int uiParam) { uiPoidsArc = uiParam; }






};

#endif
