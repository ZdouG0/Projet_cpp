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
* FICLireNbSommet
* ****************************************************
* Entrée : une variables istream
* Nécessite : la variable est valide
* Sortie : un entier
* Entraîne : Le nombre de sommet du fichier est retourne
* ****************************************************/
const int CFichier :: FICLireNbSommet(ifstream MonFichier) {
	string sLigne;

	getline(MonFichier, sLigne);
	return FILRecupNombre(POSITION_EGALE_NBSOM, sLigne.size(), sLigne);

}

/*****************************************************
* FICLireNbArc
* ****************************************************
* Entrée : une variables istream
* Nécessite : la variable est valide
* Sortie : un entier
* Entraîne : Le nombre d'arc du fichier est retourne
* ****************************************************/
const int CFichier :: FICLireNbArc(ifstream MonFichier) {
	string sLigne;

	getline(MonFichier, sLigne);
	return FILRecupNombre(POSITION_EGALE_NBARC, sLigne.size(), sLigne);
	
}

