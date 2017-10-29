#include "Input.h"
#include "Display.h"
#include "Keyboard.h"
#include "Math.h"

Input::Input(int x, int y, int width)
	: x(x), y(y), width(width), count(0), resetNextFocus(false)
{
	for(int i = 0; i < width; i++)
	{
		input.push(' ');
	}
}

void Input::onKeyPressed(unsigned key)
{	
	KeyType::Type type = Keyboard::getKeyType(key);
	if (resetNextFocus && type != KeyType::Other)
	{
		resetNextFocus = false;
		count = 0;
		for (int i = 0; i < input.getSize(); i++)
		{
			input[i] = ' ';
		}
	}

	if(type == KeyType::Del)
	{
		count = Math::max(0, count - 1);
		input[count] = ' ';
	}
	else if(type == KeyType::Number)
	{
		if(count < width)
		{
			input[count] = Keyboard::getDigit(key) + '0';
			count++;
		}
	}

	Display::locate(x, y);
	Display::printStringReverse(input);
}

void Input::focus()
{

	Display::locate(x, y);
	Display::printStringReverse(input);
}

void Input::unfocus()
{
	Display::locate(x, y);
	Display::printString(input);
}

void Input::setDefault(const String& defaultString)
{
	for(int i = 0; i < defaultString.getLength(); i++)
	{
		input[i] = defaultString[i];
	}

	count = defaultString.getLength();
	resetNextFocus = true;
}

bool Input::empty() const
{
	return count == 0;
}

