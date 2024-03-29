#include <iostream>
#include "CArc.h"
#include "CSommet.h"
using namespace std;

int main()
{
    cout << "Hello World!\n";

    //routine de test des methodes de la classe CArc
    
    CArc ARCVar;
    string somA = "sommet A";
    string somB = "sommet B";
    ARCVar.ARCModifierSommetArrive(somA);
    ARCVar.ARCModifierSommetDepart(somB);

    cout << "L'arc relie le sommet " + ARCVar.ARCLireDepart() + " au sommet " + ARCVar.ARCLireArrive();

    //routine de test des methodes de la classe CSommet


        

}

