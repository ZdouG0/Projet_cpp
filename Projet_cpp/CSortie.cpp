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
	pGROSORGraphe = nullptr;
}


/*****************************************************
* CSortie
* ****************************************************
* Entrée : un objet de la Classe CSortie passe par valeur
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'objet en parametre est recopié
* ****************************************************/
CSortie :: CSortie(CSortie& SortieParam) {
	pGROSORGraphe = new CGrapheOriente(*SortieParam.pGROSORGraphe);
}

/*****************************************************
* operator=
* ****************************************************
* Entrée : un objet de la Classe CSortie passe par valeur
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'objet en parametre est recopié
* ****************************************************/
void CSortie::operator=(CSortie& SortieParam) {
	pGROSORGraphe = new CGrapheOriente(*SortieParam.pGROSORGraphe);
}


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
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreSommet; uiBoucle++) {   // on parcourt les sommets de notre graphe
		SOMTemp = pGROSORGraphe->GROLireSommet(uiBoucle);   // on mets dans une variable temporaire un Sommet pour travailler dessus
		cout << "****************************" << " Information sur le sommet " << SOMTemp->SOMLireNom() << " *****************************" << endl;
		cout << "Sommet sortant : " << endl;
		vListeNomSommet = SOMTemp->SOMLireListSomSortant();   // on recupere la liste des sommet sortant 
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < vListeNomSommet.size(); uiBoucle2++) {  // on parcout la liste creer precedement
			cout << SOMTemp->SOMLireNom() << "-->" << vListeNomSommet[uiBoucle2] << endl;   //on affiche les sommets sortant
		}
		cout << "___________________________________________________" << endl;
		cout << "Sommet entrant : " << endl;
		vListeNomSommet = SOMTemp->SOMLireListSomEntrant();  // on recupere la liste des sommets entrant 
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < vListeNomSommet.size(); uiBoucle2++) { // on parcourt la liste
			cout << SOMTemp->SOMLireNom() << "<--" << vListeNomSommet[uiBoucle2] << endl; // et on affiche en suivant le formalisme voulu
		}
	}

}