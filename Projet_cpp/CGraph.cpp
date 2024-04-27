#include "CGraph.h"




/*****************************************************
	* GROCreerArc
	* ****************************************************
	* Entrée : une chaine de caractere ( nom du sommet de depart) et une deuxième chaine de caractère (nom du sommet d'arrivée)
	* Nécessite : La liste de CSommet contienne au moins deux elements et que les deux chaines de caractères se réfèrent bien à des sommets existants
	* Sortie : Aucune
	* Entraîne : ( Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste) OU (Exception Element_inconnu)
	* Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste
	* De plus les deux sommets sont maintenant lié par un arc
	* ****************************************************/
void CGraph::GROCreerArc(string sParamDepart, string sParamArrive) {
	CGrapheOriente::GROCreerArc(sParamDepart, sParamArrive);
	CGrapheOriente::GROCreerArc(sParamArrive, sParamDepart);
}




/*****************************************************
* GROSupprimerArc
* ****************************************************
* Entrée : une chaine de caractere ( nom du sommet de départ) et une chaine de caractere ( nom du sommet d'arrivé de l'arc)
* Nécessite : Rien
* Sortie : Aucune
* Entraîne : (le sommet avec le nom chParam est supprimé) OU (Exception Element_inconnu)
* ****************************************************/
void CGraph::GROSupprimerArc(string chParamDepart, string chParamArrive) {
	//Je vais devoir supprimer les deux arcs si bool = false lors de la suppression c'est que j'ai pas encore trouve le retour
	CGrapheOriente::GROSupprimerArc(chParamDepart, chParamArrive);
	CGrapheOriente::GROSupprimerArc(chParamArrive, chParamDepart);
}