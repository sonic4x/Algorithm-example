

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;


void main()
{
	/*
	remain.txt中含成对的字串。 对第一个字串，要减去两个字串中相同的部分，并按字符顺序输出
	*/
	ifstream in("remain.txt");
	for(string s,t; in>>s>>t;)
	{
		sort(s.begin(), s.end());//sort 是对各个字符按ASCII值大小排序
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