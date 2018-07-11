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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return root;

		int lDepth = 0;
		return hSubtreeWithAllDeepest(root, lDepth);
    }

private:
	TreeNode* hSubtreeWithAllDeepest(TreeNode* root, int& depth) {
		depth++;

		int lLeftDepth = depth;
		TreeNode* lLeftSubtree;
		if (root->left)
			lLeftSubtree = hSubtreeWithAllDeepest(root->left, lLeftDepth);

		int lRightDepth = depth;
		TreeNode* lRightSubtree;
		if (root->right)
			lRightSubtree = hSubtreeWithAllDeepest(root->right, lRightDepth);

		if (lLeftDepth < lRightDepth) {
			depth = lRightDepth;
			return lRightSubtree;
		}

		if (lLeftDepth > lRightDepth) {
			depth = lLeftDepth;
			return lLeftSubtree;
		}

		depth = lLeftDepth;
		return root;
	}
};
