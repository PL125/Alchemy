#include "Display.h"
#include "dispbios.h"
#include "Math.h"

extern "C" {
	#include "fxlib.h"
}

void Display::locate(int x, int y)
{
	::locate(x, y);
}

void Display::drawLine(int x1, int y1, int x2, int y2)
{
	Bdisp_DrawLineVRAM(x1, x2, y1, y2);
}

void Display::printNumber(int number)
{
	String s = String::fromNumber(number);
	printString(s);
}

void Display::printNumber(float number, int precision)
{
	int integer = (int)number;
	printNumber(integer);
	float decimal = Math::abs(number - integer);
	
	if(decimal <= 0.0001f)
	{
		return;
	}

	printCharacter('.');

	//Decimal *= 10^precision
	for(int i = 0; i < precision; i++)
	{
		decimal *= 10;
		
		if (decimal - (int)decimal <= 0.0001f)
		{
			break;
		}
	}

	int dec = (int)decimal;
	printNumber(dec);
}

void Display::printExponent(int x, int y, int exponent)
{
	int posx = 6 * (x - 1) + 1;
	int posy = 8 * (y - 1);

	String s = String::fromNumber(exponent);
	PrintMini(posx, posy, (const unsigned char*)s.getString(), MINI_OVER);
}

void Display::printExponent(int x, int y, String& str)
{
	int posx = 6 * (x - 1) + 1;
	int posy = 8 * (y - 1);

	PrintMini(posx, posy, (const unsigned char*)str.getString(), MINI_OVER);
}

void Display::printCharacter(char c)
{
	char buffer[2] = { c, 0 };
	PrintC((const unsigned char*)buffer);
}

void Display::printString(String& str)
{
	Print((const unsigned char*) str.getString());
}

void Display::printString(char* str)
{
	String s(str);
	printString(s);
}

void Display::clear()
{
	Bdisp_AllClr_DDVRAM();
}
