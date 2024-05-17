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
*  pas de types particulier de d�clar�
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
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : constructeur par defaut
		* ****************************************************/
		inline CInversion() { pGROINVGraphe = nullptr; };

		/*****************************************************
		* Cinversion
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : constructeur de recopie par defaut
		* ****************************************************/
		CInversion(CInversion& InverParam);

		/*****************************************************
		* Cinversion
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : constructeur de recopie par defaut
		* ****************************************************/
		void operator=(CInversion& InverParam);


		/*****************************************************
		* INVLectureGraphe
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : le graphe
		* Entra�ne : le graphe pointe par l'attribut est retourne
		* ****************************************************/
		inline PGrapheOriente<CArc, PSommet<CArc>>* INVLectureGraphe() { return pGROINVGraphe; };


		/*****************************************************
		* INVLectureGraphe
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : le graphe
		* Entra�ne : le graphe pointe par l'attribut est retourne
		* ****************************************************/
		inline void INVChangerGraphe(PGrapheOriente<CArc, PSommet<CArc>>* GrapheParam) { pGROINVGraphe = GrapheParam; };


		/*****************************************************
		* INVInversion
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Le graphe oriente inverse
		* Entra�ne : le graphe en attribut est inverse dans une 
		* nouvelle instance de la classe
		* ****************************************************/
		PGrapheOriente<CArc, PSommet<CArc>>* INVInversion();



};

#endif