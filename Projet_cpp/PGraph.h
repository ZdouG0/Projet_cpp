#ifndef __PGRAPH__
#define __PGRAPH__					



#include <string>
#include <list>
#include "PGrapheOriente.h"
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




template<class T,class S>
class PGraph : public PGrapheOriente<T,S> 
{


public :
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
	void GROCreerArc(string sParamDepart, string sParamArrive) {
		PGrapheOriente<T,S>::GROCreerArc(sParamDepart, sParamArrive);
		PGrapheOriente<T,S>::GROCreerArc(sParamArrive, sParamDepart);
	}

	/*****************************************************
	* GROCreerArc
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommet de depart) et une deuxi�me chaine de caract�re (nom du sommet d'arriv�e)
	* N�cessite : La liste de PSommet contienne au moins deux elements et que les deux chaines de caract�res se r�f�rent bien � des sommets existants
	* Sortie : Aucune
	* Entra�ne : ( Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste) OU (Exception Element_inconnu)
	* Il y a un arc de plus dans la liste des arc si les sommets sont bien dans la liste
	* De plus les deux sommets sont maintenant li� par un arc
	* ****************************************************/
	void GROCreerArc(string sParamDepart, string sParamArrive, unsigned int uiPoids = 0) {
		//Je vais appeler ces deux fonctions pour etre sur que les sommet de depart et d'arrive existent
		//Dans cette fonction je l�ve une CException si le sommet n'est pas dans le tableau des sommets
		size_t stPosD = GROTrouverSommetPosition(sParamDepart); size_t stPosA = GROTrouverSommetPosition(sParamArrive); size_t stCompteur = 0;


		///Depart -----> Arrive ///////////// Dans depart jai donc un arc sortant allant vers arrive et dans arrive un arc entrant allant dans depart

		//ajouter liste des arcs
		T* ARCParam = nullptr;
		if constexpr (is_same<T, CArcPondere>::value) {
			// Si T est CArcPondere, appelez le constructeur avec trois param�tres
			ARCParam = new T(sParamDepart, sParamArrive, uiPoids);

		}
		else {
			// Sinon, appelez le constructeur avec deux param�tres
			ARCParam = new T(sParamDepart, sParamArrive);

		}
		pARCGROListArc.push_back(ARCParam);

		// ajouter dans les sommets
		S* sommetDepart = nullptr;
		S* sommetArrive = nullptr;
		for (auto iter = pSOMGROListSom.begin(); iter != pSOMGROListSom.end(); ++iter, ++stCompteur) {
			if (stCompteur == stPosD) {
				sommetDepart = *iter;
				sommetDepart->SOMAjoutArcSortant(ARCParam);

			}
			if (stCompteur == stPosA) {
				sommetArrive = *iter;
				sommetArrive->SOMAjoutArcEntrant(ARCParam);

			}
		}
	}



	/*****************************************************
	* GROSupprimerArc
	* ****************************************************
	* Entr�e : une chaine de caractere ( nom du sommet de d�part) et une chaine de caractere ( nom du sommet d'arriv� de l'arc)
	* N�cessite : Rien
	* Sortie : Aucune
	* Entra�ne : (le sommet avec le nom chParam est supprim�) OU (Exception Element_inconnu)
	* ****************************************************/
	void GROSupprimerArc(string chParamDepart, string chParamArrive) {
		//Je vais devoir supprimer les deux arcs si bool = false lors de la suppression c'est que j'ai pas encore trouve le retour
		PGrapheOriente<T,S>::GROSupprimerArc(chParamDepart, chParamArrive);
		PGrapheOriente<T,S>::GROSupprimerArc(chParamArrive, chParamDepart);
	}
};

#endif