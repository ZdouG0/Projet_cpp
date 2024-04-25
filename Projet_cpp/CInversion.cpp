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
void CInversion :: INVInversion() {
	unsigned int uiBoucle_som;
	unsigned int uiBoucle_arc;
	CSommet* pSOMtemp = nullptr;
	string sNomArrive;
	string sNomDepart;
	CArc* pARCtemp = nullptr;
	CArc* pARCtemp2 = nullptr;
	for (uiBoucle_som = 0; uiBoucle_som < pGROINVGraphe->GROLireTailleListSommet(); uiBoucle_som++) {
		pSOMtemp = pGROINVGraphe->GROLireSommet(uiBoucle_som);
		for (uiBoucle_arc = 0; uiBoucle_arc < pSOMtemp->SOMTaileListArcSortant(); uiBoucle_arc++) {
			pARCtemp = pSOMtemp->SOMLireElemListArcSortant(uiBoucle_arc); // on recupere l'arc a inverser
			sNomArrive = pARCtemp->ARCLireArrive(); // on stock l'arrivée pour la seconde partie de l'inversion
			sNomDepart = pARCtemp->ARCLireDepart();  // on stock l'arrivée pour la seconde partie de l'inversion
			pARCtemp2 = new CArc(sNomArrive, sNomArrive); // on cree notre nouvel arc
			pGROINVGraphe->GROSupprimerArc(pARCtemp->ARCLireDepart(), pARCtemp->ARCLireArrive());// on supprime l'arc initial
			pSOMtemp->SOMAjoutArcEntrant(pARCtemp2); // on ajoute notre nouvel arc a la liste des arcs
		}
		
	}
}