# include<iostream.h>
# include<string.h>

char* fun(char(*p)[20],int n) //p��һ��ָ���������ָ�����20��Ԫ�ص�һά����
{
	int i;
	char* max;
	max=p[0];
	for (i=1;i<n;i++)
		if(strlen(p[i])>strlen(max))
			max=p[i];
		return max;
}

void main()
{
	int wsize;
	cout<<"Please enter the number of words :";
    cin>>wsize;		//��ʱ����Ԫ�صĸ���
    char(* a)[20];
	a=new char[wsize][20];//��ʱ������ЩԪ��������ڴ�ռ䣨���ڴ��У�

	if(a!=NULL)		//�жϣ��ѿռ䲻������ʱ��ϵͳ�᷵��һ����ָ��ֵNULL
	{
	   for(int i=0;i<wsize;i++)
	   {
	
		 	cin>>a[i];
	   }
	   cout<<"the words you inputted are:"<<endl;
	   for( i=0;i<wsize;i++)
	   {
			cout<<a[i];
		    cout<<"  ";
	   }
	   cout<<endl;
	   char*(*s)(char(*)[20],int);
	   s=fun;
	   char* max;
	   max= s (a,wsize);  //�ȼ���max=(*s)(a,wsize);  or max=fun(a,wsize);
	   cout<<"The longest word is:"<<max<<endl;
	   delete[] a;	//�ͷŶ��ڴ�
	}
    else
		cout<<"Can't allocate more memory."<<endl;

}
