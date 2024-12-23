#include "CGrapheOriente.h"



/*****************************************************
	* CGrapheOriente
	* ****************************************************
	* Entr�e : Aucune
	* N�cessite : RIen
	* Sortie : Aucune
	* Entra�ne : Creation d'un objet CGrapheOriente
	* ****************************************************/
CGrapheOriente::CGrapheOriente() {
	list<CArc*>listeArcs;
	list<CSommet*>listeSommet;
	pARCGROListArc = listeArcs;
	pSOMGROListSom = listeSommet;
}

/***************************************************
*CGrapheOriente
*****************************************************
* Entr�e : Aucune
* N�cessite : RIen
* Sortie : Aucune
* Entra�ne : Creation d'un objet CGrapheOriente
* ****************************************************/
CGrapheOriente::CGrapheOriente(CGrapheOriente& GROTocopie) {
	list<CArc*>listeArcs; size_t uiboucle;
	for (uiboucle = 0; uiboucle < GROTocopie.GROLireTailleListArc(); uiboucle++) {
		listeArcs.push_back(GROTocopie.GROLireArc(uiboucle));
	}
	list<CSommet*>listeSommet;
	for (uiboucle = 0; uiboucle < GROTocopie.GROLireTailleListSommet(); uiboucle++) {
		listeSommet.push_back(GROTocopie.GROLireSommet(uiboucle));
	}
	pARCGROListArc = listeArcs;
	pSOMGROListSom = listeSommet;
}

/*****************************************************
* operator=
* ****************************************************
* Entr�e : Aucune
* N�cessite : RIen
* Sortie : Aucune
* Entra�ne : Creation d'un objet CGrapheOriente
* ****************************************************/
void CGrapheOriente :: operator=(CGrapheOriente& GROTocopie) {
	list<CArc*>listeArcs; size_t uiboucle;
	for (uiboucle = 0; uiboucle < GROTocopie.GROLireTailleListArc(); uiboucle++) {
		listeArcs.push_back(GROTocopie.GROLireArc(uiboucle));
	}
	list<CSommet*>listeSommet;
	for (uiboucle = 0; uiboucle < GROTocopie.GROLireTailleListSommet(); uiboucle++) {
		listeSommet.push_back(GROTocopie.GROLireSommet(uiboucle));
	}
	pARCGROListArc = listeArcs;
	pSOMGROListSom = listeSommet;
}



/*****************************************************
	* GROCreerArc
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommet de depart) et une deuxi�me chaine de caract�re (nom du sommet d'arriv�e)
	* N�cessite : La liste de CSommet contienne au moins deux elements et que les deux chaines de caract�res se r�f�rent bien � des sommets existants
	* Sortie : Aucune
	* Entra�ne : ( Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste) OU (Exception Element_inconnu)
	* Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste
	* De plus les deux sommets sont maintenant li� par un arc
	* ****************************************************/
void CGrapheOriente::GROCreerArc(string sParamDepart, string sParamArrive) {
	//Je vais appeler ces deux fonctions pour etre sur que les sommet de depart et d'arrive existent
	//Dans cette fonction je l�ve une CException si le sommet n'est pas dans le tableau des sommets
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
	* Entr�e : un size_t (qui correspond � la position de l'arc � lire)
	* N�cessite : Rien
	* Sortie : string
	* Entra�ne : (le nom des sommets de depart et d'arrive de notre arc avec la position stPos est retourn�e) OU (Exception Element_inconnu)
	* ****************************************************/
CArc* CGrapheOriente::GROLireArc(size_t stPos) const {
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

	return *iter;
}


/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommet de d�part) et une chaine de caractere ( nom du sommet d'arriv� de l'arc)
	* N�cessite : Rien
	* Sortie : Aucune
	* Entra�ne : (le sommet avec le nom chParam est supprim�) OU (Exception Element_inconnu)
	* ****************************************************/
void CGrapheOriente::GROSupprimerArc(string chParamDepart, string chParamArrive) {
	//Cette methode a trois choses � faire : supprimer l'arc de la liste des arcs du graph mais aussi supprimer le fait que les deux sommets soient li�es + d�salour
	size_t stPosSomE; size_t stPosSomS;
	for (auto iter = pARCGROListArc.begin(); iter != pARCGROListArc.end(); ++iter) {
		if ((*iter)->ARCLireDepart() == chParamDepart && (*iter)->ARCLireArrive() == chParamArrive) {
			//etape 1
			pARCGROListArc.erase(iter);
			//etape 2
			stPosSomE = GROTrouverSommetPosition(chParamDepart);
			stPosSomS = GROTrouverSommetPosition(chParamArrive);
			auto iterE = GROLireSommet(stPosSomE);
			iterE->SOMSupprimerArcSortantLie(chParamDepart);
			auto iterS = GROLireSommet(stPosSomS);
			iterS->SOMSupprimerArcSortantLie(chParamArrive);
			pARCGROListArc.erase(iter);
			delete *iter;
			
			return;
		}
	}
	CException EXCErreur;
	EXCErreur.EXCModifierValeur(Element_inconnu);
	throw(EXCErreur);
}


/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entr�e : Un sommet pour lequel on va supprimer tout les arcs qui pointent vers lui
	* N�cessite : Rien
	* Sortie : Aucune
	* Entra�ne : Un sommet isol� qui ne pointent vers personne et avec personne qui pointent sur lui
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
* Entr�e : une chaine de caractere ( nom du sommet � creer)
* N�cessite : Rien
* Sortie : Aucune
* Entra�ne : Il y a un sommet de plus dans la liste des sommets si le sommet est bien dans la liste
* ****************************************************/
void CGrapheOriente::GROCreerSommet(string chParam) {
	CSommet* SOMParam = new CSommet();
	SOMParam->SOMModifierNom(chParam);
	pSOMGROListSom.push_back(SOMParam);
}





/*****************************************************
* GROModifierSommet
* ****************************************************
* Entr�e : une chaine de caractere
* N�cessite : Rien
* Sortie : Aucune
* Entra�ne : Il y a un sommet qui a chang� de nom
* ****************************************************/
void CGrapheOriente::GROModifierSommet(string chParam, string chNvNom) {
	size_t posSOM;
	auto iter = pSOMGROListSom.begin();
	posSOM = GROTrouverSommetPosition(chParam);
	advance(iter, posSOM);

	// Modifier le nom du sommet
	(*iter)->SOMModifierNom(chNvNom);

	// Parcourir tous les sommets du graphe
	for (auto it = pSOMGROListSom.begin(); it != pSOMGROListSom.end(); ++it) {
		CSommet* sommet = *it;

		// Mettre � jour les arcs sortants
		for (size_t i = 0; i < sommet->SOMTaileListArcSortant(); ++i) {
			CArc* arc = sommet->SOMLireElemListArcSortant(i);
			if (arc->ARCLireDepart() == chParam) {
				arc->ARCModifierSommetDepart((*it)->SOMLireNom());
			}
		}

		// Mettre � jour les arcs entrants
		for (size_t i = 0; i < sommet->SOMTaileListArcEntrant(); ++i) {
			CArc* arc = sommet->SOMLireElemListArcEntrant(i);
			if (arc->ARCLireArrive() == chParam) {
				arc->ARCModifierSommetArrive((*it)->SOMLireNom());
			}
		}
	}
}





/*****************************************************
* GROTrouverSommet
* ****************************************************
* Entr�e : une chaine de caractere (nom du sommet � trouver)
* N�cessite : Rien
* Sortie : size_t
* Entra�ne : (la position du sommet avec le nom chParam est retourn�e) OU (Exception Element_inconnu)
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
	* Entr�e : un size_t (qui correspond � la position du sommet � lire)
	* N�cessite : Rien
	* Sortie : un pointeur vers un sommet
	* Entra�ne : (lenom du sommet avec la position sPos est retourn�e) OU (Exception Element_inconnu)
	* ****************************************************/
CSommet* CGrapheOriente::GROLireSommet(size_t stPos) const {
	if (stPos >= pSOMGROListSom.size()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(Element_inconnu);
		throw(EXCErreur);
	}

	auto iter = pSOMGROListSom.begin();
	advance(iter, stPos);

	return (*iter);
}




/*****************************************************
	* GROLireSommetSortantLie
	* ****************************************************
	* Entr�e : un string (qui correspond au nom du sommet � lire)
	* N�cessite : Rien
	* Sortie : vector<string>
	* Entra�ne : (le nom des sommet qui sont li� avec des arcs � notre sommet d'entr�) OU (Exception Element_inconnu)
	* ****************************************************/
vector<string> CGrapheOriente::GROLireSommetSortantLie(string chParam) {
	size_t stPos = GROTrouverSommetPosition(chParam);
	auto iter = pSOMGROListSom.begin();
	advance(iter, stPos);
	return (*iter)->SOMLireListSomSortant();
}


/*****************************************************
	* GROLireSommetEntrantLie
	* ****************************************************
	* Entr�e : un string (qui correspond au nom du sommet � lire)
	* N�cessite : Rien
	* Sortie : vector<string>
	* Entra�ne : (le nom des sommet qui sont li� avec des arcs � notre sommet d'entr�) OU (Exception Element_inconnu)
	* ****************************************************/
vector<string> CGrapheOriente::GROLireSommetEntrantLie(string chParam) {
	size_t stPos = GROTrouverSommetPosition(chParam);
	auto iter = pSOMGROListSom.begin();
	advance(iter, stPos);
	return (*iter)->SOMLireListSomEntrant();
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
	size_t stPos = GROTrouverSommetPosition(chParam);
	auto iter = pSOMGROListSom.begin();
	advance(iter, stPos);

	// Supprimer les arcs associe au sommet
	GROSupprimerArcs(**iter);

	// Supprimer le sommet de la liste
	delete *iter;
	pSOMGROListSom.erase(iter);
}