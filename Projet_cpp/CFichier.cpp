#include "CFichier.h"
#include <cmath>




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
	
	unsigned int uiNbArc;
	

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
const unsigned int CFichier::FILRecupNombre(unsigned int uiDebut, unsigned int uiFin, string sLigne) {
	unsigned int uiNombre = 0;
	unsigned int uicpt = 0;

	for (uicpt = uiDebut + 1; uicpt < uiFin; uicpt++) { // on se place juste apres le egale de la ligne
		uiNombre += sLigne[uicpt] * pow(10, sLigne.size() - uicpt); // la valeur que l'on souhaite est ajoute caractere par caractere en respectant dizaine centaine etc
	}

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
const string CFichier::FILRecupNom(unsigned int uiDebut, unsigned int uiFin, string sLigne) {
	size_t stTaille;
	char cResultat[20];
	
	stTaille = sLigne.size();
	sLigne.copy(cResultat, uiFin);  // on copie dans cResulat les caractere compris entre la pos uiDebut et la uiFin

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
	string sLigne;
	string sNomSom;
	string sNomSomFin;
	while (getline(MonFichier, sLigne)) {
		if (sLigne.find(BALISE_NBSOMMET) != string::npos) {
			FICNbSommet = FILRecupNombre(sLigne.find(BALISE_NBSOMMET)+1, sLigne.size(), sLigne);
		}
		if (sLigne.find(BALISE_NBARC) != string::npos) {
			FICNbArc = FILRecupNombre(sLigne.find(BALISE_NBARC)+1, sLigne.size(), sLigne);
		}
		if (sLigne.find(BALISE_NUMERO) != string::npos) {
			sNomSom = FILRecupNom(sLigne.find(BALISE_NUMERO)+1, sLigne.size(), sLigne);
			GROFICGraphe->GROCreerSommet(sNomSom); //RESTE A CORRIGER POUR RECUP UN NOM ET PAS UN CHIFFRE UTILISER str.copy(buffer,6,5)
		}
		if (sLigne.find(BALISE_DEBUT) != string::npos) {
			sNomSom = FILRecupNombre(sLigne.find(BALISE_DEBUT)+1, sLigne.size(), sLigne);
			sNomSom = FILRecupNom(sLigne.find(BALISE_FIN) + 1, sLigne.find(',') - 1, sLigne);
			GROFICGraphe->GROCreerArc(sNomSom, sNomSom);
		}
		
	}
}
