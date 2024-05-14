#include "Test.h"
#include "CArc.h"
#include "CSommet.h"
#include "PGrapheOriente.h"

void CTest::TESTestMethodesARC(CArc ARCParam) {
    CArc ARCVar;
    cout << "~*************************************~      CARC      ~*************************************~" << endl;
    cout << "\nTest sur la classe CArc" << endl;
    string somA = "sommet A";
    string somB = "sommet B";
    // ajout d'un sommet d'arrivée
    ARCVar.ARCModifierSommetArrive(somA);
    // ajout d'un sommet de depart
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
    // ajout d'un sommet de depart
    ARCParam->ARCModifierSommetDepart(somB);
    cout << "Les constructeurs de la classe CArc fonctionnent correctement" << endl;

    assert(ARCParam->ARCLireDepart() == "sommet B");
    assert(ARCParam->ARCLireDepart() == ARCVar.ARCLireDepart() == false);
    assert(ARCParam->ARCLireArrive() == somA);
    assert(ARCParam->ARCLireArrive() == "sommet A");
    assert((ARCParam->ARCLireArrive() == "sommet A ") == false);
}



void CTest::TESTestMethodesSOM(CSommet<CArc> SomParam) {
    cout << "~*************************************~      CSOMMET      ~*************************************~" << endl;
    cout << "\nTest sur la classe CSommet" << endl;
    string nomSOM = "sommet A";
    SomParam.SOMModifierNom(nomSOM);
    assert(SomParam.SOMLireNom() == nomSOM);
    assert((SomParam.SOMLireNom() == "sommet a") == false);
}

void CTest::TESTestMethodesSOM(CSommet<CArc>* SomParam) {
    cout << "~*************************************~      CSOMMET      ~*************************************~" << endl;
    cout << "\nTest sur la classe CSommet" << endl;
    string nomSOM = "sommet A";
    SomParam->SOMModifierNom(nomSOM);
    assert(SomParam->SOMLireNom() == nomSOM);
    assert((SomParam->SOMLireNom() == "sommet a") == false);

}



void CTest::TESTestMethodesGRO(PGrapheOriente<CArc,CSommet<CArc>> GROParam) {
    cout << "~*************************************~      CGRAPHORIENTE      ~*************************************~" << endl;

    //routine de test pour CGraphOriente
    cout << "\nTest sur la classe PGrapheOriente" << endl;


    //Creation de deux sommets
    GROParam.GROCreerSommet("Paris");
    size_t posParis = GROParam.GROTrouverSommetPosition("Paris");
    assert(GROParam.GROLireSommet(posParis)->SOMLireNom() == "Paris");
    assert((GROParam.GROLireSommet(posParis)->SOMLireNom() == "paris") == false);
    assert(GROParam.GROTrouverSommetPosition("Paris") == posParis);
}

void CTest::TESTestMethodesGRO(PGrapheOriente<CArc, CSommet<CArc>>* GROParam) {
    cout << "~*************************************~      CGRAPHORIENTE      ~*************************************~" << endl;

    //routine de test pour CGraphOriente
    cout << "\nTest sur la classe PGrapheOriente" << endl;
    //Creation de deux sommets
    GROParam->GROCreerSommet("Paris");
    //Verification des methodes : PGrapheOriente, CreerSommet, LireSommet, TrouverSomPos
    size_t posParis = GROParam->GROTrouverSommetPosition("Paris");
    assert(GROParam->GROLireSommet(posParis)->SOMLireNom() == "Paris");
    assert((GROParam->GROLireSommet(posParis)->SOMLireNom() == "paris") == false);
    assert(GROParam->GROTrouverSommetPosition("Paris") == posParis);
}