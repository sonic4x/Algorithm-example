#pragma once
/*
1 + 2 + 3... + n = ?
condition: cannot use if, while, for, switch...
*/

#include <functional>
using namespace std;


unsigned int sln3_terminator(unsigned int n)
{
	return 0;
}

unsigned int sln3(unsigned int n)
{
	function<unsigned int(unsigned int)> f[2] = { sln3_terminator, sln3 };
	return n + f[!!(n - 1)](n - 1);
}

