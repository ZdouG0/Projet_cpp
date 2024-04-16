#include "CSortie.h"


/*****************************************************
* CSortie
* ****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Un objet de la classe CSortie est construit
* ****************************************************/
CSortie :: CSortie() {
	pGROSORGraphe = new CGrapheOriente;
}


/*****************************************************
* CSortie
* ****************************************************
* Entrée : un objet de la Classe CSortie passe par valeur
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'objet en parametre est recopié
* ****************************************************/
/*
CSortie :: CSortie(CSortie& SortieParam) {
	pGROSORGraphe = new CGrapheOriente(SortieParam.pGROSORGraphe);
}
*/

/*****************************************************
* SORAfficher_Graphe
* ****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Notre Graphe est affiche
* ****************************************************/
void CSortie :: SORAfficher_Graphe() {
	CSommet* SOMTemp;
	vector<string> vListeNomSommet;
	size_t uiNombreSommet = pGROSORGraphe->GRONombreSommet();
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreSommet; uiBoucle++) {
		SOMTemp = pGROSORGraphe->GROLireSommet(uiBoucle);
		vListeNomSommet = SOMTemp->SOMLireListSomSortant();
		for (unsigned int uiBoucle2 = 0; uiBoucle < vListeNomSommet.size(); uiBoucle2++) {
			cout << SOMTemp->SOMLireNom() << "->" << vListeNomSommet[uiBoucle2] << endl;
		}
	}

}