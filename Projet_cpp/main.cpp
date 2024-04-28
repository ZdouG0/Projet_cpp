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

    FICMonFichier.FICModifierNomFichier("fichiertest.txt");
    

    ifstream ifsMonfichier = FICMonFichier.FICLireFichier();
    FICMonFichier.FICParser(FICMonFichier.FICLireFichier());



    CSortie* SORSortie = new CSortie();
    SORSortie->SORModifierGraphe(FICMonFichier.FICLireGraphe());
    SORSortie->SORAfficher_Graphe();
    CInversion* INVInverse = new CInversion();
    INVInverse->INVChangerGraphe(FICMonFichier.FICLireGraphe());
    INVInverse->INVInversion();
    SORSortie->SORModifierGraphe(INVInverse->INVInversion());

    SORSortie->SORAfficher_Graphe();


    return 0;
}