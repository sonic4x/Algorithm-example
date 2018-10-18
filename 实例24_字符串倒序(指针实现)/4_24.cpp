# include <iostream.h>
void invert(char*,int);
void main()
{
	char *s,a[30];
	int n;
	cout<<"请输入字符个数n：";
	cin>>n;
	cout<<"请输入n个数："<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<endl;
	s=&a[0];  //本行可用s=a;替换
	invert(s,n);
    cout<<"逆序串为："<<endl;
	for (i=0;i<n;i++)
		cout<<*(s+i)<<" ";//a[i] = = s[i] = = *(a+i) = = *(s+i)	互相等价
	cout<<endl;
}

void invert(char* s,int j)
{
	
	char ch,*s1,*s2;
	int i;
	for(i=0;i<j/2;i++)
	{
		s1=s+i;
		s2=s+(j-1-i);
		ch=*s1;
		*s1=*s2;
		*s2=ch;
	}
	
}
