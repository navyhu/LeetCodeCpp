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

using namespace std;

class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		if (level >= values.size()) {
			values.push_back(root->val);
		}   

		if (root->left) {
			level++;
			findBottomLeftValue(root->left);
			level--;
		}

		if (root->right) {
			level++;
			findBottomLeftValue(root->right);
			level--;
		}

		return *values.rbegin();
	}

	Solution() : level(0), values() {}
private:
	int level;
	vector<int> values;
};
