#include "CInversion.h"


/*****************************************************
* Cinversion
* ****************************************************
* Entr�e : Rien
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : constructeur de recopie par defaut
* ****************************************************/
CInversion::CInversion(CInversion& InverParam) {
	pGROINVGraphe = new PGrapheOriente<CArc,CSommet<CArc>>(*InverParam.pGROINVGraphe);
}

/*****************************************************
* Cinversion
* ****************************************************
* Entr�e : Rien
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : constructeur de recopie par defaut
* ****************************************************/
void CInversion :: operator=(CInversion& InverParam) {
	pGROINVGraphe = new PGrapheOriente<CArc, CSommet<CArc>>(*InverParam.pGROINVGraphe);
}


/*****************************************************
* INVInversion
* ****************************************************
* Entr�e : Rien
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : le graphe en attribut est inverse
* ****************************************************/
PGrapheOriente<CArc, CSommet<CArc>>* CInversion :: INVInversion() {
	unsigned int uiBoucle_som;
	unsigned int uiBoucle_arc;
	CSommet<CArc>* pSOMtemp = nullptr;
	string sNomArrive;
	string sNomDepart;
	CArc* pARCtemp = nullptr;
	CArc* pARCtemp2 = nullptr;
	PGrapheOriente<CArc, CSommet<CArc>>* pGROGrapheInv = new PGrapheOriente<CArc,CSommet<CArc>>();
	for (uiBoucle_som = 0; uiBoucle_som < pGROINVGraphe->GROLireTailleListSommet(); uiBoucle_som++) {  // cette boucle permet de copier notre graphe en attributs mais prov� des arcs
		pSOMtemp = pGROINVGraphe->GROLireSommet(uiBoucle_som);
		pGROGrapheInv->GROCreerSommet(pSOMtemp->SOMLireNom());
	}
	for (uiBoucle_som = 0; uiBoucle_som < pGROINVGraphe->GROLireTailleListSommet(); uiBoucle_som++) {
		pSOMtemp = pGROINVGraphe->GROLireSommet(uiBoucle_som);
		for (uiBoucle_arc = 0; uiBoucle_arc < pSOMtemp->SOMTaileListArcSortant(); uiBoucle_arc++) {
			pARCtemp = pSOMtemp->SOMLireElemListArcSortant(uiBoucle_arc); // on recupere l'arc a inverser
			sNomArrive = pARCtemp->ARCLireArrive(); // on stock l'arriv�e pour la seconde partie de l'inversion
			sNomDepart = pARCtemp->ARCLireDepart();  // on stock l'arriv�e pour la seconde partie de l'inversion
			pGROGrapheInv->GROCreerArc(sNomArrive, sNomDepart); //on ajoute notre nouvel arc
		}
		
	}
	return pGROGrapheInv;
}