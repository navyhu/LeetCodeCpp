
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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<pair<long, int>> total;

		averageOfLevels(root, 0, total);

		vector<double> result;
		for (auto& it : total) {
			result.push_back(double(it.first) / double(it.second));
		}

		return result;
	}

	void averageOfLevels(TreeNode* root, int level, vector<pair<long, int>>& total) {
		if (!root) return;

		if (level < total.size()) {
			total[level].first += root->val;
			total[level].second++;
		} else {
			total.push_back(make_pair(root->val, 1));
		}

		averageOfLevels(root->left, level + 1, total);
		averageOfLevels(root->right, level + 1, total);
	}
};
