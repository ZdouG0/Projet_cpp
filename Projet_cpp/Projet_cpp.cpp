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
/*
int main()
{   
    
    cout << "Hello World!"<<endl<<endl;
    cout << "Debut des routines de Test" << endl;
    // routine de test de la classe CArc
    // création d'un objet de la classe Carc a partir du constructeur par défault
    CArc ARCVar;
    cout << "~*************************************~      CARC      ~*************************************~" << endl;
    cout << "\nTest sur la classe CArc" << endl;
    string somA = "sommet A"; 
    string somB = "sommet B";
    // ajout d'un sommet d'arrivée
    ARCVar.ARCModifierSommetArrive(somA);
    // ajout d'un sommet de depar
    ARCVar.ARCModifierSommetDepart(somB); 
    // création d'un objet de la classe CArc a partir du constructeur de recopie
    CArc* ARCVarCopie = new CArc(ARCVar);
    // creation d'un objet de la classe CArc à partir du constructeur de confort à deux argument
    CArc ARCVarConfort = CArc(somA, somB); 
    cout << "Les constructeurs de la classe CArc fonctionnent correctement" << endl;

    assert(ARCVarCopie->ARCLireDepart() == "sommet B");
    assert(ARCVarCopie->ARCLireDepart() == ARCVarConfort.ARCLireDepart() == false);
    assert(ARCVar.ARCLireArrive() == somA);
    assert(ARCVar.ARCLireArrive() == "sommet A");
    assert((ARCVarCopie->ARCLireArrive() == "sommet A ") == false);

    cout << "Les méthodes de CArc semblent fonctionner correctement " << endl;
    cout << "~********************************************************************************************~" << endl<<endl<<endl;
    
    //routine de test des methodes de la classe CSommet
    // création d'un objet de la classe Csommet a partir du constructeur par défault
    CSommet SOMVar;
    cout << "~*************************************~      CSOMMET      ~*************************************~" << endl;
    cout << "\nTest sur la classe CSommet" << endl;
    string nomSOM = "sommet A";
    SOMVar.SOMModifierNom(nomSOM);
    assert(SOMVar.SOMLireNom() == nomSOM);
    assert((SOMVar.SOMLireNom() == "sommet a") == false );
    CSommet SOMConfort = CSommet("sommet Z");
    assert(SOMConfort.SOMLireNom() == "sommet Z");
    assert((SOMConfort.SOMLireNom() == nomSOM) == false);
    cout << "Les constructeurs de la classe CArc fonctionnent correctement" << endl;
    //______________________________________________________________________________________
    // Creation d'arc pour remplir la liste

    // création d'un objet de la classe Carc  qui va relier les sommet A et C
    CArc ARCVar2;   
    string somC = "sommet C";
    ARCVar2.ARCModifierSommetArrive(somA); //ajout d'un sommet d'arrivée
    ARCVar2.ARCModifierSommetDepart(somC); //ajout d'un sommet de depart

    // création d'un objet de la classe Carc qui va relier les sommet D et A 
    CArc ARCVar3;   
    string somD = "sommet D";
    ARCVar3.ARCModifierSommetArrive(somD); //ajout d'un sommet d'arrivée
    ARCVar3.ARCModifierSommetDepart(somA); //ajout d'un sommet de depart

    CArc ARCVar4;   // création d'un objet de la classe Carc qui va relier les sommet E et A 
    string somE = "sommet E";
    ARCVar4.ARCModifierSommetArrive(somE); //ajout d'un sommet d'arrivée
    ARCVar4.ARCModifierSommetDepart(somA); //ajout d'un sommet de depart
    //____________________________________________________________________________________
    //on ajoute nos arc a notre sommet 
    //les arc entrant (les sommets de X a A)
    SOMVar.SOMAjoutArcEntrant(&ARCVar3);
    SOMVar.SOMAjoutArcEntrant(&ARCVar4);

    //les arc sortant (les sommet de A a X)
    SOMVar.SOMAjoutArcSortant(&ARCVar);
    SOMVar.SOMAjoutArcSortant(&ARCVar2);



    /*
    //on test maintenant les fonctions SOMLireElemListArcEntrant SOMLireElemListArcSortant
    //pour cela comme un arc n'a pas de nom on va afficher les sommets auquel il est lié
    CArc* ARCVar5 = SOMVar.SOMLireElemListArcEntrant(1); //on doit obtenir ARCVar5 = ARCVar4
    CArc* ARCVar6 = SOMVar.SOMLireElemListArcSortant(1); //on doit obtenir ARCVar6 = ARCVar2


    
    assert(ARCVar5->ARCLireArrive() == ARCVar4.ARCLireArrive());
    assert(ARCVar5->ARCLireDepart() == ARCVar4.ARCLireDepart());
    assert((ARCVar5->ARCLireArrive() == ARCVar4.ARCLireDepart()) == false);
    cout << "Les methodes de CSommet semblent fonctionner correctement " << endl;
    cout << "~********************************************************************************************~" << endl << endl << endl;*/


    // Creaction d'un objet de la classe graphe oriente
    CGrapheOriente GROParam; 
    cout << "~*************************************~      CGRAPHORIENTE      ~*************************************~" << endl;
    
    
    //routine de test pour CGraphOriente
    cout << "\nTest sur la classe CGrapheOriente" << endl;

    
    //Creation de deux sommets
    GROParam.GROCreerSommet("Paris");
    string Capitale = "Paris";
    GROParam.GROCreerSommet(Capitale);
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
    cout << "Toutes les methdoes relatives aux sommets dans le grapheOriente sont testes et semblent fonctionnels" << endl;
    cout << "***************************************************************************************" << endl;


    cout<<"Voici le premier arc de ma list d'arc " << GROParam.GROLireArc(0)->ARCLireArrive()<< " - "<< GROParam.GROLireArc(0)->ARCLireDepart()<<endl;
    cout<<"Voici la position du Sommet Courcouronnes "<<GROParam.GROTrouverSommetPosition("Courcouronnes")<<endl;
    GROParam.GROLireSommet(2);
  
    cout << GROParam.GROLireArc(0)->ARCLireArrive()<<endl;
    GROParam.GROSupprimerSommet("Paris");
    for(int i = 0; i < GROParam.GROLireTailleListArc(); i++) {
        string s = GROParam.GROLireArc(i)->ARCLireArrive();
        string s2 = GROParam.GROLireArc(i)->ARCLireDepart();
        cout << s2 << " - " << s<<endl;
    }
    cout << endl << endl << endl;
    GROParam.GROSupprimerArc("Paris", "Evry");
    
    
    /*
    
    
    //routine de test pour CFichier
    CFichier FICMonFichier;

    // test de FICModifierNomFichier
    FICMonFichier.FICModifierNomFichier("fichiertest.txt");

    CTest TestParam;
    TestParam.TESTestMethodesSOM(SOMVar);
    TestParam.TESTestMethodesGRO(GROParam);
       
    //CTest TestParam;
    //TestParam.TESTestMethodesARC(ARCVar5);
    //TestParam.TESTestMethodesSOM(SOMVar);
    //TestParam.TESTestMethodesGRO(GROParam);
      
    //test de FICLireNomFichier
    cout << "Le nom du fichier est " + FICMonFichier.FICLireNomFichier() << endl;

    //test de FILRecupNombre
    string sTest = "On veut recuperer le nombre 821 qui se trouve apres nombre";
    //le 7 represente la taille de notre balise
    cout << "le nombre cherche est " << FICMonFichier.FILRecupNombre(sTest.find("nombre")+7, sTest.find("qui")-1, sTest) << endl ;

    //test de FILRecupNombre
    sTest = " On veut recuperer le nom de sommet numero=Tours, au milieu de ce string";
    // la taille de notre balise est de 7
    cout << "le nom du sommet est " << FICMonFichier.FILRecupNom(sTest.find("numero=") + 7, sTest.find(',') , sTest) << endl;

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

*/