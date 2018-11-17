// FindMinimalK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
//K=0, return the min 

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
	swap(t, a[j]);
	// pivot is j now
	if (j < k)
		rt = FindMinimalK_recursive(a, j + 1, hi, k);
	else if (j > k)
		rt = FindMinimalK_recursive(a, lo, j - 1, k);
	else
		rt = a[j];
	return rt;
}
int FindMinimalK(int a[], int lo, int hi, int k)
{
	
	int l = lo;
	int h = hi;

	while (true)
	{
		int i = l;
		int j = h+1;
		int pivot = l;
		while (i < j)
		{
			do {
				i++;
			} while (i <= hi && a[i] < a[pivot]);

			do {
				j--;
			} while (a[j] > a[pivot]);

			if (i > j)
				break;
			
			swap(a[i], a[j]);
			
		}
		swap(a[pivot], a[j]);
		pivot = j;

		if (pivot == k)
			return a[pivot];
		if (pivot < k)
			l = pivot + 1;
		else
			h = pivot - 1;

	}

}
int main()
{
	int a[] = { 3,9, 4, 6, 7, 8,2, 5,11,7 };
	int len = sizeof(a) / sizeof(a[0]);
	int k = 3;
	int MinimalKValue = FindMinimalK(a, 0, len - 1, k);
	cout << MinimalKValue << endl;

	int minK = FindMinimalK_recursive(a, 0, len - 1, k);
	cout << minK << endl;
	getchar();
    return 0;
}

