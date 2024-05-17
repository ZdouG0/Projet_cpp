#include "CFichier.h"
#include <cmath>


/*****************************************************
* CFichier
* ****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Constructeur pardefaut
* ****************************************************/
CFichier :: CFichier() {
	GROFICGraphe = new PGrapheOriente<CArc,PSommet<CArc>>();
	FICNbSommet=0;
	FICNbArc=0;
	sFICNomFichier= "Rien";
	sTypeGraphe = "NonOriente";
}

/*****************************************************
* CFichier
* ****************************************************
* Entrée : string Le type de Graphe
* Nécessite : Oriente ou NonOriente
* Sortie : rien
* Entraîne : le type du graphe qui sera creer
* plus tard depend de cette valeur
* ****************************************************/
void CFichier :: FICModifierTypeGraphe(string sParam) { 
	sTypeGraphe = sParam;
	if (sTypeGraphe == "Oriente") {
		GROFICGraphe = new PGrapheOriente<CArc, PSommet<CArc>>();
	}
	if (sTypeGraphe == "NonOriente") {
		GROFICGraphe = new PGraph<CArc, PSommet<CArc>>();
	}
}

/*****************************************************
* FICLireFichier
* ****************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : un ifstream notre fichier
* Entraîne : (Le fichier est lu en lecture) OU (ERREUR le fichier n'a
* pas pu etre lu)
* ****************************************************/
ifstream CFichier :: FICLireFichier() {
	
	

	ifstream FILFichier(sFICNomFichier.c_str());

	if (!FILFichier) {  //	on leve une exception si l'ouverture du fichier echoue
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ECHEC_LECTURE);
		throw EXCErreur;
	}

	return FILFichier;
}

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
const int CFichier::FILRecupNombre(size_t uiDebut, size_t uiFin, string sLigne) {
	int uiNombre = 0;
	string sResultat;

	sResultat = sLigne.substr(uiDebut, uiFin-uiDebut);  // on copie dans cResulat les caractere compris entre la pos uiDebut et la uiFin
	uiNombre = stoi(sResultat, nullptr, 0);

	return uiNombre;

}

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
const string CFichier::FILRecupNom(size_t uiDebut, size_t uiFin, string sLigne) {
	size_t stTaille;
	char cResultat[20];
	
	stTaille = sLigne.size();
	sLigne.copy(cResultat, uiFin-uiDebut, uiDebut);  // on copie dans cResulat les caractere compris entre la pos uiDebut et la uiFin
	cResultat[uiFin - uiDebut] = '\0';

	string sResultat = cResultat; // on change le type de char* a string

	return sResultat;

}


/*****************************************************
* FICParser
* ****************************************************
* Entrée : une variables istream
* Nécessite : la variable est valide
* Sortie : Rien
* Entraîne : determine le contenu d'un ligne et quelles
* methode appele en consequence
* ****************************************************/
void CFichier :: FICParser(ifstream MonFichier) {
	size_t stTaille;
	string sBalise;
	string sLigne;
	string sNomSom;
	string sNomSomFin;
	while (getline(MonFichier, sLigne)) { //permet qu'a chaque iteration de la boucle on travaille sur une nouvelle ligne
		if (sLigne.find(BALISE_NBSOMMET) != string::npos) {
			sBalise = BALISE_NBSOMMET; //on place la variable globale dans une variable local afin d'avoir acces a toute les methodes de String
			stTaille = sBalise.size(); //on recupere la taille car la methode .find retourne la position du debut de la balise et non la fin
			FICNbSommet = FILRecupNombre(sLigne.find(sBalise) + stTaille, sLigne.size(), sLigne); // on met dans la variable le nombre de Sommet 
		}
		if (sLigne.find(BALISE_GRAPHE) != string::npos) {
			sBalise = BALISE_GRAPHE; //on place la variable globale dans une variable local afin d'avoir acces a toute les methodes de String
			stTaille = sBalise.size(); //on recupere la taille car la methode .find retourne la position du debut de la balise et non la fin
			FICModifierTypeGraphe(FILRecupNom(sLigne.find(sBalise) + stTaille, sLigne.size(), sLigne))  ;
		}
		if (sLigne.find(BALISE_NBARC) != string::npos) {
			sBalise = BALISE_NBARC; //--
			stTaille = sBalise.size();//--
			FICNbArc = FILRecupNombre(sLigne.find(sBalise) + stTaille, sLigne.size(), sLigne);
		}
		if (sLigne.find(BALISE_NUMERO) != string::npos) {
			sBalise = BALISE_NUMERO;
			stTaille = sBalise.size();
			sNomSom = FILRecupNom(sLigne.find(sBalise)+stTaille, sLigne.size(), sLigne);
			GROFICGraphe->GROCreerSommet(sNomSom); //On appele la methode creer sommet de notre Classe CGrapheOrient
		}
		if (sLigne.find(BALISE_DEBUT) != string::npos) {  // on recherche la balise Debut et on interprete
			sBalise = BALISE_DEBUT;
			stTaille = sBalise.size();
			size_t temp = sLigne.find(sBalise) + stTaille;
			size_t temp2 = sLigne.find(',');
			sNomSom = FILRecupNom(sLigne.find(sBalise) + stTaille, sLigne.find(','), sLigne);
			sBalise = BALISE_FIN;
			stTaille = sBalise.size();
			sNomSomFin = FILRecupNom(sLigne.find(sBalise) + stTaille, sLigne.size(), sLigne);
			GROFICGraphe->GROCreerArc(sNomSom, sNomSomFin);
		}
		
	}
}
