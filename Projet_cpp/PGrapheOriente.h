#ifndef __PGrapheOriente__
#define __PGrapheOriente__


#include <string>
#include <list>
#include "CSommet.h"
using namespace std;



/************************************************************
* CLASSE : Classe pour la gestion d' un Graphe Orient�
* ************************************************************
* ROLE : Interface de la classe PGrapheOriente,
* cette classe permet de generer un graphe orient�
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

/* VARIABLES :

*/
#define Element_inconnu 404


template<class T, class S>
class PGrapheOriente {
	//ATTRIBUTS
private:
	list<T*> pARCGROListArc;
	list<S*> pSOMGROListSom;


public:
	//Constructeurs
	/*****************************************************
	* PGrapheOriente
	* ****************************************************
	* Entr�e : Aucune
	* N�cessite : RIen
	* Sortie : Aucune
	* Entra�ne : Creation d'un objet PGrapheOriente
	* ****************************************************/
	PGrapheOriente();

	/*****************************************************
	* PGrapheOriente
	* ****************************************************
	* Entr�e : Aucune
	* N�cessite : RIen
	* Sortie : Aucune
	* Entra�ne : Creation d'un objet PGrapheOriente
	* ****************************************************/
	PGrapheOriente(PGrapheOriente<T,S>& GROTocopie);

	/*****************************************************
	* operator=
	* ****************************************************
	* Entr�e : Aucune
	* N�cessite : RIen
	* Sortie : Aucune
	* Entra�ne : Creation d'un objet PGrapheOriente
	* ****************************************************/
	void operator=(PGrapheOriente<T,S>& GROTocopie);



	/*****************************************************
	* Methodes de gestion des Arcs
	******************************************************/

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
	* GROLireTailleListSommet
	* ****************************************************
	* Entr�e : Aucune
	* N�cessite : Aucune
	* Sortie : size_t 
	* Entra�ne : Renvoie le nombre de sommet 
	* ****************************************************/
	inline size_t GROLireTailleListSommet() { return pSOMGROListSom.size(); }

	/*****************************************************
	* GROLireArc
	* ****************************************************
	* Entr�e : un size_t (qui correspond � la position de l'arc � lire)
	* N�cessite : Rien
	* Sortie : string
	* Entra�ne : (le nom des sommets de depart et d'arrive de notre arc avec la position stPos est retourn�e) OU (Exception Element_inconnu)
	* ****************************************************/
	T* GROLireArc(size_t stPos) const;




	/*****************************************************
	* GROLireTailleListArc
	* ****************************************************
	* Entr�e : Aucune
	* N�cessite : Rien
	* Sortie : un size_t
	* Entra�ne : la taille de ma liste des arcs
	* ****************************************************/
	size_t GROLireTailleListArc() const { return pARCGROListArc.size(); }



	/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommet de d�part) et une chaine de caractere ( nom du sommet d'arriv� de l'arc)
	* N�cessite : Rien
	* Sortie : Aucune
	* Entra�ne : (le sommet avec le nom chParam est supprim�) OU (Exception Element_inconnu)
	* ****************************************************/
	virtual void GROSupprimerArc(string chParamDepart, string chParamArrive);




	/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entr�e : Un sommet pour lequel on va supprimer tout les arcs qui pointent vers lui
	* N�cessite : Rien
	* Sortie : Aucune
	* Entra�ne : Un sommet isol� qui ne pointent vers personne et avec personne qui pointent sur lui
	* ****************************************************/
	void GROSupprimerArcs(S& SOMParam);



	/*****************************************************
	* Methodes de gestion des Sommets
	******************************************************/



	/*****************************************************
	* GROCreerSommet
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommet � creer)
	* N�cessite : Rien
	* Sortie : Aucune
	* Entra�ne : Il y a un sommet de plus dans la liste des sommets si le sommet est bien dans la liste
	* ****************************************************/
	void GROCreerSommet(string chParam);



	/*****************************************************
	* GROModifierSommet
	* ****************************************************
	* Entr�e : deux chaines de caracteres
	* N�cessite : Rien
	* Sortie : Aucune
	* Entra�ne : Il y a un sommet qui a chang� de nom
	* ****************************************************/
	void GROModifierSommet(string chParam, string chNvnom);



	/*****************************************************
	* GROTrouverSommet
	* ****************************************************
	* Entr�e : une chaine de caractere (nom du sommet � ajouter)
	* N�cessite : Rien
	* Sortie : size_t
	* Entra�ne : (la position du sommet avec le nom chParam est retourn�e) OU (Exception Element_inconnu)
	* ****************************************************/
	size_t GROTrouverSommetPosition(string chParam);

	


	/*****************************************************
	* GROLireTailleListSommet
	* ****************************************************
	* Entr�e : Aucune
	* N�cessite : Rien
	* Sortie : un size_t
	* Entra�ne : la taille de ma liste des sommets
	* ****************************************************/
	size_t GROLireTailleListSommet() const { return pSOMGROListSom.size(); }





	/*****************************************************
	* GROLireSommet
	* ****************************************************
	* Entr�e : un size_t (qui correspond � la position du sommet � lire)
	* N�cessite : Rien
	* Sortie : un pointeur vers un sommet
	* Entra�ne : (lenom du sommet avec la position sPos est retourn�e) OU (Exception Element_inconnu)
	* ****************************************************/
	S* GROLireSommet(size_t stPos) const;
	//ICI tu va devoir utiliser iterator car la surcharge de loperator [] nous parait pas petinante




	/*****************************************************
	* GROLireSommetSortantLie
	* ****************************************************
	* Entr�e : un string (qui correspond au nom du sommet � lire)
	* N�cessite : Rien
	* Sortie : vector<string>
	* Entra�ne : (le nom des sommet qui sont li� avec des arcs � notre sommet d'entr�) OU (Exception Element_inconnu)
	* ****************************************************/
	vector<string> GROLireSommetSortantLie(string chParam);


	/*****************************************************
	* GROLireSommetEntrantLie
	* ****************************************************
	* Entr�e : un string (qui correspond au nom du sommet � lire)
	* N�cessite : Rien
	* Sortie : vector<string>
	* Entra�ne : (le nom des sommet qui sont li� avec des arcs � notre sommet d'entr�) OU (Exception Element_inconnu)
	* ****************************************************/
	vector<string> GROLireSommetEntrantLie(string chParam);

	/*****************************************************
	* GROSupprimerSommet
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommer � supprimer)
	* N�cessite : Rien
	* Sortie : Aucune
	* Entra�ne : (le sommet avec le nom chParam est supprim�) OU (Exception Element_inconnu)
	* ****************************************************/
	void GROSupprimerSommet(string chParam);

	/*****************************************************
	* GRONombreSommet
	* ****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : le nombre de sommet
	* Entra�ne : le nombre de sommet est retourn�
	* ****************************************************/
	inline size_t GRONombreSommet() const { return pSOMGROListSom.size(); };


	/*****************************************************
	* GRONombreArc
	* ****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : le nombre de arc
	* Entra�ne : le nombre de arc est retourn�
	* ****************************************************/
	inline size_t GRONombreArc() const { return pARCGROListArc.size(); };





};
#endif