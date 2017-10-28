#pragma once

#include <stdlib.h>
#include "Memory.h"

template <class T>
class Vector
{
protected:
	T* data;
	size_t count;
	size_t size;
public:
	Vector()
	{
		size = 8;
		data = (T*)malloc(sizeof(T) * size);
		count = 0;
	}

	Vector(const Vector<T>& other)
	{
		data = (T*)malloc(sizeof(T) * other.size);
		size = other.size;
		count = other.count;
		Memory::memcpy(data, other.data, sizeof(T) * count);
	}

	Vector& operator=(const Vector<T>& other)
	{
		data = (T*)realloc(data, sizeof(T) * other.size);
		size = other.size;
		count = other.count;
		Memory::memcpy(data, other.data, sizeof(T) * count);
		return *this;
	}

	template <size_t N>
	Vector(T (&arr)[N])
	{
		size = N;
		count = N;
		data = (T*)malloc(sizeof(T) * size);
	}

	void push(const T& e)
	{
		if (count >= size)
		{
			size *= 2;
			data = (T*)realloc(data, sizeof(T) * size);
		}
		data[count++] = e;
	}

	void push(const Vector<T>& e)
	{
		for(int i = 0; i < e.getSize(); i++)
		{
			push(e[i]);
		}
	}

	~Vector()
	{
		free(data);
	}

	T& operator[](size_t index)
	{
		return data[index];
	}

	const T& operator[](size_t index) const
	{
		return data[index];
	}

	int getSize() const
	{
		return count;
	}
};
