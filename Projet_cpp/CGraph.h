#ifndef __CGRAPH__
#define __CGRAPH__					



#include <string>
#include <list>
#include "CGrapheOriente.h"
using namespace std;



/************************************************************
* CLASSE : Classe pour la gestion d' un Graphe  NON Orient�
* ************************************************************
* ROLE : Interface de la classe CGraphe,
* cette classe permet de generer un graphe orient� mais avec tout les arcs reversibles
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI / Milan HERGOTT
* DATE : 22/03/2024
* ************************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES :
*  pas de types particulier de d�clar�
*/




class CGraph : public CGrapheOriente {



	/*****************************************************
	* GROCreerArc
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommet de depart) et une deuxi�me chaine de caract�re (nom du sommet d'arriv�e)
	* N�cessite : La liste de CSommet contienne au moins deux elements et que les deux chaines de caract�res se r�f�rent bien � des sommets existants
	* Sortie : Aucune
	* Entra�ne : Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste
	* De plus les deux sommets sont maintenant li� par un arc
	* ****************************************************/
	virtual void GROCreerArc(string chParamDepart, string chParamArrive);




	/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommet de d�part) et une chaine de caractere ( nom du sommet d'arriv� de l'arc)
	* N�cessite : Rien
	* Sortie : Aucune
	* Entra�ne : (le sommet avec le nom chParam est supprim�) OU (Exception Element_inconnu)
	* ****************************************************/
	virtual void GROSupprimerArc(string chParamDepart, string chParamArrive);
};
#endif