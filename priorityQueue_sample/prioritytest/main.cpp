#include<iostream>
#include<queue>
#include<set>

using namespace std;
 
//模拟存放节点信息
typedef struct
{
int a;
int b;      
}Node;
//自定义优先级类型
struct cmp
{
       bool operator()(const Node &t1,const Node &t2)
       {
            return t1.b<t2.b;// 相当于less,对于priority_queue,大顶堆; 对于multiset是从小到大
       }
};
//#include<ctype.h>

//演示函数可以修改const char*
void ChangeStr(const char *String)
{
	
	char *Source = (char *)String;

	while (*Source)
	{
		*Source = toupper(*Source);
		Source++;
	}
}

char* STRA()
{
     char st[] = "xxx";
     char *p = st;
     return p;
}

char* STRB()
{
	 char *p = "yyy";	//"yyy"在静态数据区
     return p;
}

char* STRC()
{
	 char *p = "yyy";	//
     return p;
 }

void fun(const int* ni)
{
//	*ni = 1;
	ni = NULL;

}

struct S{
	int i;
	int *p;
};


int main()
{
	//////////////////////////
	/*
	S s;
	int *p = &s.i;
	p[0] = 4;
	p[1] = 3;
	s.p = p;
	s.p[1] = 1;
	s.p[2] = 2;
	*////////////////////////////////

	////////////////////////////////
	//演示函数可以修改const char*
	////////////////////////////////
	char str[] = "The C programme";
	ChangeStr(str);

	///////////////////////////////
	char *pa = NULL;
	pa = STRA();

	char *pb = NULL;
	pb = STRB();

	char *pc = NULL;
	pc = STRC();
	printf("pa = %s , pb = %s, pc = %s\n",pa, pb,pc);
    //初始化
   int n;
   cout<<"num of array:"<<endl;
   cin>>n;
   cout<<"element:"<<endl;
   Node *arr=new Node[n];
   for(int i=0;i<n;i++)
   {
          cin>>arr[i].a>>arr[i].b;

   }
   //定义优先队列 ，自定义优先级,跟Qsort里面自定义相似
   priority_queue<Node,vector<Node>,cmp> Q(arr,arr+n); // 大顶堆 descend
   while(!Q.empty())
   {
         Node n=Q.top();
         cout<<n.a<<" "<<n.b<<endl;
         Q.pop();             
   }
   
   multiset<Node, cmp> setNode( { arr[0],arr[1],arr[2]} ); //小顶堆 ascend
   multiset<Node, cmp>::iterator it;
   while (!setNode.empty())
   {
	   it = setNode.begin();
	   cout << (*it).a << " " << (*it).b << endl;
	   setNode.erase(it);
   }
    system("pause");
    return 0;
}