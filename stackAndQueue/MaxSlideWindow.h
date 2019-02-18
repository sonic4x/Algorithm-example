#pragma once

/**
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7      3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7
*/
#include <vector>
#include <queue>
#include <deque>
#include <stdio.h>
using namespace std;

//O(n) --best
class Solution {

public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		vector <int> res;

		if (n == 0)
			return res;
		if (k == 1)
			return nums;

		int *left = new int[n];
		int *right= new int[n];

		left[0] = nums[0];
		right[n - 1] = nums[n - 1];

		//max from left in the windows of k
		for (int i = 0; i < n; i++)
		{
			if (i % k == 0)
				left[i] = nums[i];
			else
				left[i] = std::max(nums[i], left[i - 1]);
		}

		// max from right in the windows of k
		for (int i = n - 2; i >= 0; i--)
		{
			if (i % k == 0)
				right[i] = nums[i];
			else
				right[i] = std::max(nums[i], right[i + 1]);
		}

		//overall maximum
		for (int i = 0; i <= n - k; i++)
		{
			res.push_back(std::max(right[i], left[i + k - 1]));
		}

		delete[] left;
		delete[] right;

		return res;
	}
};

//O(NlogN)
class Solution2 {

public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		if (k == 0) 
			return result;

		int n = nums.size();
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < n; i++) {
			while (!pq.empty() && pq.top().second <= i - k)
				pq.pop();

			pq.push(make_pair(nums[i], i));
			if (i >= k - 1)
				result.push_back(pq.top().first);
		}
		return result;
	}
};

//deque, O(N)
class Solution3 {

public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		
		vector<int> result;
		if (k == 0 || k == 1) 
			return result;
		int n = (int)nums.size();
		deque<int> dq;
		for (int i = 0; i < n; i++) {
			while (!dq.empty() && dq.front() <= i - k)
				dq.pop_front();
			while (!dq.empty() && nums[dq.back()] <= nums[i])  //note here is <=, not <
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1)
				result.push_back(nums[dq.front()]);
		}
		return result;
	}
};