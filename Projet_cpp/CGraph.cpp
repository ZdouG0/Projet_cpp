#include "CGraph.h"




/*****************************************************
	* GROCreerArc
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommet de depart) et une deuxi�me chaine de caract�re (nom du sommet d'arriv�e)
	* N�cessite : La liste de CSommet contienne au moins deux elements et que les deux chaines de caract�res se r�f�rent bien � des sommets existants
	* Sortie : Aucune
	* Entra�ne : ( Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste) OU (Exception Element_inconnu)
	* Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste
	* De plus les deux sommets sont maintenant li� par un arc
	* ****************************************************/
void CGraph::GROCreerArc(string sParamDepart, string sParamArrive) {
	CGrapheOriente::GROCreerArc(sParamDepart, sParamArrive);
	CGrapheOriente::GROCreerArc(sParamArrive, sParamDepart);
}




/*****************************************************
* GROSupprimerArc
* ****************************************************
* Entr�e : une chaine de caractere ( nom du sommet de d�part) et une chaine de caractere ( nom du sommet d'arriv� de l'arc)
* N�cessite : Rien
* Sortie : Aucune
* Entra�ne : (le sommet avec le nom chParam est supprim�) OU (Exception Element_inconnu)
* ****************************************************/
void CGraph::GROSupprimerArc(string chParamDepart, string chParamArrive) {
	//Je vais devoir supprimer les deux arcs si bool = false lors de la suppression c'est que j'ai pas encore trouve le retour
	CGrapheOriente::GROSupprimerArc(chParamDepart, chParamArrive);
	CGrapheOriente::GROSupprimerArc(chParamArrive, chParamDepart);
}