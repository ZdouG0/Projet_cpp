#ifndef __PGRAPH__
#define __PGRAPH__

#include <string>
#include <list>
#include "PGrapheOriente.h"
#include "CException.h"
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
    * Il y a un arc de plus dans la liste des arcs si les sommets sont bien dans la liste
    * De plus les deux sommets sont maintenant liés par un arc
    * ****************************************************/
    void GROCreerArc(string sParamDepart, string sParamArrive) {
        PGrapheOriente<T, S>::GROCreerArc(sParamDepart, sParamArrive);
        PGrapheOriente<T, S>::GROCreerArc(sParamArrive, sParamDepart);
    }

    void GROCreerArc(string sParamDepart, string sParamArrive, unsigned int uiPoids) {
        PGrapheOriente<T, S>::GROCreerArc(sParamDepart, sParamArrive, uiPoids);
        PGrapheOriente<T, S>::GROCreerArc(sParamArrive, sParamDepart, uiPoids);
    }

    /*****************************************************
    * GROSupprimerArc
    * ****************************************************
    * Entrée : une chaîne de caractères (nom du sommet de départ) et une chaîne de caractères (nom du sommet d'arrivée de l'arc)
    * Nécessite : Rien
    * Sortie : Aucune
    * Entraîne : (le sommet avec le nom chParam est supprimé) OU (Exception Element_inconnu)
    * ****************************************************/
    void GROSupprimerArc(string chParamDepart, string chParamArrive) {
        // Je vais devoir supprimer les deux arcs si bool = false lors de la suppression c'est que je n'ai pas encore trouvé le retour
        PGrapheOriente<T, S>::GROSupprimerArc(chParamDepart, chParamArrive);
        PGrapheOriente<T, S>::GROSupprimerArc(chParamArrive, chParamDepart);
    }

    /*****************************************************
    * GROArbreNonReflexif
    * ****************************************************
    * Entrée : Aucune
    * Nécessite : Rien
    * Sortie : Un Arbre avec au plus une liaison entre deux sommets et sans arc réflexif
    * Entraîne :
    * ****************************************************/
    void GROArbreNonReflexif() {
        unsigned int uiCompteurIter = 0;
        unsigned int uiCompteurIter2 = 2;
        unsigned int uiMin;
        unsigned int uiMax = 0;
        auto iter = this->GROLireArc(uiCompteurIter);
        auto iter2 = this->GROLireArc(uiCompteurIter2);

        while (uiCompteurIter < this->GROLireTailleListArc() - 2) {
            if (iter->ARCLireArrive() == iter->ARCLireDepart()) {
                std::string sParam1 = iter->ARCLireDepart();
                uiCompteurIter2 += 1;
                uiMin = iter->PGrapheOriente<T, S>::LirePoids();
                if (uiMin > uiMax) {
                    uiMax = uiMin;
                }
                iter2 = this->GROLireArc(uiCompteurIter2);
                this->GROSupprimerArc(sParam1, sParam1, uiMax);
            }
            else if (iter->ARCLireDepart() == iter2->ARCLireDepart()) {
                if (iter->ARCLireArrive() == iter2->ARCLireArrive()) {
                    std::string sParam1 = iter->ARCLireDepart();
                    std::string sParam2 = iter->ARCLireArrive();
                    if (uiMax < uiMin) {
                        uiMin = uiMax;
                    }
                    try {
                        uiMax = iter->PGrapheOriente<T, S>::LirePoids();
                        this->GROSupprimerArc(sParam1, sParam2);
                    }
                    catch (CException EXCErreur) {
                        uiCompteurIter2++;
                        iter2 = this->GROLireArc(uiCompteurIter2);
                        this->GROCreerArc(sParam1, sParam2, uiMin);
                    }
                }
                else {
                    if (uiCompteurIter2 < this->GROLireTailleListSommet() - 1) {
                        uiCompteurIter2++;
                        iter2 = this->GROLireArc(uiCompteurIter2);
                    }
                    else {
                        uiCompteurIter++;
                        uiCompteurIter2 = uiCompteurIter + 1;
                        iter = this->GROLireArc(uiCompteurIter);
                        iter2 = this->GROLireArc(uiCompteurIter2);
                    }
                }
            }
            else {
                if (uiCompteurIter2 < this->GROLireTailleListSommet() - 1) {
                    uiCompteurIter2++;
                    iter2 = this->GROLireArc(uiCompteurIter2);
                }
                else {
                    uiCompteurIter++;
                    uiCompteurIter2 = uiCompteurIter + 1;
                    iter = this->GROLireArc(uiCompteurIter);
                    iter2 = this->GROLireArc(uiCompteurIter2);
                }
            }
        }
    }
};

#endif // __PGRAPH__
