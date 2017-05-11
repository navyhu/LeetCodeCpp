#include <iostream>

using namespace std;

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
	bool isEqual(TreeNode* s, TreeNode* t) {
		if (!s && !t) return true;

		if (!s || !t || s->val != t->val) return false;

		if (!isEqual(s->left, t->left) || !isEqual(s->right, t->right)) return false;

		return true;
	}

	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s) {
			if (!t) return true;
			return false;
		}

		if (s->val == t->val && isEqual(s, t)) return true;

		if (isSubtree(s->left, t)) return true;
		return isSubtree(s->right, t);
	}
};
