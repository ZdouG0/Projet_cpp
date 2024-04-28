#ifndef __CARC__
#define __CARC__


#include <string>
using namespace std;



/************************************************************
* CLASSE : Classe pour la gestion des arcs
* ************************************************************
* ROLE : Interface de la classe CArc,
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


class CArc
{
	//ATTRIBUTS
private:
	string sARCSommetDepart;
	string sARCSommetArrive;

public:
	//CONSTRUCTEUR/DESTRUCTEUR
		/******************************************************
		* CArc
		* *****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : l'initialisation d'un CArc
		* ****************************************************/
	CArc();



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
	CArc(string sParamDepart, string sParamArrive);
	
	//METHODES
		/******************************************************
		* ARCLireDepart
		* *****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : une chaine de caractere le nom d'un sommet
		* Entraîne : Le nom du sommet de depart est retourné
		* ****************************************************/
	inline const string ARCLireDepart() const { return sARCSommetDepart; };

	/******************************************************
	* ARCLireArrive
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : une chaine de caractere le nom d'un sommet
	* Entraîne : Le nom du sommet d'arrive est retourné
	* ****************************************************/
	inline const string ARCLireArrive() const { return sARCSommetArrive; };

	/******************************************************
	* ARCModifierSommetDepart
	* *****************************************************
	* Entrée : un string
	* Nécessite : Le sommet en parametre existe
	* Sortie : Rien
	* Entraîne : le nom du sommet de depart est modifié
	* ****************************************************/
	inline void ARCModifierSommetDepart(string sParam) { sARCSommetDepart = sParam; };

	/******************************************************
	* ARCModifierSommetArrive
	* *****************************************************
	* Entrée : un string
	* Nécessite : le sommet en parametre doit exister
	* Sortie : Rien
	* Entraîne : le nom du sommet d'arrivé est modifié
	* ****************************************************/
	inline void ARCModifierSommetArrive(string sParam) { sARCSommetArrive = sParam; };


};
#endif