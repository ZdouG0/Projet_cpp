#include <iostream>
#include "CArc.h"
#include "CSommet.h"
#include <iterator>;
#include <string>;
#include <vector>;

using namespace std;

int main()
{
    cout << "Hello World!\n";

    //routine de test des methodes de la classe CArc
    
    CArc ARCVar;   // création d'un objet de la classe Carc
    string somA = "sommet A"; 
    string somB = "sommet B";
    ARCVar.ARCModifierSommetArrive(somA); //ajout d'un sommet d'arrivée
    ARCVar.ARCModifierSommetDepart(somB); //ajout d'un sommet de depart

    cout << "L'arc relie le sommet " + ARCVar.ARCLireDepart() + " au sommet " + ARCVar.ARCLireArrive();

    //routine de test des methodes de la classe CSommet
    CSommet SOMVar;

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

    //on ajoute nos arc a notre sommet 
    //les arc entrant (les sommets de X a A)
    SOMVar.SOMAjoutArcEntrant(&ARCVar3);
    SOMVar.SOMAjoutArcEntrant(&ARCVar4);

    //les arc sortant (les sommet de A a X)
    SOMVar.SOMAjoutArcSortant(&ARCVar);
    SOMVar.SOMAjoutArcSortant(&ARCVar2);

    //on lit les sommet lie au notre
    unsigned int uiTaille;
    vector<string>::iterator iter;
    vector<string> s = SOMVar.SOMLireListSom();
    iter = s.begin();
    uiTaille = SOMVar.SOMLireListSom().size();

    for (unsigned int uiBoucle = 0; uiBoucle <= uiTaille-1; uiBoucle++) {
        cout << *iter;
        iter++;
    }




       


}

