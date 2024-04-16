#include "CGrapheOriente.h"



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
void CGrapheOriente::GROCreerArc(string sParamDepart, string sParamArrive) {
	//Je vais appeler ces deux fonctions pour etre sur que les sommet de depart et d'arrive existent
	//Dans cette fonction je lève une CException si le sommet n'est pas dans le tableau des sommets
	size_t stPosD = GROTrouverSommetPosition(sParamDepart); size_t stPosA = GROTrouverSommetPosition(sParamArrive); size_t stCompteur = 0;


	///Depart -----> Arrive ///////////// Dans depart jai donc un arc sortant allant vers arrive et dans arrive un arc entrant allant dans depart

	//ajouter liste des arcs
	CArc* ARCParam = new CArc(sParamDepart, sParamArrive);
	pARCGROListArc.push_back(ARCParam);
	// ajouter dans les sommets
	CSommet* sommetDepart = nullptr;
	CSommet* sommetArrive = nullptr;
	for (auto iter = pSOMGROListSom.begin(); iter != pSOMGROListSom.end(); ++iter, ++stCompteur) {
		if (stCompteur == stPosD) {
			sommetDepart = *iter;
		}
		if (stCompteur == stPosA) {
			sommetArrive = *iter;
		}
	}
	sommetDepart->SOMAjoutArcSortant(ARCParam);
	sommetArrive->SOMAjoutArcEntrant(ARCParam);
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
	unsigned int uiBoucle;
	if (stPos >= pARCGROListArc.size()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(Element_inconnu);
		throw(EXCErreur);
	}

	auto iter = pARCGROListArc.begin();
	for (uiBoucle = 0; uiBoucle < stPos; ++uiBoucle) {
		++iter;
	}

	return **iter;
}


/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entrée : une chaine de caractere ( nom du sommet de départ) et une chaine de caractere ( nom du sommet d'arrivé de l'arc)
	* Nécessite : Rien
	* Sortie : Aucune
	* Entraîne : (le sommet avec le nom chParam est supprimé) OU (Exception Element_inconnu)
	* ****************************************************/
void CGrapheOriente::GROSupprimerArc(string chParamDepart, string chParamArrive) {
	
	
	for (auto iter = pARCGROListArc.begin(); iter != pARCGROListArc.end(); ++iter) {
		if ((*iter)->ARCLireDepart() == chParamDepart && (*iter)->ARCLireArrive() == chParamArrive) {
			pARCGROListArc.erase(iter);
		}
	}
}


/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entrée : Un sommet pour lequel on va supprimer tout les arcs qui pointent vers lui
	* Nécessite : Rien
	* Sortie : Aucune
	* Entraîne : Un sommet isolé qui ne pointent vers personne et avec personne qui pointent sur lui
	* ****************************************************/
void CGrapheOriente::GROSupprimerArcs(CSommet& SOMParam) {
	unsigned int  stBoucle;

	for (stBoucle = 0; stBoucle < SOMParam.SOMTaileListArcEntrant(); stBoucle++) {
		CArc* ARCParam = SOMParam.SOMLireElemListArcEntrant(stBoucle);
		GROSupprimerArc(ARCParam->ARCLireDepart(), ARCParam->ARCLireArrive());
	}
	for (stBoucle = 0; stBoucle < SOMParam.SOMTaileListArcSortant(); stBoucle++) {
		CArc* ARCParam = SOMParam.SOMLireElemListArcSortant(stBoucle);
		GROSupprimerArc(ARCParam->ARCLireDepart(), ARCParam->ARCLireArrive());
	}
}



/*****************************************************
* GROCreerSommet
* ****************************************************
* Entrée : une chaine de caractere ( nom du sommet à creer)
* Nécessite : Rien
* Sortie : Aucune
* Entraîne : Il y a un sommet de plus dans la liste des sommets si le sommet est bien dans la liste
* ****************************************************/
void CGrapheOriente::GROCreerSommet(string chParam) {
	CSommet* SOMParam = new CSommet();
	SOMParam->SOMModifierNom(chParam);
	pSOMGROListSom.push_back(SOMParam);
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
	auto iter = pSOMGROListSom.begin();
	while (stboucle < pSOMGROListSom.size() && bEstDansLaListe == false) {
		if ((*iter)->SOMLireNom() == chParam) {
			bEstDansLaListe = true;
		}
		else {
			iter++;
			stboucle++;
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

	auto iter = pSOMGROListSom.begin();
	advance(iter, stPos);

	return (*iter)->SOMLireNom();
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
	size_t stPos = GROTrouverSommetPosition(chParam);
	auto iter = pSOMGROListSom.begin();
	advance(iter, stPos);

	// Supprimer les arcs associe au sommet
	GROSupprimerArcs(**iter);

	// Supprimer le sommet de la liste
	delete* iter;
	pSOMGROListSom.erase(iter);
}