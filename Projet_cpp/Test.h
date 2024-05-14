#pragma once
#include "PGrapheOriente.h"
#include "assert.h"
#include <iostream>


class CTest
{
public:
	void TESTestMethodesARC(CArc ARCParam);
	void TESTestMethodesARC(CArc* ARCParam);


	void TESTestMethodesSOM(CSommet SOMParam);
	void TESTestMethodesSOM(CSommet* SOMParam);




	void TESTestMethodesGRO(PGrapheOriente<CArc> GROParam);
	void TESTestMethodesGRO(PGrapheOriente<CArc>* GROParam);
};

