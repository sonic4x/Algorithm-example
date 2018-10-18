#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_DIGITS_INT 10

void IntToStr(int num, char str[])
{
	char temp[MAX_DIGITS_INT+2];     //buffer big enough for largest INT,-sign and NULL
	int tempIndex=0;
	int sIndex=0;
	int IsNeg=0;

	if(num<0)
	{
		IsNeg=1;
		num*=-1;					//将其变为正数
	}

/*	while()
	{
		int tmp=num%10;
		temp[tempIndex++]=tmp+'0';
		num/=10;
	}
*/
	do	//这样整数为0时也行
	{
		int tmp=num%10;
		temp[tempIndex++]=tmp+'0';            
		num/=10;
	} 
	while(num!=0);

	if(IsNeg==1)
		temp[tempIndex]='-';

	while(tempIndex>=0)
	{
		str[sIndex++]=temp[tempIndex--];     //逆序拷贝
	}
	str[sIndex]='\0';
}

void main()
{
//	printf("Please enter an Integer:\n");
	char s[12];
	int number=-376;
	IntToStr(number,s);
	cout<<s<<endl;
}