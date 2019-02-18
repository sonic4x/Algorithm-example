#include "stdio.h"
#include <assert.h>     
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <functional>
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
		getchar();
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
struct stu* InvertList(stu *head)
{
	if (head == NULL)
	{
		return NULL;
	}

	stu *pre = NULL;
	stu *cur = head;
	stu *next;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}


struct stu* InvertList_recursive(stu *head) {
	if (head == nullptr || head->next == nullptr) 
		return head;

	stu *newHead = InvertList_recursive(head->next);
	head->next->next = head;
	head->next = nullptr;

	return newHead;
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

/*
删除链表中倒数第K个元素 （K从1开始）
*/
stu *RmKth2Tail(stu *head, int k)
{
	if (head == NULL || k <= 0)
	{
		return NULL;
	}
	stu *fast = head;
	
	int i = 0;
	for (; i < k-1; i++)
	{
		if (fast->next == NULL)
		{
			//k is too big
			return NULL;
		}
		fast = fast->next;
	}
	stu *slow = head;
	stu *slowPre;

	if (fast->next == NULL)
	{
		//remove head
		stu *deleteOne = head;
		head = head->next;
		delete deleteOne;
	}

	while (fast->next != NULL)
	{
		slowPre = slow;
		slow = slow->next;
		fast = fast->next;
	}

	//now slow is the one need to be removed, slowPre is the pre node of the slow
	slowPre = slow->next;
	delete slow;
}






















struct stu *DeleteKth2Tail(struct stu *head, int k)
{
	if (head == NULL || k <= 0)
		return NULL;

	stu *pBefore = head;
	int idx = 0;
	for (; idx < k - 1; idx++)
	{
		if (pBefore->next == NULL)
			return NULL;

		pBefore = pBefore->next;
	}

	if (pBefore->next == NULL)
	{
		//head need to be deleted
		stu *newHead = head->next;
		free(head);
		//head = NULL; //useless
		return newHead;
	}

	stu *pBehind = head;
	while (pBefore->next->next != NULL)
	{
		pBefore = pBefore->next;
		pBehind = pBehind->next;
	}

	//now pBehind is the node before Kth to tail.
	stu * tobeDel = pBehind->next;
	pBehind->next = pBehind->next->next;
	free(tobeDel);
	tobeDel = NULL;  //important!!
	return head;
}


/*有序链表连接*/
struct stu *MergeNode(stu *head1, stu *head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	stu *pMergedHead;
	if (head1->age < head2->age)
	{
		pMergedHead = head1;
		pMergedHead->next = MergeNode(head1->next, head2);
	}
	else
	{
		pMergedHead = head2;
		pMergedHead->next = MergeNode(head1, head2->next);
	}
	return pMergedHead;
}

/*
删除倒数第M个元素
*/
bool DeleteReverseMElem(struct stu **head, int m)
{
	if (*head == NULL)
		return false;

	stu *fast = *head;

	for (int i = 0; i < m; ++i)
	{
		if (fast->next == NULL) {
			return false;
		}
		fast = fast->next;
	}

	if (fast->next == NULL) {
		//it means the reverse M elem is the head
		*head = (*head)->next;
		return true;
	}

	stu *behind = *head;
	while (fast->next->next != NULL) {
		fast = fast->next;
		behind = behind->next;
	}

	// Now, the behind is the element before the reversed M elem
	behind->next = behind->next->next;
	return true;
}

#pragma region find first common node
/*
a->b->c
	   ->f->g
   d->e
the first common node is f
*/
int getLengthofNode(stu* head)
{
	int len = 0;
	stu *curNode = head;
	while (curNode != NULL)
	{
		len++;
		curNode = curNode->next;
	}
	return len;
}
stu* FindFirstCommonNode(stu* head1, stu *head2)
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}

	//get length of each node
	int len1 = getLengthofNode(head1);
	int len2 = getLengthofNode(head2);
	int diff;

	stu *fast = NULL;
	stu *slow = NULL;
	if (len1 > len2)
	{
		fast = head1;
		slow = head2;
		diff = len1 - len2;
	}
	else
	{
		fast = head2;
		slow = head1;
		diff = len2 - len1;
	}

	for (int i = 0; i < diff; i++)
	{
		fast = fast->next;
	}

	//now 2 list are same length
	while (fast != NULL)
	{
		if (fast == slow)
		{
			return fast;
		}
		fast = fast->next;
		slow = slow->next;
	}
	return NULL;
}
#pragma endregion

#pragma region 求链表的中间结点
typedef stu Node;
Node *GetMidNode(Node *head) {
	if (head == nullptr)
		return nullptr;

	Node *slow = head;
	Node *fast = head;

	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;	
}

#pragma endregion



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

	//增加
	printf("Please input the insert info:\n");
	Ins = (struct stu *)malloc(sizeof(stu));            //don't forget allocate memory
	scanf("%s %c %d %d", Ins->name, &Ins->sex, &Ins->no, &Ins->age);
	Ins->next = NULL;
	s = InsertListInfo(s, Ins);
	display(s);

	printf("kth to tail to be deleted\n");
	stu * newHead = DeleteKth2Tail(s, 4);
	display(newHead);
	display(s);
	//反转
	newHead = InvertList_recursive(newHead);
	display(newHead);
	newHead = InvertList_recursive(newHead);
	display(newHead);

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





    return 0;
}
