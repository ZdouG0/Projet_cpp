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
*  pas de types particulier de d�clar�
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
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : l'initialisation d'un CArc
		* ****************************************************/
	CArc();



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
	CArc(string sParamDepart, string sParamArrive);
	
	//METHODES
		/******************************************************
		* ARCLireDepart
		* *****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : une chaine de caractere le nom d'un sommet
		* Entra�ne : Le nom du sommet de depart est retourn�
		* ****************************************************/
	inline const string ARCLireDepart() const { return sARCSommetDepart; };

	/******************************************************
	* ARCLireArrive
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : une chaine de caractere le nom d'un sommet
	* Entra�ne : Le nom du sommet d'arrive est retourn�
	* ****************************************************/
	inline const string ARCLireArrive() const { return sARCSommetArrive; };

	/******************************************************
	* ARCModifierSommetDepart
	* *****************************************************
	* Entr�e : un string
	* N�cessite : Le sommet en parametre existe
	* Sortie : Rien
	* Entra�ne : le nom du sommet de depart est modifi�
	* ****************************************************/
	inline void ARCModifierSommetDepart(string sParam) { sARCSommetDepart = sParam; };

	/******************************************************
	* ARCModifierSommetArrive
	* *****************************************************
	* Entr�e : un string
	* N�cessite : le sommet en parametre doit exister
	* Sortie : Rien
	* Entra�ne : le nom du sommet d'arriv� est modifi�
	* ****************************************************/
	inline void ARCModifierSommetArrive(string sParam) { sARCSommetArrive = sParam; };


};
#endif