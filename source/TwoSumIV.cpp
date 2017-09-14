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
		bool findTarget(TreeNode* root, int k) {
			set<int> nums;
			return findTarget(root, nums, k);
		}

		bool findTarget(TreeNode* root, set<int>& nums, int k) {
			if (!root) return false;

			if (nums.find(root->val) != nums.end()) return true;
			else nums.insert(k - root->val);

			if (findTarget(root->left, nums, k)) return true;
			if (findTarget(root->right, nums, k)) return true;

			return false;
		}
};
