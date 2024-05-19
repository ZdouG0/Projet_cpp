#ifndef __PGRAPH__
#define __PGRAPH__

#include <string>
#include <list>
#include "PGrapheOriente.h"

using namespace std;

/************************************************************
* CLASSE : Classe pour la gestion d'un Graphe NON Orient�
* ************************************************************
* ROLE : Interface de la classe CGraphe,
* cette classe permet de g�n�rer un graphe orient� mais avec tous les arcs r�versibles
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
    * Entr�e : une cha�ne de caract�res (nom du sommet de d�part) et une deuxi�me cha�ne de caract�res (nom du sommet d'arriv�e)
    * N�cessite : La liste de CSommet contient au moins deux �l�ments et que les deux cha�nes de caract�res se r�f�rent bien � des sommets existants
    * Sortie : Aucune
    * Entra�ne : (Il y a un arc de plus dans la liste des arcs si les sommets sont bien dans la liste) OU (Exception Element_inconnu)
    * De plus les deux sommets sont maintenant li�s par un arc
    * ****************************************************/
    void GROCreerArc(string sParamDepart, string sParamArrive);
    void GROCreerArc(string sParamDepart, string sParamArrive, unsigned int uiPoids = 0);

    /*****************************************************
    * GROSupprimerArc
    * ****************************************************
    * Entr�e : une cha�ne de caract�res (nom du sommet de d�part) et une cha�ne de caract�res (nom du sommet d'arriv�e de l'arc)
    * N�cessite : Rien
    * Sortie : Aucune
    * Entra�ne : (le sommet avec le nom chParam est supprim�) OU (Exception Element_inconnu)
    * ****************************************************/
    void GROSupprimerArc(string chParamDepart, string chParamArrive);

    /*****************************************************
    * GROArbreNonReflexif
    * ****************************************************
    * Entr�e : rien
    * N�cessite : Rien
    * Sortie : Un PGraph l'arbre sans arcs r�flexifs
    * Entra�ne : Un PGraph l'arbre sans arcs r�flexifs
    * ****************************************************/
    void GROArbreNonReflexif();





};



#endif // __PGRAPH__
