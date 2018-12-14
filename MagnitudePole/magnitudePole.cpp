

/*
Magnitude Pole: An element in an array whose left hand side elements are lesser than or equal to it and whose right hand side element are greater than or equal to it.

A zero-indexed array A consisting of N integers is given. A magnitude pole of this array is an integer Q such that:
0 ≤ Q < N;
A[P] ≤ A[Q] for 0 ≤ P < Q;
A[Q] ≤ A[R] for Q < R < N.
For example, consider array A consisting of ten elements such that:
A[0] = 4
A[1] = 2
A[2] = 2
A[3] = 3
A[4] = 1
A[5] = 4
A[6] = 7
A[7] = 8
A[8] = 6
A[9] = 9
Number 5 is a magnitude pole of this array, because all elements to the left of A[5] have values smaller than or equal to A[5] (4, 2, 2, 3 and 1 are smaller than or equal to 4) and all elements to the right of A[5] have values greater than or equal to A[5] (7, 8, 6 and 9 are greater than or equal to 4). Number 9 is also a magnitude pole of this array.
Write a function:
class Solution { public int solution(int[] A); }
that, given a zero-indexed array A consisting of N integers, returns any of its magnitude poles. The function should return ?1 if array A does not have a magnitude pole.
For example, given array A consisting of ten elements such that:
A[0] = 4
A[1] = 2
A[2] = 2
A[3] = 3
A[4] = 1
A[5] = 4
A[6] = 7
A[7] = 8
A[8] = 6
A[9] = 9
the function may return 5 or 9, as explained above.
Assume that:
N is an integer within the range [0..100,000];
each element of array A is an integer within the range [-2147483648..2147483647].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <windows.h>  //for gettickCount
#include <chrono>  // for high_resolution_clock

using namespace std;

#define MAXINT ((1<<31) - 1)	//2147483647 
#define MININT ((-1) * (1<<31)) //-2147483648 
int FindMagnitudePole(int a[], int len)
{
	if (a == NULL || len <= 0)
	{
		return -1;
	}

	int i = 0;
	int lastUnmatchedLeft = 1;
	while (i < len)
	{
		bool isPole = true;
		int lastUnmatchedLeft = len;
		//check left
		int leftIdx = (lastUnmatchedLeft -1 > i - 1)? i-1: lastUnmatchedLeft - 1;
		for (; leftIdx > 0; leftIdx--)
		{
			if (a[leftIdx] > a[i])
			{
				isPole = false;
				
				break;
			}
		}

		if (!isPole)
		{
			int j = leftIdx;
			for (; j < len; j++)
			{
				if (a[j] >= a[leftIdx])
				{
					break;
				}
			}
			if (j == len)
				return -1;

			i = j;  //pivot in next loop
			lastUnmatchedLeft = leftIdx ;
			continue;
		}

		if(i != 0)  // i ==0, special case
			lastUnmatchedLeft = 0; // no need to check left 

		//check right
		int maxRightNumIdx = i ;
		int maxRightNum = a[maxRightNumIdx];
		int rightIdx = i + 1;
		for (; rightIdx < len; rightIdx++)
		{
			if (a[rightIdx] > maxRightNum)
			{
				maxRightNum = a[rightIdx];
				maxRightNumIdx = rightIdx;
			}
				
			if (a[rightIdx] < a[i])
			{
				isPole = false;
				
				break;
			}
		}

		if (!isPole)
		{
			int k = rightIdx;
			for (; k < len; k++)
			{
				if (a[k] >= maxRightNum)
				{
					break;
				}
			}

			if (k == len)
			{
				return -1;
			}

			i = k;  //pivot in next loop
			continue;
		}

		return i;
		
	}
}

int FindMagnitudePole_v2(int a[], int n)
{
	if (n <= 0 || a == NULL)
		return -1;

	int *maxNumberFromLeftStart2Cur = new int[n];
	int *minNumberFromCur2RightEnd = new int[n];

	int maxnum = MININT;

	int i = 0;
	for (; i < n; i++)
	{
		if (a[i] > maxnum)
		{
			maxnum = a[i];
		}
		maxNumberFromLeftStart2Cur[i] = maxnum;
	}

	int minnum = MAXINT;
	for (i = n - 1; i >= 0; i--)
	{
		if (a[i] < minnum)
		{
			minnum = a[i];
		}
		minNumberFromCur2RightEnd[i] = minnum;
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] >= maxNumberFromLeftStart2Cur[i]
			&& a[i] <= minNumberFromCur2RightEnd[i])
		{
			return i;
		}
	}
	return -1;
}
int main()
{

	int a[] = { 3,1,4,5,9,7,11,2,3,11 };
	auto start = std::chrono::high_resolution_clock::now();
	int pole = FindMagnitudePole(a, 10);	//9	
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Totle Time : " << elapsed.count() << "s" << endl;
	printf("%d\n", pole);

	int b[] = { 3,1,4,5,9,7,11,2,3,10};
	pole = FindMagnitudePole(b, 10);	//-1
	printf("%d\n", pole);

	start = std::chrono::high_resolution_clock::now();
	pole = FindMagnitudePole_v2(a, 10);
	finish = std::chrono::high_resolution_clock::now();
	cout << "Totle Time : " << elapsed.count() << "s" << endl;
	printf("%d\n", pole);
	getchar();
}