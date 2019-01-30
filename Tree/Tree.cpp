// Tree.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


template<typename T>
class Singleton
{
public:
	static T& getInstance(int size = 8)
	{
		static T value(size);
		return value;
	}

private:
	Singleton();
	~Singleton();
};

class TreeNode;
TreeNode *freeNode;
TreeNode *freeNode2;

TreeNode * GetFreeBlock();
void ReturnBlock(TreeNode* pTn);
class TreeNode
{
public:
	int value;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data = 0) { 
		value = data;  
		left = right = root = nullptr; 
		bDeleted = false;
	}


public:
#pragma region BST insert
	TreeNode *root;
	bool bDeleted;
	void BST_insert(int data) {
		if (nullptr == root) {
			//root = freeNode++;
			root = GetFreeBlock();
			root->value = data;
			//root = new(freeNode2) TreeNode(data); //It will construct more than 1 obj.
			//freeNode2 += sizeof(TreeNode);
			
			return;
		}

		TreeNode *p = root;
		while (p != nullptr)
		{
			if (data > p->value) {
				if (p->right == nullptr) {
					// way1:
					//p->right = new TreeNode(data);
					// way2:
					//p->right = freeNode++;
					//p->right->value = data;
					// way3: cannot do this!!!
					/*p->right = new(freeNode2) TreeNode(data);
					freeNode2 += sizeof(TreeNode);*/
					// way4:
					p->right = GetFreeBlock();
					p->right->value = data;
					return;
				}
				p = p->right;
			}
			else if(data < p->value){
				if (p->left == nullptr) {
					/*p->left = freeNode++;
					p->left->value = data;*/
					// way3:
					/*p->left = new(freeNode2) TreeNode(data);
					freeNode2 += sizeof(TreeNode);*/
					p->left = GetFreeBlock();
					p->left->value = data;
					return;
				}
				p = p->left;
			}
			else {
				p->bDeleted = false;
				return;
			}
		}
	}
#pragma endregion 

	void BST_Del(int data) {
		TreeNode *p = root;
		while (p != nullptr && p->value != data)
		{
			if (data > p->value) {
				p = p->right;
			}
			else {
				p = p->left;
			}
		}

		if (p == nullptr) {
			//not found
			return;
		}

		p->bDeleted = true;
		//ReturnBlock(p); 

	}
};

class TreeNodeMemBlock
{
public:
	bool _bUsed; // 4 bytes align pack 
	TreeNode _tn;

	TreeNodeMemBlock()
	{
		_bUsed = false;
		//_tn = new TreeNode();
	}
};

class MemBlockMgr
{
private:
	TreeNodeMemBlock *_blocks;
	int _size;
public:
	MemBlockMgr(int size) {
		_blocks = new TreeNodeMemBlock[size];
		_size = size;
	}

	TreeNode* GetFreeBlock() {
		int idx = 0;
		for (; idx < _size; idx++)
		{
			if (!_blocks[idx]._bUsed) {
				_blocks[idx]._bUsed = true;
				return &_blocks[idx]._tn;
			}
		}
	}

	void ReturnBlock(TreeNode* pTn) {
		// note: cast to point size and then do - operation
		TreeNodeMemBlock *blk = (TreeNodeMemBlock *)((unsigned int*)pTn - sizeof(bool));
		blk->_bUsed = false;
	}
};

TreeNode * GetFreeBlock() {
	return Singleton<MemBlockMgr>::getInstance(8).GetFreeBlock();
}

void ReturnBlock(TreeNode* pTn) {
	return Singleton<MemBlockMgr>::getInstance(8).ReturnBlock(pTn);
}

#pragma region 判断tree2是不是tree1的子节点
bool DoesTree1HasTree2(TreeNode *root1, TreeNode *root2)
{
	// Note: we check root2 first.
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;

	if (root1->value != root2->value)
		return false;

	return DoesTree1HasTree2(root1->left, root2->left) && DoesTree1HasTree2(root1->right, root2->right);
}
bool HasSubTree(TreeNode *root1, TreeNode *root2)
{
	if (root1 == NULL || root2 == NULL)
		return false;

	bool bRet = false;
	bRet = DoesTree1HasTree2(root1, root2);
	if (!bRet)
		bRet = HasSubTree(root1->left, root2);
	if (!bRet)
		bRet = HasSubTree(root1->right, root2);

	return bRet;
}

#pragma endregion

#pragma region Mirror of the tree
void MirrorRecursively(TreeNode *root)
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return;
	
	TreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;

	MirrorRecursively(root->left);
	MirrorRecursively(root->right);

}

void Mirror(TreeNode* root, TreeNode* root2)
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return;

	if (root2 == nullptr)
		return;

	if (root->right) {
		root2->left = new TreeNode();
		root2->left->value = root->right->value;
		Mirror(root->right, root2->left);
	}
		
	if (root->left) {
		root2->right = new TreeNode();
		root2->right->value = root->left->value;
		Mirror(root->left, root2->right);
	}
		
	
}
#pragma endregion

#pragma region Check if the sequence is post-order of BST
/*for example: 1,5,3,14,18,16,10 is true*/
bool verifySequenceOfBST(int sequence[], int length) {
	if (sequence == NULL || length == 0)
		return false;

	int rootValue = sequence[length - 1];
	int idx = 0;
	for (; idx < length - 1; idx++) {
		if (sequence[idx] > rootValue) {
			break;
		}
	}

	//now idx is the start of the right sub tree
	int rightStart = idx;
	for (; idx < length - 1; idx++) {
		if (sequence[idx] < rootValue)
			return false;
	}

	bool leftMatched = true;
	bool rightMatched = true;
	if (idx > 0) // indicate we have left tree
		leftMatched = verifySequenceOfBST(sequence, rightStart);

	if (idx < length - 1) // indicate we have right tree
		rightMatched = verifySequenceOfBST(sequence + rightStart, length - 1 - rightStart);


	return (leftMatched && rightMatched);
}
#pragma endregion

#pragma region 打印二叉树中结点值的和为输入值的所有路径
void FindPath(TreeNode *root, int expectedSum, std::vector<int> & path, int &sum)
{
	sum += root->value;
	path.push_back(root->value);

	bool leaf = root->left == NULL && root->right == NULL;
	if (leaf && sum == expectedSum) {
		//print path
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter) {
			printf("%d\t", (*iter));
		}
		printf("\n");
	}


	if (root->left != NULL) {
		FindPath(root->left, expectedSum, path, sum);
	}
	if (root->right != NULL) {
		FindPath(root->right, expectedSum, path, sum);
	}

	sum -= root->value;
	path.pop_back();
}
void FindPath(TreeNode *root, int expectedSum)
{
	if (root == NULL) return;

	int sum = 0;
	std::vector<int> vecPath;
	
	FindPath(root, expectedSum, vecPath, sum);

}


#pragma endregion

#pragma region B-search tree -> sorted doubly linked List
/*
requirement: use no extra space.
*/
void ConvertBTree(TreeNode *root, TreeNode **lastNode);
TreeNode *ConvertBTree2SortedDoublyList(TreeNode *root) {
	if (root == NULL)
		return NULL;

	TreeNode *lastNode = NULL;
	ConvertBTree(root, &lastNode);

	//find head
	while (lastNode !=NULL && lastNode->left != NULL)
	{
		lastNode = lastNode->left;
	}
	return lastNode; //new head

}
void ConvertBTree(TreeNode *root, TreeNode **lastNode)
{
	if (root == NULL)
		return;

	TreeNode *curNode = root;

	if (root->left != NULL) {
		ConvertBTree(root->left, lastNode);
	}

	if(*lastNode != NULL)
		(*lastNode)->right = curNode;
	curNode->left = *lastNode;

	*lastNode = root;
	if (root->right != NULL) {
		ConvertBTree(root->right, lastNode);
	}
}
#pragma endregion

#pragma region Tree depth related
bool IsBalanced(TreeNode *root, int& depth);
int TreeDepth(TreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftLeafDepth = TreeDepth(root->left);
	int rightLeafDepth = TreeDepth(root->right);

	return (leftLeafDepth > rightLeafDepth ? leftLeafDepth + 1 : rightLeafDepth + 1);
}
/*depth between left and right on each node is no more than 1, then we call it balanced*/
bool IsBalancedTree_v1(TreeNode *root) {
	if (root == NULL)
		return true;
	int leftLeafDepth = TreeDepth(root->left);
	int rightLeafDepth = TreeDepth(root->right);
	int diff = leftLeafDepth - rightLeafDepth;
	if (diff > 1 || diff < -1)
		return false;

	return IsBalancedTree_v1(root->left) && IsBalancedTree_v1(root->right);
}

bool IsBalanceTree_v2(TreeNode *root) {
	int depth = 0;
	return IsBalanced(root, depth);
}

bool IsBalanced(TreeNode *root, int& depth) {

	if (root == NULL) {
		depth = 0;
		return true;
	}
	int depthLeft;
	int depthRight = 0;
	if (IsBalanced(root->left, depthLeft) && IsBalanced(root->right, depthLeft))
	{
		int diff = depthLeft - depthRight;
		if (diff < 1 && diff > -1) {
			depth = depthLeft > depthRight ? depthLeft + 1 : depthRight + 1;
			return true;
		}
	}
	return false;
}
#pragma endregion


#pragma region Find lowest common ancestor in BST
int FindLowestCommonAncestor(TreeNode *root, int value1, int value2) {
	if (root == NULL)
		return 0;
	TreeNode *curNode = root;
	while (true) {
		if (value1 < curNode->value && value2 < curNode->value) {
			curNode = curNode->left;
		}
		else if (value1 > curNode->value && value2 > curNode->value) {
			curNode = curNode->right;
		}
		else {
			return curNode->value;
		}
	}

}
#pragma endregion

#pragma region rebuild tree based on preOrder array and inOrder array
TreeNode* BuildTreeBasedOnPreInArray(int pre[], int in[], int length)
{
	if (pre == NULL || in == NULL || length <= 0)
		return NULL;
		
	int rootValue = pre[0];
	TreeNode *root = new TreeNode();
	root->value = rootValue;
	root->left = root->right = NULL;

	int i = 0;
	for (; i < length; ++i)
	{
		if (in[i] == rootValue)
			break;
	}

	if (i == length)
	{
		//no match
		throw std::exception("invalid arr");
	}

	if (i > 0) {
		// It means we have left sub-tree
		root->left = BuildTreeBasedOnPreInArray(pre + 1, in, i);
	}
	if (i < length - 1)
	{
		// It means we have right sub-tree
		root->right = BuildTreeBasedOnPreInArray(pre + 1 + i, in + i + 1, length - 1 - i);
	}
	return root;
}
#pragma endregion

#pragma region traverse Tree
void display(TreeNode *root)
{
	if (root == nullptr) {
		return;
	}

	display(root->left);
	if(root->bDeleted != true)
		printf("%d\t", root->value);
	display(root->right);
}

void display_widthTraverse(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	std::queue<TreeNode*> que;
	que.push(root);

	while (!que.empty())
	{
		TreeNode *curNode = que.front();
		printf("%d\t", curNode->value);
		que.pop();

		if(curNode->left != NULL)
			que.push(curNode->left);
		if(curNode->right != NULL)
			que.push(curNode->right);
	}
	printf("\n");
	return;
}

#pragma endregion
int main()
{

	freeNode = new TreeNode[10];
	freeNode2 = (TreeNode*)malloc((sizeof(TreeNode)) * 10);
	TreeNodeMemBlock *tnMemBlock = new TreeNodeMemBlock[10];
	TreeNode tn;
	tn.BST_insert(1);
	tn.BST_insert(2);
	tn.BST_insert(4);
	tn.BST_insert(7);
	tn.BST_insert(3);
	tn.BST_insert(5);
	tn.BST_insert(6);
	tn.BST_insert(8);
	display(tn.root);
	tn.BST_Del(5);
	display(tn.root);
	tn.BST_insert(5);
	display(tn.root);
	int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int in[] = {4,7,2,1,5, 3, 8, 6};
	try {
		TreeNode * root = BuildTreeBasedOnPreInArray(pre, in, 8);
		display(root);
		cout << endl;
		display_widthTraverse(root);
		MirrorRecursively(root);
		display(root); //1 3 6 8 5 2 4 7
		cout << endl;
		TreeNode *root2 = new TreeNode();
		root2->value = root->value;
		root2->left = nullptr;
		root2->right = nullptr;
		Mirror(root, root2);
		display_widthTraverse(root2);

	}
	catch (exception e)
	{
		printf("%s", e.what());
	}

	getchar();
    return 0;
}

