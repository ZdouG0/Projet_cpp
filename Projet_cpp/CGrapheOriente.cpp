#include "CGrapheOriente.h"


/*****************************************************
* GROCreerSommet
* ****************************************************
* Entr�e : une chaine de caractere ( nom du sommer � creer)
* N�cessite : Rien
* Sortie : Aucune
* Entra�ne : Il y a un sommet de plus dans la liste des sommets si le sommet est bien dans la liste
* ****************************************************/
void CGrapheOriente::GROCreerSommet(string chParam) {
	/*CSommet SOMParam = CSommet(chParam);
	pSOMGROListSom.push_back(SOMParam);*/
}


/*****************************************************
* GROTrouverSommet
* ****************************************************
* Entr�e : une chaine de caractere (nom du sommet � ajouter)
* N�cessite : Rien
* Sortie : size_t
* Entra�ne : (la position du sommet avec le nom chParam est retourn�e) OU (Exception Element_inconnu)
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
* Entr�e : une chaine de caractere ( nom du sommer � supprimer)
* N�cessite : Rien
* Sortie : Aucune
* Entra�ne : (le sommet avec le nom chParam est supprim�) OU (Exception Element_inconnu)
* ****************************************************/
void CGrapheOriente::GROSupprimerSommet(string chParam) {
	//Bien faire attention que la suppression du sommet supprime bien les arcs 
	size_t stPos = GROTrouverSommetPosition(chParam);
	pSOMGROListSom.erase(stPos);
}
/*****************************************************
	* GROLireSommet
	* ****************************************************
	* Entr�e : un size_t (qui correspond � la position du sommet � lire)
	* N�cessite : Rien
	* Sortie : string
	* Entra�ne : (lenom du sommet avec la position sPos est retourn�e) OU (Exception Element_inconnu)
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
	* Entr�e : un size_t (qui correspond � la position de l'arc � lire)
	* N�cessite : Rien
	* Sortie : string
	* Entra�ne : (le nom des sommets de depart et d'arrive de notre arc avec la position stPos est retourn�e) OU (Exception Element_inconnu)
	* ****************************************************/
CArc& CGrapheOriente::GROLireArc(size_t stPos) const {
	if (stPos >= pSOMGROListSom.size()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(Element_inconnu);
	}
}