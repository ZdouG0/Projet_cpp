#ifndef __CGrapheOriente__
#define __CGrapheOriente__


#include <string>
#include <list>
#include "CSommet.h"
using namespace std;



/************************************************************
* CLASSE : Classe pour la gestion d' un Graphe Orienté
* ************************************************************
* ROLE : Interface de la classe CGrapheOriente,
* cette classe permet de generer un graphe orienté
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

/* VARIABLES :

*/
#define Element_inconnu 404

class CGrapheOriente {
	//ATTRIBUTS
private:
	list<CArc*> pARCGROListArc;
	list<CSommet*> pSOMGROListSom;


public:
	//Constructeurs
	/*****************************************************
	* CGrapheOriente
	* ****************************************************
	* Entrée : Aucune
	* Nécessite : RIen
	* Sortie : Aucune
	* Entraîne : Creation d'un objet CGrapheOriente
	* ****************************************************/
	CGrapheOriente();

	/*****************************************************
	* CGrapheOriente
	* ****************************************************
	* Entrée : Aucune
	* Nécessite : RIen
	* Sortie : Aucune
	* Entraîne : Creation d'un objet CGrapheOriente
	* ****************************************************/
	CGrapheOriente(CGrapheOriente& GROTocopie);





	/*****************************************************
	* Methodes de gestion des Arcs
	******************************************************/

	/*****************************************************
	* GROCreerArc
	* ****************************************************
	* Entrée : une chaine de caractere ( nom du sommet de depart) et une deuxième chaine de caractère (nom du sommet d'arrivée)
	* Nécessite : La liste de CSommet contienne au moins deux elements et que les deux chaines de caractères se réfèrent bien à des sommets existants
	* Sortie : Aucune
	* Entraîne : Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste
	* De plus les deux sommets sont maintenant lié par un arc
	* ****************************************************/
	void GROCreerArc(string chParamDepart, string chParamArrive);

	inline size_t GROLireTailleListSommet() { return pSOMGROListSom.size(); }

	/*****************************************************
	* GROLireArc
	* ****************************************************
	* Entrée : un size_t (qui correspond à la position de l'arc à lire)
	* Nécessite : Rien
	* Sortie : string
	* Entraîne : (le nom des sommets de depart et d'arrive de notre arc avec la position stPos est retournée) OU (Exception Element_inconnu)
	* ****************************************************/
	CArc* GROLireArc(size_t stPos) const;




	/*****************************************************
	* GROLireTailleListArc
	* ****************************************************
	* Entrée : Aucune
	* Nécessite : Rien
	* Sortie : un size_t
	* Entraîne : la taille de ma liste des arcs
	* ****************************************************/
	size_t GROLireTailleListArc() const { return pARCGROListArc.size(); }



	/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entrée : une chaine de caractere ( nom du sommet de départ) et une chaine de caractere ( nom du sommet d'arrivé de l'arc)
	* Nécessite : Rien
	* Sortie : Aucune
	* Entraîne : (le sommet avec le nom chParam est supprimé) OU (Exception Element_inconnu)
	* ****************************************************/
	void GROSupprimerArc(string chParamDepart, string chParamArrive);




	/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entrée : Un sommet pour lequel on va supprimer tout les arcs qui pointent vers lui
	* Nécessite : Rien
	* Sortie : Aucune
	* Entraîne : Un sommet isolé qui ne pointent vers personne et avec personne qui pointent sur lui
	* ****************************************************/
	void GROSupprimerArcs(CSommet& SOMParam);

	/*****************************************************
	* Methodes de gestion des Sommets
	******************************************************/

	/*****************************************************
	* GROCreerSommet
	* ****************************************************
	* Entrée : une chaine de caractere ( nom du sommet à creer)
	* Nécessite : Rien
	* Sortie : Aucune
	* Entraîne : Il y a un sommet de plus dans la liste des sommets si le sommet est bien dans la liste
	* ****************************************************/
	void GROCreerSommet(string chParam);

	/*****************************************************
	* GROTrouverSommet
	* ****************************************************
	* Entrée : une chaine de caractere (nom du sommet à ajouter)
	* Nécessite : Rien
	* Sortie : size_t
	* Entraîne : (la position du sommet avec le nom chParam est retournée) OU (Exception Element_inconnu)
	* ****************************************************/
	size_t GROTrouverSommetPosition(string chParam);



	/*****************************************************
	* GROLireTailleListSommet
	* ****************************************************
	* Entrée : Aucune
	* Nécessite : Rien
	* Sortie : un size_t
	* Entraîne : la taille de ma liste des sommets
	* ****************************************************/
	size_t GROLireTailleListSommet() const { return pSOMGROListSom.size(); }


	/*****************************************************
	* GROLireSommet
	* ****************************************************
	* Entrée : un size_t (qui correspond à la position du sommet à lire)
	* Nécessite : Rien
	* Sortie : un pointeur vers un sommet
	* Entraîne : (lenom du sommet avec la position sPos est retournée) OU (Exception Element_inconnu)
	* ****************************************************/
	CSommet* GROLireSommet(size_t stPos) const;
	//ICI tu va devoir utiliser iterator car la surcharge de loperator [] nous parait pas petinante




/*****************************************************
	* GROLireSommetSortantLie
	* ****************************************************
	* Entrée : un string (qui correspond au nom du sommet à lire)
	* Nécessite : Rien
	* Sortie : vector<string>
	* Entraîne : (le nom des sommet qui sont lié avec des arcs à notre sommet d'entré) OU (Exception Element_inconnu)
	* ****************************************************/
	vector<string> GROLireSommetSortantLie(string chParam);


	/*****************************************************
	* GROLireSommetEntrantLie
	* ****************************************************
	* Entrée : un string (qui correspond au nom du sommet à lire)
	* Nécessite : Rien
	* Sortie : vector<string>
	* Entraîne : (le nom des sommet qui sont lié avec des arcs à notre sommet d'entré) OU (Exception Element_inconnu)
	* ****************************************************/
	vector<string> GROLireSommetEntrantLie(string chParam);

	/*****************************************************
	* GROSupprimerSommet
	* ****************************************************
	* Entrée : une chaine de caractere ( nom du sommer à supprimer)
	* Nécessite : Rien
	* Sortie : Aucune
	* Entraîne : (le sommet avec le nom chParam est supprimé) OU (Exception Element_inconnu)
	* ****************************************************/
	void GROSupprimerSommet(string chParam);

	/*****************************************************
	* GRONombreSommet
	* ****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : le nombre de sommet
	* Entraîne : le nombre de sommet est retourné
	* ****************************************************/
	inline size_t GRONombreSommet() const { return pSOMGROListSom.size(); };


	/*****************************************************
	* GRONombreArc
	* ****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : le nombre de arc
	* Entraîne : le nombre de arc est retourné
	* ****************************************************/
	inline size_t GRONombreArc() const { return pARCGROListArc.size(); };





};
#endif