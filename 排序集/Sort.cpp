//#include <iostream.h>
#include <stdlib.h>	//for rand()
#include <time.h>	//for srand()
#include <stdio.h>
#include <malloc.h>
#include <string>
#include <set>
#include <vector>
#include<functional>  //for greater<int>
using namespace std;
#define  SIZE 10
int TestArray0[SIZE] = {91,7,15,3,11,18,236,4,21,0};

typedef struct Node
{
 int data;
 struct Node *next;
}node;


/*
链表操作辅助函数
Given a list, split it into two sublists — one for the front half, and one for the back half. 
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
选择排序(Selection Sort)的基本思想是：每一趟从待排序的记录中选出关键字最大的记录，
顺序放在已排好序的子文件的最后，直到全部记录排序完毕
*/
//------------数组实现------------------------
void sort(int array[],int num,int increase=0)    //默认降序排序 
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

/*-----------------单链表实现-----------------
 功能：单链表的选择法排序，并返回被排序后链表的首指针
 参数描述：
  Node *head： 单链表的首指针
  int increase: 排序升降标志  
   increase = 1 <按升序排序>
   increase = 0 <按降序排序>
 返回值描述:
  Select_Sort_LinkTable: 被排序后链表的首指针
*/
Node *Select_Sort_LinkTable(Node *head,int increase)
{
		Node *newhead,			//排序后新链表的头节点指针
		*tail,  				//排序后新链表的尾节点指针
		*p,  					//链表遍历指针
		*pre,  					//最小节点的前驱节点指针
		*min;  					//本轮的最小节点(对于升序）;本轮的最大节点(对于降序）
	
		/*设置排序新链表的首指针为空*/
		newhead = NULL;
		/*在剩余的链表中查找链值最小的节点*/
	
	while(head!=NULL)
	{
		for(p = min = head; p->next != NULL; p = p->next)
		{
			if(increase)
			{
				if(p->next->data < min->data)
				{
					/*保存更小节点的前驱节点指针*/
					pre = p;
					/*保存更小节点指针*/
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
		
		/*让查找到的最小节点从原链表中脱掉*/
		if(min == head)
			/*最小节点是首节点*/
			head = head->next;
		else
			pre->next = min->next;
		
		/*将依次找到的最小节点挂到排序链表中*/
		if(newhead == NULL)
			/*首次找到的最小节点*/
			tail = newhead = min;
		else
			tail = tail->next = min;
	}
	
	/*在排序链表中加上链表结束符*/ //easy to forget!!
	if(newhead != NULL)
		tail->next = NULL;
	return(newhead);
}
/*---------------------------------插入排序-------------------------------------
插入排序(Insertion Sort)的基本思想是：每次将一个待排序的记录，
按其关键字大小插入到前面已经排好序的子文件中的适当位置，直到全部记录插入完成为止。

--------------用数组实现-------------------------
/*
 插入排序算法函数Insert_Sort_Array<用数组实现>
 参数描述：
 int array[] :被排序的数组
 int n  :被排序的数组元素个数
 int increase:排序升降标志  
  increase = 1 <按升序排序>
  increase = 0 <按降序排序>
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
				array[j+1] = array[j];	//逐个往后移的过程
		}
		array[j+1] = t;
		//printf("第%d轮外循环：\tj = %d\tArray[j+1] = %d\n",i,j,array[j+1]);
	}
}

// 上面的for等同与下面简单的for+break
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
					array[j+1] = array[j];	//逐个往后移的过程
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
					array[j+1] = array[j];	//逐个往后移的过程
				}
				else
				{
					break;
				}
			}
				
		}
		array[j+1] = t;
		//printf("第%d轮外循环：\tj = %d\tArray[j+1] = %d\n",i,j,array[j+1]);
	}
}

/*-----------------------------------插入法链表实现-----------------------------
Node *Insert_Sort_LinkTable()功能：单链表的插入法排序，并返回被排序后链表的首指针
 参数描述：
  Node *head： 单链表的首指针
  int increase: 排序升降标志  
   increase = 1 <按升序排序>
   increase = 0 <按降序排序>
 返回值描述:
  Select_Sort_LinkTable: 被排序后链表的首指针
  算法Notes： 用单链表每次插入要从链表头开始比较大小，而数组是倒过来比，所以对于降序，如果源数据更接近升序，用链表比更快；若源数据更接近降序，用数组更快。
---------------------------------------------------------------------------*/
Node *Insert_Sort_LinkTable(Node *head,int increase)
{
	Node*pUnsorted,  //还未排序节点序列的首结点指针
		*pTrvrs,  //链表遍历指针
		*pPre,  //当前节点的前驱节点指针
		*pM;  //本轮的最小节点（对于升序）/ 本轮的最大节点（对于降序）
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

Node *Insert_Sort_LinkTable2(Node *head,int increase)	//for清晰版
{
	Node*pUnsorted,  //还未排序节点序列的首结点指针
		*pTrvrs,  //链表遍历指针
		*pPre,  //当前节点的前驱节点指针
		*pM;  //本轮的最小节点（对于升序）/ 本轮的最大节点（对于降序）
	pUnsorted = head->next;
	head->next = NULL;
	while(pUnsorted != NULL)
	{
		if (increase)
		{
			for( pTrvrs= head; pTrvrs != NULL; pPre = pTrvrs,pTrvrs = pTrvrs->next)
			{
				if( pTrvrs->data > pUnsorted->data )
				{
					break;
				}
			}
		}
		else
		{
			for( pTrvrs = head; pTrvrs != NULL; pPre = pTrvrs,pTrvrs = pTrvrs->next)
			{
				if( pTrvrs->data < pUnsorted->data )
				{
					break;
				}
			}
		}
		pM = pUnsorted;
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
希尔(Shell)排序:该方法实质上是一种分组插入方法
算法分析

1．增量序列的选择
    　Shell排序的执行时间依赖于增量序列。
    　好的增量序列的共同特征：
　　① 最后一个增量必须为1；
　　② 应该尽量避免序列中的值(尤其是相邻的值)互为倍数的情况。
    　 有人通过大量的实验，给出了目前较好的结果：当n较大时，比较和移动的次数
	   约在nl.25到1.6n1.25之间。

2．Shell排序的时间性能优于直接插入排序
    　希尔排序的时间性能优于直接插入排序的原因：
　　①当文件初态基本有序时直接插入排序所需的比较和移动次数均较少。
　　②当n值较小时，n和n2的差别也较小，即直接插入排序的最好时间复杂度O(n)和
      最坏时间复杂度0(n2)差别不大。
　　③在希尔排序开始时增量较大，分组较多，每组的记录数目少，故各组内直接插入较快，
      后来增量di逐渐缩小，分组数逐渐减少，而各组的记录数目逐渐增多，但由于已经按di-1作为距离
	  排过序，使文件较接近于有序状态，所以新的一趟排序过程也较快。
    　因此，希尔排序在效率上较直接插人排序有较大的改进。

3．稳定性
    　希尔排序是不稳定的。参见上述实例，该例中两个相同关键字49在排序前后的相对次序发生了变化。
--------------------------------------------------------
 希尔(Shell)排序算法函数Shell_Sort_Array<用数组实现>
 参数描述：
 int array[] :被排序的数组
 int n  :被排序的数组元素个数
 int increase:排序升降标志  
  increase = 1 <按升序排序>
  increase = 0 <按降序排序>
-------------------------------------------------------*/
void Shell_Sort_Array(int array[],int n,int increase=1)
{
	int i,j, //循环控制变量
		step, //每轮内循环插入的步长
		t;  //内循环临时变量
	for(step = n / 2;step > 0;step = step / 2)
	{	for(i = step;i < n;i++)
		{
			
			t = array[i];					/*让出当前考察元素的存储位置*/
			if (increase==1)
			{
				for(j = i - step;j >= 0 && t < array[j]; j = j - step)
				{
					array[j+step] = array[j];	/*移动元素*/
				}
			}
			else 
			{
				for(j = i - step;j >= 0 && t > array[j]; j = j - step)
				{
					array[j+step] = array[j];	/*移动元素*/
				}
			}
			array[j+step] = t;				/*插入当前考察的元素*/
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

/*--------------------------------------- 双冒泡------------------------------
冒泡算法改进
    　一般的冒泡排序还可做如下的改进：
(1)记住最后一次交换发生位置lastExchange的冒泡排序
　　在每趟扫描中，记住最后一次交换发生的位置lastExchange，（该位置之前的相邻记录均已有序）。
下一趟排序开始时，R[1..lastExchange-1]是有序区，R[lastExchange..n]是无序区。
这样，一趟排序可能使当前有序区扩充多个记录，从而减少排序的趟数。

(2) 改变扫描方向的冒泡排序
 ①冒泡排序的不对称性：以一次大循环让最轻的气泡到最上层
　　能一趟扫描完成排序的情况：
    　只有最轻的气泡位于R[n]的位置，其余的气泡均已排好序，那么也只需一趟扫描就可以完成排序。
【例】对初始关键字序列12，18，42，44，45，67，94，10就仅需一趟扫描。
需要n-1趟扫描完成排序情况：
　    当只有最重的气泡位于R[1]的位置，其余的气泡均已排好序时，则仍需做n-1趟扫描才能完成排序。
【例】对初始关键字序列：94，10，12，18，42，44，45，67就需七趟扫描。
 
②造成不对称性的原因
　　每趟扫描仅能使最重气泡"下沉"一个位置，因此使位于顶端的最重气泡下沉到底部时，
需做n-1趟扫描。

 ③改进不对称性的方法
    　在排序过程中交替改变扫描方向，可改进不对称性。
---------------------------------------------------------------------------------------*/
//----------双向冒泡算法----------
void Sort_2bubble(int arry[],int count)	//ascend
{
	int low,high;
	int t;
	int arrytmp;
	high=count-1;
	low=0;							//if low is initialized 1, we have to use do...while(),为了应对只有两个元素的情况; now since low initialize 0, it's not necessary.
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


/*---------------快速排序是C.R.A.Hoare于1962年提出的一种划分交换排序-------------------
它采用了一种分治的策略，通常称其为分治法(Divide-and-Conquer Method)。

（1） 分治法的基本思想是：将原问题分解为若干个规模更小但结构与原问题相似的子问题。
递归地解这些子问题，然后将这些子问题的解组合为原问题的解。

（2）快速排序的基本思想
    　设当前待排序的无序区为R[low..high]，利用分治法可将快速排序的基本思想描述为：
①分解： 
    　在R[low..high]中任选一个记录作为基准(Pivot)，
	以此基准将当前无序区划分为左、右两个较小的子区间R[low..pivotpos-1)和R[pivotpos+1..high]，
	并使左边子区间中所有记录的关键字均小于等于基准记录(不妨记为pivot)的关键字pivot.key，
	右边的子区间中所有记录的关键字均大于等于pivot.key，
	而基准记录pivot则位于正确的位置(pivotpos)上，它无须参加后续的排序。
②求解： 
   　 通过递归调用快速排序对左、右子区间R[low..pivotpos-1]和R[pivotpos+1..high]快速排序。
③组合： 
    　因为当"求解"步骤中的两个递归调用结束时，其左、右两个子区间已有序。
	对快速排序而言，"组合"步骤无须做什么，可看作是空操作。
(3) 时间复杂度：最理想情况算法时间复杂度O(nlog2n)，最坏O(n ^2)。不稳定。
*改进：如果原数据已经有一定顺序了，则pivot取随机比较好
*改进2：当拆分程成的子数组规模很小了，可以退出递归。然后最后用插入sort。
--------------------------------------------------------------------------
 快速排序算法函数Quick_Sort_Array0<用数组实现>
 (快速排序算法是对冒泡算法的改进算法)(递归算法)
 参数描述：
 int array[] :被排序的数组
 int low  :被排序的数组的上界
 int high :被排序的数组的下界
------------------------------------------------------------------------------*/
void Quick_Sort_Array0(int array[],int low,int high)	//ascend
{
	int i,j,t;
	if(low<high)
	{
		i = low;
		j = high;
		t = array[low]; //选其为pivot
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
归并法： 也是分治法，自底向上，有合并过程
-------------------------------*/

//将有二个有序数列a[first...mid]和a[mid...last]合并。  注意两搓数本身已经是有序的了
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
		a[first + i] = temp[i];  //将中间数再复制给a
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
//get 位数
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


bool BucketSort(int a[], int num, int byInc = 1)	//默认升序
{
	int nDigNum = GetMaxDigNum(a, num);
	int *pnTmp = new int[num];		//temp array			
	int nTmpNum[10] = {0};			//记录num of element for every bucket

	int i,k;
	int nDivider = 1;
	//根据位数循环n次，从个位开始
	for(i = 1; i <= nDigNum; ++i)
	{
		//clear the bucket
		memset(nTmpNum, 0, sizeof(int)*10);
		
		
		//统计各bucket的数目（因为可能有重复的数，照理每个箱子应该设计为链表，这里用妙法，仍以数组来做）
		for(k = 0; k < num; ++k )
		{
			int t = (a[k]/nDivider) % 10;
			nTmpNum[t]++;
		}
		
		//升序
//		for( k = 1; k< 10; ++k)
//		{
//			nTmpNum[k] = nTmpNum[k] + nTmpNum[k-1];
//		}

		//涵盖升序和降序（可以优化，这里不用这么麻烦，直接按一种做，之后拷贝时要降序则逆序拷贝即可） 
		for( k = 1; k< 10; ++k)
		{
			int m = (byInc) ? k : 9 - k;
			int n = (byInc) ? m -1 : m + 1;
			nTmpNum[m] = nTmpNum[m] + nTmpNum[n];
		}



		for(k = num-1;k >= 0;k--)			//注意这里要从大到小。
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
面试题：一个数组只含0,1,2三种数，对这个数组排序，要求只能扫描一遍数组
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
 功能：创建排序的单链表，并返回一个指向其头节点的指针
 参数描述：
  int nodecount：新建链表的节点个数
 返回值描述:
  CreateSortNode: 新建链表的头指针
*/
node *CreateSortNode(int nodecount,int *array)
{
	node 
		*p1,//指向产生的新节点
		*p2,//指向链表的尾节点
		*head;//指向链表的头节点
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

//将链表倒序 （iterator)
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
//逆序链表（iterator）---更优雅的算法
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

//逆序（recursive）?
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
【solution】
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
			int nRandNum = rand()%(n);	//[0,n-1]之间的随机数， 1/n概率    
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
/*
下面算法的时间复杂度为O(n)
n + n/2 + n/4 + ... + 1 = 2n - 1, so O(n)
*/
int k = 3;  //第k大
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
		swap( a[rand()%(high-low+1)+low],  a[low] ); //从[low-high]间取一个数作为pivot，也可以直接取a[low]
	
	//下面的循环以及循环后的swap，旨在把大于pivot的数都移到pivot索引前，这样移动后，可知pivot按降序排第几
	//last表明在已经大于pivot的元素中的最后一个下标索引
	for( i = low+1, last = low; i <= high;  i++ )
	{
		if( a[i] >= a[low] )
			swap( a[i], a[++last] );
	}
	swap( a[last], a[low] );
	
	return   last;		
}

int partition_v2(int a[], int low, int high) {
	int pivot = low;
	if (high != low)
		swap(a[rand() % (high - low + 1) + low], a[low]); //从[low-high]间取一个数作为pivot，也可以直接取a[low]
	int pivotValue = a[pivot];
	int i = low;
	int j = high + 1;
	while (low < high) {
		do {
			i++;
		} while (i < j && a[i] < pivotValue);

		do {
			j--;
		} while (a[j] > pivotValue);

		if(i<j)
			swap(a[i], a[j]);

	}
	swap(a[pivot], a[j]);

	return j;
}

void   Rand_select( int  a[],  int  p,  int  q)
{
	int   m;
	if (p <= q)
	{
		m = partition( a, p, q );// m 返回的是下标值，所以要+1后与k比较
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
		ans = head->data;		//pivot 排位等于k，则pivot便是第k大的数
		return;
	}
	else if( k < m+1 )
	{
		head->next = NULL;
		findMaxK( newHead );	//寻找范围[newhead, pivot]
	}
	else
	{
		k -= (m + 1);			//list 头部砍掉了m+1个节点，所以K要相应减小
		findMaxK( head->next );	//即寻找范围从pivot元素之后开始 (pivot, end]
	}
}

//////////////////////////////////////////////////
#pragma region output k most smallest numbers
/* way1 take advantage of partition*/
/* way2*/
typedef multiset<int, greater<int>>						intSet;   //descend order
typedef multiset<int, greater<int>>::iterator	intSetIter;
void GetLeastNumbers(vector<int> &numbers, intSet& leastNumbers, int k) {
	if (numbers.size() == 0 || k < 1 || numbers.size() < k)
		return;

	leastNumbers.clear();
	vector<int>::iterator it = numbers.begin();
	for (; it != numbers.end(); it++) {
		if (leastNumbers.size() < k) {
			leastNumbers.insert(*it);
		}
		else {
			intSetIter maxNumberInLeastNumbersIt = leastNumbers.begin();
			if (*it < *maxNumberInLeastNumbersIt) {
				leastNumbers.erase(maxNumberInLeastNumbersIt);
				leastNumbers.insert(*it);
			}
		}
	}
}

#pragma endregion
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
	printf("[原始]数组元素.........\n");
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
	
	//MergeSort(TestArray0, SIZE);		//归并排序
	//Sort_2bubble(TestArray0, SIZE);
//	printf("after 2bubble sort:\n");
//	for(int n=0;n<SIZE;n++)
//	{
//		printf("%d ", TestArray0[n]);
//	}
//	printf("\n");

	node *head,*s_head;
	head = CreateSortNode(SIZE,TestArray0);

	//findMaxK(head);
	//printf("find k max num: %d\n", ans);
	printf("[排序]前链表元素.........\n");
	List_output(head);
	printf("[排序]后链表元素.........\n");
//	s_head = Select_Sort_LinkTable(head,1);
	s_head = Insert_Sort_LinkTable(head,0);
	List_output(s_head);
	
	//ReverseNode(&s_head);
	ReverseNode2(&s_head);
	printf("[倒序]后链表元素.........\n");
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
	printf("[split]front链表元素.........\n");
	List_output(front);
	printf("[split]back链表元素.........\n");
	List_output(back);

	getchar();
	return 0;
}


/*----------------------------tips--------------------------
按平均时间将排序分为四类：

（1）平方阶(O(n2))排序
    　一般称为简单排序，例如
	 插入: 不稳定
	 选择：稳定
	 冒泡：不稳定

（2）线性对数阶(O(nlgn))排序
    　快速：	 不稳定
	  归并排序： 稳定
	  堆：		 不稳定

（3）O(n1+￡)阶排序
    　￡是介于0和1之间的常数，即0<￡<1，如希尔排序；

（4）线性阶(O(n))排序
    　桶排序（bucket): 稳定
	  基数排序：		？

各种排序方法比较

     简单排序中直接插入最好，快速排序最快，当文件为正序时，直接插入和冒泡均最佳。

影响排序效果的因素

    　因为不同的排序方法适应不同的应用环境和要求，所以选择合适的排序方法应综合考虑下列因素：
　　①待排序的记录数目n；
　　②记录的大小(规模)；
　　③关键字的结构及其初始状态；
　　④对稳定性的要求；
　　⑤语言工具的条件；
　　⑥存储结构；
　　⑦时间和辅助空间复杂度等。

不同条件下，排序方法的选择

(1)若n较小(如n≤50)，可采用直接插入或直接选择排序。
    　当记录规模较小时，直接插入排序较好；否则因为直接选择移动的记录数少于直接插人，
	应选直接选择排序为宜。
(2)若文件初始状态基本有序(指正序)，则应选用直接插人、冒泡或随机的快速排序为宜；
(3)若n较大，则应采用时间复杂度为O(nlgn)的排序方法：快速排序、堆排序或归并排序。
    快速排序是目前基于比较的内部排序中被认为是最好的方法，当待排序的关键字是随机分布时，快速排序的平均时间最短；
    堆排序所需的辅助空间少于快速排序，并且不会出现快速排序可能出现的最坏情况。
	这两种排序都是不稳定的。若要求排序稳定，则可选用归并排序。
*/
