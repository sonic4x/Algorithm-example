#pragma once


#ifndef MULTIPATTERN
#define MULTIPATTERN

#include <string>
#include <queue>
#include <string>
using namespace std;
class AcNode {
public:
	char _data;
	AcNode *children[26]; 
	bool isEndingChar = false; 
	int length = -1; // set pattern string length when isEndingChar=true
	AcNode *fail = nullptr; 

	AcNode(char data) {
		_data = data;
		for (int i = 0; i < 26; i++)
		{
			children[i] = nullptr;
		}
	}

	~AcNode() {

		for (int i = 0; i < 26; i++)
		{
			if (children[i] != nullptr)
			{
				delete children[i];
			}
		}
		
		fail = nullptr;
	}
};


class MultiPatternSearch
{
	AcNode *root;
	//PossibleContainer _possible;

public:
	MultiPatternSearch()
	{
		root = new AcNode('/');
	}

	~MultiPatternSearch()
	{
		delete root;
		root = nullptr;
	}

	void insert(char text[]) {
		AcNode *p = root;
		for (int i = 0; i < strlen(text); ++i) {
			int index = text[i] - 'a';
			if (p->children[index] == nullptr) {
				AcNode *newNode = new AcNode(text[i]);
				p->children[index] = newNode;
			}
			p = p->children[index];

		}
		p->isEndingChar = true;
		p->length = strlen(text);
	}


	void buildFailurePointer() {
		queue<AcNode*> que;
		root->fail = nullptr;
		que.push(root);
		while (!que.empty()) {
			AcNode *p = que.front();
			que.pop();
			for (int i = 0; i < 26; ++i) {
				AcNode *pc = p->children[i];
				if (pc == nullptr) 
					continue;
				if (p == root) {
					pc->fail = root;
				}
				else {
					AcNode *q = p->fail;
					while (q != nullptr) {
						AcNode *qc = q->children[pc->_data - 'a'];
						if (qc != nullptr) {
							pc->fail = qc;
							break;
						}
						q = q->fail;
					}
					if (q == nullptr) {
						pc->fail = root;
					}
				}
				que.push(pc);
			}
		}
	}

	void match(char text[]) { // text is main string
		int n = strlen(text);
		AcNode *p = root;
		for (int i = 0; i < n; ++i) {
			int idx = text[i] - 'a';
			while (p->children[idx] == nullptr && p != root) {
				p = p->fail; 
			}
			p = p->children[idx];
			if (p == nullptr) 
				p = root; // start from root again if unmatched
			AcNode *tmp = p;
			while (tmp != root) { // print matched 
				if (tmp->isEndingChar == true) {
					int pos = i - tmp->length + 1;
					printf("matched start index: %d, length: %d\n",pos, tmp->length);
					
					char *matchedOne = new char[tmp->length + 1];
					strncpy_s(matchedOne, tmp->length+1, &text[pos], tmp->length); // The function include \0 at the end 
					//matchedOne[tmp->length] = '\0'; // no need
					printf("%s\n", matchedOne);
					delete matchedOne;
					matchedOne = nullptr;

					// Don't break here, cause there maybe dictionary like: oi,i,im
				}
				tmp = tmp->fail;
			}
		}
	}



	

	//void printPossible(TrieNode *tnode)
	//{
	//	TrieNode *p = tnode;
	//	if (p->isEndingChar)
	//	{
	//		//print stack
	//		printQueue(_possible);
	//		return;
	//	}
	//	for (int index = 0; index < 26; index++)
	//	{
	//		if (p->children[index] == nullptr)
	//			continue;

	//		_possible.push_back(p->children[index]->_data);
	//		printPossible(p->children[index]);
	//		_possible.pop_back();

	//	}
	//}

	//void printQueue(const PossibleContainer &qc)
	//{
	//	for (auto c : qc)
	//	{
	//		cout << c;
	//	}
	//	cout << endl;
	//}

};





#endif