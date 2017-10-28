#include "Orbital.h"

Orbital::Orbital(int level, char type, int electronNumber)
 : level(level), type(type), electronNumber(electronNumber)
{
}

int Orbital::getMaxElectronsNumber(char type)
{
	int max = 0;
	switch (type)
	{
	case 's':
		max = 2;
		break;
	case 'p':
		max = 6;
		break;
	case 'd':
		max = 10;
		break;
	case 'f':
		max = 14;
		break;
	}
	return max;
}
