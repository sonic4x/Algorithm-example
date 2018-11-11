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
int main()
{
    return 0;
}

