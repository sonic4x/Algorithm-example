
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

#pragma region Find min when combine to integer
//{3,32,321}  => 321323
const  int g_nMaxNumberLength = 19;
char *g_strCombine1 = new char[2 * g_nMaxNumberLength + 1];
char *g_strCombine2 = new char[2 * g_nMaxNumberLength + 1];

int compare(const void *strNumber1, const void *strNumber2)
{
	strcpy_s(g_strCombine1, 2 * g_nMaxNumberLength + 1, (const char*)strNumber1);
	strcat_s(g_strCombine1, 2 * g_nMaxNumberLength + 1, *(const char**)strNumber1);

	strcpy_s(g_strCombine2, 2 * g_nMaxNumberLength + 1, (const char*)strNumber2);
	strcat_s(g_strCombine2, 2 * g_nMaxNumberLength + 1, *(const char**)strNumber2);

	return strcmp(g_strCombine1, g_strCombine2);
}

void printMinNumber(int* numbers, int length)
{
	if (numbers == NULL || length == 0)
		return;

	//int 64位，可以有19位数字

	char **strNumbers = (char**)(new char*[length]);

	for (int i = 0; i < length; i++)
	{
		strNumbers[i] = new char[g_nMaxNumberLength + 1];
		sprintf_s(strNumbers[i], g_nMaxNumberLength + 1, "%d", numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);

	for (int i = 0; i < length; i++)
	{
		printf("%s", strNumbers[i]);
	}
	printf("\n");

	//release res
	for (int i = 0; i < length; i++)
	{
		delete[] strNumbers[i];
	}
	delete[] strNumbers;
}



#pragma endregion

#pragma region Find max length in a str with no repeated char in it
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAXASCIINUM 256
int FindMaxLenWithNoRepeatedChar(char str[], int len)
{
	if (str == nullptr || len <= 0)
		return 0;


	int aPos[MAXASCIINUM];
	int i;
	for (i = 0; i < MAXASCIINUM; i++)
	{
		aPos[i] = len;
	}
	int *pLastUnrepeatedPos = new int[len + 1];
	pLastUnrepeatedPos[len] = len;

	
	for (i = len - 1; i >= 0; i--)
	{
		char strValue = str[i];
		pLastUnrepeatedPos[i] = MIN(pLastUnrepeatedPos[i + 1], aPos[strValue] - 1);
		aPos[strValue] = i;
	}

	int maxDiff = -1;
	for (i = 0; i < len; i++)
	{
		int delta = pLastUnrepeatedPos[i] - i;
		if (delta > maxDiff)
			maxDiff = delta;
	}
	return maxDiff + 1;
}
#pragma endregion

#pragma region Merge 2 sorted arrays
int * MergeArray(int a[], int n, int b[], int m)
{
	if (n <= 0 || m <= 0)
		return nullptr;
	if (a == nullptr)
		return b;
	if (b == nullptr)
		return a;

	int *newArray = new int[n + m];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n && j < m) {
		if (a[i] < b[j])
			newArray[k++] = a[i++];
		else
			newArray[k++] = b[j++];
	}

	while (i < n) {
		newArray[k++] = a[i++];
	}

	while (j < m) {
		newArray[k++] = b[j++];
	}

	return newArray;
}

#pragma endregion
int main()
{
	int strArr[3] = { 3,32,321 };
	printMinNumber(strArr, 3);

	char *a = "abcdedfgfi";
	int maxLenwithNoRepeat = FindMaxLenWithNoRepeatedChar(a, 10);
	cout << maxLenwithNoRepeat << endl;

	//Merge array
	int a1[] = { 3,4,9,18,20 };
	int a2[] = { 1,5,6,10,19,21,32 };
	int *c = MergeArray(a1, 5, a2, 7);
	for (int idx = 0; idx < 12; idx++)
	{
		cout << c[idx] << "\t";
	}
	getchar();
}