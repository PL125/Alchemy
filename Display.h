#pragma once
#include "String.h"

class Display
{
public:
	static void locate(int x, int y);

	static void printNumber(int number);
	static void printNumber(float number, int precision = 3);

	static void printExponent(int x, int y, int exponent);
	static void printExponent(int x, int y, String& str);
	
	static void printCharacter(char c);
	static void printString(String& str);
	static void printString(char* str);
	static void clear();
};

