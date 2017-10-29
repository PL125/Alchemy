#pragma once
class Math
{
public:
	template <class T>
	static T max(T a, T b)
	{
		return a > b ? a : b;
	}

	template <class T>
	static T min(T a, T b)
	{
		return a < b ? a : b;
	}

	template <class T>
	static T abs(T n)
	{
		return n < 0 ? -n : n;
	}

	template <class T>
	static T pow(T n, T exp)
	{
		T result = 1;
		for(T i = 0; i < exp; ++i)
		{
			result *= n;
		}
		return result;
	}
};
