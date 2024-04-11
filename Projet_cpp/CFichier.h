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
		CGrapheOriente* GROFICGraphe;
		unsigned int FICNbSommet;
		unsigned int FICNbArc;


	//Methodes
	public :
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
		* Entraîne : determine le contenu d'un ligne et quelles
		* methode appele en consequence
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
		const unsigned int FILRecupNombre(unsigned int uiDebut, unsigned int uiFin, string sLigne);

		/*****************************************************
		* FILRecupNom
		* ****************************************************
		* Entrée : unsigned int la position de debut, unsigned
		* int la position de fin et sLigne la ligne sur laquelle
		* le traitement est fait
		* Nécessite : les position sont bien dans les ligne FAIRE EXCEPTIONN ???????
		* Sortie : un entier non signé
		* Entraîne : On recupere le nombre apres le egale
		* ****************************************************/
		const string FILRecupNom(unsigned int uiDebut, unsigned int uiFin, string sLigne);
};

