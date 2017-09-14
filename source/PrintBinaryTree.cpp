

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
		vector<vector<string>> printTree(TreeNode* root) {
			int m = getDepth(root);
			int n = pow(2, m) - 1;

			vector<vector<string>> result(m, vector<string>(n, ""));

			printTree(root, 0, n / 2, n, result);

			return result;
		}

		void printTree(TreeNode* root, int level, int idx, int n, vector<vector<string>>& result) {
			if (!root) return;

			result[level][idx] = numToStr(root->val);

			n  /= 2;
			printTree(root->left, level + 1, idx - (n + 1) / 2, n, result);
			printTree(root->right, level + 1, idx + (n + 1) / 2, n, result);
		}

		string numToStr(int num) {
			if (num == 0) return "0";
			string str;

			int pos = 0;
			if (num < 0) {
				str = "-";
				num = - num;
				pos = 1;
			}
			while (num > 0) {
				char digit = static_cast<char>(num % 10) + '0';
				num = num / 10;
				str.insert(pos, 1, digit);
			}

			return str;
		}

		int getDepth(TreeNode* root) {
			if (!root) return 0;

			int leftDepth = getDepth(root->left);
			int rightDepth = getDepth(root->right);

			return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
		}
};
