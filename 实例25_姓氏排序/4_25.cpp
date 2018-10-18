# include<iostream.h>
# include<string.h>
# define max 20  //定义姓氏字符串的最大长度
void sort(char**);
void main()
{
	int i;
	char **p,*pstr[5],str[5][max];
	cout<<"请依次输入n个字符串（空格隔开）："<<endl;
	for(i=0;i<5;i++)
		cin>>str[i];
	for (i=0;i<5;i++)
		pstr[i]=str[i];  //将第i个字符串的首地址赋给指针数组的第i个元素

	p=pstr;
	sort(p);
	cout<<"排序后的字符串为："<<endl;
	for (i=0;i<5;i++)
		cout<<pstr[i]<<" ";
	cout<<endl;
}

void sort(char **p)  //起泡法对n个字符串排序
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
