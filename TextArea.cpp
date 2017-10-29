#include "TextArea.h"
#include "Display.h"
#include "Element.h"
#include "Math.h"

TextArea::TextArea(int x, int y, int w, int h)
	: x(x), y(y), cursorX(x), cursorY(y), width(w), height(h)
{
}

void TextArea::setCursor(int x, int y)
{
	this->cursorX = x;
	this->cursorY = y;
}

void TextArea::printNumber(int n)
{
	String s = String::fromNumber(n);
	printString(s);
}

void TextArea::printNumber(float number, int precision)
{
	int integer = (int)number;
	printNumber(integer);
	float decimal = Math::abs(number - integer);

	if (decimal <= 0.0001f)
	{
		return;
	}

	printCharacter('.');

	//Decimal *= 10^precision
	for (int i = 0; i < precision; i++)
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

void TextArea::printCharacter(char c)
{
	String s;
	s.push(c);
	printString(s);
}

void TextArea::printString(String& s)
{
	int length = s.getLength();

	locate();
	Display::printString(s);
	cursorX += length;
}

void TextArea::printString(char* str)
{
	String s = str;
	printString(s);
}

void TextArea::locate() const
{
	Display::locate(cursorX, cursorY);
}


void TextArea::printElement(const Element& element)
{
	String symbol = element.getSymbol();
	printString(symbol);
	int charge = element.getCharge();
	
	if(charge != 0)
	{
		String exp = String::fromNumber(Math::abs(charge));
		if(charge > 0)
		{
			exp.push('+');
		}
		else
		{
			exp.push('-');
		}
		printExponent(exp);
	}

}

void TextArea::printExponent(int number)
{
	String str = String::fromNumber(number);
	printExponent(str);
}

void TextArea::printExponent(String& s)
{
	int length = s.getLength();

	locate();
	Display::printExponent(cursorX, cursorY, s);
	cursorX += length;
}

bool TextArea::fitsInCurrentLine(int length) const
{
	return cursorX + length < x + width;
}

void TextArea::newLine()
{
	cursorY++;
	cursorX = x;
}
