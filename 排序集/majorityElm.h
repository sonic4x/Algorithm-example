#pragma once
#include <vector>
using namespace std;

class Solution {

	int partition(vector<int>& a, int lo, int hi)
	{
		if (lo >= hi)
			return hi;
		int i = lo;
		int j = hi + 1;
		int t = a[lo];
		int rt;
		while (i < j)
		{
			do
				i++;
			while (i < hi && a[i] < t);

			do {
				j--;
			} while (a[j] > t);

			if (i > j)
				break;

			swap(a[i], a[j]);
		}
		swap(a[lo], a[j]);  //note here is not swap(t,a[j])
							// pivot is j now
		return j;
	}

public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size();
		int midPos = len >> 1;
		int lo = 0;
		int hi = len - 1;
		while (true) {
			int pivot = partition(nums, lo, hi);
			if (pivot == midPos)
				return nums[pivot];
			else if (pivot < midPos)
				lo = pivot + 1;
			else
				hi = pivot - 1;
		}

	}
};


class Solution2 {

public:
	int majorityElement(vector<int>& nums) {

		int len = nums.size();

		int idx = 0;
		int count = 0;
		int curSelectedNumber;
		for (; idx < len; idx++)
		{
			if (count == 0) {
				curSelectedNumber = nums[idx];
				count++;
			}
			else if (curSelectedNumber == nums[idx])
				count++;
			else
				count--;
		}
		return curSelectedNumber;

	}
};