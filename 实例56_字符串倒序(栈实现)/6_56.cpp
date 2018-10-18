#include<iostream.h>
struct sqstack
{
	char data;
	sqstack* top;
};
class stack
{
	sqstack * st;
public:
	void init()
	{
		st=NULL;
	}
	void push(char );
	char pop();
};
void stack::push(char k)
{
	sqstack * newst=new sqstack;
	newst->data=k;
	newst->top=st;
	st=newst;
}
char stack::pop()
{
	char value;
	sqstack* t;
	value=st->data;
	t=st;
	st=st->top;
	delete t;
	return value;
}
void main()
{
	stack A;
A.init();
	int n;
	cout<<"ÇëÊäÈë×Ö·û¸öÊýn£º";
	cin>>n;
    char *arr=new char[n];
	cout<<"ÇëÊäÈën¸ö×Ö·û£º"<<endl;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<endl;
	cout<<"ÈëÕ»Ë³Ðò£º";
	for ( i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
		A.push(arr[i]);
	}
	cout<<endl<<"Out! ";
	for( i=0;i<n;i++)
		cout<<A.pop()<<" ";
	cout<<endl;
	delete arr;
}
