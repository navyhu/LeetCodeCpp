/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>

class Solution {
public:
	// pair to store:
	// 1. diameter of the subtree
	// 2. depth of the subtree
	pair<int, int> diameterOfSubtree(TreeNode* root) {
		if (!root) return make_pair<int, <int>(0, 0);

		pair<int, int> left = diameterOfSubtree(root->left);
		pair<int, int> right = diameterOfSubtree(root->right);


		int diameter = (left.second + right.second > right.first) ? left.second + right.second : right.first;
		left.first = diameter > left.first ? diameter : left.first;

		left.second = 1 + (right.second > left.second ? right.second : left.second);

		return left;
	}

	int diameterOfBinaryTree(TreeNode* root) {
		pair<int, int> result = diameterOfSubtree(root);

		return result.first;
	}
};

