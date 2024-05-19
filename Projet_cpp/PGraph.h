#ifndef __PGRAPH__
#define __PGRAPH__

#include <string>
#include <list>
#include "PGrapheOriente.h"
#include "CException.h"
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
    * Il y a un arc de plus dans la liste des arcs si les sommets sont bien dans la liste
    * De plus les deux sommets sont maintenant li�s par un arc
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
    * Entr�e : une cha�ne de caract�res (nom du sommet de d�part) et une cha�ne de caract�res (nom du sommet d'arriv�e de l'arc)
    * N�cessite : Rien
    * Sortie : Aucune
    * Entra�ne : (le sommet avec le nom chParam est supprim�) OU (Exception Element_inconnu)
    * ****************************************************/
    void GROSupprimerArc(string chParamDepart, string chParamArrive) {
        // Je vais devoir supprimer les deux arcs si bool = false lors de la suppression c'est que je n'ai pas encore trouv� le retour
        PGrapheOriente<T, S>::GROSupprimerArc(chParamDepart, chParamArrive);
        PGrapheOriente<T, S>::GROSupprimerArc(chParamArrive, chParamDepart);
    }

    /*****************************************************
    * GROArbreNonReflexif
    * ****************************************************
    * Entr�e : Aucune
    * N�cessite : Rien
    * Sortie : Un Arbre avec au plus une liaison entre deux sommets et sans arc r�flexif
    * Entra�ne :
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
