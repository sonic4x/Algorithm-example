// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
};

#pragma region 判断tree2是不是tree1的子节点
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
void FindPath(TreeNode *root, int expectedSum)
{
	if (root == NULL) return;

	int sum = 0;
	std::vector<int> vecPath;
	
	FindPath(root, expectedSum, vecPath, sum);

}

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
#pragma endregion

#pragma region B-search tree -> sorted doubly linked List
/*
requirement: use no extra space.
*/
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
	int depthLeft, depthRight;
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
TreeNode * BuildTree(int preOrderArr[], int inOrderArr[], int length)
{
	if (preOrderArr == NULL || inOrderArr == NULL || length <= 0)
		return NULL;

	int rootValue = preOrderArr[0];

	TreeNode *root = new TreeNode();
	root->left = root->right = NULL;
	root->value = rootValue;
	int i = 0;
	for (; i < length; i++)
	{
		if (inOrderArr[i] = rootValue)
		{
			break;
		}
	}

	//check if valid 
	if (i == length)
		throw std::exception("invalid arr");

	//now for inOrder arry, the [0,i-1] is the left tree
	//[i+1, length-1] is the right tree
	if(i>0)
		root->left = BuildTree(preOrderArr + 1, inOrderArr, i);
	if(length-i-1 > 0)
		root->right = BuildTree(preOrderArr + i, inOrderArr + i +1, length - i - 1);

	return root;
}
#pragma endregion
int main()
{
    return 0;
}

