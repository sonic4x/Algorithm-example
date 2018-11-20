// FindMinimalK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
//K=0, return the min 

int partition(int a[], int lo, int hi)
{
	if (lo >= hi)
		return hi;
	int i = lo;
	int j = hi + 1;
	int t = a[lo];
	int rt;
	while (i < j)
	{
		do
			i++;
		while (i < hi && a[i] < t);

		do {
			j--;
		} while (a[j] > t);

		if (i > j)
			break;

		swap(a[i], a[j]);
	}
	swap(a[lo], a[j]);  //note here is not swap(t,a[j])
	// pivot is j now
	return j;
}

//non-recursive version
int FindMinimalK_nonRecursive(int a[], int len, int k)
{
	if (k < 0 || k > len - 1)
	{
		throw std::exception("invalid input");
	}
	
	int lo = 0;
	int hi = len - 1;
	while (true)
	{
		int pivot = partition(a, lo, hi);
		if (pivot > k)
		{
			hi = pivot - 1;
		}
		else if (pivot < k)
		{
			lo = pivot + 1;
		}
		else
		{
			return a[pivot];
		}
	}
}
int FindMinimalK_recursive(int a[], int lo, int hi, int k)
{
	if (lo >= hi)
		return a[hi];

	int i = lo;
	int j = hi + 1;
	int t = a[lo];
	int rt;
	while (i < j)
	{
		do
			i++;
		while (i < hi && a[i] < t);

		do {
			j--;
		} while (a[j] > t);

		if (i > j)
			break;

		swap(a[i], a[j]);
	}
	swap(t, a[j]);     //problem, should be swap(a[lo], a[j]
	// pivot is j now
	if (j < k)
		rt = FindMinimalK_recursive(a, j + 1, hi, k);
	else if (j > k)
		rt = FindMinimalK_recursive(a, lo, j - 1, k);
	else
		rt = a[j];
	return rt;
}

int main()
{
	int a[] = { 3,9, 4, 6, 7, 8,2, 5,11,7 };
	int len = sizeof(a) / sizeof(a[0]);
	int k = 0;
	int MinimalKValue = FindMinimalK_nonRecursive(a, len, k);
	cout << MinimalKValue << endl;

	int a2[] = { 3,9, 4, 6, 7, 8,2, 5,11,7 };
	int minK = FindMinimalK_recursive(a2, 0, len - 1, k);
	cout << minK << endl;
	getchar();
    return 0;
}

