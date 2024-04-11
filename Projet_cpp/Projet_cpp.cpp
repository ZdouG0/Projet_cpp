#include <iostream>
#include "CArc.h"
#include "CSommet.h"
#include <iterator>;
#include <string>;
#include <vector>;
#include "CGrapheOriente.h"


using namespace std;

int main()
{
    cout << "Hello World!"<<endl<<endl;
    /*
    //routine de test des methodes de la classe CArc
    cout << "test des methodes de CARC\n";
    CArc ARCVar;   // création d'un objet de la classe Carc
    string somA = "sommet A"; 
    string somB = "sommet B";
    ARCVar.ARCModifierSommetArrive(somA); //ajout d'un sommet d'arrivée
    ARCVar.ARCModifierSommetDepart(somB); //ajout d'un sommet de depart

    cout << "L'arc relie le sommet " + ARCVar.ARCLireDepart() + " au sommet " + ARCVar.ARCLireArrive();

    //routine de test des methodes de la classe CSommet
    cout << "\ntest des methodes de CARC\n";
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

    //on lit les sommets lie au notre
    cout << "\ntest de LireListSom\n";
    size_t stTaille;
    vector<string> s = SOMVar.SOMLireListSom();
    stTaille = SOMVar.SOMLireListSom().size();

    for (unsigned int uiBoucle = 0; uiBoucle <= stTaille-1; uiBoucle++) {
        cout << s[uiBoucle] <<endl;
    }

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
    cout << "\n\nTest des methodes de CGrapheOriente"<<endl;

    CGrapheOriente GROParam; //Creaction 'un objet de la classe graphe oriente
    GROParam.GROCreerSommet("Paris");
    GROParam.GROCreerSommet("Evry");
    GROParam.GROLireSommet(1);
    GROParam.GROCreerSommet("Courcouronnes");
    
    GROParam.GROCreerArc("Paris", "Evry");
    GROParam.GROCreerArc("Evry", "Courcouronnes");
    cout<<"Voici le premier arc de ma list d'arc " << GROParam.GROLireArc(0).ARCLireArrive()<< " - "<< GROParam.GROLireArc(0).ARCLireDepart();
    cout<<"Voici la position du Sommet Courcouronnes "<<GROParam.GROTrouverSommetPosition("Courcouronnes");
    GROParam.GROLireSommet(2);
    GROParam.GROSupprimerArc("Paris", "Evry");
    */
    

    //routine de test pour CFichier

    return 0;
}

