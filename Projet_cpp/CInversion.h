#pragma once

#include "CGrapheOriente.h"
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
		CGrapheOriente* pGROINVGraphe;

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
		inline CGrapheOriente* INVLectureGraphe() { return pGROINVGraphe; };


		/*****************************************************
		* INVLectureGraphe
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : le graphe
		* Entra�ne : le graphe pointe par l'attribut est retourne
		* ****************************************************/
		inline void INVChangerGraphe(CGrapheOriente* GrapheParam) { pGROINVGraphe = GrapheParam; };


		/*****************************************************
		* INVInversion
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : le graphe en attribut est inverse
		* ****************************************************/
		void INVInversion();


};

