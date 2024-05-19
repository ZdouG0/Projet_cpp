
					
#ifndef __CBoruvka__
#define __CBoruvka__					

#include "PGraph.h"
#include "CArc.h"
#include "CArcPondere.h"
using namespace std;


/************************************************************
* CLASSE : Classe outils pour la creation d'un arbre couvrant
* de poids minimal
* ************************************************************
* ROLE : Interface de la classe CBoruvka,
* cette classe fournit un ensemble de service pour la realisation
* d'un arbre couvrant de poids minimal a partir de l'algo de 
* Boruvka
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI / Milan HERGOTT
* DATE : 06/05/2024
* ************************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES :
*  pas de types particulier de d�clar�
*/

/* VARIABLES :
*
*
*/



class CArbreBoruvka
{
	
	//attributs

	private :
		PGraph<CArcPondere,PSommet<CArcPondere>>* pGROABKGraphParam;
	//Constructeur/ Destructeurs
	public :
		/*****************************************************
		* CArbreBoruvka
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : Un objet de la classe CArbreBoruvka est construit
		* ****************************************************/
		inline CArbreBoruvka() { pGROABKGraphParam = new PGraph<CArcPondere, PSommet<CArcPondere>>(); };


		/*****************************************************
		* CArbreBoruvka
		* ****************************************************
		* Entr�e : Un pointeur sur un arbre orient
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : Un objet de la classe CArbreBoruvka est construit
		* ****************************************************/
		inline CArbreBoruvka(PGraph<CArcPondere, PSommet<CArcPondere>>* pGROParam){pGROABKGraphParam = pGROParam;}






		/*****************************************************
		* CArbreBoruvka
		* ****************************************************
		* Entr�e : Un CArbreBoruvka a copier
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : Un objet de la classe CSortie est creer en 
		* copiant l'objet en parametre
		* ****************************************************/
		CArbreBoruvka(CArbreBoruvka& ABKParam);

		/*****************************************************
		* operator=
		* ****************************************************
		* Entr�e : Un CArbreBoruvka a copier
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : Un objet de la classe CSortie est creer en
		* copiant l'objet en parametre
		* ****************************************************/
		void operator=(CArbreBoruvka& ABKParam);


		/*****************************************************
		* ABKBoruvka
		* ****************************************************
		* Entr�e : rien
		* N�cessite : Rien
		* Sortie : Un PGraph l'arbe couvrant minimal
		* Entra�ne : creation de l'arbre couvrant minimal a partir
		* de l'algorithme Boruvka
		* ****************************************************/
		PGrapheOriente<CArcPondere, PSommet<CArcPondere>>* ABKBoruvka();





		/*****************************************************
		* ABKMinPoids
		* ****************************************************
		* Entr�e : rien
		* N�cessite : Rien
		* Sortie : Un PGraph l'arbe couvrant minimal
		* Entra�ne : creation de l'arbre couvrant minimal a partir
		* de l'algorithme Boruvka
		* ****************************************************/
		CArcPondere* ABKMinPoids(list<CArcPondere*> ListParam);






		/*****************************************************
		* ABKMinPoids
		* ****************************************************
		* Entr�e : rien
		* N�cessite : Rien
		* Sortie : Un PGrapheOriente l'arbe couvrant minimal
		* Entra�ne : creation de l'arbre couvrant minimal a partir
		* de l'algorithme Boruvka
		* ****************************************************/
		PSommet<CArcPondere>* ABKMinPoids(list<string> ListParam);

};

#endif