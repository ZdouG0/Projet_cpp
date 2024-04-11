#include "CArc.h"


CArc::CArc() {
	sARCSommetDepart = "Le sommet de départ n'a pas encore été parametré";
	sARCSommetArrive = "Le sommet d'arrivé n'a pas encore été parametré";
}

CArc::CArc(string sParamDepart, string sParamArrive) {
	sARCSommetDepart = sParamDepart;
	sARCSommetArrive = sParamArrive;
}