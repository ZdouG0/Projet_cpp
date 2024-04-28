#include "CInversion.h"


/*****************************************************
* Cinversion
* ****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : constructeur de recopie par defaut
* ****************************************************/
CInversion::CInversion(CInversion& InverParam) {
	pGROINVGraphe = new CGrapheOriente(*InverParam.pGROINVGraphe);
}

/*****************************************************
* Cinversion
* ****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : constructeur de recopie par defaut
* ****************************************************/
void CInversion :: operator=(CInversion& InverParam) {
	pGROINVGraphe = new CGrapheOriente(*InverParam.pGROINVGraphe);
}


/*****************************************************
* INVInversion
* ****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : le graphe en attribut est inverse
* ****************************************************/
CGrapheOriente* CInversion :: INVInversion() {
	unsigned int uiBoucle_som;
	unsigned int uiBoucle_arc;
	CSommet* pSOMtemp = nullptr;
	string sNomArrive;
	string sNomDepart;
	CArc* pARCtemp = nullptr;
	CArc* pARCtemp2 = nullptr;
	CGrapheOriente* pGROGrapheInv = new CGrapheOriente();
	for (uiBoucle_som = 0; uiBoucle_som < pGROINVGraphe->GROLireTailleListSommet(); uiBoucle_som++) {  // cette boucle permet de copier notre graphe en attributs mais prové des arcs
		pSOMtemp = pGROINVGraphe->GROLireSommet(uiBoucle_som);
		pGROGrapheInv->GROCreerSommet(pSOMtemp->SOMLireNom());
	}
	for (uiBoucle_som = 0; uiBoucle_som < pGROINVGraphe->GROLireTailleListSommet(); uiBoucle_som++) {
		pSOMtemp = pGROINVGraphe->GROLireSommet(uiBoucle_som);
		for (uiBoucle_arc = 0; uiBoucle_arc < pSOMtemp->SOMTaileListArcSortant(); uiBoucle_arc++) {
			pARCtemp = pSOMtemp->SOMLireElemListArcSortant(uiBoucle_arc); // on recupere l'arc a inverser
			sNomArrive = pARCtemp->ARCLireArrive(); // on stock l'arrivée pour la seconde partie de l'inversion
			sNomDepart = pARCtemp->ARCLireDepart();  // on stock l'arrivée pour la seconde partie de l'inversion
			pGROGrapheInv->GROCreerArc(sNomArrive, sNomDepart); //on ajoute notre nouvel arc
		}
		
	}
	return pGROGrapheInv;
}