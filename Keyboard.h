#pragma once

namespace KeyType
{
	enum Type
	{
		Exe,
		Del,
		Number,
		LeftArrow,
		RightArrow,
		Other
	};
}

class Keyboard
{
public:
	static KeyType::Type getKeyType(unsigned int key);
	static int getDigit(unsigned int key);
};

