#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> PossibleContainer;
class TrieNode {
public:
	char _data;
	TrieNode *children[26];
	bool isEndingChar = false;
	TrieNode(char data) {
		_data = data;
		for (int i = 0; i < 26; i++)
		{
			children[i] = nullptr;
		}
	}


	~TrieNode() {

		for (int i = 0; i < 26; i++)
		{
			if (children[i] != nullptr)
			{
				delete children[i];
			}
		}
	}
};

class TrieSearch
{
	TrieNode *root;
	PossibleContainer _possible;

public:
	TrieSearch()
	{
		root = new TrieNode('/');
	}

	~TrieSearch()
	{
		delete root;
		root = nullptr;
	}

	void insert(char text[]) {
		TrieNode *p = root;
		for (int i = 0; i < strlen(text); ++i) {
			int index = text[i] - 'a';
			if (p->children[index] == nullptr) {
				TrieNode *newNode = new TrieNode(text[i]);
				p->children[index] = newNode;
			}
			p = p->children[index];
			
		}
		p->isEndingChar = true;
	}


	bool find(char pattern[]) {

		TrieNode *p = root;
		for (int i = 0; i < strlen(pattern); ++i) {
			int index = pattern[i] - 'a';
			if (p->children[index] == nullptr) {
				return false; // ²»´æÔÚ pattern
			}
			p = p->children[index];
		}
		if (p->isEndingChar == false)
		{
			// Given the prefix, show all combinations in dictionary
			_possible.push_back(p->_data);
			printPossible(p);

			//clear container effectively
			PossibleContainer(_possible).swap(_possible);
			return false;
		}
			
		else 
			return true; // ÕÒµ½ pattern
	}

	void printPossible(TrieNode *tnode)
	{
		TrieNode *p = tnode;
		if (p->isEndingChar)
		{
			//print stack
			printQueue(_possible);
			return;
		}
		for (int index = 0; index < 26; index++)
		{
			if (p->children[index] == nullptr)
				continue;

			_possible.push_back(p->children[index]->_data);
			printPossible(p->children[index]);
			_possible.pop_back();
			
		}
	}

	void printQueue(const PossibleContainer &qc)
	{
		for (auto c : qc)
		{
			cout << c;
		}
		cout << endl;
	}

};



int main()
{
	char *dict[] = { "see", "so", "hello","her","hi" };
	char s[] = "s";
	TrieSearch ts;
	for (int i = 0; i < 5; i++)
	{
		ts.insert(dict[i]);
	}
	bool isFound = ts.find(s);
	string str = isFound ? "perfect match" : "unmatch";
	cout << str << endl;

	getchar();
}