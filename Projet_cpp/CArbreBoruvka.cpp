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

PGrapheOriente<CArcPondere,PSommet<CArcPondere>>* CArbreBoruvka::ABKBoruvka() {
	unsigned int uiBoucle;
	PSommet<CArcPondere > *pSOMTemp;
	list<CArcPondere*> lARCTemp;
	CArcPondere* pARCMin;
	string NomSommetDepart;
	string NomSommetArrivee;
	list<PSommet<CArcPondere>*> lSOMAgregeDepart;
	list<PSommet<CArcPondere>*> lSOMAgregeArrivee;
	PGrapheOriente<CArcPondere, PSommet<CArcPondere>>* pGROArbreCouvrant = new PGrapheOriente<CArcPondere, PSommet<CArcPondere>>();
	PGrapheOriente<CArcPondere, PSommet<CArcPondere>>* pGROGrapheTravail = new PGrapheOriente<CArcPondere, PSommet<CArcPondere>>(*pGROABKGraphParam);
	while (pGROGrapheTravail->GRONombreSommet() > 1) {
		//elimination arc reflexif et multiple

		for (uiBoucle = 0; uiBoucle < pGROGrapheTravail->GRONombreSommet(); uiBoucle++) {

			//Partie Trouver Arc Minimum

			pSOMTemp = pGROGrapheTravail->GROLireSommet(uiBoucle);  //on recupere un sommet contenu dans le graphe de travail
			for (unsigned int uiBoucle2 = 0; uiBoucle2 < pSOMTemp->SOMTaileListArcSortant(); uiBoucle2++) {
				lARCTemp.push_back(pSOMTemp->SOMLireElemListArcEntrant(uiBoucle2)); // creation de la liste des Arc sortant d'un sommet.
			}
			pARCMin = ABKMinPoids(lARCTemp);  // on recupere l'arc de poids minimal de la liste
			

			//Partie ajouter decouverte dans L'arbre

			
			lSOMAgregeDepart = pGROABKGraphParam->GRODecomposeNom(pARCMin->ARCLireDepart());  // on decompose sans distinction les sommets
			lSOMAgregeArrivee = pGROABKGraphParam->GRODecomposeNom(pARCMin->ARCLireArrive());

			for (PSommet<CArcPondere>* SomDepart : lSOMAgregeDepart) {
				for (PSommet<CArcPondere>* SomArrive : lSOMAgregeArrivee) {
					unsigned int uiIndice = pGROABKGraphParam->GROTrouverSommetPosition(SomArrive->SOMLireNom());
					PSommet<CArcPondere>* SOMTemp = pGROABKGraphParam->GROLireSommet(uiIndice);   //ces deux lignes permettent de recuperer notre Sommet d'arrivée dans le graphe d'origine
					for (unsigned int uiBoucle2 = 0; uiBoucle2 < SOMTemp->SOMTaileListArcEntrant();uiBoucle2++){
						CArcPondere* pARCEntrantTemp = SOMTemp->SOMLireElemListArcEntrant(uiBoucle2);
						if (pARCEntrantTemp->ARCLireDepart() == SomDepart->SOMLireNom() && pARCEntrantTemp->ARCLirePoids() == pARCMin->ARCLirePoids()) {
							NomSommetDepart = pARCEntrantTemp->ARCLireDepart();
							NomSommetArrivee  = pARCEntrantTemp->ARCLireArrive();
							
						}
					}
				}
			}
			unsigned int uiIndice = pGROABKGraphParam->GROTrouverSommetPosition(NomSommetDepart);
			PSommet<CArcPondere>* SomDepart = pGROABKGraphParam->GROLireSommet(uiIndice);   //ces deux lignes permettent de recuperer notre Sommet de depart avant agregation
			
			 uiIndice = pGROABKGraphParam->GROTrouverSommetPosition(NomSommetArrivee);
			PSommet<CArcPondere>* SomArrivee = pGROABKGraphParam->GROLireSommet(uiIndice);   //ces deux lignes permettent de recuperer notre Sommet d'arrivee avant agregation
			
			if (pGROArbreCouvrant->GROSommetPresent(SomDepart->SOMLireNom()) == false) {
				pGROArbreCouvrant->GROCreerSommet(SomDepart->SOMLireNom());
			}
			if (pGROArbreCouvrant->GROSommetPresent(SomArrivee->SOMLireNom()) == false) {
				pGROArbreCouvrant->GROCreerSommet(SomArrivee->SOMLireNom());
			}
			pGROArbreCouvrant->GROCreerArc(SomDepart->SOMLireNom(), SomArrivee->SOMLireNom());

			
			//Partie Fusion 
			
			//fusion dans le graphe de travail
			//objectif fusionner les arbre

			// suppression de l'arc min dans le graphe de travail
			pGROGrapheTravail->GROSupprimerArc(pARCMin->ARCLireDepart(), pARCMin->ARCLireArrive());

			//creation du nouveau sommet agrege dans le graphe de travail
			string sNvNom = pARCMin->ARCLireArrive() + pARCMin->ARCLireDepart();
			pGROGrapheTravail->GROCreerSommet(sNvNom);
			

			uiIndice = pGROABKGraphParam->GROTrouverSommetPosition(sNvNom);
			PSommet<CArcPondere>* SOMnvSommet = pGROABKGraphParam->GROLireSommet(uiIndice);

			//regroupement des arcs entrant des deux sommet (resp. sortant)
			for (unsigned int uiBoucle3 = 0; uiBoucle3 < pGROGrapheTravail->GROLireTailleListArc(); uiBoucle3++) { //on parcourt la liste des arcs de notre Graphe de travail
				CArcPondere* ArcTempTravail = pGROABKGraphParam->GROLireArc(uiBoucle3);
				//si l'arrivée d'un des arc est l'un de nos sommet avant agragation alors
				if (ArcTempTravail->ARCLireArrive() == pARCMin->ARCLireArrive() || ArcTempTravail->ARCLireArrive() == pARCMin->ARCLireDepart()) {
					ArcTempTravail->ARCModifierSommetArrive(sNvNom); // on modifie son nom pour le nom agreger
					SOMnvSommet->SOMAjoutArcSortant(ArcTempTravail); // on l'ajoute dans notre Sommet
				}
				if (ArcTempTravail->ARCLireDepart() == pARCMin->ARCLireArrive() || ArcTempTravail->ARCLireDepart() == pARCMin->ARCLireDepart()) {
					ArcTempTravail->ARCModifierSommetArrive(sNvNom); // on modifie son nom pour le nom agreger
					SOMnvSommet->SOMAjoutArcEntrant(ArcTempTravail); // on l'ajoute dans notre Sommet
				}
			}

			
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


				

