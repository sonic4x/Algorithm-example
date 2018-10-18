# include<iostream.h>
#include <iomanip.h>

typedef struct candidate
{
	char cdd;
	struct candidate* next;
}Candidate;

int n;int b[6];

Candidate *ballot()   //相当于struct candidate *ballot()
{
    Candidate* head,*p1,*p2;
	n=1;
	p1=p2=new Candidate;
    cout<<"请输入第"<<n<<"张选票所选的候选人（\"#\"表结束）：";
    cin>>p1->cdd;
	head=NULL;  //不带头节点
	while(p1->cdd!='#')
	{
		n++;
		if(n==2)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=new Candidate;
		cout<<"请输入第"<<n<<"张选票所选的候选人（\"#\"表结束）：";
		cin>>p1->cdd;
	}
	p2->next=NULL;
	return head;
}
void vote(Candidate*h,int a[6])
{
	Candidate *p=h;
	char candd;
 	while(p!=NULL)
	{
		candd=p->cdd;
		switch (candd)
		{
		case 'A':a[0]++;break;
		case 'B':a[1]++;break;
        case 'C':a[2]++;break;
		case 'D':a[3]++;break;
		case 'E':a[4]++;break;
		default:a[5]++;break;
		}
		p=p->next;
	}
}
void main()
{
	Candidate* head;
	head=ballot();
	vote(head,b);
	cout<<"候选人：";
	for(int i=0;i<6;i++) cout<<setw(3)<<char(65+i);  //setw设置字符间距，需要iomanip.h
	cout<<endl<<"得票数：";
	for(int j=0;j<6;j++) cout<<setw(3)<<b[j];
	cout<<endl<<"注：F代表弃权票，A，B，C，D为候选人！";
    cout<<endl;
}
