# include<iostream.h>
# include<string.h>
void bsearch(char*list[],char obj[],int len)
{
	char** low,**high,**mid;
	low=list;
	high=list+len-1;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(strcmp(*mid,obj)<0)   //小于所找字符串
			low=mid+1;
		else if(strcmp(*mid,obj)>0)
			high=mid-1;
		else 
		{cout<<"Success! The sequential number="<<mid-list+1<<endl;
		 return;
		}
	}
		cout<<"Unsucess!"<<endl;
}
void main()
{
	char*a[10]={"aa","bbb","cccc","ddddd","eeeeee","fffffff"};	
	for (int i=0;i<6;i++)
		cout<<*(a+i)<<" ";
	char c[20];
	cout<<endl;
	cout<<"请输入要查阅的字符串：";
	cin>>c;
    char *b;
    b=c;
    void (*s)(char*[],char*,int);
    s=bsearch;
    (*s)(a,c,6);
}
