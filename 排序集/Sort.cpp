//#include <iostream.h>
#include <stdlib.h>	//for rand()
#include <time.h>	//for srand()
#include <stdio.h>
#include <malloc.h>
#include <string>

#define  SIZE 10
int TestArray0[SIZE] = {91,7,15,3,11,18,236,4,21,0};

typedef struct Node
{
 int data;
 struct Node *next;
}node;


/*
���������������
Given a list, split it into two sublists �� one for the front half, and one for the back half. 
If the number of elements is odd, the extra element should go in the front list. 
So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}.

*/
void FrontBackSplit(Node *head, Node **front, Node **back)
{
    if(head == NULL) 
		return;
    
    Node *fast = head;
	Node *slow = head;
	Node *prev;

    //when fast move to the end, slow just move to the middle
    while (fast != NULL) {
        prev = slow;
		slow = slow->next;
        fast = (fast->next) ? fast->next->next : NULL;
    }
    
    prev->next = NULL;	// put end to the front list
    *front = head;
    *back = slow;
}

/*
ѡ������(Selection Sort)�Ļ���˼���ǣ�ÿһ�˴Ӵ�����ļ�¼��ѡ���ؼ������ļ�¼��
˳��������ź�������ļ������ֱ��ȫ����¼�������
*/
//------------����ʵ��------------------------
void sort(int array[],int num,int increase=0)    //Ĭ�Ͻ������� 
{
	int i,j,k,t;
	for(i=0;i<num-1;i++)
	{
		k=i;
		for(j=i+1;j<num;j++)
		{
			if(increase==1)
			{
				if(array[j]<array[k])
				{
					k=j;
				}
			}
			else
			{
				if(array[j]>array[k])
				{
					k=j;
				}
			}
		}
		if(k!=i)
		{
			t=array[i];
			array[i]=array[k];
			array[k]=t;
		}
	}
}

/*-----------------������ʵ��-----------------
 ���ܣ��������ѡ�����򣬲����ر�������������ָ��
 ����������
  Node *head�� ���������ָ��
  int increase: ����������־  
   increase = 1 <����������>
   increase = 0 <����������>
 ����ֵ����:
  Select_Sort_LinkTable: ��������������ָ��
*/
Node *Select_Sort_LinkTable(Node *head,int increase)
{
		Node *newhead,			//������������ͷ�ڵ�ָ��
		*tail,  				//������������β�ڵ�ָ��
		*p,  					//�������ָ��
		*pre,  					//��С�ڵ��ǰ���ڵ�ָ��
		*min;  					//���ֵ���С�ڵ�(��������;���ֵ����ڵ�(���ڽ���
	
		/*�����������������ָ��Ϊ��*/
		newhead = NULL;
		/*��ʣ��������в�����ֵ��С�Ľڵ�*/
	
	while(head!=NULL)
	{
		for(p = min = head; p->next != NULL; p = p->next)
		{
			if(increase)
			{
				if(p->next->data < min->data)
				{
					/*�����С�ڵ��ǰ���ڵ�ָ��*/
					pre = p;
					/*�����С�ڵ�ָ��*/
					min = p->next;
				}
			}
			else
			{
				if(p->next->data > min->data)
				{
					pre = p;
					min = p->next;
				}
			}
		}
		
		/*�ò��ҵ�����С�ڵ��ԭ�������ѵ�*/
		if(min == head)
			/*��С�ڵ����׽ڵ�*/
			head = head->next;
		else
			pre->next = min->next;
		
		/*�������ҵ�����С�ڵ�ҵ�����������*/
		if(newhead == NULL)
			/*�״��ҵ�����С�ڵ�*/
			tail = newhead = min;
		else
			tail = tail->next = min;
	}
	
	/*�����������м������������*/ //easy to forget!!
	if(newhead != NULL)
		tail->next = NULL;
	return(newhead);
}
/*---------------------------------��������-------------------------------------
��������(Insertion Sort)�Ļ���˼���ǣ�ÿ�ν�һ��������ļ�¼��
����ؼ��ִ�С���뵽ǰ���Ѿ��ź�������ļ��е��ʵ�λ�ã�ֱ��ȫ����¼�������Ϊֹ��

--------------������ʵ��-------------------------
/*
 ���������㷨����Insert_Sort_Array<������ʵ��>
 ����������
 int array[] :�����������
 int n  :�����������Ԫ�ظ���
 int increase:����������־  
  increase = 1 <����������>
  increase = 0 <����������>
*/
void Insert_Sort_Array(int array[],int n,int increase)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=array[i];
		if(increase)
		{
			for(j=i-1;j>=0 && t < array[j];j--)
				array[j+1] = array[j];
		}
		else
		{
			for(j=i-1;j>=0 && t > array[j];j--)
				array[j+1] = array[j];	//��������ƵĹ���
		}
		array[j+1] = t;
		//printf("��%d����ѭ����\tj = %d\tArray[j+1] = %d\n",i,j,array[j+1]);
	}
}

// �����for��ͬ������򵥵�for+break
void Insert_Sort_Array2(int array[],int n,int increase)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=array[i];
		if(increase)
		{
			for(j=i-1;j>=0; j--)
			{
				if (t < array[j])
				{
					array[j+1] = array[j];	//��������ƵĹ���
				}
				else
				{
					break;
				}
			}
				
		}
		else
		{
			for(j=i-1; j>=0; j--)
			{
				if (t > array[j])
				{
					array[j+1] = array[j];	//��������ƵĹ���
				}
				else
				{
					break;
				}
			}
				
		}
		array[j+1] = t;
		//printf("��%d����ѭ����\tj = %d\tArray[j+1] = %d\n",i,j,array[j+1]);
	}
}

/*-----------------------------------���뷨����ʵ��-----------------------------
Node *Insert_Sort_LinkTable()���ܣ�������Ĳ��뷨���򣬲����ر�������������ָ��
 ����������
  Node *head�� ���������ָ��
  int increase: ����������־  
   increase = 1 <����������>
   increase = 0 <����������>
 ����ֵ����:
  Select_Sort_LinkTable: ��������������ָ��
  �㷨Notes�� �õ�����ÿ�β���Ҫ������ͷ��ʼ�Ƚϴ�С���������ǵ������ȣ����Զ��ڽ������Դ���ݸ��ӽ�����������ȸ��죻��Դ���ݸ��ӽ�������������졣
---------------------------------------------------------------------------*/
Node *Insert_Sort_LinkTable(Node *head,int increase)
{
	Node*pUnsorted,  //��δ����ڵ����е��׽��ָ��
		*pTrvrs,  //�������ָ��
		*pPre,  //��ǰ�ڵ��ǰ���ڵ�ָ��
		*pM;  //���ֵ���С�ڵ㣨��������/ ���ֵ����ڵ㣨���ڽ���
	pUnsorted = head->next;
	head->next = NULL;
	while(pUnsorted != NULL)
	{
		if (increase)
		{
			for(pM = pUnsorted, pTrvrs= head; pTrvrs != NULL && pTrvrs->data < pM->data; pPre = pTrvrs,pTrvrs = pTrvrs->next);
		}
		else
		{
			for(pM = pUnsorted, pTrvrs = head; pTrvrs != NULL && pTrvrs->data > pM->data; pPre = pTrvrs,pTrvrs = pTrvrs->next);
		}

		pUnsorted = pUnsorted->next;
		
		if(pTrvrs == head)
			head = pM;
		else
			pPre->next = pM;
			
		pM->next = pTrvrs;
	}
	return(head);
}

Node *Insert_Sort_LinkTable2(Node *head,int increase)	//for������
{
	Node*pUnsorted,  //��δ����ڵ����е��׽��ָ��
		*pTrvrs,  //�������ָ��
		*pPre,  //��ǰ�ڵ��ǰ���ڵ�ָ��
		*pM;  //���ֵ���С�ڵ㣨��������/ ���ֵ����ڵ㣨���ڽ���
	pUnsorted = head->next;
	head->next = NULL;
	while(pUnsorted != NULL)
	{
		if (increase)
		{
			for(pM = pUnsorted, pTrvrs= head; pTrvrs != NULL; pPre = pTrvrs,pTrvrs = pTrvrs->next)
			{
				if( pTrvrs->data > pM->data )
				{
					break;
				}
			}
		}
		else
		{
			for(pM = pUnsorted, pTrvrs = head; pTrvrs != NULL; pPre = pTrvrs,pTrvrs = pTrvrs->next)
			{
				if( pTrvrs->data < pM->data )
				{
					break;
				}
			}
		}

		pUnsorted = pUnsorted->next;
		
		if(pTrvrs == head)
			head = pM;
		else
			pPre->next = pM;
			
		pM->next = pTrvrs;
	}
	return(head);
}

/*---------------------------------------------------
ϣ��(Shell)����:�÷���ʵ������һ�ַ�����뷽��
�㷨����

1���������е�ѡ��
    ��Shell�����ִ��ʱ���������������С�
    ���õ��������еĹ�ͬ������
������ ���һ����������Ϊ1��
������ Ӧ�þ������������е�ֵ(���������ڵ�ֵ)��Ϊ�����������
    �� ����ͨ��������ʵ�飬������Ŀǰ�ϺõĽ������n�ϴ�ʱ���ȽϺ��ƶ��Ĵ���
	   Լ��nl.25��1.6n1.25֮�䡣

2��Shell�����ʱ����������ֱ�Ӳ�������
    ��ϣ�������ʱ����������ֱ�Ӳ��������ԭ��
�����ٵ��ļ���̬��������ʱֱ�Ӳ�����������ıȽϺ��ƶ����������١�
�����ڵ�nֵ��Сʱ��n��n2�Ĳ��Ҳ��С����ֱ�Ӳ�����������ʱ�临�Ӷ�O(n)��
      �ʱ�临�Ӷ�0(n2)��𲻴�
��������ϣ������ʼʱ�����ϴ󣬷���϶࣬ÿ��ļ�¼��Ŀ�٣��ʸ�����ֱ�Ӳ���Ͽ죬
      ��������di����С���������𽥼��٣�������ļ�¼��Ŀ�����࣬�������Ѿ���di-1��Ϊ����
	  �Ź���ʹ�ļ��Ͻӽ�������״̬�������µ�һ���������Ҳ�Ͽ졣
    ����ˣ�ϣ��������Ч���Ͻ�ֱ�Ӳ��������нϴ�ĸĽ���

3���ȶ���
    ��ϣ�������ǲ��ȶ��ġ��μ�����ʵ����������������ͬ�ؼ���49������ǰ�����Դ������˱仯��
--------------------------------------------------------
 ϣ��(Shell)�����㷨����Shell_Sort_Array<������ʵ��>
 ����������
 int array[] :�����������
 int n  :�����������Ԫ�ظ���
 int increase:����������־  
  increase = 1 <����������>
  increase = 0 <����������>
-------------------------------------------------------*/
void Shell_Sort_Array(int array[],int n,int increase=1)
{
	int i,j, //ѭ�����Ʊ���
		step, //ÿ����ѭ������Ĳ���
		t;  //��ѭ����ʱ����
	for(step = n / 2;step > 0;step = step / 2)
	{	for(i = step;i < n;i++)
		{
			
			t = array[i];					/*�ó���ǰ����Ԫ�صĴ洢λ��*/
			if (increase==1)
			{
				for(j = i - step;j >= 0 && t < array[j]; j = j - step)
				{
					array[j+step] = array[j];	/*�ƶ�Ԫ��*/
				}
			}
			else 
			{
				for(j = i - step;j >= 0 && t > array[j]; j = j - step)
				{
					array[j+step] = array[j];	/*�ƶ�Ԫ��*/
				}
			}
			array[j+step] = t;				/*���뵱ǰ�����Ԫ��*/
		}
	}
}

/*--------------------bubble-------------------
*/
void bubble(int a[],int n)
{
	int i,j,k;

	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
		}
	}
}

/*--------------------------------------- ˫ð��------------------------------
ð���㷨�Ľ�
    ��һ���ð�����򻹿������µĸĽ���
(1)��ס���һ�ν�������λ��lastExchange��ð������
������ÿ��ɨ���У���ס���һ�ν���������λ��lastExchange������λ��֮ǰ�����ڼ�¼�������򣩡�
��һ������ʼʱ��R[1..lastExchange-1]����������R[lastExchange..n]����������
������һ���������ʹ��ǰ��������������¼���Ӷ����������������

(2) �ı�ɨ�跽���ð������
 ��ð������Ĳ��Գ��ԣ���һ�δ�ѭ������������ݵ����ϲ�
������һ��ɨ���������������
    ��ֻ�����������λ��R[n]��λ�ã���������ݾ����ź�����ôҲֻ��һ��ɨ��Ϳ����������
�������Գ�ʼ�ؼ�������12��18��42��44��45��67��94��10�ͽ���һ��ɨ�衣
��Ҫn-1��ɨ��������������
��    ��ֻ�����ص�����λ��R[1]��λ�ã���������ݾ����ź���ʱ����������n-1��ɨ������������
�������Գ�ʼ�ؼ������У�94��10��12��18��42��44��45��67��������ɨ�衣
 
����ɲ��Գ��Ե�ԭ��
����ÿ��ɨ�����ʹ��������"�³�"һ��λ�ã����ʹλ�ڶ��˵����������³����ײ�ʱ��
����n-1��ɨ�衣

 �۸Ľ����Գ��Եķ���
    ������������н���ı�ɨ�跽�򣬿ɸĽ����Գ��ԡ�
---------------------------------------------------------------------------------------*/
//----------˫��ð���㷨----------
void Sort_2bubble(int arry[],int count)	//ascend
{
	int low,high;
	int t;
	int arrytmp;
	high=count-1;
	low=0;							//if low is initialized 1, we have to use do...while(),Ϊ��Ӧ��ֻ������Ԫ�ص����; now since low initialize 0, it's not necessary.
	do								//both do...while() and while()...do have the same effect.
	{
		for(int i=high;i>low;i--)
		{
			if(arry[i]<arry[i-1])
			{
				arrytmp=arry[i-1];
				arry[i-1]=arry[i];
				arry[i]=arrytmp;
				t=i;
			}
			
		}
		low=t;

		for(int j=low;j<high;j++)
		{
			if(arry[j]>arry[j+1])
			{
				arrytmp=arry[j+1];
				arry[j+1]=arry[j];
				arry[j]=arrytmp;
				t=j;
			}
			
		}
		high=t;
	}
	while(low<high);
}


/*---------------����������C.R.A.Hoare��1962�������һ�ֻ��ֽ�������-------------------
��������һ�ַ��εĲ��ԣ�ͨ������Ϊ���η�(Divide-and-Conquer Method)��

��1�� ���η��Ļ���˼���ǣ���ԭ����ֽ�Ϊ���ɸ���ģ��С���ṹ��ԭ�������Ƶ������⡣
�ݹ�ؽ���Щ�����⣬Ȼ����Щ������Ľ����Ϊԭ����Ľ⡣

��2����������Ļ���˼��
    ���赱ǰ�������������ΪR[low..high]�����÷��η��ɽ���������Ļ���˼������Ϊ��
�ٷֽ⣺ 
    ����R[low..high]����ѡһ����¼��Ϊ��׼(Pivot)��
	�Դ˻�׼����ǰ����������Ϊ����������С��������R[low..pivotpos-1)��R[pivotpos+1..high]��
	��ʹ��������������м�¼�Ĺؼ��־�С�ڵ��ڻ�׼��¼(������Ϊpivot)�Ĺؼ���pivot.key��
	�ұߵ������������м�¼�Ĺؼ��־����ڵ���pivot.key��
	����׼��¼pivot��λ����ȷ��λ��(pivotpos)�ϣ�������μӺ���������
����⣺ 
   �� ͨ���ݹ���ÿ������������������R[low..pivotpos-1]��R[pivotpos+1..high]��������
����ϣ� 
    ����Ϊ��"���"�����е������ݹ���ý���ʱ������������������������
	�Կ���������ԣ�"���"����������ʲô���ɿ����ǿղ�����
(3) ʱ�临�Ӷȣ�����������㷨ʱ�临�Ӷ�O(nlog2n)���O(n ^2)�����ȶ���
*�Ľ������ԭ�����Ѿ���һ��˳���ˣ���pivotȡ����ȽϺ�
*�Ľ�2������ֳ̳ɵ��������ģ��С�ˣ������˳��ݹ顣Ȼ������ò���sort��
--------------------------------------------------------------------------
 ���������㷨����Quick_Sort_Array0<������ʵ��>
 (���������㷨�Ƕ�ð���㷨�ĸĽ��㷨)(�ݹ��㷨)
 ����������
 int array[] :�����������
 int low  :�������������Ͻ�
 int high :�������������½�
------------------------------------------------------------------------------*/
void Quick_Sort_Array0(int array[],int low,int high)	//ascend
{
	int i,j,t;
	if(low<high)
	{
		i = low;
		j = high;
		t = array[low]; //ѡ��Ϊpivot
		while(i<j)
		{
			while(i<j && array[j] > t)
				j--;
			if(i<j)
				array[i++] = array[j];
			while(i<j && array[i] <= t)
				i++;
			if(i<j)
				array[j--] = array[i];
		}
		array[i] = t;
		Quick_Sort_Array0(array,low,i-1);
		Quick_Sort_Array0(array,i+1,high);
	}
}


/*------------------------------
�鲢���� Ҳ�Ƿ��η����Ե����ϣ��кϲ�����
-------------------------------*/

//���ж�����������a[first...mid]��a[mid...last]�ϲ���  ע�������������Ѿ����������
void __merge(int a[], int first, int mid, int last, int temp[])  
{  
	int i = first, j = mid + 1;  
	int m = mid,   n = last;  
	int k = 0;  

	while (i <= m && j <= n)  
	{  
		if (a[i] <= a[j])  
			temp[k++] = a[i++];  
		else  
			temp[k++] = a[j++];  
	}  

	while (i <= m)  
		temp[k++] = a[i++];  

	while (j <= n)  
		temp[k++] = a[j++];  
	
	for (i = 0; i < k; i++)		
		a[first + i] = temp[i];  //���м����ٸ��Ƹ�a
}  

void __merge_sort(int a[], int first, int last, int temp[])  
{  
	if(first < last)  
	{  
		int mid = (first + last) / 2;  
		__merge_sort(a, first, mid, temp);  
		__merge_sort(a, mid + 1, last, temp);  
		__merge(a, first, mid, last, temp);  
	}  
}  

bool MergeSort(int a[], int n)  
{  
	int *p = new int[n];  
	if(p == NULL)  
	{  
		return false;  
	}  
	else  
	{  
		__merge_sort(a, 0, n - 1, p);  
		delete[] p;  
		return true;  
	}  
}  

/*--------------------------------------
bucket sort
---------------------------------------*/
//get λ��
int GetMaxDigNum(int a[], int num)
{
	int nMaxDigNum = 1;
	int ndivider = 10;
	for (int i = 0; i< num; ++i)
	{
		while( a[i] / ndivider != 0)
		{
			ndivider *= 10;
			nMaxDigNum ++;
			
		}
	}

	return nMaxDigNum;
}


bool BucketSort(int a[], int num, int byInc = 1)	//Ĭ������
{
	int nDigNum = GetMaxDigNum(a, num);
	int *pnTmp = new int[num];		//temp array			
	int nTmpNum[10] = {0};			//��¼num of element for every bucket

	int i,k;
	int nDivider = 1;
	//����λ��ѭ��n�Σ��Ӹ�λ��ʼ
	for(i = 1; i <= nDigNum; ++i)
	{
		//clear the bucket
		memset(nTmpNum, 0, sizeof(int)*10);
		
		
		//ͳ�Ƹ�bucket����Ŀ����Ϊ�������ظ�����������ÿ������Ӧ�����Ϊ���������������������������
		for(k = 0; k < num; ++k )
		{
			int t = (a[k]/nDivider) % 10;
			nTmpNum[t]++;
		}
		
		//����
//		for( k = 1; k< 10; ++k)
//		{
//			nTmpNum[k] = nTmpNum[k] + nTmpNum[k-1];
//		}

		//��������ͽ��򣨿����Ż������ﲻ����ô�鷳��ֱ�Ӱ�һ������֮�󿽱�ʱҪ���������򿽱����ɣ� 
		for( k = 1; k< 10; ++k)
		{
			int m = (byInc) ? k : 9 - k;
			int n = (byInc) ? m -1 : m + 1;
			nTmpNum[m] = nTmpNum[m] + nTmpNum[n];
		}



		for(k = num-1;k >= 0;k--)			//ע������Ҫ�Ӵ�С��
		{
			int t = (a[k]/nDivider) % 10;
			pnTmp[nTmpNum[t]-1] = a[k];

			//printf("pnTmp[%d] = %d\n", nTmpNum[t]-1, a[k]);
			nTmpNum[t] --;					//don't forget --
		}
		

		//copy tmparray to a
		for(k = 0; k < num; ++k )
		{
			a[k] = pnTmp[k];
			//printf("%d ", a[k]);
		}

		nDivider *= 10;
	}
	return 1;
}

/*
�����⣺һ������ֻ��0,1,2���������������������Ҫ��ֻ��ɨ��һ������
*/
void Swap(int* v1, int* v2) {  
  int temp = *v1;  
  *v1 = *v2;  
  *v2 = temp;  
}  
  
void SortArray(int* array, int len) 
{  
  int i = 0, j = len - 1, k = 0;  
  
  while (k < j) {  
    if (array[k] == 2) {  
      while(array[j] == 2 && j > k) {  
        j--;  
      }     
      if (j > k) {  
        swap(array[k], array[j]);  
      }     
    }     
    if (array[k] == 0) {  
      while(array[i] == 0 && i < k) {  
        i++;  
      }     
      if (i < k) {  
        swap(array[i], array[k]);  
      }     
    }     
    if (array[k] == 1 || k == i) {  
      k++;  
    }     
  }  
}  


/*
 ���ܣ���������ĵ�����������һ��ָ����ͷ�ڵ��ָ��
 ����������
  int nodecount���½�����Ľڵ����
 ����ֵ����:
  CreateSortNode: �½������ͷָ��
*/
node *CreateSortNode(int nodecount,int *array)
{
	node 
		*p1,//ָ��������½ڵ�
		*p2,//ָ�������β�ڵ�
		*head;//ָ�������ͷ�ڵ�
	int i;
	head = NULL;
	for(i=0;i<nodecount;i++)
	{
		p1=(node *)malloc(sizeof(node));
		p1->data = array[i];
		p1->next = NULL;
		if (i == 0)
			head = p1;
		else
			p2->next = p1;
		
		p2 = p1;
	}
	p2->next = NULL;
	return(head);
}

//�������� ��iterator)
bool ReverseNode(node **head)
{
	if(NULL == *head || NULL== (*head)->next)
	{
		return 0;
	}

	node *p1;
	node *p2;
	node *p3;

	p1 = *head;
	p2 = p1->next;
	p1->next = NULL;

	while(p2 != NULL)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	*head = p1;
	return 1;
}
//��������iterator��---�����ŵ��㷨
void ReverseNode2(Node **head) 
{
    if (head == NULL || *head == NULL) 
		return;
    Node *node = *head;
    Node *prev = NULL;
    
    while (node != NULL) 
	{
        Node *next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    *head = prev;
}

//����recursive��?
void ReverseNode_recursive(Node **head) 
{
    if (head == NULL || *head == NULL) 
		return;
    Node *node = *head;
    Node *next = node->next;

    if (next == NULL) 
	{
		return;
	}
    ReverseNode_recursive(&next);
    node->next->next = node;
    node->next = NULL;
    node = next;
}

////////////////////////////////////
/*
how to randomly find an element with equal probability? 
Given the head pointer to a loop-less singly linked list, and you are allowed to scan from the head to the end of the list only once.
��solution��
Read the 1st element, store it. Read 2nd element, keep either it or the first one, 50% chance for each. 
Read 3rd element, keep either it or the other kept one, 1/3 chance for new one. 
Read 4th element, keep either it or the other kept one, 1/4 chance for new one. Keep going.
*/
void RandomElement(node *head)
{
	
	Node *pChosen = NULL;
	Node *p = head;
	int n = 0;		
	while (NULL != p)
	{
		n++;
		if( pChosen == NULL)	//indicate its the 1st element
		{
			pChosen = p;
		}
		else
		{
			int nRandNum = rand()%(n);	//[0,n-1]֮���������� 1/n����    
			if( n == nRandNum +1)
			{
				pChosen = p;
			}
		}
		p = p->next;
	}
	printf("the random chosen element is:%d\n",pChosen->data);

}

//void RemoveDuplicates(node* head) 
//{ 
//	node* current = head; 
//	if (current == NULL) 
//		return; 
//	
//	while(current->next!=NULL) 
//	{ 
//		if (current->data == current->next->data) 
//		{ 
//			struct node* nextNext = current->next->next; 
//			free(current->next); 
//			current->next = nextNext; 
//		} 
//		else 
//			current = current->next; 
//	} 
//}


/////////////////find k max num///////////////////
int k = 3;  //��k��
int ans;

int   swap( int &p, int &q )
{
	int  temp = p;
	p = q;
	q = temp;
	return   0;
}

int   partition( int a[], int low, int high )
{
	int   last,   i;
	if( high != low )
		swap( a[rand()%(high-low+1)+low],  a[low] ); //��[low-high]��ȡһ������Ϊpivot��Ҳ����ֱ��ȡa[low]
	
	//�����ѭ���Լ�ѭ�����swap��ּ�ڰѴ���pivot�������Ƶ�pivot����ǰ�������ƶ��󣬿�֪pivot�������ŵڼ�
	//last�������Ѿ�����pivot��Ԫ���е����һ���±�����
	for( i = low+1, last = low; i <= high;  i++ )
	{
		if( a[i] >= a[low] )
			swap( a[i], a[++last] );
	}
	swap( a[last], a[low] );
	
	return   last;		
}

void   Rand_select( int  a[],  int  p,  int  q)
{
	int   m;
	if (p <= q)
	{
		m = partition( a, p, q );// m ���ص����±�ֵ������Ҫ+1����k�Ƚ�
		if( k == m+1 )
		{             
			ans   =   a[m];
			return;
		}
		else if( k > m +1 )
			Rand_select( a, m+1, q );
		else
			Rand_select( a, p, m-1 );
	}
}

void List_output(node *head);
///////////list implementation////////////////
int division(Node* head, Node **newHead)
{
	int id = 0;
	Node *pivot = head;
	
	Node *pCur = head->next;
	*newHead = NULL;
	Node *lstHead = head;
	Node *pre = head;

	while( pCur != NULL) 
	{
		if( pCur->data > pivot->data)
		{
			id ++;
			Node *next = pCur->next;
			pre->next = next;
			*newHead = pCur;
			(*newHead)->next = lstHead;
			lstHead = *newHead;

			pCur = next;
		}
		else
		{
			pre  = pCur;
			pCur = pCur->next;
		}
		
	}

	List_output(*newHead);

	return id;
}

void  findMaxK(Node *head)
{
	Node *newHead;

	int m = division(head, &newHead);
	if( k == m+1 )
	{
		ans = head->data;		//pivot ��λ����k����pivot���ǵ�k�����
		return;
	}
	else if( k < m+1 )
	{
		head->next = NULL;
		findMaxK( newHead );	//Ѱ�ҷ�Χ[newhead, pivot]
	}
	else
	{
		k -= (m + 1);			//list ͷ��������m+1���ڵ㣬����KҪ��Ӧ��С
		findMaxK( head->next );	//��Ѱ�ҷ�Χ��pivotԪ��֮��ʼ (pivot, end]
	}
}

//////////////////////////////////////////////////


void List_output(node *head)
{
	node *p;
	p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	printf("[ԭʼ]����Ԫ��.........\n");
	for(int i=0;i<SIZE;i++)
	{
		printf("%d ",TestArray0[i]);
	}
	printf("\n");

//	{
//
//		Rand_select(  TestArray0,   0,   SIZE-1   );
//		printf("find k max num: %d\n", ans);
//	
//	}
/*	sort(TestArray0,SIZE,1);
	for(int n=0;n<SIZE;n++)
	{
		cout<<TestArray0[n]<<",";
	}
*/
/*	Shell_Sort_Array(TestArray0,SIZE,1);
	for(int n=0;n<SIZE;n++)
	{
		cout<<TestArray0[n]<<",";
	}
*/	

//	Quick_Sort_Array0(TestArray0, 0,SIZE-1);
//	BucketSort(TestArray0, SIZE);
	
	//MergeSort(TestArray0, SIZE);		//�鲢����
	//Sort_2bubble(TestArray0, SIZE);
//	printf("after 2bubble sort:\n");
//	for(int n=0;n<SIZE;n++)
//	{
//		printf("%d ", TestArray0[n]);
//	}
//	printf("\n");

	node *head,*s_head;
	head = CreateSortNode(SIZE,TestArray0);

	findMaxK(head);
	printf("find k max num: %d\n", ans);


	printf("[����]������Ԫ��.........\n");
//	s_head = Select_Sort_LinkTable(head,1);
	s_head = Insert_Sort_LinkTable(head,0);
	List_output(s_head);
	
	//ReverseNode(&s_head);
	ReverseNode2(&s_head);
	printf("[����]������Ԫ��.........\n");
	List_output(s_head);

	//random chosen
	srand((unsigned)time(NULL));
	RandomElement(s_head);
	RandomElement(s_head);
	RandomElement(s_head);
	RandomElement(s_head);
	RandomElement(s_head);
	RandomElement(s_head);
	RandomElement(s_head);
	RandomElement(s_head);
	RandomElement(s_head);
	RandomElement(s_head);
	//split list
	Node *front, *back;
	FrontBackSplit(s_head, &front, &back);
	printf("[split]front����Ԫ��.........\n");
	List_output(front);
	printf("[split]back����Ԫ��.........\n");
	List_output(back);

	getchar();
	return 0;
}


/*----------------------------tips--------------------------
��ƽ��ʱ�佫�����Ϊ���ࣺ

��1��ƽ����(O(n2))����
    ��һ���Ϊ����������
	 ����: ���ȶ�
	 ѡ���ȶ�
	 ð�ݣ����ȶ�

��2�����Զ�����(O(nlgn))����
    �����٣�	 ���ȶ�
	  �鲢���� �ȶ�
	  �ѣ�		 ���ȶ�

��3��O(n1+��)������
    �����ǽ���0��1֮��ĳ�������0<��<1����ϣ������

��4�����Խ�(O(n))����
    ��Ͱ����bucket): �ȶ�
	  ��������		��

�������򷽷��Ƚ�

     ��������ֱ�Ӳ�����ã�����������죬���ļ�Ϊ����ʱ��ֱ�Ӳ����ð�ݾ���ѡ�

Ӱ������Ч��������

    ����Ϊ��ͬ�����򷽷���Ӧ��ͬ��Ӧ�û�����Ҫ������ѡ����ʵ����򷽷�Ӧ�ۺϿ����������أ�
�����ٴ�����ļ�¼��Ŀn��
�����ڼ�¼�Ĵ�С(��ģ)��
�����۹ؼ��ֵĽṹ�����ʼ״̬��
�����ܶ��ȶ��Ե�Ҫ��
���������Թ��ߵ�������
�����޴洢�ṹ��
������ʱ��͸����ռ临�Ӷȵȡ�

��ͬ�����£����򷽷���ѡ��

(1)��n��С(��n��50)���ɲ���ֱ�Ӳ����ֱ��ѡ������
    ������¼��ģ��Сʱ��ֱ�Ӳ�������Ϻã�������Ϊֱ��ѡ���ƶ��ļ�¼������ֱ�Ӳ��ˣ�
	Ӧѡֱ��ѡ������Ϊ�ˡ�
(2)���ļ���ʼ״̬��������(ָ����)����Ӧѡ��ֱ�Ӳ��ˡ�ð�ݻ�����Ŀ�������Ϊ�ˣ�
(3)��n�ϴ���Ӧ����ʱ�临�Ӷ�ΪO(nlgn)�����򷽷����������򡢶������鲢����
    ����������Ŀǰ���ڱȽϵ��ڲ������б���Ϊ����õķ�������������Ĺؼ���������ֲ�ʱ�����������ƽ��ʱ����̣�
    ����������ĸ����ռ����ڿ������򣬲��Ҳ�����ֿ���������ܳ��ֵ�������
	�����������ǲ��ȶ��ġ���Ҫ�������ȶ������ѡ�ù鲢����
*/
