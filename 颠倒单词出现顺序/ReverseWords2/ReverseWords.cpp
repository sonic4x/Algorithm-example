#include <iostream>
using namespace std;

/*
Do not try.---->try. not Do	

idea: ��ȫ������	--->.yrt ton oD
	  �ٸ�����������--->try. not Do
	  �˷������˴���������
*/
void ReverseString(char str[], int start, int end)
{
	char tmp;
	while(start<end)
	{
		tmp=str[start];
		str[start]=str[end];
		str[end]=tmp;
		start++;
		end--;
	}
}

void ReverseWords(char str[])
{
	int strEnd,strStart,wordEnd,wordStart;
	int len = strlen(str);
	strStart=0;
	strEnd=len-1;
	ReverseString(str,strStart,strEnd);

	while(strStart<len)
	{
		if(str[strStart]!=' ')
		{
			wordStart=strStart;
			while(strStart<len && str[strStart]!=' ')
			{
				strStart++;
			}
			wordEnd=strStart-1;
			ReverseString(str,wordStart,wordEnd);
		}
		else
		{
			strStart++;
		}
	}
}

void ReverseWords2(char str[])
{
	//�����������ո�������
	int len = strlen(str);
	ReverseString(str, 0, len-1);

	int start = 0;
	int end = 0;
	for(int lp=0;lp<len;lp++)
	{

		if (str[lp] != ' ')
			continue;

		end = lp - 1;
		ReverseString(str, start, end);
		start = lp + 1;
	}
	ReverseString(str, start, len-1);
}

void main()
{
	char str[]="Do not try.";
	ReverseWords(str);
	ReverseWords2(str);
	cout<<str<<endl;
}