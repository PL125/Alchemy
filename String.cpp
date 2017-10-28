#include "String.h"
#include "Math.h"

String::String()
	: Vector()
{
	cStr = (char*) malloc(sizeof(char));
}

String::String(const char* str)
{
	int count = 0;
	while(str[count] != '\0')
	{
		push(str[count]);
		count++;
	}
	
	cStr = (char*)malloc(sizeof(char) * (count +  1));
}

String::~String()
{
	free(cStr);
}

const char* String::getString()
{
	cStr = (char*) realloc(cStr, sizeof(char) * (count + 1));
	Memory::memcpy(cStr, data, sizeof(char) * count);
	cStr[count] = '\0';
	return cStr;
}

int String::getSize() const
{
	return count + 1;
}

int String::getLength() const
{
	return count;
}

String String::fromNumber(int number)
{
	char buffer[11];
	int count = 0;

	bool negative = number < 0;
	number = Math::abs(number);

	do {
		char digit = '0' + number % 10;
		buffer[count++] = digit;
		number /= 10;
	} while (number > 0);
	count--;

	String result;

	if(negative)
	{
		result.push('-');
	}

	while (count >= 0) {
		result.push(buffer[count]);
		count--;
	}

	return result;
}