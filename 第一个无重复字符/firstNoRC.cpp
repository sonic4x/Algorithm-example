#include <stdio.h>
#include <conio.h>

#include <iostream>
using namespace std;


char FirstNonRepeated(string str)
{	
	char c;
	const int MAX_SIZE=256;
	int st[MAX_SIZE];
	int j=0;

	for(int i=0;i<MAX_SIZE;i++)
	{
		st[i]=0;
	}
	
	while(str[j]!='\0')
	{
		st[str[j]]+=1;
		j++;
	}

	j=0;
	while(str[j++]!='\0')
	{
		if(st[str[j]]==1)
		{
			c=str[j];
			return 	c;
		}
	}
	return 1;
}

void main()
{
	char nonRepeated;
	string testStr="total";
	nonRepeated=FirstNonRepeated(testStr);
	printf("%c\n",nonRepeated);
	getch();
}