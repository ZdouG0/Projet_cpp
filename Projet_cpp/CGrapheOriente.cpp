#include "CGrapheOriente.h"


/*****************************************************
* GROCreerSommet
* ****************************************************
* Entrée : une chaine de caractere ( nom du sommer à creer)
* Nécessite : Rien
* Sortie : Aucune
* Entraîne : Il y a un sommet de plus dans la liste des sommets si le sommet est bien dans la liste
* ****************************************************/
void CGrapheOriente::GROCreerSommet(string chParam) {
	/*CSommet SOMParam = CSommet(chParam);
	pSOMGROListSom.push_back(SOMParam);*/
}


/*****************************************************
* GROTrouverSommet
* ****************************************************
* Entrée : une chaine de caractere (nom du sommet à ajouter)
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
	pSOMGROListSom.erase(stPos);
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
	}
	string sParam = pSOMGROListSom[stPost].sSOMNom;
	return sParam;
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
	}
}