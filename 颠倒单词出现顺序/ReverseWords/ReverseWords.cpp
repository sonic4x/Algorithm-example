#include <iostream>
using namespace std;

/*
Do not try. ----> try. not Do		//标点当作字母
*/


int ReverseWords(char str[])
{
	int wordStart,wordEnd,strIndex,buffIndex;
	int len=strlen(str);
	strIndex=len-1;
	buffIndex=0;

	char *buff=(char*)malloc(len+1);
	if(buff==NULL)
		return 0;

	while(strIndex>=0)
	{
		if(str[strIndex]!=' ')
		{
			wordEnd=strIndex;
			while(strIndex>=0 && str[strIndex]!=' ')
			{
				strIndex--;
			}
			wordStart=strIndex+1;
			
			while(wordStart<=wordEnd)
			{
				buff[buffIndex++]=str[wordStart++];
			}
		}
		else			//遇空格
		{
			buff[buffIndex++]=str[strIndex--];
		}
		
	}

	buff[buffIndex]='\0';  //don't forget put an end '\0'
	strcpy(str,buff);
	free(buff);
	buff=NULL;
	return 1;
}

void main()
{
	char str[]="Do not try.";
	ReverseWords(str);
	cout<<str<<endl;
}

