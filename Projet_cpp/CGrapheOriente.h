#pragma once
#include <string>
#include <list>
#include "CSommet.h"
using namespace std;



/************************************************************
* CLASSE : Classe pour la gestion d' un Graphe Orienté
* ************************************************************
* ROLE : Interface de la classe CGrapheOriente,
* cette classe permet de generer un graphe orienté
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

class CGrapheOriente {
	//ATTRIBUTS
private:
	list<CArc*> pARCGROListArc;
	list<CSommet*> pSOMGROListSom;

	//METHODES
	//On le met en private pour ne creer qu'une seule instance de Graphe Orienté
	CGrapheOriente();
	CGrapheOriente(const CGrapheOriente& rGROParam) = delete;
	CGrapheOriente(const CGrapheOriente&& rGROMove) = delete;
public :
	//void GROCreerSommet(string chParam){}
	
};