#include "CArbreBoruvka.h"
#include<iterator>
#include "CArcPondere.h"


/*****************************************************
* CArbreBoruvka
* ****************************************************
* Entr�e : Un CArbreBoruvka a copier
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : Un objet de la classe CSortie est creer en
* copiant l'objet en parametre
* ****************************************************/
CArbreBoruvka::CArbreBoruvka(CArbreBoruvka& ABKParam) {
	pGROABKGraphParam = new PGrapheOriente<CArcPondere,CSommet<CArcPondere>>(*ABKParam.pGROABKGraphParam);
}

/*****************************************************
* operator=
* ****************************************************
* Entr�e : Un CArbreBoruvka a copier
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : Un objet de la classe CSortie est creer en
* copiant l'objet en parametre
* ****************************************************/
void CArbreBoruvka :: operator=(CArbreBoruvka& ABKParam) {
	pGROABKGraphParam = new PGrapheOriente<CArcPondere, CSommet<CArcPondere>>(*ABKParam.pGROABKGraphParam);
}


/*****************************************************
* ABKMinPoids
* ****************************************************
* Entr�e : rien
* N�cessite : Rien
* Sortie : Un PGrapheOriente l'arbe couvrant minimal
* Entra�ne : retourne l'arc avec le plus petit poids 
* d'une liste
* ****************************************************/
CArc* CArbreBoruvka::ABKMinPoids(list<CArc*> ListParam) {
	
	CArc* ARCPoidsMin = (*ListParam.begin()); // on recupere le premier element de la liste
	for (CArc* Arctemp : ListParam) {  // on parcout la liste en parametre
		if (Arctemp->ARCLirePoids() < ARCPoidsMin->ARCLirePoids()) ARCPoidsMin = Arctemp; // si le poids de l'element stock� dans ARCPoidsMin est plus petit on l'ecrase
	}
	return ARCPoidsMin;
}






/*****************************************************
* ABKBoruvka
* ****************************************************
* Entr�e : rien
* N�cessite : Rien
* Sortie : Un PGrapheOriente l'arbre couvrant minimal
* Entra�ne : creation de l'arbre couvrant minimal a partir
* de l'algorithme Boruvka
* ****************************************************/

PGrapheOriente* CArbreBoruvka::ABKBoruvka() {
	unsigned int uiBoucle;
	PGrapheOriente* pGROArbreCouvrant = new PGrapheOriente();
	PGrapheOriente* pGROGrapheTravail = new PGrapheOriente(*pGROABKGraphParam);
	while (pGROGrapheTravail->GRONombreSommet() > 1) {
		//elimination arc reflexif et multiple
		for (uiBoucle = 0; uiBoucle < pGROABKGraphParam->GRONombreSommet(); uiBoucle++) {
			pGROABKGraphParam->GROLireSommet(uiBoucle);
		}
	}
}




/*****************************************************
* ABKArbreNonReflexif
* ****************************************************
* Entr�e : rien
* N�cessite : Rien
* Sortie : Un PGrapheOriente l'arbre sans arcs reflexif
* Entra�ne : Un PGrapheOriente l'arbre sans arcs reflexif
* ****************************************************/
template<class T, class S>
void CArbreBoruvka<T, S>::ABKArbreNonReflexif() {
	unsigned int uiCompteur = 0;

	auto iter = GROLireSommet(0); // On met un iterateur sur le premier sommet de la list
	auto iter2 = GROLireSommet(1);
	while (iter2 != GROLireSommet(GROLireTailleListSommet()-1)) { // tant qu'on est pas � la fin
		while (uiCompteur < iter2->SOMTaileListArcEntrant()) {//tant qu'on est pas � la fin de ses sommets entrants
			if (iter->SOMLireNom() == iter->SOMLireElemListArcEntrant(compteur){// il faut supprimer -> arc reflexible

			}
			else if {}
		}
	}
}