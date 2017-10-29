#include "Display.h"
#include "ElectronicConfiguration.h"
#include "Element.h"
#include "Math.h"
#include "TextArea.h"
#include "Input.h"
#include "Keyboard.h"
#include <keybios.h>

extern "C" {
	
	#include "fxlib.h"

	void printInformation(Element& e, TextArea& t)
	{

		Display::clearArea(0, 8, 127, 63);
		t.setCursor(18, 1);
		t.printString("     ");
		t.setCursor(18, 1);
		t.printElement(e);

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

		Element e(86, -25);

		Display::clear();
		TextArea t(1, 1);

		t.printString("Z:");
		t.setCursor(7, 1);
		t.printString("Charge:");

		//printInformation(e, t);

		Input inputZ(3, 1, 3);
		inputZ.focus();

		Input chargeInput(15, 1, 2);
		chargeInput.setDefault("0");
		chargeInput.unfocus();

		Input* focused = &inputZ;
		char chargeSign = '+';

		Display::locate(14, 1);
		Display::printCharacter(chargeSign);

		unsigned int key;
		while (true) {
			GetKey(&key);

			KeyType::Type type = Keyboard::getKeyType(key);
			if(type == KeyType::LeftArrow)
			{
				inputZ.focus();
				chargeInput.unfocus();
				focused = &inputZ;
				Display::locate(14, 1);
				Display::printCharacter(chargeSign);
			}
			else if(type == KeyType::RightArrow)
			{		
				inputZ.unfocus();
				chargeInput.focus();
				focused = &chargeInput;

				Display::locate(14, 1);
				Display::printCharacterReverse(chargeSign);
			}
			else if(type == KeyType::Exe && !inputZ.empty() && !chargeInput.empty())
			{
				int sign = chargeSign == '-' ? -1 : 1;
				
				int charge = chargeInput.getNumber() * sign;
				int z = inputZ.getNumber();

				if(z > 0 && z <= 118 && z - charge >= 0)
				{
					Element e(z, charge);
					printInformation(e, t);
				}

			}
			else if(key == 0x89)
			{
				//Plus
				if(focused == &chargeInput)
				{
					chargeSign = '+';
					Display::locate(14, 1);
					Display::printCharacterReverse(chargeSign);
				}
			}
			else if(key == 0x99)
			{
				//Minus
				if (focused == &chargeInput)
				{
					chargeSign = '-';
					Display::locate(14, 1);
					Display::printCharacterReverse(chargeSign);
				}
			}
			else if (key == KEY_CTRL_EXIT)
			{
				break;
			}
			else
			{
				focused->onKeyPressed(key);
			}

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

