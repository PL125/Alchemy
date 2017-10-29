#include "Keyboard.h"
#include <keybios.h>

KeyType::Type Keyboard::getKeyType(unsigned key)
{
	if(key == KEY_CTRL_DEL)
	{
		return KeyType::Del;
	}
	else if(key == KEY_CTRL_EXE)
	{
		return KeyType::Exe;
	}
	else if(key == KEY_CTRL_LEFT)
	{
		return KeyType::LeftArrow;
	}
	else if(key == KEY_CTRL_RIGHT)
	{
		return KeyType::RightArrow;
	}
	else if(key >= 0x30 && key <= 0x39)
	{
		return KeyType::Number;
	}
	
	return KeyType::Other;
}

int Keyboard::getDigit(unsigned key)
{
	return key - 0x30;
}
