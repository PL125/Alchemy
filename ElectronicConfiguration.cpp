#include "ElectronicConfiguration.h"
#include "Element.h"

const char* ElectronicConfiguration::orbitalsOrder[] = {
	"1s","2s", "2p", "3s", "3p", "4s", "3d", "4p", "5s", "4d", "5p", "6s", "4f", "5d", "6p", "7s", "5f", "6d", "7p", "6f", "7d", "7f"
};

ElectronicConfiguration::ElectronicConfiguration(int e)
	: electronsNumber(e)
{
	int electronsRemaining = electronsNumber, currentOrbital = 0;
	while (electronsRemaining > 0)
	{
		const char* orbital = orbitalsOrder[currentOrbital++];
		int level = orbital[0] - '0';
		char type = orbital[1];

		int electronNumber = Orbital::getMaxElectronsNumber(type) > electronsRemaining ? electronsRemaining : Orbital::getMaxElectronsNumber(type);
		electronsRemaining -= electronNumber;

		orbitals.push(Orbital(level, type, electronNumber));
	}
}

Orbital ElectronicConfiguration::getLastOrbital() const
{
	return orbitals[orbitals.getSize() - 1];
}

void ElectronicConfiguration::printReduced(TextArea& area) const
{

	Element e(electronsNumber);

	int period = e.getPeriod();
	char* periodStrings[] = {"He", "Ne", "Ar", "Kr", "Xe", "Rn"};

	if(period > 1)
	{
		area.printString("[");
		area.printString(periodStrings[period - 2]);
		area.printString("]");
	}

	bool print = false;
	for(int i = 0; i < orbitals.getSize(); i++)
	{
		const Orbital& o = orbitals[i];
			
		if(o.level == period)
		{
			print = true;
		}

		if (print)
		{
			area.printNumber(o.level);
			area.printCharacter(o.type);
			area.printExponent(o.electronNumber);
		}

	}

}

void ElectronicConfiguration::printExtended(TextArea& area) const
{
	for(int i = 0; i < orbitals.getSize(); i++)
	{
		const Orbital& o = orbitals[i];
		if(!area.fitsInCurrentLine(o.getStringLength()))
		{
			area.newLine();
		}

		area.printNumber(o.level);
		area.printCharacter(o.type);
		area.printExponent(o.electronNumber);
	}
}
