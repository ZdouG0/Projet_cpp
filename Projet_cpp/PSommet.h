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
*  pas de types particulier de déclaré
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
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : l'initialisation d'un PSommet
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
	* Entrée : un string sParam
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : l'initialisation d'un PSommet avec comme parametres sSOMNom = sParam
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
	* Entrée : un entier non signé l'indice de l'element
	* souhaité dans la liste
	* Nécessite : Rien
	* Sortie : un Arc qui part de ce sommet
	* Entraîne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
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
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : la liste des sommets liés a ce sommet
	* Entraîne : la liste des sommets liés a ce sommet est retourne
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
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : la liste des sommets liés a ce sommet
	* Entraîne : la liste des sommets liés a ce sommet est retourne
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
	* Entrée : une entier non signé l'indice de l'element
	* souhaité dans la liste
	* Nécessite : Rien
	* Sortie : un Arc qui entre dans ce sommet
	* Entraîne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
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
	* SOMSupprimerArcEntrantLie
	* *****************************************************
	* Entrée : Une chaîne de caractères représentant le nom du sommet d'arrivée de l'arc à supprimer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Supprime l'arc entrant de la liste des arcs entrants du sommet, en fonction du nom du sommet d'arrivée de l'arc à supprimer
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
		* Entrée : Une chaîne de caractères représentant le nom du sommet de départ de l'arc à supprimer
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : Supprime l'arc sortant de la liste des arcs sortants du sommet, en fonction du nom du sommet de départ de l'arc à supprimer
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