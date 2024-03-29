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
*  pas de types particulier de d�clar�
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
		* Entr�e : un entier non sign� l'indice de l'element 
		* souhait� dans la liste
		* N�cessite : Rien
		* Sortie : un Arc qui part de ce sommet
		* Entra�ne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
		* ****************************************************/
		CArc& SOMLireListArcEntrant(unsigned int uiIndice);

		/******************************************************
		* SOMLireListArcSortant
		* *****************************************************
		* Entr�e : une entier non sign� l'indice de l'element
		* souhait� dans la liste
		* N�cessite : Rien
		* Sortie : un Arc qui entre dans ce sommet
		* Entra�ne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
		* ****************************************************/
		CArc& SOMLireListArcSortant(unsigned int uiIndice);

		/******************************************************
		* SOMAjoutArcSortant
		* *****************************************************
		* Entr�e : un CArc; l'arc que l'on veut ajouter
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : L'arc entre en parametre est ajout� a la liste
		* des arc sortant
		* ****************************************************/
		void SOMAjoutArcSortant(CArc& ARCParam);

		/******************************************************
		* SOMAjoutArcEntrant
		* *****************************************************
		* Entr�e : un CArc; l'arc que l'on veut ajouter
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : L'arc entre en parametre est ajout� a la liste
		* des arc entrant
		* ****************************************************/
		void SOMAjoutArcEntrant(CArc& ARCParam);

		/******************************************************
		* SOMLireNom
		* *****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : le nom du sommet est retourn�
		* ****************************************************/
		const string SOMLireNom() const { return sSOMNom; };


		/******************************************************
		* SOMModifierNom
		* *****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : le nom du sommet est modifi�
		* ****************************************************/
		void SOMModifierNom(string& sParam) { sSOMNom = sParam; };



};

