#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "CArc.h"
#include "CSommet.h"
#include <iterator>
#include <string>
#include <vector>
#include "PGrapheOriente.h"
#include "assert.h"
#include "Test.h"
#include "CFichier.h"
#include "CSortie.h"
#include "CInversion.h"
#include "CArbreBoruvka.h"

using namespace std;

int main() {
    
   
   /*

    CFichier FICMonFichier;
    string snomfichier;
    cout << "Entrer le nom de votre fichier ou son chemin complet :";
    cin >> snomfichier;
    FICMonFichier.FICModifierNomFichier(snomfichier); // parametre a modifier si on souhaite modifier le fichier a interpreter
    bool bCheminOK = false;
    while (!bCheminOK) {
        try {
            bCheminOK = true;
            ifstream ifsMonfichier = FICMonFichier.FICLireFichier();
        }
        catch (CException EXCErreur) {
            bCheminOK = false;
            cout << "nom ou chemin du fichier incorrect reesayer :";
            cin >> snomfichier;
            FICMonFichier.FICModifierNomFichier(snomfichier); // parametre a modifier si on souhaite modifier le fichier a interpreter
        }
    }
    
    
    

    
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
    */

    CArbreBoruvka Test;
    Test.ABKArbreNonReflexif();

    return 0;
}