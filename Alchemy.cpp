#include "Display.h"
#include "ElectronicConfiguration.h"
#include "Element.h"
#include "Math.h"

extern "C" {
	
	#include "fxlib.h"

	int AddIn_main(int isAppli, unsigned short OptionNum)
	{
		unsigned int key;

		Display::clear();

		Element e(12, -1);

		Display::locate(1, 1);
		String symbol = e.getSymbol();
		Display::printString(symbol);

		int charge = e.getCharge();
		if(charge != 0)
		{
			String exp = String::fromNumber(Math::abs(charge));
		
			if(charge < 0)
			{
				exp.push('-');
			}
			else
			{
				exp.push('+');
			}
				
			Display::printExponent(3, 1, exp);
		}

		Display::locate(1, 2);
		Display::printNumber(e.getRadius());

		Display::locate(1, 3);
		Display::printNumber(e.getIonizationEnergy());

		Display::locate(1, 4);
		Display::printNumber(e.getElectronAffinity());

		Display::locate(1, 5);
		Display::printNumber(e.getElectroNegativity());

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

