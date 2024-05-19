#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "CArc.h"
#include "PSommet.h"
#include <iterator>
#include <string>
#include <vector>
#include "PGrapheOriente.h"
#include "assert.h"
#include "Test.h"
#include "CFichier.h"
#include "CSortie.h"
#include "CInversion.h"
#include "CArcPondere.h"
#include "PGraph.h"
#include "CArbreBoruvka.h"

using namespace std;

int main(int argc, char* argv[]) {
    CFichier FICMonFichier;
    string snomfichier;
    if (argc > 1) {
        snomfichier = argv[argc - 1];
    }
    else {
        cout << "Entrer le nom de votre fichier ou son chemin complet :";
        cin >> snomfichier;
    }
    FICMonFichier.FICModifierNomFichier(snomfichier); // parametre a modifier si on souhaite modifier le fichier a interpreter
    bool bCheminOK = false;
    while (!bCheminOK) {
        try {
            bCheminOK = true;
            ifstream ifsMonfichier = FICMonFichier.FICLireFichier();
        }
        catch (CException) {
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

    PGraph<CArcPondere, PSommet<CArcPondere>>* initialGraph;

    initialGraph->GROCreerSommet("A");
    initialGraph->GROCreerSommet("B");
    initialGraph->GROCreerSommet("C");
    initialGraph->GROCreerSommet("D");

    initialGraph->GROCreerArc("A", "B", 4);
    initialGraph->GROCreerArc("A", "C", 3);
    initialGraph->GROCreerArc("B", "C", 2);
    initialGraph->GROCreerArc("B", "D", 5);
    initialGraph->GROCreerArc("C", "D", 7);

    CArbreBoruvka arbreBoruvka;

    arbreBoruvka.setGraphe(initialGraph);

    PGrapheOriente<CArcPondere, PSommet<CArcPondere>>* minimumSpanningTree = arbreBoruvka.ABKBoruvka();

    // Output the result
    std::cout << "Minimum Spanning Tree Edges:" << std::endl;
    for (unsigned int i = 0; i < minimumSpanningTree->GROLireTailleListArc(); ++i) {
        CArcPondere* arc = minimumSpanningTree->GROLireArc(i);
        std::cout << arc->ARCLireDepart() << " -> " << arc->ARCLireArrive()
            << " [Weight: " << arc->ARCLirePoids() << "]" << std::endl;
    }

    // Clean up
    delete minimumSpanningTree;

    return 0;
}
