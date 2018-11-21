

/*
Magnitude Pole: An element in an array whose left hand side elements are lesser than or equal to it and whose right hand side element are greater than or equal to it.

example input

3,1,4,5,9,7,6,11
desired output

4,5,11
*/

#include <stdio.h>
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

int main()
{
	int a[] = { 3,1,4,5,9,7,11,2,3,11 };
	int pole = FindMagnitudePole(a, 10);	//9	
	printf("%d\n", pole);

	int b[] = { 3,1,4,5,9,7,11,2,3,10};
	pole = FindMagnitudePole(b, 10);	//-1
	printf("%d\n", pole);

	getchar();
}