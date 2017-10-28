#include "Memory.h"

void Memory::memcpy(void* destination, void* source, size_t size)
{
	unsigned char* src = (unsigned char*)source;
	unsigned char* dest = (unsigned char*)destination;

	for (size_t s = 0; s < size; s++)
	{
		dest[s] = src[s];
	}
}
