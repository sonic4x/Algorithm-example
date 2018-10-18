#include "stdio.h"
#include "conio.h"
#include <assert.h>     //assert ����
#include <iostream>

using namespace std;

struct stu{
    char name[20];
    char sex;
    int no;
    int age;
    struct stu * next;
}*linklist;

struct stu *creatlist(int n)
{
    int i;
    
    struct stu *head,*p1,*p2;//hΪͷ��㣬pΪǰһ��㣬sΪ��ǰ���
//  p1 = (struct stu *)malloc(sizeof(struct stu));   //Ҫд��forѭ��������
    head=NULL;
    
    for(i=0;i<n;i++)
	{
		p1 = (struct stu *)malloc(sizeof(struct stu));
        printf("Please input the information of the student: name sex no age \n");
        scanf("%s %c %d %d",p1->name,&p1->sex,&p1->no,&p1->age);
        p1->next = NULL;
        if(i==0)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
		}
		p2=p1;
    }
    printf("Create successful!\n");
	getch();
    return head;
}
//-----------������ɾ��ѧ���������age��ѧ����Ϣ(ֻɾ����һ���ҵ���)
struct stu* deletelistInfo(struct stu *head,int a)  
{
	if(head==NULL)
	{
		printf("list null!\n");
		return NULL;
	}
	
	struct stu	*p1, 
				*p2;    //ǰһ�ڵ�
	p1=head;
	while(p1->next!=NULL && p1->age!=a)  //ע�ⲻҪ��p1->next!=NULLд��p1!=NULL
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1->age==a)
	{
		if(p1==head)
			head=p1->next;
		else
			p2->next=p1->next;
		printf("Delete successful!\n");
	}
	else
	{
		printf("no matched student!");
	}
	
	return head;
/*	while(s->age!=a)   //������ѭ��
	{
		p = s;
		s = s->next;
	}
	if(s==NULL)
		printf("The record is not exist.");
	else
	{
		p->next = s->next;
		printf("Delete successful!");
	}
*/
}

//-----------������ɾ��ѧ���������age��ѧ����Ϣ(ɾ�����з���������)
struct stu* deletelistInfo_all(struct stu *head,int a) 
{
	if(head==NULL)
	{
		printf("list null!\n");
		return NULL;
	}
	struct stu *p1,*p2;
	p1=head;
	while(p1!=NULL)
	{
		if(p1->age==a)
		{
			if(p1==head)
			{
				head=p1->next;
			}
			else
			{
				p2->next=p1->next;    
			}
		}
		else
		{
			p2=p1;
		}
		p1=p1->next;       
	}
	return head;
}

/*---------------------------------------
�����䰴����嵽ԭ������
------------------------------------------*/
struct stu* InsertListInfo(struct stu *head, struct stu *stud)
{
	struct stu *p1,*p2;
	p2=p1=head;

	if(head==NULL)
	{
		head=stud;
//		stud->next=NULL;     //����stud->next��main���Ѿ�=NULL���˴���ʡ
	}
	else
	{
		while(p1->age <= stud->age && p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(p1->age > stud->age)
		{
			if(p1==head)
				head=stud;
			else
				p2->next=stud;

			stud->next=p1;
		}
		else
		{
			p1->next=stud;
			stud->next=NULL;
		}
	}
	return head;
}
/*--------------������Ƚ�
��ͬ����1�����򷵻�0
*/
int Compare_list(struct stu *head1,struct stu *head2)
{
	struct stu *p1,*p2;
	p1=head1;
	p2=head2;
	while(1)
	{
		if(p1==NULL && p2==NULL)
		{
			return 1;
		}
		else if(p1==NULL ||p2==NULL)
		{
			return 0;
		}
		else
		{
			if( p1->age!=p2->age   ||
				strcmp(p1->name,p2->name) ||
			//	p1->name!=p2->name ||		//���ֶ���char[],����Ҫ��strcmp
				p1->no!=p2->no     ||
				p1->sex!=p2->sex )
			{
				return 0;
			}
			else
			{
				p1=p1->next;
				p2=p2->next;
			}
		}
	}
}
/*------------------------------------------
������ķ�ת
------------------------------------------*/
struct stu* Invert_list(struct stu *head)
{
	struct stu *back;   
	struct stu *p1;
	struct stu *p2;

	assert(head!=NULL);      // ��������Ϊ��

	//ֻ��һ��Ԫ�أ������ظ�Ԫ��
	if(head->next==NULL)
	{
		return head;
	}

	back=head;
	p1=back->next;
	back->next=NULL;

	while( p1->next !=NULL)
	{
		p2=p1;
		p1=p1->next;
		p2->next=back;
		back=back->next;
	}
	p1->next=back;
	head=p1;
	return head;
}

/*---------------------------
����������
----------------------------*/
struct stu *Concatenate_list(struct stu *head1,struct stu *head2)
{
	struct stu *p;
	p=head1;

	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head2;

	return head1;
}


void display(struct stu *head)
{
	struct stu* p;
	p=head;
    while(p!=NULL)
    {
        printf("%s %c %d %d\n",p->name,p->sex,p->no,p->age);
        p = p->next;
    }
}

int main()
{
    struct stu *s,*Ins;
	int n,age;
	printf("Please input the length of seqlist:\n");
	scanf("%d",&n);
    s = creatlist(n);
    display(s);

	//��ת
	s=Invert_list(s);
	display(s);

	//����Ƚ�
	struct stu *s1;
	int n1;
	printf("Please input the length of seqlist:\n");
	scanf("%d",&n1);
    s1 = creatlist(n1);
    display(s1);
	
	int compare_result=Compare_list(s,s1);
	printf("compare result is:%d\n",compare_result);

	//Delete
	printf("Please input the age:\n");
	scanf("%d",&age);
	s=deletelistInfo_all(s,age);
	display(s);

	//����
	printf("Please input the insert info:\n");
	Ins=(struct stu *)malloc(sizeof(stu));            //don't forget allocate memory
	scanf("%s %c %d %d",Ins->name,&Ins->sex,&Ins->no,&Ins->age);
	Ins->next=NULL;
	s=InsertListInfo(s,Ins);
	display(s);



    return 0;
}
