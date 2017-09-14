
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
		vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
			vector<TreeNode*> result;
			if (!root) return result;

			map<string, pair<TreeNode*, bool>> val2Nodes;
			findDuplicateSubtrees(root->left, val2Nodes, result);
			findDuplicateSubtrees(root->right, val2Nodes, result);
			return result;
		}

		string findDuplicateSubtrees(TreeNode* root, map<string, pair<TreeNode*, bool>>& val2Nodes, vector<TreeNode*>& result) {
			if (!root) return "";
			string key = to_string(root->val);

			key = key + "l" + findDuplicateSubtrees(root->left, val2Nodes, result) + "r" + findDuplicateSubtrees(root->right, val2Nodes, result);
			auto it = val2Nodes.find(key);
			if (it != val2Nodes.end()) {
				if (it->second.second == false) {
					result.push_back(it->second.first);
					it->second.second = true;
				}
			} else {
				val2Nodes[key] = make_pair(root, false);
			}

			return key;
		}
};
