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
	pGROABKGraphParam = new PGraph<CArcPondere,PSommet<CArcPondere>>(*ABKParam.pGROABKGraphParam);
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
	pGROABKGraphParam = new PGraph<CArcPondere, PSommet<CArcPondere>>(*ABKParam.pGROABKGraphParam);
}


/*****************************************************
* ABKMinPoids
* ****************************************************
* Entrée : rien
* Nécessite : Rien
* Sortie : Un PGraph l'arbe couvrant minimal
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
* Sortie : Un PGraph l'arbre couvrant minimal
* Entraîne : creation de l'arbre couvrant minimal a partir
* de l'algorithme Boruvka
* ****************************************************/

void CArbreBoruvka::ABKBoruvka() {
	unsigned int uiBoucle;
	PGraph<CArcPondere,PSommet<CArcPondere>>* pGROArbreCouvrant = new PGraph<CArcPondere,PSommet<CArcPondere>>();
	PGraph<CArcPondere, PSommet<CArcPondere>>* pGROArbreTravail = new PGraph<CArcPondere, PSommet<CArcPondere>>();
	while (pGROArbreTravail->GRONombreSommet() > 1) {
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
* Sortie : Un PGraph l'arbre sans arcs reflexif
* Entraîne : Un PGraph l'arbre sans arcs reflexif
* ****************************************************/
void CArbreBoruvka::ABKArbreNonReflexif() {
	unsigned int uiCompteurIter = 0;
	unsigned int uiCompteurIter2 = 2;
	auto iter = pGROABKGraphParam->GROLireArc(uiCompteurIter);
	auto iter2 = pGROABKGraphParam->GROLireArc(uiCompteurIter2);
	while (uiCompteurIter < pGROABKGraphParam->GROLireTailleListArc() - 2) {
		if (iter->ARCLireArrive() == iter->ARCLireDepart()) { // ArcRefelxible oblige de mettre iter et iter2 au cas ou premier (iter) ou dernier (iter2)
			
			string sParam1 = iter->ARCLireDepart();
			uiCompteurIter2 += 1;
			iter2 = pGROABKGraphParam->GROLireArc(uiCompteurIter2);
			pGROABKGraphParam->GROSupprimerArc(sParam1, sParam1);
		}
		else if (iter->ARCLireDepart() == iter2->ARCLireDepart()) {
			if (iter->ARCLireArrive() == iter2->ARCLireArrive()) { // il faut supprimer
				string sParam1 = iter->ARCLireDepart(); string sParam2 = iter->ARCLireArrive();
				try {
					pGROABKGraphParam->GROSupprimerArc(sParam1, sParam2); // si jmais 3 pareil, pas d'augmentation , je suppr tout d'un coup
					//defaut je vais mm suppr le dernier que je rajt a la main ici
				}
				catch (CException EXCErreur) {
					uiCompteurIter2++;
					iter2 = pGROABKGraphParam->GROLireArc(uiCompteurIter2);
					pGROABKGraphParam->GROCreerArc(iter->ARCLireDepart(), iter->ARCLireArrive()); //ici
				}
			}
			else { //ils sont differents
				if (uiCompteurIter2 < pGROABKGraphParam->GROLireTailleListSommet() - 1) {
					uiCompteurIter2++;
					iter2 = pGROABKGraphParam->GROLireArc(uiCompteurIter2);
				}
				else {
					uiCompteurIter ++; //car cgraph
					uiCompteurIter2 = uiCompteurIter + 1;
					iter = pGROABKGraphParam->GROLireArc(uiCompteurIter);
					iter2 = pGROABKGraphParam->GROLireArc(uiCompteurIter2);
				}
			}
		}
		else { //ils sont differents
			if (uiCompteurIter2 < pGROABKGraphParam->GROLireTailleListSommet() - 1) {
				uiCompteurIter2++;
				iter2 = pGROABKGraphParam->GROLireArc(uiCompteurIter2);
			}
			else {
				uiCompteurIter ++ ; //car cgraph
				uiCompteurIter2 = uiCompteurIter + 1;
				iter = pGROABKGraphParam->GROLireArc(uiCompteurIter);
				iter2 = pGROABKGraphParam->GROLireArc(uiCompteurIter2);
			}
		}
	}
}


				

