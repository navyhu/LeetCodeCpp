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
#include <map>
#include <vector>

class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		if (!root) return rowMax;

		int size = rowMax.size();
		if (level < size) {
			rowMax[level] = root->val > rowMax[level] ? root->val : rowMax[level];
		} else {
			rowMax.push_back(root->val);
		}

		level++;
		rowMax = largestValues(root->left);
		rowMax = largestValues(root->right);
		level--;

		return rowMax;
	}

	vector<int> largestValues2(TreeNode* root) {
		vector<int> result;
		if (!root) return result;

		vector<TreeNode*> nodes;
		int level = 0;
		TreeNode* cur = root;
		vector<int> visited;

		while (level >= 0) {
			if (!cur) {
				level--;
				if (level >= 0) cur = nodes[level];
			}

			if (level < nodes.size()) {
				nodes[level] = cur;
				result[level] = cur->val > result[level] ? cur->val : result[level];
			} else {
				nodes.push_back(cur);
				result.push_back(cur->val);
				visited.push_back(0);
			}

			// to lower level
			if (visited[level] == 0) {
				visited[level] = 1;
				level++;
				cur = cur->left;
			} else if (visited[level] == 1) {
				visited[level] = 2;
				level++;
				cur = cur->right;
			} else {
				//to upper level
				visited[level] = 0;
				level--;
				if (level >= 0) cur = nodes[level];
			}
		}

		return result;
	}

	Solution() : level(0), rowMax() {}
private:
	vector<int> rowMax;
	int level;
};
