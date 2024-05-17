#ifndef __PGRAPH__
#define __PGRAPH__					



#include <string>
#include <list>
#include "PGrapheOriente.h"
using namespace std;



/************************************************************
* CLASSE : Classe pour la gestion d' un Graphe  NON Orienté
* ************************************************************
* ROLE : Interface de la classe CGraphe,
* cette classe permet de generer un graphe orienté mais avec tout les arcs reversibles
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI / Milan HERGOTT
* DATE : 22/03/2024
* ************************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES :
*  pas de types particulier de déclaré
*/




template<class T,class S>
class PGraph : public PGrapheOriente<T,S> {



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
	void GROCreerArc(string sParamDepart, string sParamArrive) {
		PGrapheOriente<T>::GROCreerArc(sParamDepart, sParamArrive);
		PGrapheOriente<T>::GROCreerArc(sParamArrive, sParamDepart);
	}





	/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entrée : une chaine de caractere ( nom du sommet de départ) et une chaine de caractere ( nom du sommet d'arrivé de l'arc)
	* Nécessite : Rien
	* Sortie : Aucune
	* Entraîne : (le sommet avec le nom chParam est supprimé) OU (Exception Element_inconnu)
	* ****************************************************/
	void GROSupprimerArc(string chParamDepart, string chParamArrive) {
		//Je vais devoir supprimer les deux arcs si bool = false lors de la suppression c'est que j'ai pas encore trouve le retour
		PGrapheOriente<T>::GROSupprimerArc(chParamDepart, chParamArrive);
		PGrapheOriente<T>::GROSupprimerArc(chParamArrive, chParamDepart);
	}
};

#endif