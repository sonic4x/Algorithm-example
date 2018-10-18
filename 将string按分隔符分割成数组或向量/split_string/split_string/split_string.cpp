// split_string.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;



int SplitStr(const wstring & strSrc, const wstring& strDelims, vector<wstring>& strDest)  
{  
	typedef wstring::size_type ST;  
	wstring delims = strDelims;  
	wstring STR;  

	if(delims.empty()) 
		delims = L"/n/r";  


	ST pos = 0;
	ST LEN = strSrc.size();  
	while(pos < LEN )
	{  
		STR = L"";

		//filter the delims in head of the string
		while( (delims.find(strSrc[pos]) != wstring::npos) && (pos < LEN) ) 
			++pos;  

		if(pos == LEN)
		{
			return strDest.size();  
		}
		
		while( (delims.find(strSrc[pos]) == wstring::npos) && (pos < LEN) ) 
			STR += strSrc[pos++];  
 
		if (!STR.empty()) 
		{
			strDest.push_back(STR);  
		}
	}  

	return strDest.size();  
}  

int main()
{
	wstring wstr=L"C:\\resource,1018;1016;" ;
	
	//truncate the begin to ","
	int pos = wstr.find(L",");
	wstring wstr2 = wstr.substr(pos+1, wstr.length() - pos -1);

	vector<wstring> vec;
	SplitStr(wstr2, L";", vec);

	for(int idx = 0; idx < vec.size(); ++idx)
	{
		wstring wstrAAId = vec[idx];
		cout<<"vec."<<idx <<" "<< wstrAAId.c_str()<<endl; // wstrAAId.c_str() shouldn't use cout 
	}
	cout<<"vecNum"<<vec.size()<<endl;
	return 0;
}

