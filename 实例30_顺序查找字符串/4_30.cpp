# include<iostream.h>
# include<string.h>
void search(char*list[],char obj[],int len)
{
	char** p;
	p=list;
	while(p<list+len)
	{
		if(strcmp(*p,obj)==0)
			break;
		else p++;
	}
		if(p<list+len)
			cout<<"Success! The sequential number="<<p-list+1<<endl;
		else 
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
    s=search;
    (*s)(a,c,6);
}
