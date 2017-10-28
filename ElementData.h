#pragma once
#include "String.h"

struct ElementData
{
	char* symbol;
	float radius;
	float ionizationEnergy;
	float electronAffinity;
	float electroNegativity;
	
	static String getSymbol(int z);
	static float getRadius(int z);
	static float getIonizationEnergy(int z);
	static float getElectronAffinity(int z);
	static float getElectroNegativity(int z);
};