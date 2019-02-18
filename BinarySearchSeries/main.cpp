#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
if found, return the idx of the element.
if not found, return the idx of the insert postion of the new element
*/
int Bs(int *a, int n, int x) {
	if (a == nullptr || n <= 0)
		return -1;

	if (n == 1) // only 1 element
	{
		if (a[0] > x)
			return 0;
		return 1;
	}

	int lo = 0;
	int hi = n - 1;

	while (lo <= hi)  // <= not <
	{
		int mid = lo + ((hi - lo) >> 1);
		if (a[mid] == x)
			return mid;

		if (a[mid] > x)
		{
			hi = mid - 1;
			if (a[hi] < x)
				return mid;

		}
		else
		{
			lo = mid + 1;
			if (a[lo] > x)
				return lo;
		}
	}

	if (hi == n-1)
		return n;


	if (lo == 0)
		return 0;
}

int main()
{
	vector<int> vi = { 1,2,3 };
	map<int, vector<int>> mm;
	mm.insert(make_pair(1, vi));

	if (mm.end() != mm.find(1)) {
		auto &v = mm[1];
		v.push_back(4);
	}

	int a[] = { 1,3,5,8,12,18,22,26 };
	int len = sizeof(a) / sizeof(a[0]); //8
	
	int idx = Bs(a, len, 18); // 5
	cout << idx << endl;

	idx = Bs(a, len, 16); // 5
	cout << idx << endl;
	
	idx = Bs(a, len, 28); // 8
	cout << idx << endl;

	idx = Bs(a, len, 0);  // 0
	cout << idx << endl;

	idx = Bs(a, 1, 2); // 1
	cout << idx << endl; 
	
	idx = Bs(a, 1, 0); // 0
	cout << idx << endl;

	getchar();



}