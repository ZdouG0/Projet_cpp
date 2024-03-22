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
		CArc& operator[](unsigned i);
		const string SOMLireNom() const { return sSOMNom; };
		void SOMModifierNom(string& sParam) { sSOMNom = sParam; };



};

