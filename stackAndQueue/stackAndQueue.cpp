#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

#pragma region use 2 stacks to implement queue
class MyQueue
{
public:
	void Mypush(int value)
	{
		s1.push(value);
	}

	void MyPop()
	{
		while (s1.size() > 1)
		{
			s2.push(s1.top());
			s1.pop();
		}
		s1.pop();

		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}

	int MyFront()
	{
		while (s1.size() > 1)
		{
			s2.push(s1.top());
			s1.pop();
		}
		int ret =  s1.top();

		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		return ret;
	}
private:
	stack<int> s1;
	stack<int> s2;

};


#pragma endregion
int main()
{
	MyQueue mq;
	mq.Mypush(1);
	mq.Mypush(2);
	mq.Mypush(3);
	int a = mq.MyFront();  
	cout << a << endl;   //1
	mq.MyPop();
	a = mq.MyFront();		
	cout << a << endl;	 //2

	mq.Mypush(4);          
	a = mq.MyFront();    //2
	cout << a << endl;
	mq.MyPop();
	a = mq.MyFront();    //3
	cout << a << endl;
	mq.MyPop();

	
	getchar();
	return 0;
}