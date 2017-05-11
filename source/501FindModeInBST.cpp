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
#include <map>

using namespace std;

class Solution {
public:
	void iterateTree(TreeNode* root) {
		if (!root) return;

		if (modes.find(root->val) == modes.end()) {
			modes[root->val] = 1;
		} else {
			modes[root->val]++;
		}

		mode = modes[root->val] > mode ? modes[root->val] : mode;

		iterateTree(root->left);
		iterateTree(root->right);
	}

	vector<int> findMode(TreeNode* root) {
		iterateTree(root);

		vector<int> result;
		for (auto entry : modes) {
			if (entry.second == mode)
				result.push_back(entry.first);
		}

		return result;
	}

	Solution() : mode(0), modes() {}

private:
	int mode;
	map<int, int> modes;
};
