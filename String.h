#pragma once
#include "Vector.h"

class String : public Vector<char>
{
protected:

	char* cStr;

public:
	String();
	String(const char* str);

	~String();

	const char* getString();
	int getSize() const;
	int getLength() const;

	static String fromNumber(int n);
};

