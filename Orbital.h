#pragma once
class Orbital
{
public:
	int level;
	char type;
	int electronNumber;
public:
	Orbital(int level, char type, int electronNumber);

	static int getMaxElectronsNumber(char type);
};

