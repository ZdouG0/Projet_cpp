#include "CArbreBoruvka.h"
#include<iterator>
#include "CArcPondere.h"


/*****************************************************
* CArbreBoruvka
* ****************************************************
* Entrée : Un CArbreBoruvka a copier
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Un objet de la classe CSortie est creer en
* copiant l'objet en parametre
* ****************************************************/
CArbreBoruvka::CArbreBoruvka(CArbreBoruvka& ABKParam) {
	pGROABKGraphParam = new PGrapheOriente<CArcPondere,PSommet<CArcPondere>>(*ABKParam.pGROABKGraphParam);
}

/*****************************************************
* operator=
* ****************************************************
* Entrée : Un CArbreBoruvka a copier
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Un objet de la classe CSortie est creer en
* copiant l'objet en parametre
* ****************************************************/
void CArbreBoruvka :: operator=(CArbreBoruvka& ABKParam) {
	pGROABKGraphParam = new PGrapheOriente<CArcPondere, PSommet<CArcPondere>>(*ABKParam.pGROABKGraphParam);
}


/*****************************************************
* ABKMinPoids
* ****************************************************
* Entrée : rien
* Nécessite : Rien
* Sortie : Un PGrapheOriente l'arbe couvrant minimal
* Entraîne : retourne l'arc avec le plus petit poids 
* d'une liste
* ****************************************************/
CArcPondere* CArbreBoruvka::ABKMinPoids(list<CArcPondere*> ListParam) {
	
	CArcPondere* ARCPoidsMin = (*ListParam.begin()); // on recupere le premier element de la liste
	for (CArcPondere* Arctemp : ListParam) {  // on parcout la liste en parametre
		if (Arctemp->ARCLirePoids() < ARCPoidsMin->ARCLirePoids()) ARCPoidsMin = Arctemp; // si le poids de l'element stocké dans ARCPoidsMin est plus petit on l'ecrase
	}
	return ARCPoidsMin;
}






/*****************************************************
* ABKBoruvka
* ****************************************************
* Entrée : rien
* Nécessite : Rien
* Sortie : Un PGrapheOriente l'arbre couvrant minimal
* Entraîne : creation de l'arbre couvrant minimal a partir
* de l'algorithme Boruvka
* ****************************************************/

void CArbreBoruvka::ABKBoruvka() {
	unsigned int uiBoucle;
	PGrapheOriente<CArcPondere,CSommet<CArcPondere>>* pGROArbreCouvrant = new PGrapheOriente<CArcPondere,CSommet<CArcPondere>>();
	PGrapheOriente<CArcPondere, CSommet<CArcPondere>>* pGROArbreTravail = new PGrapheOriente<CArcPondere, CSommet<CArcPondere>>();
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
* Entrée : rien
* Nécessite : Rien
* Sortie : Un PGrapheOriente l'arbre sans arcs reflexif
* Entraîne : Un PGrapheOriente l'arbre sans arcs reflexif
* ****************************************************/
void CArbreBoruvka::ABKArbreNonReflexif() {
	unsigned int uiCompteur = 1; 
	unsigned int uiCompteurFixe = 0;
	auto iter = pGROABKGraphParam->GROLireSommet(0); // On met un iterateur sur le premier sommet de la list
	while (iter != pGROABKGraphParam->GROLireSommet(pGROABKGraphParam->GROLireTailleListSommet())) { // tant que le sommet n'est pas le dernier sommet de la list
		while (uiCompteurFixe < iter->SOMTaileListArcEntrant()) { //tant qu'on est pas à la fin du sommet du ses sommets entrants
			if (iter->SOMLireNom() == iter->SOMLireListSomEntrant()[uiCompteurFixe]){// il faut supprimer -> arc reflexible
				pGROABKGraphParam->GROSupprimerArc(iter->SOMLireNom(), iter->SOMLireNom());
			}
			else if (iter->SOMLireListSomEntrant()[uiCompteur] != iter->SOMLireListSomEntrant()[uiCompteurFixe]){
				uiCompteur++;
			}
			else {
				pGROABKGraphParam->GROSupprimerArc(iter->SOMLireNom(), iter->SOMLireListSomEntrant()[uiCompteurFixe]);
				uiCompteurFixe++;
			}
		}
	}
}