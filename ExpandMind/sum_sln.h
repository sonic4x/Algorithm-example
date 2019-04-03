#pragma once
/*
1 + 2 + 3... + n = ?
condition: cannot use if, while, for, switch...
*/
template <unsigned int n> struct sum_sln4
{
	enum value
	{
		N = sum_sln4<n - 1>::N + n
	};

};

template <>
struct sum_sln4<1>
{
	enum value
	{
		N = 1
	};

};