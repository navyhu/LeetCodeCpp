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
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode* newRoot = new TreeNode(v);
			newRoot->left = root;
			return newRoot;
		}

		addOneRow(root, 1, v, d);

		return root;
	}

	void addOneRow(TreeNode* root, int cur_d, int v, int d) {
		if (!root) return;
		if (cur_d + 1 == d) {
			TreeNode* left = new TreeNode(v);
			TreeNode* right = new TreeNode(v);
			left->left = root->left;
			right->right = root->right;
			root->left = left;
			root->right = right;
			return;
		}
		addOneRow(root->left, cur_d + 1, v, d);
		addOneRow(root->right, cur_d + 1, v, d);
	}
};
