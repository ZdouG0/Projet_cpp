#ifndef __CFICHIER__
#define __CFICHIER__					


using namespace std;
#include <string>
#include <fstream>
#include <iostream>
#include "CException.h"
#include "PGrapheOriente.h"
#include "PGraph.h"

//variable exception
#define ECHEC_LECTURE 984


//on definnit des variables pour les differnte balise 
#define BALISE_GRAPHE "TypedeGraphe="
#define BALISE_NBARC "NBArcs="
#define BALISE_NBSOMMET "NBSommets="
#define BALISE_NUMERO "Numero="
#define BALISE_DEBUT "Debut="
#define BALISE_FIN "Fin="


/************************************************************
* CLASSE : Classe pour la lecture et la gestion de fichier
* ************************************************************
* ROLE : Interface de la classe CFichier,
* cette classe fournit un ensemble de service pour la lecture
* des donnees d'un fichier et la creation d'un graphe a partir
* de ce fichier
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI / Milan HERGOTT
* DATE : 09/04/2024
* ************************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES :
*  pas de types particulier de déclaré
*/

/* VARIABLES :
*
*
*/

class CFichier
{	
	//Attributs
	private :
		string  sFICNomFichier; // le chemin d'acces du fichier
		string	sTypeGraphe; // le type de GrapheOriente ou non
		PGrapheOriente<CArc,CSommet<CArc>>* GROFICGraphe;
		unsigned int FICNbSommet;
		unsigned int FICNbArc;


	//Methodes
	public :
		/*****************************************************
		* CFichier
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : un string constant
		* Entraîne : Le nom/chemin du fichier est retourné
		* ****************************************************/
		CFichier();

		/*****************************************************
		* CFichier
		* ****************************************************
		* Entrée : string Le type de Graphe 
		* Nécessite : 1 ou 2
		* Sortie : rien
		* Entraîne : le type du graphe qui sera creer 
		* plus tard depend de cette valeur
		* ****************************************************/
		void FICModifierTypeGraphe(string sParam);

		/*****************************************************
		* CFichier
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : un pointeur vers GROFICGraphe
		* Entraîne : un pointeur vers GROFICGraphe est retourné
		* ****************************************************/
		inline PGrapheOriente<CArc,CSommet<CArc>>* FICLireGraphe() { return GROFICGraphe; }


		/*****************************************************
		* FICLireNomFichier
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : un string constant
		* Entraîne : Le nom/chemin du fichier est retourné
		* ****************************************************/
		inline const string  FICLireNomFichier() const { return sFICNomFichier;  };

		/*****************************************************
		* FICModifierNomFichier
		* ****************************************************
		* Entrée : un string le nouveau nom du fichier
		* Nécessite : le nom du fichier represente un chemin valide
		* Sortie : Rien
		* Entraîne : Le nom du fichier est modifié
		* ****************************************************/
		inline void FICModifierNomFichier(string NomParam) { sFICNomFichier = NomParam; };

		/*****************************************************
		* FICLireFichier
		* ****************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : un ifstream notre fichier
		* Entraîne : (Le fichier est lu en lecture) OU (ERREUR le fichier n'a
		* pas pu etre lu)
		* ****************************************************/
		ifstream FICLireFichier();

		/*****************************************************
		* FICParser
		* ****************************************************
		* Entrée : une variables istream
		* Nécessite : la variable est valide
		* Sortie : Rien
		* Entraîne : determine le contenu d'un fichier en faisant une 
		* analyse syntaxique ligne par ligne
		* ****************************************************/
		void FICParser(ifstream MonFichier);

		/*****************************************************
		* FILRecupNombre
		* ****************************************************
		* Entrée : unsigned int la position de debut, unsigned
		* int la position de fin et sLigne la ligne sur laquelle
		* le traitement est fait
		* Nécessite : les position sont bien dans les ligne FAIRE EXCEPTIONN ???????
		* Sortie : un entier non signé
		* Entraîne : On recupere le nombre apres le egale
		* ****************************************************/
		const int FILRecupNombre(size_t uiDebut, size_t uiFin, string sLigne);

		/*****************************************************
		* FILRecupNom
		* ****************************************************
		* Entrée : unsigned int la position de debut, unsigned
		* int la position de fin et sLigne la ligne sur laquelle
		* le traitement est fait
		* Nécessite : les position sont bien dans les ligne FAIRE EXCEPTIONN ???????
		* Sortie : un entier non signé
		* Entraîne : On recupere le nom apres le egale
		* ****************************************************/
		const string FILRecupNom(size_t uiDebut, size_t uiFin, string sLigne);
};

#endif