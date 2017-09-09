
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
		int widthOfBinaryTree(TreeNode* root) {
			if (!root) return 0;

			std::vector<std::pair<int, int> > lLRMostIndics;

			leftRightMostNodes(root, 1, 1, lLRMostIdices);

			int result = 0;
			for (auto it = lLRMostIndics.begin(); it != lLRMostIndics.end(); ++it) {
				int width = it->second - it->first + 1;

				if (width > result) result = width;
			}

			return result;
		}

		void leftRightMostNodes(TreeNode* node, int level, int idx, std::vector<std::pair<int, int> >& LRMostIndices) {
			if (LRMostIndices.size() < level) {
				LRMostIndices.push_back(std::make_pair(idx, idx));
			} else {
				if (idx < LRMostIndices[level - 1].first) LRMostIndices[level - 1].first = idx;
				else if (idx > LRMostIndices[level - 1].second) LRMostIndices[level - 1].second = idx;
			}

			if (node->left) {
				leftRightMostNodes(node->left, level + 1, 2 * idx - 1, LRMostIndices);
			}
			if (node->right) {
				leftRightMostNodes(node->right, level + 1, 2 * idx, LRMostIndices);
			}
		}
};
