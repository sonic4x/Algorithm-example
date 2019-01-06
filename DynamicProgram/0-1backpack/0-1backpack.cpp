// 0-1backpack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int maxV = ~0;

int weight[] = { 2, 2, 4, 6, 3 };
int value[] = { 3, 4,8, 9,6 };
const int n = 5;  //item number in total
const int w = 9;  //max weight that backpack can take 
int state[n+1][w + 1] = { -1 };
/*
»ØËÝ·¨
i-   idx item to be decided
cw - current weight
cv - current value
*/
void f(int i, int cw, int cv)
{
	if (cw == w		// backpack is full 
		|| i == n	// all items have been decided
		)
	{
		if (cv > maxV) 
			maxV = cv;

		return;
	}

	f(i + 1, cw, cv); // don't choose i

	if (cw + weight[i] <= w) //choose i
		f(i + 1, cw + weight[i], cv + value[i]);
	
}


/*
dynamic way

state table :
     0  1  2  3  4  5  6  7  8  9
[0]	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
[1]	{0, 0, 3, 3, 3, 3, 3, 3, 3, 3}
[2]	{0, 0, 4, 4, 7, 7, 7, 7, 7, 7}
[3]	{0, 0, 4, 4, 8, 8, 12, 12, 15, 15}
[4]	{0, 0, 4, 4, 8, 8, 12, 12, 15, 15}
[5]	{0, 0, 4, 6, 8, 10, 12, 14, 15, 18}
*/
void f2()
{
	
	for (int i = 0; i <= n; ++i) {  //init state
		for (int j = 0; j < w + 1; ++j) {
			state[i][j] = -1;
		}
	}
	//init first row/col 
	state[0][0] = 0;  //assume we have an item with 0 weight, 0 value.

	//first item start from i = 1 in the state table
	for (int i = 1; i <= n; i++)
	{
		int itemIdx = i - 1;
		//don't choose this item
		for (int j = 0; j < w + 1; j++)
		{
			if (state[i - 1][j] >= 0)
			{
				state[i][j] = state[i - 1][j];
			}
		}

		//choose this item
		for (int j = 0; j <= w - weight[itemIdx]; j++)
		{
			if (state[i - 1][j] >= 0)
			{
				int v = state[i - 1][j] + value[itemIdx];
				if (v > state[i][j+ weight[itemIdx]])
				{
					state[i][j + weight[itemIdx]] = v;
				}
			}
		}
	}


	//check the state to output what we choose
	int weight4MaxV = 1;
	for (int j = 1; j < w + 1; j++)
	{
		if (state[n][j] > maxV) {
			maxV = state[n][j];
			weight4MaxV = j;
		}
	}

	int leftValue = maxV;
	int leftWeight = weight4MaxV;
	int i = n;
	while(i > 0)
	{
		int col = leftWeight - weight[i-1];
		int v = leftValue - value[i - 1];

		int k = i - 1;
		for (; k > 0; k--)
		{
			if (state[k][col] == v)
			{
				break;
			}
		}
		if (k == 0)  // this item is not chosen
		{
			i--;
			continue;
		}
		else
		{
			// this item is chosen
			cout << value[i - 1] << endl;

			i = k;
			leftWeight = col;
			leftValue = v;
		}
		
		
	}
	





}

int main()
{

	//f(0, 0, 0);
	f2();
	cout << "max value is: " << maxV << endl;
	getchar();

    return 0;
}

