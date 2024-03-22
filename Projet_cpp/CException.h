
/************************************************************
* CLASSE : Classe pour la gestion des exceptions
* ************************************************************
* ROLE : Interface de la classe Cecxeption,
* Cette classe permet de cr�er des objets qui sont repmont�s
* lors de la lev�e d'exception dans votre programme.
* ************************************************************
* VERSION :
* AUTEUR : Yassine ELLATIFI
* DATE : 16/02/2024
* ************************************************************
* INCLUSIONS EXTERNES :
*/

/* TYPES :
*  pas de types particulier de d�clar�
*/

/* VARIABLES :
*
*/

// D�finition de la valeur initiale d'une exception
#define FAUX 0

class CException
{
	// ATTRIBUTS :
private:
	unsigned int uiEXCValeur; //cette variable contient la valeur de l'exception retourn�

	// CONSTRUCTEURS ET DESTRUCTEURS
public:
	/******************************************************
	* CException
	* *****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'exception est initialis� a FAUX
	* ****************************************************/
	CException();
	// METHODES 
		/*****************************************************
		* EXCModifierValeur
		* ****************************************************
		* Entr�e : uiP, unsigned int, la nouvelle valeur
		* N�cessite : Rien
		* Sortie : Rien
		* Entra�ne : La valeur de l'exception est modifi�e
		* ****************************************************/
	inline void EXCModifierValeur(unsigned int uiP) { uiEXCValeur = uiP; }
	/*****************************************************
	* EXCLireValeur
	* ****************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : un unsigned int, la valeur de l'exception
	* Entra�ne : La valeur de l'exception est retourn�
	* ****************************************************/
	inline unsigned int EXCLireValeur() const { return(uiEXCValeur); }

};

