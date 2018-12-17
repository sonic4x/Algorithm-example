#include <stdio.h>
#include <iostream>
using namespace std;



static int* getNexts(char b[], int m) {
	int *next = new int[m];
	next[0] = -1;
	int k = -1;
	for (int i = 1; i < m; ++i) {
		while (k != -1 && b[k + 1] != b[i]) {
			k = next[k];	// go to minor ones
		}
		if (b[k + 1] == b[i]) {
			++k;
		}
		next[i] = k;
	}
	return next;
}



// a, b are main string and pattern string; n, m are corresponding len
static int kmp(char a[], int n, char b[], int m) {
	int *next = getNexts(b, m);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j > 0 && a[i] != b[j]) {
			j = next[j - 1] + 1;
		}
		if (a[i] == b[j]) {
			++j;
		}
		if (j == m) { // found perfect match
			return i - m + 1;
		}
	}
	return -1;
}

int main()
{
	char *a = "elaborate how you feel";
	char *pattern = "you";
	int idx = kmp(a, strlen(a), pattern, strlen(pattern));
	cout << idx << endl;
	getchar();

}


