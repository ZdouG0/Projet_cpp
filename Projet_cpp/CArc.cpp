#include "CArc.h"


CArc::CArc() {
	sARCSommetDepart = "Le sommet de d�part n'a pas encore �t� parametr�";
	sARCSommetArrive = "Le sommet d'arriv� n'a pas encore �t� parametr�";
}

CArc::CArc(string sParamDepart, string sParamArrive) {
	sARCSommetDepart = sParamDepart;
	sARCSommetArrive = sParamArrive;
}