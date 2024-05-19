#ifndef __PGRAPH__
#define __PGRAPH__

#include <string>
#include <list>
#include "PGrapheOriente.h"

using namespace std;

/************************************************************
* CLASSE : Classe pour la gestion d'un Graphe NON Orienté
* ************************************************************
* ROLE : Interface de la classe CGraphe,
* cette classe permet de générer un graphe orienté mais avec tous les arcs réversibles
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI / Milan HERGOTT
* DATE : 22/03/2024
* ************************************************************
* INCLUSIONS EXTERNES :
*/

template<class T, class S>
class PGraph : public PGrapheOriente<T, S> {
public:
    /*****************************************************
    * GROCreerArc
    * ****************************************************
    * Entrée : une chaîne de caractères (nom du sommet de départ) et une deuxième chaîne de caractères (nom du sommet d'arrivée)
    * Nécessite : La liste de CSommet contient au moins deux éléments et que les deux chaînes de caractères se réfèrent bien à des sommets existants
    * Sortie : Aucune
    * Entraîne : (Il y a un arc de plus dans la liste des arcs si les sommets sont bien dans la liste) OU (Exception Element_inconnu)
    * De plus les deux sommets sont maintenant liés par un arc
    * ****************************************************/
    void GROCreerArc(string sParamDepart, string sParamArrive);
    void GROCreerArc(string sParamDepart, string sParamArrive, unsigned int uiPoids = 0);

    /*****************************************************
    * GROSupprimerArc
    * ****************************************************
    * Entrée : une chaîne de caractères (nom du sommet de départ) et une chaîne de caractères (nom du sommet d'arrivée de l'arc)
    * Nécessite : Rien
    * Sortie : Aucune
    * Entraîne : (le sommet avec le nom chParam est supprimé) OU (Exception Element_inconnu)
    * ****************************************************/
    void GROSupprimerArc(string chParamDepart, string chParamArrive);

    /*****************************************************
    * GROArbreNonReflexif
    * ****************************************************
    * Entrée : rien
    * Nécessite : Rien
    * Sortie : Un PGraph l'arbre sans arcs réflexifs
    * Entraîne : Un PGraph l'arbre sans arcs réflexifs
    * ****************************************************/
    void GROArbreNonReflexif();





};



#endif // __PGRAPH__
