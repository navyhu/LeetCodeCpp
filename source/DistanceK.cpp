#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		vector<int> result;

		if (root) hFindTarget(root, target, K, result);

		return result;
    }

private:
	int hFindTarget(TreeNode* root, TreeNode* target, int& K, vector<int>& result) {
		if (root == target) {
			// Target found, get distance K children nodes
			hGetDistanceKChildren(root, K, result);
			K--;
			return 1;
		}

		if (root->left && hFindTarget(root->left, target, K, result) == 1) {
			if (K == 0) result.push_back(root->val);
			else if (K > 0 && root->right)
				hGetDistanceKChildren(root->right, K - 1, result);
			K--;
			return 1;
		}

		if (root->right && hFindTarget(root->right, target, K, result) == 1) {
			if (K == 0) result.push_back(root->val);
			else if (K > 0 && root->left)
				hGetDistanceKChildren(root->left, K - 1, result);
			K--;
			return 1;
		}

		return -1;
	}

	void hGetDistanceKChildren(TreeNode* root, int K, vector<int>& result) {
		// Caller to make sure the root is not null
		if (K == 0) {
			result.push_back(root->val);
		} else {
			if (root->left) hGetDistanceKChildren(root->left, K - 1, result);
			if (root->right) hGetDistanceKChildren(root->right, K - 1, result);
		}
	}
};
