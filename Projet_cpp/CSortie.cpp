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
* ~CSortie
* ****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : destruction de l'instance
* ****************************************************/
CSortie :: ~CSortie() {
	unsigned int uiBoucle_arc;
	unsigned int uiBoucle_som;
	for (uiBoucle_arc = 0; uiBoucle_arc < pGROSORGraphe->GROLireTailleListArc(); uiBoucle_arc++) {  // cette boucle permet de copier notre graphe en attributs mais prové des arcs
		delete pGROSORGraphe->GROLireArc(uiBoucle_arc);
	}
	for (uiBoucle_som= 0; uiBoucle_som < pGROSORGraphe->GROLireTailleListSommet(); uiBoucle_som++) {  // cette boucle permet de copier notre graphe en attributs mais prové des arcs
		delete pGROSORGraphe->GROLireSommet(uiBoucle_som);
	}
	delete pGROSORGraphe;
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
	PSommet<CArc>* SOMTemp;
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