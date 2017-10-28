#pragma once
#include "ElectronicConfiguration.h"

class Element
{
protected:

	int z;
	int charge;
	int electronNumber;

public:

	Element(int z, int charge = 0);

	ElectronicConfiguration getElectronicConfiguration() const;

	int getPeriod() const;
	int getGroup() const;

	float getShielding() const;
	float getEffectiveNuclearCharge() const;

	String getSymbol() const;
	float getRadius() const;
	float getIonizationEnergy() const;
	float getElectronAffinity() const;
	float getElectroNegativity() const;

	int getAtomicNumber() const;
	int getCharge() const;
	int getElectronNumber() const;
};

