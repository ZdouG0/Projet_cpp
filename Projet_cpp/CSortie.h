#ifndef __CSortie__
#define __CSortie__					


#include "CGrapheOriente.h"
#include "CException.h"
using namespace std;
#include <iostream>



/************************************************************
* CLASSE : Classe pour l'affichage de graphe
* ************************************************************
* ROLE : Interface de la classe CSortie,
* cette classe fournit un ensemble de service pour l'affichage
* sommaire d'un graphe dans un terminal
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI / Milan HERGOTT
* DATE : /04/2024
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


class CSortie
{
	//ATTRIBUTS
	private :
		CGrapheOriente* pGROSORGraphe;
	//METHODES
	public :
		/*****************************************************
		* CSortie
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : Un objet de la classe CSortie est construit
		* ****************************************************/
		CSortie();


		/*****************************************************
		* ~CSortie
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : destruction de l'instance
		* ****************************************************/
		~CSortie();
		
		/*****************************************************
		* SORAfficher_Graphe
		* ****************************************************
		* Entrée : le GrapheOriente a afficher
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : Le graphe en parametre est Modifié
		* ****************************************************/
		void SORModifierGraphe(CGrapheOriente* GrapheParam) { pGROSORGraphe = GrapheParam; };

		/*****************************************************
		* SORAfficher_Graphe
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : Notre Graphe est affiche
		* ****************************************************/
		void SORAfficher_Graphe();

};

#endif