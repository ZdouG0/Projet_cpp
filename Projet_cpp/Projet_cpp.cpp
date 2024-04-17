#include <iostream>
#include <iterator>;
#include <string>;
#include <vector>;
#include "CGrapheOriente.h"
#include "assert.h"



using namespace std;

int main()
{
    cout << "Hello World!"<<endl<<endl;
    cout << "Debut des routines de Test" << endl;
    // routine de test de la classe CArc
    // création d'un objet de la classe Carc a partir du constructeur par défault
    CArc ARCVar;
    cout << "~*************************************~      CARC      ~*************************************~" << endl;
    string somA = "sommet A"; 
    string somB = "sommet B";
    // ajout d'un sommet d'arrivée
    ARCVar.ARCModifierSommetArrive(somA);
    // ajout d'un sommet de depar
    ARCVar.ARCModifierSommetDepart(somB); 
    // création d'un objet de la classe CArc a partir du constructeur de recopie
    CArc* ARCVarCopie = new CArc(ARCVar);
    
    CArc ARCVarConfort = CArc(somA, somB); // creation d'un objet de la classe CArc à partir du constructeur de confort à deux argument
    assert(ARCVarCopie->ARCLireDepart() == "sommet B");
    assert(ARCVarCopie->ARCLireDepart() == ARCVarConfort.ARCLireDepart() == false);
    cout << endl;
    cout << "Les constructeurs de la classe CArc fonctionnent correctement"<<endl;
    cout << "~********************************************************************************************~" << endl<<endl<<endl;
    cout << "~*************************************~      CSOMMET      ~*************************************~" << endl;
    //routine de test des methodes de la classe CSommet
    CSommet SOMVar;
    cout << "\ntest des modifiernom et lirenom\n";
    string nomSOM = "sommet A";
    SOMVar.SOMModifierNom(nomSOM);
    cout << "Le nom de notre sommet est " + SOMVar.SOMLireNom() << endl;

    //______________________________________________________________________________________
    // Creation d'arc pour remplir la liste
    CArc ARCVar2;   // création d'un objet de la classe Carc  qui va relier les sommet A et C
    string somC = "sommet C";
    ARCVar2.ARCModifierSommetArrive(somA); //ajout d'un sommet d'arrivée
    ARCVar2.ARCModifierSommetDepart(somC); //ajout d'un sommet de depart

    CArc ARCVar3;   // création d'un objet de la classe Carc qui va relier les sommet D et A 
    string somD = "sommet D";
    ARCVar3.ARCModifierSommetArrive(somD); //ajout d'un sommet d'arrivée
    ARCVar3.ARCModifierSommetDepart(somA); //ajout d'un sommet de depart

    CArc ARCVar4;   // création d'un objet de la classe Carc qui va relier les sommet E et A 
    string somE = "sommet E";
    ARCVar4.ARCModifierSommetArrive(somE); //ajout d'un sommet d'arrivée
    ARCVar4.ARCModifierSommetDepart(somA); //ajout d'un sommet de depart
    //____________________________________________________________________________________
    cout << "\ntest des AjoutArcentrant et AjoutArcSortant\n";
    //on ajoute nos arc a notre sommet 
    //les arc entrant (les sommets de X a A)
    SOMVar.SOMAjoutArcEntrant(&ARCVar3);
    SOMVar.SOMAjoutArcEntrant(&ARCVar4);

    //les arc sortant (les sommet de A a X)
    SOMVar.SOMAjoutArcSortant(&ARCVar);
    SOMVar.SOMAjoutArcSortant(&ARCVar2);




    //on test maintenant les fonctions SOMLireElemListArcEntrant SOMLireElemListArcSortant
    cout << "\ntest de SOMLireElemListArcEntrant SOMLireElemListArcSortant\n";
    //pour cela comme un arc n'a pas de nom on va afficher les sommets auquel il est lié
    CArc* ARCVar5 = SOMVar.SOMLireElemListArcEntrant(1); //on doit obtenir ARCVar5 = ARCVar4
    CArc* ARCVar6 = SOMVar.SOMLireElemListArcSortant(1); //on doit obtenir ARCVar6 = ARCVar2

    
    cout << "les deux arc doivent etres les meme\n";
    cout << "ARCVar5 : sommet de d'arrive " + ARCVar5->ARCLireArrive() + " sommet de depart " + ARCVar5->ARCLireDepart() << endl;
    cout << "ARCVar4 : sommet de d'arrive " + ARCVar4.ARCLireArrive() + " sommet de depart " + ARCVar4.ARCLireDepart() << endl;
    cout << "\n";
    cout << "les deux arc doivent etres les meme\n";
    cout << "ARCVar6 : sommet de d'arrive " + ARCVar6->ARCLireArrive() + " sommet de depart " + ARCVar6->ARCLireDepart() << endl;
    cout << "ARCVar2 : sommet de d'arrive " + ARCVar2.ARCLireArrive() + " sommet de depart " + ARCVar2.ARCLireDepart() << endl;

    
    //routine de test pour CGraphOriente
    cout << "\nTest des methodes de CGrapheOriente"<<endl;

    CGrapheOriente GROParam; //Creaction 'un objet de la classe graphe oriente
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

    cout << endl<<endl;
    cout << "***************************************************************************************" << endl;
    cout << "Le constructeur par defaut, et les methodes CreerSommet, LireSommet, TrouverSomPos, LireTailleListSommet fonctionnent" << endl;
   

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


       

    return 0;
}

