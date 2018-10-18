#include "stdio.h"
#include "conio.h"
#include <assert.h>     //assert 所需
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
    
    struct stu *head,*p1,*p2;//h为头结点，p为前一结点，s为当前结点
//  p1 = (struct stu *)malloc(sizeof(struct stu));   //要写在for循环体里面
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
//-----------链表中删除学生年龄等于age的学生信息(只删除第一个找到的)
struct stu* deletelistInfo(struct stu *head,int a)  
{
	if(head==NULL)
	{
		printf("list null!\n");
		return NULL;
	}
	
	struct stu	*p1, 
				*p2;    //前一节点
	p1=head;
	while(p1->next!=NULL && p1->age!=a)  //注意不要把p1->next!=NULL写成p1!=NULL
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
/*	while(s->age!=a)   //进入死循环
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

//-----------链表中删除学生年龄等于age的学生信息(删除所有符合条件的)
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
将年龄按升序插到原链表中
------------------------------------------*/
struct stu* InsertListInfo(struct stu *head, struct stu *stud)
{
	struct stu *p1,*p2;
	p2=p1=head;

	if(head==NULL)
	{
		head=stud;
//		stud->next=NULL;     //由于stud->next在main中已经=NULL，此处可省
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
/*--------------单链表比较
相同返回1，否则返回0
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
			//	p1->name!=p2->name ||		//该字段是char[],所以要用strcmp
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
单链表的反转
------------------------------------------*/
struct stu* Invert_list(struct stu *head)
{
	struct stu *back;   
	struct stu *p1;
	struct stu *p2;

	assert(head!=NULL);      // 断言链表不为空

	//只有一个元素，即返回该元素
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
单链表连接
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

	//反转
	s=Invert_list(s);
	display(s);

	//链表比较
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

	//增加
	printf("Please input the insert info:\n");
	Ins=(struct stu *)malloc(sizeof(stu));            //don't forget allocate memory
	scanf("%s %c %d %d",Ins->name,&Ins->sex,&Ins->no,&Ins->age);
	Ins->next=NULL;
	s=InsertListInfo(s,Ins);
	display(s);



    return 0;
}
