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
		CGrapheOriente* pGROINVGraphe;

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
		inline CGrapheOriente* INVLectureGraphe() { return pGROINVGraphe; };


		/*****************************************************
		* INVLectureGraphe
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : le graphe
		* Entraîne : le graphe pointe par l'attribut est retourne
		* ****************************************************/
		inline void INVChangerGraphe(CGrapheOriente* GrapheParam) { pGROINVGraphe = GrapheParam; };


		/*****************************************************
		* INVInversion
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : le graphe en attribut est inverse
		* ****************************************************/
		void INVInversion();


};

