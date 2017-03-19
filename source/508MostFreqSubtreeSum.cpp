#include <iostream>

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
	vector<int> findFrequentTreeSum(TreeNode* root) {
		treeSum(root);

		vector<int> result;
		for (auto entry : sums) {
			if (entry->second == mostFreq)
				result.push_back(entry->first);
		}

		return result;
	}

	int treeSum(TreeNode* root) {
		if (!root) return 0;

		int sum = root->val + treeSum(root->left) + treeSum(root->right);

		if (sums.find(sum) == sums.end())
			sums[sum] = 1;
		else
			sums[sum]++;

		mostFreq = sums[sum] > mostFreq ? sums[sums] : mostFreq;

		return sum;
	}

	Solution() : mostFreq(0), sums() {}
private:
	int mostFreq;
	map<int, int> sums;
};
