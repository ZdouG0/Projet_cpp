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
*  pas de types particulier de d�clar�
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
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : Un objet de la classe CSortie est construit
		* ****************************************************/
		CSortie();


		/*****************************************************
		* ~CSortie
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : destruction de l'instance
		* ****************************************************/
		~CSortie();
		
		/*****************************************************
		* SORAfficher_Graphe
		* ****************************************************
		* Entr�e : le GrapheOriente a afficher
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : Le graphe en parametre est Modifi�
		* ****************************************************/
		void SORModifierGraphe(CGrapheOriente* GrapheParam) { pGROSORGraphe = GrapheParam; };

		/*****************************************************
		* SORAfficher_Graphe
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : Notre Graphe est affiche
		* ****************************************************/
		void SORAfficher_Graphe();

};

#endif