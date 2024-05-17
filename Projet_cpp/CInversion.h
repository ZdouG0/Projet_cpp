#ifndef __CINVERSION__
#define __CINVERSION__					



#include "PGrapheOriente.h"
#include "CException.h"

/************************************************************
* CLASSE : Classe pour l'inversion graphe
* ************************************************************
* ROLE : Interface de la classe CInversion,
* cette classe fournit un ensemble de service pour l'inversion
* d'un graphe 
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI / Milan HERGOTT
* DATE : 23/04/2024
* ************************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES :
*  pas de types particulier de déclaré
*/

/* VARIABLES :
*
*
*/


class CInversion
{
	//attributs
	private : 
		PGrapheOriente<CArc, PSommet<CArc>>* pGROINVGraphe;

	//methodes
	public:
		/*****************************************************
		* Cinversion
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : constructeur par defaut
		* ****************************************************/
		inline CInversion() { pGROINVGraphe = nullptr; };

		/*****************************************************
		* Cinversion
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : constructeur de recopie par defaut
		* ****************************************************/
		CInversion(CInversion& InverParam);

		/*****************************************************
		* Cinversion
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : constructeur de recopie par defaut
		* ****************************************************/
		void operator=(CInversion& InverParam);


		/*****************************************************
		* INVLectureGraphe
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : le graphe
		* Entraîne : le graphe pointe par l'attribut est retourne
		* ****************************************************/
		inline PGrapheOriente<CArc, PSommet<CArc>>* INVLectureGraphe() { return pGROINVGraphe; };


		/*****************************************************
		* INVLectureGraphe
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : le graphe
		* Entraîne : le graphe pointe par l'attribut est retourne
		* ****************************************************/
		inline void INVChangerGraphe(PGrapheOriente<CArc, PSommet<CArc>>* GrapheParam) { pGROINVGraphe = GrapheParam; };


		/*****************************************************
		* INVInversion
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Le graphe oriente inverse
		* Entraîne : le graphe en attribut est inverse dans une 
		* nouvelle instance de la classe
		* ****************************************************/
		PGrapheOriente<CArc, PSommet<CArc>>* INVInversion();



};

#endif