
/************************************************************
* CLASSE : Classe pour la gestion des exceptions
* ************************************************************
* ROLE : Interface de la classe Cecxeption,
* Cette classe permet de créer des objets qui sont repmontés
* lors de la levée d'exception dans votre programme.
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI
* DATE : 16/02/2024
* ************************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES :
*  pas de types particulier de déclaré
*/

/* VARIABLES :
*
*/

// Définition de la valeur initiale d'une exception
#define FAUX 0

class CException
{
	// ATTRIBUTS :
private:
	unsigned int uiEXCValeur; //cette variable contient la valeur de l'exception retourné

	// CONSTRUCTEURS ET DESTRUCTEURS
public:
	/******************************************************
	* CException
	* *****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'exception est initialisé a FAUX
	* ****************************************************/
	CException();
	// METHODES 
		/*****************************************************
		* EXCModifierValeur
		* ****************************************************
		* Entrée : uiP, unsigned int, la nouvelle valeur
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : La valeur de l'exception est modifiée
		* ****************************************************/
	inline void EXCModifierValeur(unsigned int uiP) { uiEXCValeur = uiP; }
	/*****************************************************
	* EXCLireValeur
	* ****************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : un unsigned int, la valeur de l'exception
	* Entraîne : La valeur de l'exception est retourné
	* ****************************************************/
	inline unsigned int EXCLireValeur() const { return(uiEXCValeur); }

};

