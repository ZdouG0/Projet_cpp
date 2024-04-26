#pragma once
#include "CGrapheOriente.h"
#include "assert.h"
#include <iostream>


class CTest
{
public:
	void TESTestMethodesARC(CArc ARCParam);
	void TESTestMethodesARC(CArc* ARCParam);


	void TESTestMethodesSOM(CSommet SOMParam);
	void TESTestMethodesSOM(CSommet* SOMParam);




	void TESTestMethodesGRO(CGrapheOriente GROParam);
	void TESTestMethodesGRO(CGrapheOriente* GROParam);
};

