#include "CGrapheOriente.h"


CGrapheOriente::CGrapheOriente() {
	list<CArc*> pARCGROListArc;
	list<CSommet*> pSOMGROListSom;
}



/*****************************************************
* GROCreerSommet
* ****************************************************
* Entrée : une chaine de caractere ( nom du sommer à creer)
* Nécessite : Rien
* Sortie : Aucune
* Entraîne : Il y a un sommet de plus dans la liste des sommets si le sommet est bien dans la liste
* ****************************************************/
void CGrapheOriente::GROCreerSommet(string chParam) {
	CSommet SOMParam = CSommet(chParam);
	pSOMGROListSom.push_back(SOMParam);
}




/*****************************************************
	* GROCreerArc
	* ****************************************************
	* Entrée : une chaine de caractere ( nom du sommet de depart) et une deuxième chaine de caractère (nom du sommet d'arrivée)
	* Nécessite : La liste de CSommet contienne au moins deux elements et que les deux chaines de caractères se réfèrent bien à des sommets existants
	* Sortie : Aucune
	* Entraîne : ( Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste) OU (Exception Element_inconnu)
	* Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste
	* De plus les deux sommets sont maintenant lié par un arc
	* ****************************************************/
void CGrapheOriente::GROCreerArc(string chParamDepart, string chParamArrive) {
	size_t stPosD = GROTrouverSommetPosition(chParamDepart); size_t stPosA = GROTrouverSommetPosition(chParamArrive);

	CArc ARCParam = CArc(chParamDepart, chParamArrive);
}




/*****************************************************
* GROTrouverSommet
* ****************************************************
* Entrée : une chaine de caractere (nom du sommet à trouver)
* Nécessite : Rien
* Sortie : size_t
* Entraîne : (la position du sommet avec le nom chParam est retournée) OU (Exception Element_inconnu)
* ****************************************************/
size_t CGrapheOriente::GROTrouverSommetPosition(string chParam) {
	bool bEstDansLaListe = false; size_t stboucle = 0;
	while (stboucle < pSOMGROListSom.size() && bEstDansLaListe == false) {
		if (pSOMGROListSom[stboucle].sSOMNom == chParam) {
			bEstDansLaListe = true;
		}
	}
	if (bEstDansLaListe == false) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(Element_inconnu);
		throw(EXCErreur);
	}
	return stboucle;
}




/*****************************************************
* GROSupprimerSommet
* ****************************************************
* Entrée : une chaine de caractere ( nom du sommer à supprimer)
* Nécessite : Rien
* Sortie : Aucune
* Entraîne : (le sommet avec le nom chParam est supprimé) OU (Exception Element_inconnu)
* ****************************************************/
void CGrapheOriente::GROSupprimerSommet(string chParam) {
	//Bien faire attention que la suppression du sommet supprime bien les arcs 
	size_t stPos = GROTrouverSommetPosition(chParam);
	pSOMGROListSom.erase(pSOMGROListSom.begin() + stPos);
}




/*****************************************************
	* GROLireSommet
	* ****************************************************
	* Entrée : un size_t (qui correspond à la position du sommet à lire)
	* Nécessite : Rien
	* Sortie : string
	* Entraîne : (lenom du sommet avec la position sPos est retournée) OU (Exception Element_inconnu)
	* ****************************************************/
string CGrapheOriente::GROLireSommet(size_t stPos) const {
	if (stPos >= pSOMGROListSom.size()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(Element_inconnu);
		throw(EXCErreur);
	}
	list<CSommet*>::iterator iter;
	iter = pSOMGROListSom.begin();
	for (unsigned int uiBoucle = 0; uiBoucle <= stPos; uiBoucle++) {
		iter++;
	}
	return *iter.sSOMNom;
}






/*****************************************************
	* GROLireArc
	* ****************************************************
	* Entrée : un size_t (qui correspond à la position de l'arc à lire)
	* Nécessite : Rien
	* Sortie : string
	* Entraîne : (le nom des sommets de depart et d'arrive de notre arc avec la position stPos est retournée) OU (Exception Element_inconnu)
	* ****************************************************/
CArc& CGrapheOriente::GROLireArc(size_t stPos) const {
	if (stPos >= pSOMGROListSom.size()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(Element_inconnu);
		throw(EXCErreur);
	}
	list<CArc*>::iterator iter;
	iter = pARCGROListArc.begin();
	for (unsigned int uiBoucle = 0; uiBoucle <= stPos; uiBoucle++) {
		iter++;
	}
	return *iter.sSOMNom;
}