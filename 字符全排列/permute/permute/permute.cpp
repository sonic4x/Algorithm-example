// permute.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <iostream>
using namespace std;


static int g_nTotalPermuteNum = 0;
static int g_nTotalCombineNum = 0;

void DoPermute (char in[], char out[], int used[], int length, int recursLvl, bool bRepeat)
{
	int i;
	
	//base case
	if(recursLvl == length)
	{
		g_nTotalPermuteNum ++;
		printf("%d. %s\n", g_nTotalPermuteNum, out); //print permutation
		
		return;
	}
	
	//recursive case:
	for( i = 0; i < length; i++)
	{
		if (0 != used[i] && !bRepeat)	//if repeat not allowed, we continue
			continue;
			
		out[recursLvl] = in[i];
		used[i] = 1;	//mark this letter as used
		DoPermute( in, out, used, length, recursLvl + 1,bRepeat);
		used[i] = 0;	//unmark
		
	}
}

// permute wrap
int Permute( char inString[], bool bRepeat)
{
	int length,  *used;
	char *out;
	
	length = strlen(inString);
	out = (char*) malloc( length + 1);
	if (!out)
	{
		return 0;
	}
	
	out[length] = '\0';
	used = (int *) malloc(sizeof(int) * length);
	if (NULL == used)
	{
		return 0;
	}
	
	memset( used, 0, sizeof(int) * length);
	DoPermute(inString, out, used, length, 0, bRepeat);
	free( out);
	free (used);
	return 1;
}

// combine recursive algrithm
/*
start: 遍历起点字符索引
*/
void DoCombine(char in[], char out[], int length, int recursLvl, int start)
{
	int i;
	for( i = start; i< length; i++)
	{
		out[recursLvl] = in[i];	//select the current letter
		out[recursLvl + 1] = '\0'; //tack NULL for printf
		printf("%s\n",out);
		g_nTotalCombineNum++;

		if( i< length-1)	//broken arm recursion
		{
			DoCombine(in, out, length, recursLvl+1, i+1);
		}
	}
}

void DoCombineImproved(char in[], char out[], int length, int recursLvl, int start)
{
	int i;
	for( i = start; i< length; i++)
	{
		out[recursLvl] = in[i];	//select the current letter
		out[recursLvl + 1] = '\0'; //tack NULL for printf
		printf("%s\n",out);
		g_nTotalCombineNum++;
		//if( i< length-1)	//broken arm recursion
		{
			DoCombineImproved(in, out, length, recursLvl+1, i+1);
		}
	}
	
}

int Combine(char inString[])
{
	int length = strlen(inString);
	char *out = (char*)malloc(length+1);
	if (NULL == out)
	{
		return 0;

	}
	DoCombineImproved(inString, out, length, 0, 0);
	free (out);
	return 1;
}
int main()
{
	////////////////permute//////////////////
	g_nTotalPermuteNum = 0;
	char chStr[] = "abcd";
	Permute(chStr, 0);	//permute
	printf("the total permute num is:%d\n", g_nTotalPermuteNum);

	g_nTotalPermuteNum = 0;
	char chStr2[] = "ab";
	Permute(chStr2, 1);	//allow repeat permute, ab---> aa, ab, ba, bb
	printf("the total permute num is:%d\n", g_nTotalPermuteNum);	

	//////////////////combine////////////////
	Combine(chStr);     //abc => a,ab,abc,ac,b,bc,c
	printf("the total combine num is:%d\n", g_nTotalCombineNum);
	getchar();
}

