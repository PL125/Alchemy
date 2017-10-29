#pragma once
#include "String.h"
class Element;
class TextArea
{
protected:
	int x, y;
	int cursorX, cursorY;

	const int width;
	const int height;

public:
	TextArea(int x, int y, int w = 21, int h = 8);
	void setCursor(int x, int y);

	void printNumber(int n);
	void printNumber(float number, int precision = 3);
	void printCharacter(char c);

	void printString(String& s);
	void printString(char* str);

	void printStringReverse(String& s);

	void locate() const;

	void printElement(const Element& element);

	void printExponent(int number);
	void printExponent(String& str);

	bool fitsInCurrentLine(int length) const;
	void newLine();
};

