# include<iostream.h>
#include <iomanip.h>

typedef struct candidate
{
	char cdd;
	struct candidate* next;
}Candidate;

int n;int b[6];

Candidate *ballot()   //�൱��struct candidate *ballot()
{
    Candidate* head,*p1,*p2;
	n=1;
	p1=p2=new Candidate;
    cout<<"�������"<<n<<"��ѡƱ��ѡ�ĺ�ѡ�ˣ�\"#\"���������";
    cin>>p1->cdd;
	head=NULL;  //����ͷ�ڵ�
	while(p1->cdd!='#')
	{
		n++;
		if(n==2)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=new Candidate;
		cout<<"�������"<<n<<"��ѡƱ��ѡ�ĺ�ѡ�ˣ�\"#\"���������";
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
	cout<<"��ѡ�ˣ�";
	for(int i=0;i<6;i++) cout<<setw(3)<<char(65+i);  //setw�����ַ���࣬��Ҫiomanip.h
	cout<<endl<<"��Ʊ����";
	for(int j=0;j<6;j++) cout<<setw(3)<<b[j];
	cout<<endl<<"ע��F������ȨƱ��A��B��C��DΪ��ѡ�ˣ�";
    cout<<endl;
}
