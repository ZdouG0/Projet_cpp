#pragma once
#include <string>
using namespace std;
#include "CArc.h"
#include <list>
#include<iterator> // for iterators
#include <vector>
#include "CException.h"



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
* 
*/

#define INDICE_HORS_TABLEAU 866

class CSommet
{
	//ATTRIBUTS
	private :
		string sSOMNom;
		list<CArc&> lSOMListArcEntrant;
		list<CArc&> lSOMListArcSortant;
	//CONSTRUCTEUR / DESTRUCTEUR
	public:
	//METHODES
		/******************************************************
		* SOMLireElemListArcEntrant
		* *****************************************************
		* Entr�e : un entier non sign� l'indice de l'element 
		* souhait� dans la liste
		* N�cessite : Rien
		* Sortie : un Arc qui arrive dans ce sommet
		* Entra�ne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
		* ****************************************************/
		CArc& SOMLireElemListArcEntrant(unsigned int uiIndice);

		/******************************************************
		* SOMLireListSomEntrant
		* *****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : la liste des sommets li�s a ce sommet 
		* Entra�ne : la liste des sommets li�s a ce sommet est retourne
		* ****************************************************/
		vector<string> SOMLireListSom();

		/******************************************************
		* SOMLireElemListArcSortant
		* *****************************************************
		* Entr�e : une entier non sign� l'indice de l'element
		* souhait� dans la liste
		* N�cessite : Rien
		* Sortie : un Arc qui part de ce sommet
		* Entra�ne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
		* ****************************************************/
		CArc& SOMLireElemListArcSortant(unsigned int uiIndice);

		/******************************************************
		* SOMAjoutArcSortant
		* *****************************************************
		* Entr�e : un CArc; l'arc que l'on veut ajouter
		* N�cessite : Le sommet de depart de l'arc doit etre le sommet actuel
		* Sortie : Rien
		* Entra�ne : L'arc entre en parametre est ajout� a la liste
		* des arc sortant 
		* ****************************************************/
		inline void SOMAjoutArcSortant(CArc& ARCParam) { lSOMListArcSortant.push_back(ARCParam); };

		/******************************************************
		* SOMAjoutArcEntrant
		* *****************************************************
		* Entr�e : un CArc; l'arc que l'on veut ajouter
		* N�cessite : Le sommet d'arriv� de l'arc doit etre le sommet actuel
		* Sortie : Rien
		* Entra�ne : L'arc entre en parametre est ajout� a la liste
		* des arc entrant
		* ****************************************************/
		inline void SOMAjoutArcEntrant(CArc& ARCParam) { lSOMListArcEntrant.push_back(ARCParam); } ;

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


		/******************************************************
		* SOMModifierEntrant
		* *****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : le nom du sommet est modifi�
		* ****************************************************/
		void SOMModifierNom(string& sParam) { sSOMNom = sParam; };



};

