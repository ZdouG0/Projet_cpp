#include "CArc.h"


CArc::CArc() {
	sARCSommetDepart = "Le sommet de depart n'a pas encore �t� parametre";
	sARCSommetArrive = "Le sommet d'arrive n'a pas encore �t� parametre";
}

CArc::CArc(string sParamDepart, string sParamArrive) {
	sARCSommetDepart = sParamDepart;
	sARCSommetArrive = sParamArrive;
}