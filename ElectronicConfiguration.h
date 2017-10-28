#pragma once
#include "Orbital.h"
#include "Vector.h"
#include "String.h"

class ElectronicConfiguration
{
protected: 
	static const char* orbitalsOrder[];

public:

	Vector<Orbital> orbitals;
	int electronsNumber;

	ElectronicConfiguration(int e);
	Orbital getLastOrbital() const;
};
