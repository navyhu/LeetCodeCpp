
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
		TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
			return constructMaximumBinaryTree(nums, 0, nums.size());
		}

		TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end) {
			int idx = start;
			int val = nums[start];
			for (int i = start; i < end; i++) {
				if (val < nums[i]) {
					idx = i;
					val = nums[i];
				}
			}

			TreeNode* root = new TreeNode(val);
			if (start < idx)
				root->left = constructMaximumBinaryTree(nums, start, idx);
			if (idx + 1 < end)
				root->right = constructMaximumBinaryTree(nums, idx + 1, end);

			return root;
		}
};
