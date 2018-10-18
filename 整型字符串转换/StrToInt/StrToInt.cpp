#include <iostream>
#include <stdio.h>
using namespace std;

/*
idea: 
if 字符串的第一个字符是'-'
	set negtive flag
	从第二个字符开始扫描
对字符串中的没一个字符
	把整数值*10
	把(数字字符-'0')与整数值相加
*/
int StrToInt(char str[])
{
	int num=0;
	int IsNeg=0;
	int Index=0;
	if(str[Index]=='-')
	{
		IsNeg=1;
		Index++;
	}
	while(str[Index]!='\0')
	{
		num*=10;
		num+=str[Index]-'0';
		Index++;
	}

	if(IsNeg==1)
		num*=-1;

	return num;

}

void main()
{
	printf("Please enter strings with the limited length of 9:\n");
	char str[11];//="-376";

	gets(str);
	int n=StrToInt(str);
	cout<<n<<endl;
}