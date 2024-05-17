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
*  pas de types particulier de d�clar�
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
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : l'initialisation d'un CSommet
	* ****************************************************/
	CSommet();




	/******************************************************
	* Csommet
	* *****************************************************
	* Entr�e : un string sParam
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : l'initialisation d'un CSommet avec comme parametres sSOMNom = sParam
	* ****************************************************/
	CSommet(string sParam);





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
	T* SOMLireElemListArcEntrant(unsigned int uiIndice); 

	/******************************************************
	* SOMLireListSomEntrant
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : la liste des sommets li�s a ce sommet
	* Entra�ne : la liste des sommets li�s a ce sommet est retourne
	* ****************************************************/
	vector<string> SOMLireListSomEntrant();


	/******************************************************
	* SOMLireListSomSortant
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : la liste des sommets li�s a ce sommet
	* Entra�ne : la liste des sommets li�s a ce sommet est retourne
	* ****************************************************/
	vector<string> SOMLireListSomSortant();


	/******************************************************
	* SOMLireElemListArcSortant
	* *****************************************************
	* Entr�e : une entier non sign� l'indice de l'element
	* souhait� dans la liste
	* N�cessite : Rien
	* Sortie : un Arc qui part de ce sommet
	* Entra�ne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
	* ****************************************************/
	T* SOMLireElemListArcSortant(unsigned int uiIndice);

	/******************************************************
	* SOMAjoutArcSortant
	* *****************************************************
	* Entr�e : un CArc; l'arc que l'on veut ajouter
	* N�cessite : Le sommet de depart de l'arc doit etre le sommet actuel
	* Sortie : Rien
	* Entra�ne : L'arc entre en parametre est ajout� a la liste
	* des arc sortant
	* ****************************************************/
	inline void SOMAjoutArcSortant(T* ARCParam) { lSOMListArcSortant.push_back(ARCParam); };

	/******************************************************
	* SOMAjoutArcEntrant
	* *****************************************************
	* Entr�e : un CArc; l'arc que l'on veut ajouter
	* N�cessite : Le sommet d'arriv� de l'arc doit etre le sommet actuel
	* Sortie : Rien
	* Entra�ne : L'arc entre en parametre est ajout� a la liste
	* des arc entrant
	* ****************************************************/
	inline void SOMAjoutArcEntrant(T* ARCParam) { lSOMListArcEntrant.push_back(ARCParam); };

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
	void SOMModifierNom(string& sParam) { sSOMNom = sParam; }




	/******************************************************
	* SOMTaileListArcEntrant
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : size_t
	* Entra�ne : la taille de la liste d'arc entrant est retourn�
	* ****************************************************/
	size_t SOMTaileListArcEntrant() { return lSOMListArcEntrant.size(); }





	/******************************************************
	* SOMTaileListArcSortant
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : size_t
	* Entra�ne : la taille de la liste d'arc sortant est retourn�
	* ****************************************************/
	size_t SOMTaileListArcSortant() { return lSOMListArcSortant.size(); }


	/******************************************************
	* SOMSupprimerArcLie
	* *****************************************************
	* Entr�e : Deux cha�nes de caract�res repr�sentant le nom du sommet de d�part de l'arc � supprimer et le nom du sommet d'arriv�e de l'arc � supprimer
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Supprime l'arc de la liste des arcs entrants ou sortants du sommet, en fonction de ses noms de sommets de d�part et d'arriv�e
	* ****************************************************/
	void SOMSupprimerSOMEntrantLie(const string sParam);



	/******************************************************
	* SOMSupprimerArcSortantLie
	* *****************************************************
	* Entr�e : Une cha�ne de caract�res repr�sentant le nom du sommet de d�part de l'arc � supprimer
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Supprime l'arc sortant de la liste des arcs sortants du sommet, en fonction du nom du sommet de d�part de l'arc � supprimer
	* ****************************************************/
	void SOMSupprimerArcSortantLie(const string sParam);

};

#endif
