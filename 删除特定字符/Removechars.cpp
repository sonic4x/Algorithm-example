#include <iostream>
using namespace std;

void RemoveChars(char str[],char remove[])
{
	const int MAX_CHAR_SIZE=256;
	int st[MAX_CHAR_SIZE];
	int Index=0;

	for (int i=0;i<MAX_CHAR_SIZE;i++)
	{
		st[i]=0;
	}
	
	while(remove[Index]!='\0')
	{
		st[remove[Index]]=1;
		Index++;
	}
	int srcIndex=0;
	int desIndex=0;

	while(str[srcIndex]!='\0')				//���������⿪�ٻ�����
	{
		if(st[str[srcIndex]]==0)
			str[desIndex++]=str[srcIndex++];
		else
			srcIndex++;						//����Դָ��ǰ��
	}
	str[desIndex]='\0';						//don't forget to put '\0'
}


void main()
{
	char removechars[]="ub";
	char str[]="I love u,baby";
			//	I love ,ay
	
	RemoveChars(str,removechars);
	cout<<str<<endl;
}