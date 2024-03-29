#pragma once
#include <string>
using namespace std;
#include "CArc.h"
#include <list>
#include<iterator> // for iterators 



/************************************************************
* CLASSE : Classe pour la gestion des Sommets
* ************************************************************
* ROLE : Interface de la classe CSommet,
* cette classe fournit un ensemble de service pour la gestion 
* de sommets
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
class CSommet
{
	//ATTRIBUTS
	private :
		string sSOMNom;
		list<CArc*> lSOMListArcEntrant;
		list<CArc*> lSOMListArcSortant;
	//CONSTRUCTEUR / DESTRUCTEUR
	public:
	//METHODES
		/******************************************************
		* SOMLireListArcEntrant
		* *****************************************************
		* Entrée : un entier non signé l'indice de l'element 
		* souhaité dans la liste
		* Nécessite : Rien
		* Sortie : un Arc qui part de ce sommet
		* Entraîne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
		* ****************************************************/
		CArc& SOMLireListArcEntrant(unsigned int uiIndice);

		/******************************************************
		* SOMLireListArcSortant
		* *****************************************************
		* Entrée : une entier non signé l'indice de l'element
		* souhaité dans la liste
		* Nécessite : Rien
		* Sortie : un Arc qui entre dans ce sommet
		* Entraîne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
		* ****************************************************/
		CArc& SOMLireListArcSortant(unsigned int uiIndice);

		/******************************************************
		* SOMAjoutArcSortant
		* *****************************************************
		* Entrée : un CArc; l'arc que l'on veut ajouter
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : L'arc entre en parametre est ajouté a la liste
		* des arc sortant
		* ****************************************************/
		void SOMAjoutArcSortant(CArc& ARCParam);

		/******************************************************
		* SOMAjoutArcEntrant
		* *****************************************************
		* Entrée : un CArc; l'arc que l'on veut ajouter
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : L'arc entre en parametre est ajouté a la liste
		* des arc entrant
		* ****************************************************/
		void SOMAjoutArcEntrant(CArc& ARCParam);

		/******************************************************
		* SOMLireNom
		* *****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : le nom du sommet est retourné
		* ****************************************************/
		const string SOMLireNom() const { return sSOMNom; };


		/******************************************************
		* SOMModifierNom
		* *****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : le nom du sommet est modifié
		* ****************************************************/
		void SOMModifierNom(string& sParam) { sSOMNom = sParam; };



};

