#include "CSommet.h"
#include "CException.h"
#include<iterator>



/******************************************************
* CSommet
* *****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : l'initialisation d'un CSommet
* ****************************************************/
CSommet::CSommet() {
	list<CArc*>listeArcsEntrant;
	list<CArc*>listeArcsSortant;
	sSOMNom = "Le sommet n'a pas encore de nom";
	lSOMListArcEntrant = listeArcsEntrant;
	lSOMListArcSortant = listeArcsSortant;
}


/******************************************************
	* CArc
	* *****************************************************
	* Entrée : un string sParam
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : l'initialisation d'un CSommet avec comme parametres sSOMNom = sParam
	* ****************************************************/
CSommet::CSommet(string sParam) {
	list<CArc*>listeArcsEntrant;
	list<CArc*>listeArcsSortant;
	sSOMNom = sParam;
	lSOMListArcEntrant = listeArcsEntrant;
	lSOMListArcSortant = listeArcsSortant;
}






/******************************************************
* SOMLireListArcEntrant
* *****************************************************
* Entrée : un entier non signé l'indice de l'element
* souhaité dans la liste
* Nécessite : Rien
* Sortie : un Arc qui part de ce sommet
* Entraîne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
* ****************************************************/
CArc* CSommet::SOMLireElemListArcEntrant(unsigned int uiIndice) {
	if (uiIndice >= lSOMListArcEntrant.size()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(INDICE_HORS_TABLEAU);
		throw(EXCErreur);
	}
	list<CArc*>::iterator iter;
	iter = lSOMListArcEntrant.begin();
	for (unsigned int uiBoucle = 0; uiBoucle < uiIndice; uiBoucle++) {
		iter++;
	}
	return *iter;
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
CArc* CSommet::SOMLireElemListArcSortant(unsigned int uiIndice) {
	if (uiIndice >= lSOMListArcSortant.size()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(INDICE_HORS_TABLEAU);
		throw(EXCErreur);
	}
	list<CArc*>::iterator iter;
	iter = lSOMListArcSortant.begin();
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
vector<string> CSommet::SOMLireListSomEntrant() {
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
vector<string> CSommet::SOMLireListSomSortant() {
	vector<string> vListSom;
	for (unsigned int uiBoucle = 0; uiBoucle < lSOMListArcSortant.size(); uiBoucle++) {
		vListSom.push_back(SOMLireElemListArcSortant(uiBoucle)->ARCLireArrive());
	}
	return vListSom;
}


/******************************************************
* SOMSupprimerArcEntrantLie
* *****************************************************
* Entrée : Une chaîne de caractères représentant le nom du sommet d'arrivée de l'arc à supprimer
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Supprime l'arc entrant de la liste des arcs entrants du sommet, en fonction du nom du sommet d'arrivée de l'arc à supprimer
* ****************************************************/
void CSommet::SOMSupprimerSOMEntrantLie(const string sParam) {
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
void CSommet::SOMSupprimerArcSortantLie(const string sParam) {
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