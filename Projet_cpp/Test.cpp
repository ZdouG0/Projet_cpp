#include "Test.h"

void CTest::TESTestMethodesARC(CArc ARCParam) {
    CArc ARCVar;
    cout << "~*************************************~      CARC      ~*************************************~" << endl;
    cout << "\nTest sur la classe CArc" << endl;
    string somA = "sommet A";
    string somB = "sommet B";
    // ajout d'un sommet d'arrivée
    ARCVar.ARCModifierSommetArrive(somA);
    // ajout d'un sommet de depar
    ARCVar.ARCModifierSommetDepart(somB);
    assert(ARCParam.ARCLireDepart() == "sommet B");
    assert(ARCParam.ARCLireDepart() == ARCVar.ARCLireDepart() == false);
    assert(ARCParam.ARCLireArrive() == somA);
    assert(ARCParam.ARCLireArrive() == "sommet A");
    assert((ARCParam.ARCLireArrive() == "sommet A ") == false);

}


void CTest::TESTestMethodesARC(CArc* ARCParam) {
    CArc ARCVar;
    cout << "~*************************************~      CARC      ~*************************************~" << endl;
    cout << "\nTest sur la classe CArc" << endl;
    string somA = "sommet A";
    string somB = "sommet B";
    // ajout d'un sommet d'arrivée
    ARCParam->ARCModifierSommetArrive(somA);
    // ajout d'un sommet de depar
    ARCParam->ARCModifierSommetDepart(somB);
    cout << "Les constructeurs de la classe CArc fonctionnent correctement" << endl;

    assert(ARCParam->ARCLireDepart() == "sommet B");
    assert(ARCParam->ARCLireDepart() == ARCVar.ARCLireDepart() == false);
    assert(ARCParam->ARCLireArrive() == somA);
    assert(ARCParam->ARCLireArrive() == "sommet A");
    assert((ARCParam->ARCLireArrive() == "sommet A ") == false);
}



void CTest::TESTestMethodesSOM(CSommet SomParam) {
    cout << "~*************************************~      CSOMMET      ~*************************************~" << endl;
    cout << "\nTest sur la classe CSommet" << endl;
    string nomSOM = "sommet A";
    SomParam.SOMModifierNom(nomSOM);
    assert(SomParam.SOMLireNom() == nomSOM);
    assert((SomParam.SOMLireNom() == "sommet a") == false);
}

void CTest::TESTestMethodesSOM(CSommet* SomParam) {
    cout << "~*************************************~      CSOMMET      ~*************************************~" << endl;
    cout << "\nTest sur la classe CSommet" << endl;
    string nomSOM = "sommet A";
    SomParam->SOMModifierNom(nomSOM);
    assert(SomParam->SOMLireNom() == nomSOM);
    assert((SomParam->SOMLireNom() == "sommet a") == false);
}



void CTest::TESTestMethodesGRO(CGrapheOriente GROParam) {
    cout << "~*************************************~      CGRAPHORIENTE      ~*************************************~" << endl;

    //routine de test pour CGraphOriente
    cout << "\nTest sur la classe CGrapheOriente" << endl;


    //Creation de deux sommets
    GROParam.GROCreerSommet("Paris");
    GROParam.GROCreerSommet("Evry");

    //Verification des methodes : CGrapheOriente, CreerSommet, LireSommet, TrouverSomPos

    assert(GROParam.GROLireSommet(0)->SOMLireNom() == "Paris");
    assert((GROParam.GROLireSommet(0)->SOMLireNom() == "paris") == false);
    assert(GROParam.GROLireSommet(1)->SOMLireNom() == "Evry");
    assert((GROParam.GROLireSommet(1)->SOMLireNom() == "évry") == false);
    assert(GROParam.GROTrouverSommetPosition("Evry") == 1);
    assert(GROParam.GROLireTailleListSommet() == 2);
    GROParam.GROCreerSommet("Courcouronnes");
    GROParam.GROCreerSommet("Lisses");
    GROParam.GROCreerSommet("Mennecy");
    GROParam.GROCreerSommet("Ris-Orangis");
    GROParam.GROCreerSommet("Grigny");
    GROParam.GROCreerArc("Paris", "Evry");
    GROParam.GROCreerArc("Evry", "Courcouronnes");
    GROParam.GROCreerArc("Ris-Orangis", "Lisses");
    GROParam.GROCreerArc("Evry", "Ris-Orangis");
    GROParam.GROCreerArc("Grigny", "Ris-Orangis");
    //Verification des methodes : LireSommetEntrantLie, 
    vector<string>TestVrai{ "Evry","Grigny" };
    vector<string>TestFaux{ "Evri","Grigny" };
    assert(GROParam.GROLireSommetEntrantLie("Ris-Orangis") == TestVrai);
    assert((GROParam.GROLireSommetEntrantLie("Ris-Orangis") == TestFaux) == false);
    assert((GROParam.GROLireSommetSortantLie("Ris-Orangis") == TestFaux) == false);
    assert(GROParam.GROLireSommetSortantLie("Ris-Orangis")[0] == "Lisses");
}

void CTest::TESTestMethodesGRO(CGrapheOriente* GROParam) {
    cout << "~*************************************~      CGRAPHORIENTE      ~*************************************~" << endl;

    //routine de test pour CGraphOriente
    cout << "\nTest sur la classe CGrapheOriente" << endl;


    //Creation de deux sommets
    GROParam->GROCreerSommet("Paris");
    GROParam->GROCreerSommet("Evry");

    //Verification des methodes : CGrapheOriente, CreerSommet, LireSommet, TrouverSomPos

    assert(GROParam->GROLireSommet(0)->SOMLireNom() == "Paris");
    assert((GROParam->GROLireSommet(0)->SOMLireNom() == "paris") == false);
    assert(GROParam->GROLireSommet(1)->SOMLireNom() == "Evry");
    assert((GROParam->GROLireSommet(1)->SOMLireNom() == "évry") == false);
    assert(GROParam->GROTrouverSommetPosition("Evry") == 1);
    assert(GROParam->GROLireTailleListSommet() == 2);
    GROParam->GROCreerSommet("Courcouronnes");
    GROParam->GROCreerSommet("Lisses");
    GROParam->GROCreerSommet("Mennecy");
    GROParam->GROCreerSommet("Ris-Orangis");
    GROParam->GROCreerSommet("Grigny");
    GROParam->GROCreerArc("Paris", "Evry");
    GROParam->GROCreerArc("Evry", "Courcouronnes");
    GROParam->GROCreerArc("Ris-Orangis", "Lisses");
    GROParam->GROCreerArc("Evry", "Ris-Orangis");
    GROParam->GROCreerArc("Grigny", "Ris-Orangis");
    //Verification des methodes : LireSommetEntrantLie, 
    vector<string>TestVrai{ "Evry","Grigny" };
    vector<string>TestFaux{ "Evri","Grigny" };
    assert(GROParam->GROLireSommetEntrantLie("Ris-Orangis") == TestVrai);
    assert((GROParam->GROLireSommetEntrantLie("Ris-Orangis") == TestFaux) == false);
    assert((GROParam->GROLireSommetSortantLie("Ris-Orangis") == TestFaux) == false);
    assert(GROParam->GROLireSommetSortantLie("Ris-Orangis")[0] == "Lisses");
}