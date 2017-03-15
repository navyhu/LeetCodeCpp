/**
 *
 ** Definition for a binary tree node.
 *
 ** struct TreeNode {
 *
 **int val;
 **TreeNode *left;
 *
 **reeNode *right;
 *
 **TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *
 **};
 *
 **/

#include <iostream>

class Solution
{
public:
	int getMinimumDifference(TreeNode* root)
	{
		if (root)
		{
			int lMax = lMin = -1;
			return getMaxMinOfTree(root, lMax, lMin);
		}

		return 0;
	}

	int getMaxMinOfTree(TreeNode* node, int& max, int& min)
	{
		int lResult = -1;

		if (node->left)
		{
			int lMax = -1;
			lResult = getMaxMinOfTree(node->left, lMax, min);

			if (lResult == 0)
			  return 0;

			if (node->val - lMax < lResult)
			  lResult = node->val - lMax;
		}
		else
		{
			min = node->val;
		}

		if (node->right)
		{
			int lMin = -1;
			int lDiff = getMaxMinOfTree(node->right, max, lMin);

			if (lDiff < lResult || lResult == -1)
			  lResult = lDiff;

			if (lMin - node->val < lResult)
			  lResult = lMin - node->val;
		}
		else
		{
			max = node->val;
		}

		return lResult;
	}
};

class Solution2
{
public:
	int getMinimumDifference(TreeNode* root)
	{
		if (!root) return mResult;

		getMinimumDifference(root->left);

		if (mValue != -1)
		{
			if (root->val - mValue < mResult || mResult == -1)
			  mResult = root->val - mValue;
		}

		mValue = root->val;

		getMinimumDifference(root->right);

		return mResult;
	}

	Solution2() : mResult(-1), mValue(-1)
	{
	}

private:
	int mResult;
	int mValue;
};

int main()
{
}
