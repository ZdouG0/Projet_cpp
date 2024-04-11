#pragma once

using namespace std;
#include <string>
#include <fstream>
#include <iostream>
#include "CException.h"
#include "CGrapheOriente.h"


//on definnit des variables pour les differnte balise 
#define BALISE_NBARC "NBARC="
#define BALISE_NBSOMMET "NBSommets="
#define BALISE_NUMERO "Numero="
#define BALISE_DEBUT "Debut="
#define BALISE_FIN "Fin="


/************************************************************
* CLASSE : Classe pour la lecture et la gestion de fichier
* ************************************************************
* ROLE : Interface de la classe CEntree,
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
		CGrapheOriente* GROFICGraphe;
		unsigned int FICNbSommet;
		unsigned int FICNbArc;


	//Methodes
	public :
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
		* Entra�ne : determine le contenu d'un ligne et quelles
		* methode appele en consequence
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
		const unsigned int FILRecupNombre(unsigned int uiDebut, unsigned int uiFin, string sLigne);

		/*****************************************************
		* FILRecupNom
		* ****************************************************
		* Entr�e : unsigned int la position de debut, unsigned
		* int la position de fin et sLigne la ligne sur laquelle
		* le traitement est fait
		* N�cessite : les position sont bien dans les ligne FAIRE EXCEPTIONN ???????
		* Sortie : un entier non sign�
		* Entra�ne : On recupere le nombre apres le egale
		* ****************************************************/
		const string FILRecupNom(unsigned int uiDebut, unsigned int uiFin, string sLigne);
};

