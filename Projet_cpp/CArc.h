#pragma once
#include <string>
using namespace std;



/************************************************************
* CLASSE : Classe pour la gestion des arc
* ************************************************************
* ROLE : Interface de la classe CArc,
* cette classe permet de gerer les liaison entre les Sommets 
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
	//CONSTRUCTEUR/DESTRUCTEUR
	public :
	//METHODES
		/******************************************************
		* ARCLireDepart
		* *****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : une chaine de caractere le nom d'un sommet
		* Entraîne : Le nom du sommet de depart est retourné
		* ****************************************************/
		const string ARCLireDepart() const { return sARCSommetDepart; };

		/******************************************************
		* ARCLireArrive
		* *****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : une chaine de caractere le nom d'un sommet
		* Entraîne : Le nom du sommet d'arrive est retourné
		* ****************************************************/
		const string ARCLireArrive() const { return sARCSommetArrive; };

		/******************************************************
		* ARCModifierSommetDepart
		* *****************************************************
		* Entrée : un string
		* Nécessite : Le sommet en parametre existe
		* Sortie : Rien
		* Entraîne : le nom du sommet de depart est modifié
		* ****************************************************/
		void ARCModifierSommetDepart(string& sParam) { sARCSommetDepart = sParam; };  

		/******************************************************
		* ARCModifierSommetArrive
		* *****************************************************
		* Entrée : un string
		* Nécessite : le sommet en parametre doit exister
		* Sortie : Rien
		* Entraîne : le nom du sommet d'arrivé est modifié
		* ****************************************************/
		void ARCModifierSommetArrive(string& sParam) { sARCSommetArrive = sParam; }; 


};

