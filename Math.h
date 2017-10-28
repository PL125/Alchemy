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
};
