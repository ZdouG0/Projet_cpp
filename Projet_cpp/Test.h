#pragma once
#include "PGrapheOriente.h"
#include "assert.h"
#include <iostream>


class CTest
{
public:
	void TESTestMethodesARC(CArc ARCParam);
	void TESTestMethodesARC(CArc* ARCParam);


	void TESTestMethodesSOM(PSommet<CArc> SOMParam);
	void TESTestMethodesSOM(PSommet<CArc>* SOMParam);




	void TESTestMethodesGRO(PGrapheOriente<CArc, PSommet<CArc>> GROParam);
	void TESTestMethodesGRO(PGrapheOriente<CArc,PSommet<CArc>>* GROParam);
};

