#include "Element.h"
#include "ElementData.h"

Element::Element(int z, int charge)
	:z(z), charge(charge), electronNumber(z - charge)
{
}

ElectronicConfiguration Element::getElectronicConfiguration() const
{
	return ElectronicConfiguration(electronNumber);
}

int Element::getPeriod() const
{
	ElectronicConfiguration ec(z);
	const Orbital& o = ec.getLastOrbital();
	int period = o.level;

	switch(o.type)
	{
		case 'd': period++;    break;
		case 'f': period += 2; break;
	}

	return period;
}

int Element::getGroup() const
{
	if (z == 2)
	{
		return 18;
	}

	if(z == 71 || z == 103)
	{
		return 17;
	}

	ElectronicConfiguration ec(z);
	const Orbital& o = ec.getLastOrbital();
	int group = o.electronNumber;
	switch (o.type)
	{
		case 'p': group += 12; break;
		case 'd': group += 2;  break;
		case 'f': group += 2;  break;
	}

	return group;
}

float Element::getShielding() const
{
	if(electronNumber == 0)
	{
		return 0;
	}

	//Take account of charges in calculating what are kernel electrons
	Element e(electronNumber);

	int period = e.getPeriod();
	int periodElectrons[] = { 0, 2, 10, 18, 36, 54, 86, 118 };

	int kernelElectrons = periodElectrons[period - 1];
	int valenceElectrons = electronNumber - kernelElectrons;

	float shielding = kernelElectrons;
	shielding += (valenceElectrons - 1) / 2.0f;

	return shielding;
}

float Element::getEffectiveNuclearCharge() const
{
	return z - getShielding();
}

String Element::getSymbol() const
{
	return ElementData::getSymbol(z);
}

float Element::getRadius() const
{
	return ElementData::getRadius(z);
}

float Element::getIonizationEnergy() const
{
	return ElementData::getIonizationEnergy(z);
}

float Element::getElectronAffinity() const
{
	return ElementData::getElectronAffinity(z);
}

float Element::getElectroNegativity() const
{
	return ElementData::getElectroNegativity(z);
}

int Element::getAtomicNumber() const
{
	return z;
}

int Element::getCharge() const
{
	return charge;
}

int Element::getElectronNumber() const
{
	return electronNumber;
}
