
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

#pragma region 把数组所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
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

int main()
{
	int strArr[3] = { 3,32,321 };
	printMinNumber(strArr, 3);
	getchar();
}