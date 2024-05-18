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

PGrapheOriente<CArcPondere,PSommet<CArcPondere>>* CArbreBoruvka::ABKBoruvka() {
	unsigned int uiBoucle;
	PSommet<CArcPondere > *pSOMTemp;
	list<CArcPondere*> lARCTemp;
	CArcPondere* pARCMin;
	PGrapheOriente<CArcPondere, PSommet<CArcPondere>>* pGROArbreCouvrant = new PGrapheOriente<CArcPondere, PSommet<CArcPondere>>();
	PGrapheOriente<CArcPondere, PSommet<CArcPondere>>* pGROGrapheTravail = new PGrapheOriente<CArcPondere, PSommet<CArcPondere>>(*pGROABKGraphParam);
	while (pGROGrapheTravail->GRONombreSommet() > 1) {
		//elimination arc reflexif et multiple
		for (uiBoucle = 0; uiBoucle < pGROGrapheTravail->GRONombreSommet(); uiBoucle++) {
			pSOMTemp = pGROGrapheTravail->GROLireSommet(uiBoucle);  //on recupere un sommet contenu dans le graphe de travail
			for (unsigned int uiBoucle2 = 0; uiBoucle2 < pSOMTemp->SOMTaileListArcSortant(); uiBoucle2++) {
				lARCTemp.push_back(pSOMTemp->SOMLireElemListArcEntrant(uiBoucle2)); // creation de la liste des Arc sortant d'un sommet.
			}
			pARCMin = ABKMinPoids(lARCTemp);  // on recupere l'arc de poids minimal de la liste

			//objectif determiner si les sommet de cette arc sont une agregation de sommet, un sommet unique present de le graphe initial
			// on verifie l'existence des sommets de depart et d'arrivee dans le graphe initial
			if (pGROABKGraphParam->GROSommetPresent(pARCMin->ARCLireArrive()) == false) {  // on verifie si notre sommet est un sommet agregé si oui on le decompose
				//fonction de decomposition du nom
				// en cours de creation dans PGrapheOriente
			}
			else if (pGROArbreCouvrant->GROSommetPresent(pARCMin->ARCLireArrive()) == false) {
				pGROArbreCouvrant->GROCreerSommet(pARCMin->ARCLireArrive()); // faux a developper encore
			}
			
			//fusion dans le graphe de travail
			//objectif fusionner les arbre
			
		}
	}
}

