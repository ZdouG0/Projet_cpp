#ifndef __PSommet__
#define __PSommet__					



#include <string>
using namespace std;
#include "CArc.h"
#include <list>
#include<iterator> 
#include <vector>
#include "CException.h"



/************************************************************
* CLASSE : Classe pour la gestion des Sommets
* ************************************************************
* ROLE : Interface de la classe PSommet,
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

template<class T> class PSommet
{
	//ATTRIBUTS
private:
	string sSOMNom;
	list<T*> lSOMListArcEntrant;
	list<T*> lSOMListArcSortant;
	
public:
	//CONSTRUCTEUR/DESTRUCTEUR
	/******************************************************
	* PSommet
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : l'initialisation d'un PSommet
	* ****************************************************/
	PSommet() {
		list<T*>listeArcsEntrant;
		list<T*>listeArcsSortant;
		sSOMNom = "Le sommet n'a pas encore de nom";
		lSOMListArcEntrant = listeArcsEntrant;
		lSOMListArcSortant = listeArcsSortant;
	}




	/******************************************************
	* PSommet
	* *****************************************************
	* Entr�e : un string sParam
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : l'initialisation d'un PSommet avec comme parametres sSOMNom = sParam
	* ****************************************************/
	PSommet(string sParam) {
		list<T*>listeArcsEntrant;
		list<T*>listeArcsSortant;
		sSOMNom = sParam;
		lSOMListArcEntrant = listeArcsEntrant;
		lSOMListArcSortant = listeArcsSortant;
	}





	//METHODES
	/******************************************************
	* SOMLireElemListArcEntrant
	* *****************************************************
	* Entr�e : un entier non sign� l'indice de l'element
	* souhait� dans la liste
	* N�cessite : Rien
	* Sortie : un Arc qui part de ce sommet
	* Entra�ne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
	* ****************************************************/
	T* SOMLireElemListArcEntrant(unsigned int uiIndice) {
		if (uiIndice >= lSOMListArcEntrant.size()) {
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(INDICE_HORS_TABLEAU);
			throw(EXCErreur);
		}
		
		auto iter = lSOMListArcEntrant.begin();
		for (unsigned int uiBoucle = 0; uiBoucle < uiIndice; uiBoucle++) {
			iter++;
		}
		return *iter;
	}

	/******************************************************
	* SOMLireListSomEntrant
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : la liste des sommets li�s a ce sommet
	* Entra�ne : la liste des sommets li�s a ce sommet est retourne
	* ****************************************************/
	vector<string> SOMLireListSomEntrant() {
		vector<string> vListSom;
		for (unsigned int uiBoucle = 0; uiBoucle < lSOMListArcEntrant.size(); uiBoucle++) {
			vListSom.push_back(SOMLireElemListArcEntrant(uiBoucle)->ARCLireDepart());
		}
		return vListSom;
	}


	/******************************************************
	* SOMLireListSomSortant
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : la liste des sommets li�s a ce sommet
	* Entra�ne : la liste des sommets li�s a ce sommet est retourne
	* ****************************************************/
	vector<string> SOMLireListSomSortant() {
		vector<string> vListSom;
		for (unsigned int uiBoucle = 0; uiBoucle < lSOMListArcSortant.size(); uiBoucle++) {
			vListSom.push_back(SOMLireElemListArcSortant(uiBoucle)->ARCLireArrive());
		}
		return vListSom;
	}



	/******************************************************
	* SOMLireListArcSortant
	* *****************************************************
	* Entr�e : une entier non sign� l'indice de l'element
	* souhait� dans la liste
	* N�cessite : Rien
	* Sortie : un Arc qui entre dans ce sommet
	* Entra�ne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
	* ****************************************************/
	T* SOMLireElemListArcSortant(unsigned int uiIndice) {
		if (uiIndice >= lSOMListArcSortant.size()) {
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(INDICE_HORS_TABLEAU);
			throw(EXCErreur);
		}
		
		auto iter = lSOMListArcSortant.begin();
		for (unsigned int uiBoucle = 0; uiBoucle < uiIndice; uiBoucle++) {
			iter++;
		}
		return *iter;
	}


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
	* SOMSupprimerArcEntrantLie
	* *****************************************************
	* Entr�e : Une cha�ne de caract�res repr�sentant le nom du sommet d'arriv�e de l'arc � supprimer
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Supprime l'arc entrant de la liste des arcs entrants du sommet, en fonction du nom du sommet d'arriv�e de l'arc � supprimer
	*****************************************************/
	void SOMSupprimerSOMEntrantLie(const string sParam) {
		for (auto iter = lSOMListArcEntrant.begin(); iter != lSOMListArcEntrant.end(); ++iter) {
			if ((*iter)->ARCLireArrive() == sParam) {
				lSOMListArcEntrant.erase(iter);
				return;
			}
		}
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(INDICE_HORS_TABLEAU);
		throw(EXCErreur);
	}


		/******************************************************
		* SOMSupprimerArcSortantLie
		* *****************************************************
		* Entr�e : Une cha�ne de caract�res repr�sentant le nom du sommet de d�part de l'arc � supprimer
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : Supprime l'arc sortant de la liste des arcs sortants du sommet, en fonction du nom du sommet de d�part de l'arc � supprimer
		* ****************************************************/
		void SOMSupprimerArcSortantLie(const string sParam) {
			// Recherche de l'arc dans la liste des arcs sortants
			for (auto iter = lSOMListArcSortant.begin(); iter != lSOMListArcSortant.end(); ++iter) {
				if ((*iter)->ARCLireDepart() == sParam) {
					lSOMListArcSortant.erase(iter);
					return;
				}
			}
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(INDICE_HORS_TABLEAU);
			throw(EXCErreur);
		}

};

#endif