#pragma once

/*
Merge k Sorted Lists
*/
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
//36ms
class Solution {

	struct compare
	{
		bool operator()(const pair<ListNode*, int> lhs, const pair<ListNode*, int> rhs) const {
			return lhs.first->val > rhs.first->val;
		}
	};
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		pair<ListNode*, int> pi;
		priority_queue<pair<ListNode*, int>, vector<pair<ListNode*, int>>, compare>pq;
		int len = lists.size();
		for (int i = 0; i<len; i++)
		{

			ListNode *head = lists[i];
			if (head == nullptr)
				continue;
			pi = make_pair(head, i);
			pq.push(pi);
		}

		ListNode* head = NULL, *cur;
		while (!pq.empty()) {
			pair<ListNode*, int> topPi = pq.top();
			ListNode* node = topPi.first;
			int listsIdx = topPi.second;
			if (head == nullptr) {
				head = node;
				cur = head;
			}
			else {
				cur->next = node;
				cur = cur->next;
			}

			pq.pop();

			ListNode *toRuleOut = lists[listsIdx];
			lists[listsIdx] = toRuleOut->next;

			if (lists[listsIdx] != nullptr) {
				pair<ListNode*, int> NextPi = make_pair(lists[listsIdx], listsIdx);
				pq.push(NextPi);
			}

		}


		return head;
	}
};


class Solution3 {

	struct compare
	{
		bool operator()(const ListNode* lhs, const ListNode* rhs) const {
			return lhs->val > rhs->val;
		}
	};
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		priority_queue<ListNode*, vector<ListNode*>, compare>pq;
		
		// take more time than using for len
		/*for (auto l : lists) {
			if(l != nullptr)
				pq.push(l);
		}*/
		int len = lists.size();
		for (int i = 0; i<len; i++)
		{

			ListNode *head = lists[i];
			if (head == nullptr)
				continue;

			pq.push(head);
		}

		ListNode* head = NULL, *cur;
		while (!pq.empty()) {
			ListNode* node = pq.top();
			if (head == nullptr) {
				head = node;
				cur = head;
			}
			else {
				cur->next = node;
				cur = cur->next;
			}

			pq.pop();

			if (node->next != nullptr)
				pq.push(node->next);
		}


		return head;
	}
};
//32ms
class Solution2 { 
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		if (l2->val < l1->val) {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) 
			return NULL;

		int n = lists.size();
		for (; n > 1; n = (n + 1) / 2) {
			for (int i = 0, j = n - 1; i < j; ++i, --j) {
				lists[i] = mergeTwoLists(lists[i], lists[j]);
			}
		}
		return lists[0];
	}
};