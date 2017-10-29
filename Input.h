#pragma once
#include "String.h"

class Input
{
private:
	int x, y;
	int width;

	int count;
	String input;
	
	bool resetNextFocus;

public:

	Input(int x, int y, int width);
	void onKeyPressed(unsigned int key);
	void focus();
	void unfocus();
	void setDefault(const String& defaultString);

	bool empty() const;
	int getNumber() const;
};

