#include <iostream>
#include <stdio.h>
using namespace std;

/*
idea: 
if �ַ����ĵ�һ���ַ���'-'
	set negtive flag
	�ӵڶ����ַ���ʼɨ��
���ַ����е�ûһ���ַ�
	������ֵ*10
	��(�����ַ�-'0')������ֵ���
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