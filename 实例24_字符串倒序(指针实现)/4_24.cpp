# include <iostream.h>
void invert(char*,int);
void main()
{
	char *s,a[30];
	int n;
	cout<<"�������ַ�����n��";
	cin>>n;
	cout<<"������n������"<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<endl;
	s=&a[0];  //���п���s=a;�滻
	invert(s,n);
    cout<<"����Ϊ��"<<endl;
	for (i=0;i<n;i++)
		cout<<*(s+i)<<" ";//a[i] = = s[i] = = *(a+i) = = *(s+i)	����ȼ�
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
