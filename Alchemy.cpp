#include "Display.h"
#include "ElectronicConfiguration.h"
#include "Element.h"
#include "Math.h"
#include "TextArea.h"

extern "C" {
	
	#include "fxlib.h"

	void printInformation(Element& e, TextArea& t)
	{
		t.setCursor(1, 2);
		t.printString("P:");
		t.printNumber(e.getPeriod());
		t.printString(" G:");
		t.printNumber(e.getGroup());

		t.setCursor(10, 2);
		t.printString("R:");
		t.printNumber(e.getRadius());
		t.setCursor(16, 2);
		t.printString("a:");
		t.printNumber(e.getShielding());
		t.setCursor(1, 3);
		t.printString("Z");
		String asterisc = "*";
		t.printExponent(asterisc);
		t.printString(":");
		t.printNumber(e.getEffectiveNuclearCharge());

		t.setCursor(10, 3);
		t.printString("IE:");
		t.printNumber(e.getIonizationEnergy());
		t.setCursor(1, 4);
		t.printString("EA:");
		t.printNumber(e.getElectronAffinity());
		t.setCursor(10, 4);
		t.printString("X:");
		t.printNumber(e.getElectroNegativity(), 2);

		ElectronicConfiguration ec = e.getElectronicConfiguration();

		t.setCursor(1, 5);
		ec.printReduced(t);

		t.setCursor(1, 6);
		ec.printExtended(t);
	}

	int AddIn_main(int isAppli, unsigned short OptionNum)
	{
		unsigned int key;

		Element e(86, -25);

		Display::clear();
		TextArea t(1, 1);

		t.printString("Z:");
		t.printNumber(e.getAtomicNumber());
		t.setCursor(7, 1);
		t.printString("Charge:+10");
		t.setCursor(18, 1);
		t.printElement(e);

		printInformation(e, t);


		//Display::drawLine(0, 8, 127, 8);
		while (1) {
			GetKey(&key);
		}

		return 1;
	}



#pragma section _BR_Size
	unsigned long BR_Size;
#pragma section


#pragma section _TOP

	int InitializeSystem(int isAppli, unsigned short OptionNum)
	{
		return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
	}

#pragma section

}

