# include<iostream.h>
# include<string.h>

char* fun(char(*p)[20],int n) //p是一个指针变量，它指向包含20个元素的一维数组
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
    cin>>wsize;		//临时分配元素的个数
    char(* a)[20];
	a=new char[wsize][20];//临时分配这些元素所需的内存空间（堆内存中）

	if(a!=NULL)		//判断，堆空间不够分配时，系统会返回一个空指针值NULL
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
	   max= s (a,wsize);  //等价于max=(*s)(a,wsize);  or max=fun(a,wsize);
	   cout<<"The longest word is:"<<max<<endl;
	   delete[] a;	//释放堆内存
	}
    else
		cout<<"Can't allocate more memory."<<endl;

}
