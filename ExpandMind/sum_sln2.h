#pragma once
/*
1 + 2 + 3... + n = ?
condition: cannot use if, while, for, switch...
*/
typedef unsigned int(*func)(unsigned int);

unsigned int sln2_terminator(unsigned int n)
{
	return 0;
}

unsigned int nSum(unsigned int n)
{
	func f[2] = { sln2_terminator, nSum };
	return n + f[!!(n-1)](n - 1);
}


