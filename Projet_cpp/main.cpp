#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "CArc.h"
#include "CSommet.h"
#include <iterator>
#include <string>
#include <vector>
#include "CGrapheOriente.h"
#include "assert.h"
#include "Test.h"
#include "CFichier.h"
#include "CSortie.h"
#include "CInversion.h"

using namespace std;

int main() {
    
   
   

    CFichier FICMonFichier;

    FICMonFichier.FICModifierNomFichier("fichiertest.txt"); // parametre a modifier si on souhaite modifier le fichier a interpreter
    

    ifstream ifsMonfichier = FICMonFichier.FICLireFichier();
    FICMonFichier.FICParser(FICMonFichier.FICLireFichier());


    cout << "*************************************************************\n*                                                           *\n*                      Graphe initial                       * \n*                                                           *\n*************************************************************"<< endl;
    CSortie* SORSortie = new CSortie();
    SORSortie->SORModifierGraphe(FICMonFichier.FICLireGraphe());
    SORSortie->SORAfficher_Graphe();

    cout << "*************************************************************\n*                                                           *\n*                      Graphe inverse                       * \n*                                                           *\n*************************************************************" << endl;
    CInversion* INVInverse = new CInversion();
    INVInverse->INVChangerGraphe(FICMonFichier.FICLireGraphe());
    INVInverse->INVInversion();
    SORSortie->SORModifierGraphe(INVInverse->INVInversion());

    SORSortie->SORAfficher_Graphe();

    delete INVInverse;
    delete SORSortie;


    return 0;
}