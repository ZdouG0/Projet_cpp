#include "PGraph.h"

template<class T, class S>
void PGraph<T, S>::GROCreerArc(string sParamDepart, string sParamArrive) {
    PGrapheOriente<T, S>::GROCreerArc(sParamDepart, sParamArrive);
    PGrapheOriente<T, S>::GROCreerArc(sParamArrive, sParamDepart);
}

template<class T, class S>
void PGraph<T, S>::GROCreerArc(string sParamDepart, string sParamArrive, unsigned int uiPoids) {
    PGrapheOriente<T, S>::GROCreerArc(sParamDepart, sParamArrive);
    PGrapheOriente<T, S>::GROCreerArc(sParamArrive, sParamDepart);
}

template<class T, class S>
void PGraph<T, S>::GROSupprimerArc(string chParamDepart, string chParamArrive) {
    PGrapheOriente<T, S>::GROSupprimerArc(chParamDepart, chParamArrive);
    PGrapheOriente<T, S>::GROSupprimerArc(chParamArrive, chParamDepart);
}

template<class T, class S>
void PGraph<T, S>::GROArbreNonReflexif() {
    unsigned int uiCompteurIter = 0;
    unsigned int uiCompteurIter2 = 2;
    unsigned int uiMin;
    unsigned int uiMax = 0;
    auto iter = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter);
    auto iter2 = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter2);
    while (uiCompteurIter < PGrapheOriente<T, S>::GROLireTailleListArc() - 2) {
        if (iter->ARCLireArrive() == iter->ARCLireDepart()) {
            string sParam1 = iter->ARCLireDepart();
            uiCompteurIter2 += 1;
            uiMin = iter->PGrapheOriente<T, S>::LirePoids();
            if (uiMin > uiMax) {
                uiMax = uiMin;
            }
            iter2 = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter2);
            PGrapheOriente<T, S>::GROSupprimerArc(sParam1, sParam1,uiMax);
        }
        else if (iter->ARCLireDepart() == iter2->ARCLireDepart()) {
            if (iter->ARCLireArrive() == iter2->ARCLireArrive()) {
                string sParam1 = iter->ARCLireDepart();
                string sParam2 = iter->ARCLireArrive();
                if (uiMax < uiMin) {
                    uiMin = uiMax;
                }
                try {
                    uiMax = iter->PGrapheOriente<T, S>::LirePoids();
                    
                    PGrapheOriente<T, S>::GROSupprimerArc(sParam1, sParam2);
                }
                catch (CException EXCErreur) {
                    uiCompteurIter2++;
                    iter2 = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter2);
                    PGrapheOriente<T, S>::GROCreerArc(sParam1, sParam2,uiMin);
                }
            }
            else {
                if (uiCompteurIter2 < PGrapheOriente<T, S>::GROLireTailleListSommet() - 1) {
                    uiCompteurIter2++;
                    iter2 = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter2);
                }
                else {
                    uiCompteurIter++;
                    uiCompteurIter2 = uiCompteurIter + 1;
                    iter = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter);
                    iter2 = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter2);
                }
            }
        }
        
        else { //ils sont differents
            if (uiCompteurIter2 < PGrapheOriente<T, S>::GROLireTailleListSommet() - 1) {
                uiCompteurIter2++;
                iter2 = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter2);
            }
            else {
                uiCompteurIter++; //car cgraph
                uiCompteurIter2 = uiCompteurIter + 1;
                iter = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter);
                iter2 = PGrapheOriente<T, S>::GROLireArc(uiCompteurIter2);
            }
        }
    }
    
}

