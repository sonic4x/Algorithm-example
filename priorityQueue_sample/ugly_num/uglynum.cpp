/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence

1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
 
shows the first 11 ugly numbers. By convention, 1 is included.

Write a program to find and print the 1500'th ugly number.
*/
#include <iostream> 
#include <queue> 
#include <functional>   // for std::greater

using namespace std; 

typedef pair<unsigned long, int> node_type; 

int main() 
{ 
	unsigned long result[11]; 
	priority_queue< node_type, vector<node_type>,std::greater<node_type> > Q;    //small top
	Q.push( make_pair(1, 2) ); 
	for (int i=0; i<1500; i++) 
	{ 
		node_type node = Q.top(); 
		Q.pop(); 
		switch(node.second) 
		{ 
		case 2: 
			Q.push( make_pair(node.first*2, 2) ); 
		case 3: 
			Q.push( make_pair(node.first*3, 3) ); 
		case 5: 
			Q.push( make_pair(node.first*5, 5) ); 
		} 
		result[i] = node.first; 
	} 
	
	int n; 
	cin >> n; 
	while (n>0) 
	{ 
		cout << result[n-1] << endl; 
		cin >> n; 
	} 
	return 1; 
}