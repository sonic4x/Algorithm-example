#include<iostream>
#include<queue>
#include<set>

using namespace std;
 
//ģ���Žڵ���Ϣ
typedef struct
{
int a;
int b;      
}Node;
//�Զ������ȼ�����
struct cmp
{
       bool operator()(const Node &t1,const Node &t2)
       {
            return t1.b<t2.b;// �൱��less,����priority_queue,�󶥶�; ����multiset�Ǵ�С����
       }
};
//#include<ctype.h>

//��ʾ���������޸�const char*
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
	 char *p = "yyy";	//"yyy"�ھ�̬������
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
	//��ʾ���������޸�const char*
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
    //��ʼ��
   int n;
   cout<<"num of array:"<<endl;
   cin>>n;
   cout<<"element:"<<endl;
   Node *arr=new Node[n];
   for(int i=0;i<n;i++)
   {
          cin>>arr[i].a>>arr[i].b;

   }
   //�������ȶ��� ���Զ������ȼ�,��Qsort�����Զ�������
   priority_queue<Node,vector<Node>,cmp> Q(arr,arr+n); // �󶥶� descend
   while(!Q.empty())
   {
         Node n=Q.top();
         cout<<n.a<<" "<<n.b<<endl;
         Q.pop();             
   }
   
   multiset<Node, cmp> setNode( { arr[0],arr[1],arr[2]} ); //С���� ascend
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