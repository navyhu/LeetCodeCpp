/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		int findSecondMinimumValue(TreeNode* root) {
			if (!root || !root->left) return -1;

			int lLeftVal = root->left->val;
			int lRightVal = root->right->val;

			if (lLeftVal == root->val)
				lLeftVal = findSecondMinimumValue(root->left);

			if (lRightVal == root->val)
				lRightVal = findSecondMinimumValue(root->right);

			if (lLeftVal == -1) return lRightVal;
			if (lRightVal == -1) return lLeftVal;

			if (lLeftVal < lRightVal) return lLeftVal;

			return lRightVal;
		}
};
