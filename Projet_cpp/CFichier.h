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
*  pas de types particulier de d�clar�
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
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : un string constant
		* Entra�ne : Le nom/chemin du fichier est retourn�
		* ****************************************************/
		CFichier();

		/*****************************************************
		* CFichier
		* ****************************************************
		* Entr�e : string Le type de Graphe 
		* N�cessite : 1 ou 2
		* Sortie : rien
		* Entra�ne : le type du graphe qui sera creer 
		* plus tard depend de cette valeur
		* ****************************************************/
		void FICModifierTypeGraphe(string sParam);

		/*****************************************************
		* CFichier
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : un pointeur vers GROFICGraphe
		* Entra�ne : un pointeur vers GROFICGraphe est retourn�
		* ****************************************************/
		inline PGrapheOriente<CArc,CSommet<CArc>>* FICLireGraphe() { return GROFICGraphe; }


		/*****************************************************
		* FICLireNomFichier
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : un string constant
		* Entra�ne : Le nom/chemin du fichier est retourn�
		* ****************************************************/
		inline const string  FICLireNomFichier() const { return sFICNomFichier;  };

		/*****************************************************
		* FICModifierNomFichier
		* ****************************************************
		* Entr�e : un string le nouveau nom du fichier
		* N�cessite : le nom du fichier represente un chemin valide
		* Sortie : Rien
		* Entra�ne : Le nom du fichier est modifi�
		* ****************************************************/
		inline void FICModifierNomFichier(string NomParam) { sFICNomFichier = NomParam; };

		/*****************************************************
		* FICLireFichier
		* ****************************************************
		* Entr�e : Rien
		* N�cessite : Rien
		* Sortie : un ifstream notre fichier
		* Entra�ne : (Le fichier est lu en lecture) OU (ERREUR le fichier n'a
		* pas pu etre lu)
		* ****************************************************/
		ifstream FICLireFichier();

		/*****************************************************
		* FICParser
		* ****************************************************
		* Entr�e : une variables istream
		* N�cessite : la variable est valide
		* Sortie : Rien
		* Entra�ne : determine le contenu d'un fichier en faisant une 
		* analyse syntaxique ligne par ligne
		* ****************************************************/
		void FICParser(ifstream MonFichier);

		/*****************************************************
		* FILRecupNombre
		* ****************************************************
		* Entr�e : unsigned int la position de debut, unsigned
		* int la position de fin et sLigne la ligne sur laquelle
		* le traitement est fait
		* N�cessite : les position sont bien dans les ligne FAIRE EXCEPTIONN ???????
		* Sortie : un entier non sign�
		* Entra�ne : On recupere le nombre apres le egale
		* ****************************************************/
		const int FILRecupNombre(size_t uiDebut, size_t uiFin, string sLigne);

		/*****************************************************
		* FILRecupNom
		* ****************************************************
		* Entr�e : unsigned int la position de debut, unsigned
		* int la position de fin et sLigne la ligne sur laquelle
		* le traitement est fait
		* N�cessite : les position sont bien dans les ligne FAIRE EXCEPTIONN ???????
		* Sortie : un entier non sign�
		* Entra�ne : On recupere le nom apres le egale
		* ****************************************************/
		const string FILRecupNom(size_t uiDebut, size_t uiFin, string sLigne);
};

#endif