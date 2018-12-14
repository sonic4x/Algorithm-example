
#include <iostream>
#include <iomanip>
using namespace std;

void CreateZigzag(int n)
{
	if (n <= 0)
		return;

	int **a = (int**) (new int*[n]);
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	//upper triangle
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			int sum = i + j;
			int base = ((sum + 1) * sum) >> 1; // more effective than /2
			if (sum & 1 == 1) //odd number ( more effective than %2)
				a[i][j] = base + i;
			else
				a[i][j] = base + j;
		}
	}

	//down triangle
	for (int i = 1; i < n; i++)
	{
		for (int j = n - i; j < n; j++)
		{
			a[i][j] = n * n - 1 - a[n - 1 - i][n - 1 - j];
		}
	}

	//print
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(6) << a[i][j] ;
		}
		cout << endl;
	}

	//delete res
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return;
}

int main()
{

	CreateZigzag(4);

	getchar();
}