#include "CSommet.h"
#include "CException.h"
#include<iterator>

/******************************************************
* SOMLireListArcEntrant
* *****************************************************
* Entr�e : un entier non sign� l'indice de l'element
* souhait� dans la liste
* N�cessite : Rien
* Sortie : un Arc qui part de ce sommet
* Entra�ne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
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
* Entr�e : une entier non sign� l'indice de l'element
* souhait� dans la liste
* N�cessite : Rien
* Sortie : un Arc qui entre dans ce sommet
* Entra�ne : (l'Arc voulu est retourne ) OU (EXCEPTION l'indice est trop grand)
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
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : la liste des sommets li�s a ce sommet
	* Entra�ne : la liste des sommets li�s a ce sommet est retourne
	* ****************************************************/
vector<string> CSommet::SOMLireListSomEntrant() {
	vector<string> vListSom;
	for (unsigned int uiBoucle = 0; uiBoucle < lSOMListArcEntrant.size(); uiBoucle++) {
		vListSom.push_back(SOMLireElemListArcEntrant(uiBoucle)->ARCLireArrive());
	}
	return vListSom;
}

vector<string> CSommet::SOMLireListSomSortant() {
	vector<string> vListSom;
	for (unsigned int uiBoucle = 0; uiBoucle < lSOMListArcSortant.size(); uiBoucle++) {
			vListSom.push_back(SOMLireElemListArcSortant(uiBoucle)->ARCLireDepart());
	}
	return vListSom;
}