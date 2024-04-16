#include "CSortie.h"


/*****************************************************
* CSortie
* ****************************************************
* Entr�e : Rien
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : Un objet de la classe CSortie est construit
* ****************************************************/
CSortie :: CSortie() {
	pGROSORGraphe = new CGrapheOriente;
}


/*****************************************************
* CSortie
* ****************************************************
* Entr�e : un objet de la Classe CSortie passe par valeur
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : L'objet en parametre est recopi�
* ****************************************************/
/*
CSortie :: CSortie(CSortie& SortieParam) {
	pGROSORGraphe = new CGrapheOriente(SortieParam.pGROSORGraphe);
}
*/

/*****************************************************
* SORAfficher_Graphe
* ****************************************************
* Entr�e : Rien
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : Notre Graphe est affiche
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