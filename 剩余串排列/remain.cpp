

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;


void main()
{
	/*
	remain.txt�к��ɶԵ��ִ��� �Ե�һ���ִ���Ҫ��ȥ�����ִ�����ͬ�Ĳ��֣������ַ�˳�����
	*/
	ifstream in("remain.txt");
	for(string s,t; in>>s>>t;)
	{
		sort(s.begin(), s.end());//sort �ǶԸ����ַ���ASCIIֵ��С����
		for(int i = 0; i<s.length(); i++)
		{
			if(t.find(s[i]) == string::npos)
			{
				cout<<s[i];
			}
		}
		cout<<endl;
	}
}