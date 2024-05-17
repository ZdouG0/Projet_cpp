#ifndef __CSommet__
#define __CSommet__					



#include <string>
using namespace std;
#include "CArc.h"
#include "CArcPondere.h"
#include <list>
#include<iterator> 
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
*  pas de types particulier de déclaré
*/

/* VARIABLES :
*
*
*/

#define INDICE_HORS_TABLEAU 866

template<class T> class CSommet
{
	//ATTRIBUTS
private:
	string sSOMNom;
	list<T*> lSOMListArcEntrant;
	list<T*> lSOMListArcSortant;
	
public:
	//CONSTRUCTEUR/DESTRUCTEUR
	/******************************************************
	* CSommet
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : l'initialisation d'un CSommet
	* ****************************************************/
	CSommet();




	/******************************************************
	* Csommet
	* *****************************************************
	* Entrée : un string sParam
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : l'initialisation d'un CSommet avec comme parametres sSOMNom = sParam
	* ****************************************************/
	CSommet(string sParam);





	//METHODES
	/******************************************************
	* SOMLireElemListArcEntrant
	* *****************************************************
	* Entrée : un entier non signé l'indice de l'element
	* souhaité dans la liste
	* Nécessite : Rien
	* Sortie : un Arc qui arrive dans ce sommet
	* Entraîne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
	* ****************************************************/
	T* SOMLireElemListArcEntrant(unsigned int uiIndice); 

	/******************************************************
	* SOMLireListSomEntrant
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : la liste des sommets liés a ce sommet
	* Entraîne : la liste des sommets liés a ce sommet est retourne
	* ****************************************************/
	vector<string> SOMLireListSomEntrant();


	/******************************************************
	* SOMLireListSomSortant
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : la liste des sommets liés a ce sommet
	* Entraîne : la liste des sommets liés a ce sommet est retourne
	* ****************************************************/
	vector<string> SOMLireListSomSortant();


	/******************************************************
	* SOMLireElemListArcSortant
	* *****************************************************
	* Entrée : une entier non signé l'indice de l'element
	* souhaité dans la liste
	* Nécessite : Rien
	* Sortie : un Arc qui part de ce sommet
	* Entraîne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
	* ****************************************************/
	T* SOMLireElemListArcSortant(unsigned int uiIndice);

	/******************************************************
	* SOMAjoutArcSortant
	* *****************************************************
	* Entrée : un CArc; l'arc que l'on veut ajouter
	* Nécessite : Le sommet de depart de l'arc doit etre le sommet actuel
	* Sortie : Rien
	* Entraîne : L'arc entre en parametre est ajouté a la liste
	* des arc sortant
	* ****************************************************/
	inline void SOMAjoutArcSortant(T* ARCParam) { lSOMListArcSortant.push_back(ARCParam); };

	/******************************************************
	* SOMAjoutArcEntrant
	* *****************************************************
	* Entrée : un CArc; l'arc que l'on veut ajouter
	* Nécessite : Le sommet d'arrivé de l'arc doit etre le sommet actuel
	* Sortie : Rien
	* Entraîne : L'arc entre en parametre est ajouté a la liste
	* des arc entrant
	* ****************************************************/
	inline void SOMAjoutArcEntrant(T* ARCParam) { lSOMListArcEntrant.push_back(ARCParam); };

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
	void SOMModifierNom(string& sParam) { sSOMNom = sParam; }




	/******************************************************
	* SOMTaileListArcEntrant
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : size_t
	* Entraîne : la taille de la liste d'arc entrant est retourné
	* ****************************************************/
	size_t SOMTaileListArcEntrant() { return lSOMListArcEntrant.size(); }





	/******************************************************
	* SOMTaileListArcSortant
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : size_t
	* Entraîne : la taille de la liste d'arc sortant est retourné
	* ****************************************************/
	size_t SOMTaileListArcSortant() { return lSOMListArcSortant.size(); }


	/******************************************************
	* SOMSupprimerArcLie
	* *****************************************************
	* Entrée : Deux chaînes de caractères représentant le nom du sommet de départ de l'arc à supprimer et le nom du sommet d'arrivée de l'arc à supprimer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Supprime l'arc de la liste des arcs entrants ou sortants du sommet, en fonction de ses noms de sommets de départ et d'arrivée
	* ****************************************************/
	void SOMSupprimerSOMEntrantLie(const string sParam);



	/******************************************************
	* SOMSupprimerArcSortantLie
	* *****************************************************
	* Entrée : Une chaîne de caractères représentant le nom du sommet de départ de l'arc à supprimer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Supprime l'arc sortant de la liste des arcs sortants du sommet, en fonction du nom du sommet de départ de l'arc à supprimer
	* ****************************************************/
	void SOMSupprimerArcSortantLie(const string sParam);

};

#endif
