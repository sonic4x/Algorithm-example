// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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


int main()
{
    return 0;
}

