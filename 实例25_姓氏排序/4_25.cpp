# include<iostream.h>
# include<string.h>
# define max 20  //���������ַ�������󳤶�
void sort(char**);
void main()
{
	int i;
	char **p,*pstr[5],str[5][max];
	cout<<"����������n���ַ������ո��������"<<endl;
	for(i=0;i<5;i++)
		cin>>str[i];
	for (i=0;i<5;i++)
		pstr[i]=str[i];  //����i���ַ������׵�ַ����ָ������ĵ�i��Ԫ��

	p=pstr;
	sort(p);
	cout<<"�������ַ���Ϊ��"<<endl;
	for (i=0;i<5;i++)
		cout<<pstr[i]<<" ";
	cout<<endl;
}

void sort(char **p)  //���ݷ���n���ַ�������
{
	int i,j;
	
	char *pc;
	for (i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(strcmp(*(p+i),*(p+j))>0)
			{
				pc=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=pc;
			}
		}
	}
}
